#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "array.h"
#include "turn.h"
#include "Commandmove.h"
#include "Commandspecialmove.h"
#include "Undo.h"
#include "leaderboard.h"
#include "bufferscreen.h"

//PROTOTIPE
void mainscreen();
//UI untuk bagian main menu

void readmain(boolean* g, Stack *S); 
//input user memilih new game, load game, leaderboard, atau exit

void play(Stack* S);
//main game


int main(){
    /*KAMUS*/
    boolean gameover = false;
    Stack movehistory;

    // welcome();
    CreateEmptyStack(&movehistory);

    while (!gameover) {
        mainscreen();
        readmain(&gameover, &movehistory);
    }
    
    return 0;
}

//IMPLEMENTASI
void readmain(boolean* g, Stack* S) {
//Input user memilih new game, load game, leaderboard, atau exit
    //KAMUS
    char pil;

    //ALGORITMA
    printf("Enter your command: ");
    scanf("%c", &pil);
    
    if (pil=='N'){   
        
        system("clear");
        play(S);
    } else if (pil=='L'){
        // load(g, S);
        //jalankan fungsi load
    } else if (pil=='B'){
        //jalankan fungsi print leaderboard
        
        system("clear");
        //printleaderboard();
    } else if (pil=='E'){
        *g = true;
        // eksit();
    } else {
        printf("Please input the correct command.\n");
        readmain(g, S);
    }
}

void play(Stack* S) {
//Menjalankan game
    //KAMUS
    board B;
    arr_possible_move black, white;
    int i, turncounter;
    Queue turn;
    char currentteam;
    char str[20];
    boolean donemove;

    //SALGORITMA

    /*****INISIALISASI*****/
    /*Array board/"Papan catur" diisi dengan bidak-bidak. Bidak tim putih ada di bagian bawah papan dan tim hitam ada di bagian atas papan.*/
    CreateBoard(&B);
	
    /*Array pencatan list-of-possible-move tiap bidak tim hitam diisi dengan info masing-masing bidak dan list kosong.*/
    MakeEmptyArrPMove(&black);
    for (i=1; i<= 8; i++) {
        black.arr[i].p = BoardCell(B)[i][8];
        CreateEmptyList(&black.arr[i].possmove);
    }
    
    for (i=9; i<= 16; i++) {
        black.arr[i].p = BoardCell(B)[i-8][7];
        CreateEmptyList(&black.arr[i].possmove);
    }
    
     /*Array pencatan list-of-possible-move tiap bidak tim putih diisi dengan info masing-masing bidak dan list kosong.*/
    MakeEmptyArrPMove(&white);
    for (i=1; i<= 8; i++) {
        white.arr[i].p = BoardCell(B)[i][1];
        CreateEmptyList(&white.arr[i].possmove);
    }
    for (i=9; i<= 16; i++) {
        white.arr[i].p = BoardCell(B)[i-8][2];
        CreateEmptyList(&white.arr[i].possmove);
    }
 
    /*Queue giliran (queue yang berisi 2 elemen, yaitu karakter 'W' dan 'B,
    dengan head awal di 'W' dan tail di 'B' dibuat.*/
	init_turn(*S, &turn);
    


    /*****PERMAINAN*****/	
    /*Game akan selesai setelah masing-masing pemain mendapat 50 giliran.*/
	turncounter = 1;
    while (turncounter <= 100) {

        BoardPrintInfo(B);


        currentteam = get_turn(&turn);

        /*Cek raja tim "currentteam" sudah termakan di giliran sebelumnya atau tidak. Jika iya, game berakhir.*/
        i = 1;
        if (currentteam == 'W') {
            while (white.arr[i].p.type != 'K') {
                i++;
            }
            if (white.arr[i].p.isdead == true) {
                break;
            }
        } else {
            while (black.arr[i].p.type != 'k') {
                i++;
            }
             if (black.arr[i].p.isdead == true) {
                break;
            }
        }

        /*Cek pemain tim "currentteam" sedang ter-skakmat atau tidak. Jika iya, game berakhir.*/
        if (turncounter >= 3) {
            i = 1;
            if (currentteam == 'W') {
                while (white.arr[i].p.type != 'K') {
                    i++;
                }
                if (isCheckmate(B, white.arr[i].p.xpos, white.arr[i].p.ypos, currentteam, white)) {
                    break;
                }
            } else {
                while (black.arr[i].p.type != 'k') {
                    i++;
                }
                if (isCheckmate(B, black.arr[i].p.xpos, black.arr[i].p.ypos, currentteam, black)) {
                    break;
                }
            }
        }

        /*Jika pemain tidak sedang dalam kondisi skakmat, pemain dapat memasukkan command.*/
        /*Jika pemain memasukkan "SPECIAL_MOVE" tetapi tidak ada special move yang dapat dilakukan
          , pemain akan diminta untuk memasukkan commmand lagi.*/
        donemove = false;
        while (donemove == false) {
            printf("Masukkan command: ");
            scanf("%s", str);

            /*Setelah tim putih dan hitam masing-masing sudah melangkah 1 kali, undo baru dapat dilakukan.*/
            /*Bagian ini memvalidasi masukkan tim putih dan hitam pertama agar "UNDO" tidak dimasukkan.*/
            if (turncounter <= 2) {
                while((strcmp(str, "MOVE") != 0) && (strcmp(str, "SPECIAL_MOVE") != 0)) {
                    printf("Command tidak dapat dilakukan.\n");
                    printf("Command-command yang dapat dijalankan adalah 'MOVE' dan 'SPECIAL_MOVE'.\n");
                    printf("Masukkan command: ");
                    scanf("%s", str);
                }
            } else {
                while((strcmp(str, "MOVE") != 0) && (strcmp(str, "SPECIAL_MOVE") != 0) && (strcmp(str, "UNDO") != 0)) {
                    printf("Command tidak dapat dilakukan.\n");
                    printf("Command-command yang dapat dijalankan adalah 'MOVE', 'SPECIAL_MOVE', atau 'UNDO'.\n");
                    printf("Masukkan command: ");
                    scanf("%s", str);
                }
            }

            /*Fungsi move/special_move/Undo akan dijalankan sesuai masukkan pengguna.*/
            if (currentteam == 'W') {
                if (strcmp(str, "MOVE") == 0) {

                    move(S, currentteam, &white, &black, &B);
                    donemove = true;
                    turncounter++;

                } else if (strcmp(str, "SPECIAL_MOVE") == 0) {

                    special_move(&white, &black, &B, S, currentteam, &donemove);
                    if (donemove == true) {
                        turncounter++;
                    }

                } else if (strcmp(str, "UNDO") == 0) {

                    Undo(&white, &black, S, &B);
                    donemove = true;
                    turncounter = turncounter - 2;
                    currentteam = get_turn(&turn); /*Agar saat masuk ke loop, turn tetap tim W*/
                }
            } else {
                if (strcmp(str, "MOVE") == 0) {

                    move(S, currentteam, &black, &white, &B);
                    donemove = true;
                    turncounter++;

                } else if (strcmp(str, "SPECIAL_MOVE") == 0) {

                    special_move(&white, &black, &B, S, currentteam, &donemove);
                    if (donemove == true) {
                        turncounter++;
                    }

                } else if (strcmp(str, "UNDO") == 0) {

                    Undo(&white, &black, S, &B);
                    donemove = true;
                    turncounter = turncounter - 2;
                    currentteam = get_turn(&turn); /*Agar saat masuk ke loop, turn tetap tim B*/
                }
            }
        }
    }


    /*****KEMBALI KE MAIN MENU*****/
    printf("GAME OVER\n");
}