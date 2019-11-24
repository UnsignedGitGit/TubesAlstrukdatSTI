#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "array.h"
#include "turn.h"

#include "Commandmove.h"
#include "Commandspecialmove.h"
#include "Undo.h"
#include "leaderboard.h"

void welcome(); //animasi singkat
void initiate(); //inisialisasi semua
void mainscreen(); //UI main menu
void plyrname(); //input nama pemain
void readmain(boolean* g, Stack *S); //input user memilih new game, load game, leaderboard, atau exit
void delay(int number_of_seconds); 
void play(Stack* S); //main game
void gameover();
void load();
void eksit();

int main(){
    /*KAMUS*/
    boolean gameover = false;
    Stack movehistory;

    /*ALGORITMA*/
  /*   welcome();
        delay (7);
        printf ("Loading");
        delay (5);
        printf (".");
        delay (5);
        printf (".");
        delay(5);
        printf (".");
        delay (8);
        
        system("cls");    
        printf("                                                           \n");
        printf("                 `      :                                  \n");
        printf("             `     ` `.-o-.                                \n");
        printf("           `   ``   ` `.s-                                 \n");
        printf("             `   ``` `.:+++/            `  `  `            \n");
        printf("           `   `  ````-:o+o.       `-`````` `````   `      \n");
        printf("                 `  ``-/+++        /o+/:...  ```` `        \n");
        printf("             `    ` `-+oooo:     .ossooo+:- `` ` `         \n");
        printf("                  ```-++sss-    -o+:-/so+/-..````  `       \n");
        printf("                 ` ` .-+ooo`        -ooo++-`` ` `          \n");
        printf("                  `.`.:+soo`      .+oosoo/-`` `   `        \n");
        printf("                    `.-+ooo:     :sssoss+/.` ` `           \n");
        printf("                 `  --/+oooo.`   +sssosss+` `              \n");
        printf("                  `.osyyyyyyo-  `/sssssso/-``   `          \n");
        printf("                   .-+ossoss/.  ./sssoso/-.`` `            \n");
        printf("                  `+ssssssssss. osssssssso/-`              \n");
        printf("                  `://////////.`://////////.               \n");
        printf("                                                            \n");  
        printf("                 W  E  L  C  O  M  E    T  O               \n");
        printf("       C  H  E  S  S    M  U  L  T  I  P  L  A  Y  E  R    \n\n");
        printf("Loading complete. Press enter to continue. \n");
        getchar();
        
        system("cls"); */
    
    CreateEmptyStack(&movehistory);

    while (!gameover) {
        mainscreen();
        readmain(&gameover, &movehistory);
    }
    
    return 0;
}


void readmain(boolean* g, Stack* S) {
    /*KAMUS*/
    char pil;

    /*ALGORITMA*/

    printf("Enter your command: ");
    scanf("%c", &pil);
    
    if (pil=='N'){   
        
        system("cls");
        play(S);
    } else if (pil=='L'){
        load(g, S);
        //jalankan fungsi load
    } else if (pil=='B'){
        //jalankan fungsi print leaderboard
        
        system("cls");
        //printleaderboard();
    } else if (pil=='E'){
        *g = true;
        eksit();
    } else {
        printf("Please input the correct command.\n");
        readmain(g, S);
    }
}

void play(Stack* S) {
    /*KAMUS*/
    board B;
    arr_possible_move black, white;
    int i, turncounter;
    Queue turn;
    char currentteam;
    char str[20];
    boolean donemove;

    /*ALGORITMA*/
    

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
    gameover();
}

void load(boolean* g, Stack* S){
    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);
    delay(7);
    printf("%s loaded succesfully, starting in a few seconds", filename);
    delay(5);
    printf(".");
    delay(5);
    printf(".");
    delay(5);
    printf(".");
    delay(15);
    
    system("cls");
    play(S);
}

void delay(int number_of_seconds){ 
    // Converting time into milli_seconds 
    int milli_seconds = 100 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void welcome(){
	printf("                                                           \n");
    printf("                                                           \n");             
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("      + + +         // - ` . .                             \n");
    printf("                     ` ` - : o +o + o +     / / / /        \n");
    printf("         + oo o o : : : + = - . o s s o o o                \n");
    printf("             ` ` - + +s s s- -- +o - o+ :- / s o+ / --     \n");
    printf("          `  o  `` ` s ss s s  o o                         \n");
    printf("                    s  o o` ` `   a ` ` os o o  / `        \n");
    printf("            -  : :  o : s                                  \n");
    printf("                   + o o oo . ` ` + o = +  s s s o         \n");
    printf("               - o + ` / s s                               \n");
    printf("                              / .. + . / s ss              \n");
    printf("                         s.   o s                          \n");
    printf("                                       `:`                 \n");
    printf("                                                           \n");  
    delay(2); 
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                .:+++       //-`..                         \n");
    printf("                           ``-:o+o+o+  /////o+/:..         \n");
    printf("             ``-+oooo:::+=-.ossooo++=:                     \n");
    printf("                         ``-++sss---+o-o+:-/so+/--         \n");
    printf("             ``-+ooo```sssssssooo++-`                      \n");
    printf("                          `.:+soo```oo0a``osoo/`           \n");
    printf("              -+ooo:::==o:ssssss                           \n");
    printf("                             +oooo.``+o=+ssso              \n");
    printf("                  yyyo--o+`/ss                             \n");
    printf("                                 /..+./sss                 \n");
    printf("                       s. os                               \n");
    printf("                                    `:`                    \n");
    printf("                                                           \n");  
    delay(2); 
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");           
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                 .:+++       //-`..                        \n");
    printf("                          ``-:o+o+o+  /////o+/:..          \n");
    printf("              ``-+oooo:::+=-.ossooo++=:                    \n");
    printf("                        ``-++sss---+o-o+:-/so+/--          \n");
    printf("              ``-+ooo```sssssssooo++-`                     \n");
    printf("                         `.:+soo```oo0a``osoo/`            \n");
    printf("               -+ooo:::==o:ssssss                          \n");
    printf("                            +oooo.``+o=+ssso               \n");
    printf("                    yyyo--o+`/ss                           \n");
    printf("                                /..+./sss                  \n");
    printf("                        s. os                              \n");
    printf("                                   `:`                     \n");
    printf("                                                           \n");  
    printf("                             W  E  L                       \n");
    delay(2); 
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                  .:+++       //-`..                       \n");
    printf("                         ``-:o+o+o+  /////o+/:..           \n");
    printf("               ``-+oooo:::+=-.ossooo++=:                   \n");
    printf("                       ``-++sss---+o-o+:-/so+/--           \n");
    printf("               ``-+ooo```sssssssooo++-`                    \n");
    printf("                        `.:+soo```oo0a``osoo/`             \n");
    printf("                -+ooo:::==o:ssssss                         \n");
    printf("                           +oooo.``+o=+ssso                \n");
    printf("                     yyyo--o+`/ss                          \n");
    printf("                               /..+./sss                   \n");
    printf("                         s. os                             \n");
    printf("                                  `:`                      \n");
    printf("                                                           \n");  
    printf("                      W  E  L  C  O  M  E                  \n");
    delay(2); 
    system("cls");
    

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                    .:+++       //-`..                     \n");
    printf("                       ``-:o+o+o+  /////o+/:..             \n");
    printf("                 ``-+oooo:::+=-.ossooo++=:                 \n");
    printf("                     ``-++sss---+o-o+:-/so+/--             \n");
    printf("                 ``-+ooo```sssssssooo++-`                  \n");
    printf("                      `.:+soo```oo0a``osoo/`               \n");
    printf("                  -+ooo:::==o:ssssss                       \n");
    printf("                         +oooo.``+o=+ssso                  \n");
    printf("                       yyyo--o+`/ss                        \n");
    printf("                             /..+./sss                     \n");
    printf("                           s. os                           \n");
    printf("                                `:`                        \n");
    printf("                                                           \n");  
    printf("                 W  E  L  C  O  M  E                       \n");
    delay(2); 
    system("cls");
    
    
    printf("                                                           \n");
    printf("                                                           \n");                
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                      .:+++       //-`..                   \n");
    printf("                    ``-:o+o+o+  /////o+/:..                \n");
    printf("                   ``-+oooo:::+=-.ossooo++=:               \n");
    printf("                   ``-++sss---+o-o+:-/so+/--               \n");
    printf("                   ``-+ooo```sssssssooo++-`                \n");
    printf("                    `.:+soo```oo0a``osoo/`                 \n");
    printf("                      -+ooo:::==o:ssssss                   \n");
    printf("                       +oooo.``+o=+ssso                    \n");
    printf("                         yyyo--o+`/ss                      \n");
    printf("                           /..+./sss                       \n");
    printf("                             s. os                         \n");
    printf("                              `:`                          \n");
    printf("                                                           \n");  
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    delay(2); 
    system("cls");
    

    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                     `.:+++/       `-`````` `              \n");
    printf("                  ````-:o+o+o+  /////o+/:...``             \n");
    printf("                 ````-+oooo:::+=-.ossooo++=:-``            \n");
    printf("                 ````-++sss---+o-o+:-/so+/--```            \n");
    printf("                   ` .-+ooo```sssssssooo++-```             \n");
    printf("                  `.`.:+soo```oo0a``osoo/-```              \n");
    printf("                    `.-+ooo:::==o:ssss+/````               \n");
    printf("                      /+oooo.``+o=+sssoss+'                \n");
    printf("                        yyyyo--o+`/sssss-                   \n");
    printf("                          s/..+./sssos                     \n");
    printf("                           sss. ossss                      \n");
    printf("                              .`://                        \n");
    printf("                                                           \n");  
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("                                                           \n\n");    
    delay(2); 
    system("cls");
    

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                      `.s-              `  `               \n");
    printf("                     `.:+++///     `-`````` ```            \n");
    printf("                  ````-:o+o...  /////o+/:...``             \n");
    printf("                 ````-+oooo:::+=-.ossooo+:- ````           \n");
    printf("                 ````-++sss---  -o+:-/so+/-..``            \n");
    printf("                   ` .-+ooo```sssssssooo++-````            \n");
    printf("                  `.`.:+soo```oo0a``osoo/-````             \n");
    printf("                    `.-+ooo:::   :ssss+/.```               \n");
    printf("                     -/+oooo.``  +sssoss+''                \n");
    printf("                       yyyyyo-- `/ssssso/-                 \n");
    printf("                         ss/.. ./sssos/-                   \n");
    printf("                          ssss. ossssss                    \n");
    printf("                            //.`:////                      \n");
    printf("                                                           \n");   
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("                        C  H  E                            \n\n");
    delay(2); 
    system("cls");
    

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                     .-o-.                                 \n");
    printf("                    ` `.s-              `  `  `            \n");
    printf("                  `` `.:+++/       `-`````` ``````         \n");
    printf("                 `````-:o+o...      /o+/:...  `````        \n");
    printf("                 ````-+oooo:::   .ossooo+:- `` ``          \n");
    printf("                  ```-++sss---  -o+:-/so+/-..`````         \n");
    printf("                   ` .-+ooo```      -ooo++-`` ``           \n");
    printf("                  `.`.:+soo```   .+oosoo/-`` ``            \n");
    printf("                    `.-+ooo:::   :ssss+/.```               \n");
    printf("                     -/+oooo.``  +sssoss+                  \n");
    printf("                      yyyyyyo-- `/ssssso/-                 \n");
    printf("                       soss/.. ./sssos/-.                  \n");
    printf("                        ssssss. osssssss                   \n");
    printf("                         /////.`://///                     \n");
    printf("                                                           \n");                              
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("                        C  H  E  S  S                      \n\n");
    delay(2); 
    system("cls");
    

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                      .-o-.                                \n");
    printf("                     ``.s-                                 \n");
    printf("                   ```.:+++/            ``                 \n");
    printf("                  ````-:o+o.       `-`````````             \n");
    printf("                    ``-/+++        /o+/:...  ``            \n");
    printf("                   ``-+oooo:     .ossooo+:- ``             \n");
    printf("                   ``-++sss-    -o+:-/so+/-..``            \n");
    printf("                    `.-+ooo`        -ooo++-```             \n");
    printf("                    `.:+soo`      .+oosoo/-``              \n");
    printf("                     .-+ooo:     :sssoss+/.`               \n");
    printf("                    --/+oooo.`   +sssosss+`                \n");
    printf("                   .osyyyyyyo-  `/sssssso/-`               \n");
    printf("                   .-+ossoss/.  ./sssoso/-.`               \n");
    printf("                   +ssssssssss. osssssssso/-               \n");
    printf("                   ://////////.`://////////.               \n");
    printf("                                                            \n");                              
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("               C  H  E  S  S    M  U  L                   \n\n");
    delay(2); 
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                     `.-o-.                                \n");
    printf("                     ``.s-                                 \n");
    printf("                  ````.:+++/            ` `                \n");
    printf("                  ````-:o+o.       `-````````` `           \n");
    printf("                  ` ``-/+++        /o+/:...  ```           \n");
    printf("                  ```-+oooo:     .ossooo+:- ```            \n");
    printf("                  ```-++sss-    -o+:-/so+/-..```           \n");
    printf("                   ``.-+ooo`        -ooo++-```             \n");
    printf("                   ``.:+soo`      .+oosoo/-```             \n");
    printf("                    `.-+ooo:     :sssoss+/.``              \n");
    printf("                  ` --/+oooo.`   +sssosss+``               \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``              \n");
    printf("                   .-+ossoss/.  ./sssoso/-.``              \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    printf("                                                            \n");                              
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("               C  H  E  S  S    M  U  L  T  I             \n\n");
    delay(2); 
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                     `.-o-.                                \n");
    printf("                    ` `.s-                                 \n");
    printf("                 ``` `.:+++/            `  `               \n");
    printf("                  ````-:o+o.       `-`````` ``` `          \n");
    printf("                 `  ``-/+++        /o+/:...  `` `          \n");
    printf("                  ` `-+oooo:     .ossooo+:- `` `           \n");
    printf("                  ```-++sss-    -o+:-/so+/-..`` `          \n");
    printf("                 ` ` .-+ooo`        -ooo++-`` `            \n");
    printf("                  `.`.:+soo`      .+oosoo/-`` `            \n");
    printf("                    `.-+ooo:     :sssoss+/.` `             \n");
    printf("                 `  --/+oooo.`   +sssosss+` `              \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``              \n");
    printf("                   .-+ossoss/.  ./sssoso/-.``              \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    printf("                                                            \n");                              
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("       C  H  E  S  S    M  U  L  T  I  P  L  A            \n\n");
    delay(2); 
    system("cls");

    printf("                                                           \n");
    printf("                 `      :                                  \n");                               
    printf("             `     ` `.-o-.                                \n");
    printf("           `   ``   ` `.s-                                 \n");
    printf("             `   ``` `.:+++/            `  `  `            \n");
    printf("           `   `  ````-:o+o.       `-`````` `````   `      \n");
    printf("                 `  ``-/+++        /o+/:...  ```` `        \n");
    printf("             `    ` `-+oooo:     .ossooo+:- `` ` `         \n");
    printf("                  ```-++sss-    -o+:-/so+/-..````  `       \n");
    printf("                 ` ` .-+ooo`        -ooo++-`` ` `          \n");
    printf("                  `.`.:+soo`      .+oosoo/-`` `   `        \n");
    printf("                    `.-+ooo:     :sssoss+/.` ` `           \n");
    printf("                 `  --/+oooo.`   +sssosss+` `              \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``   `          \n");
    printf("                   .-+ossoss/.  ./sssoso/-.`` `            \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    printf("                                                            \n");                              
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    printf("       C  H  E  S  S    M  U  L  T  I  P  L  A  Y  E  R    \n\n");
}

void mainscreen(){
    printf("##################################################################\n\n");
    printf("       _________ __     __ ________  ________ ________    __      \n");
    printf("      /   ______|  |   |  |  ______|/  ______/  ______|  |  |     \n");
    printf("      |  |      |  |___|  |  |__   |  (_____ |  (_____   |  |     \n");
    printf("      |  |      |   ___   |   __|   \\_____   \\______  \\  |__| \n");  
    printf("      |  |______|  |   |  |  |_____  _____)  | _____)  |  __      \n");
    printf("      \\_________|__|   |__|________|/________/________/  |__|   \n\n");
    printf("                                                       (v.0.1)    \n");
    printf("##################################################################\n\n");
    printf("               **WELCOME TO CHESS KACANG BUNCHESS**               \n");
    printf("_________________________________________________________________\n");
    printf("|                                                               |\n");
    printf("|                          <(N)ew Game>                         |\n");
    printf("|                         <(L)oad Game>                         |\n");
    printf("|                        <Leader(B)oards>                       |\n");
    printf("|                           <(E)xit>                            |\n");
    printf("|_______________________________________________________________|  \n");
}

void eksit(){
    printf("                                                           \n");
    printf("                 `      :                                  \n");                               
    printf("             `     ` `.-o-.                                \n");
    printf("           `   ``   ` `.s-                                 \n");
    printf("             `   ``` `.:+++/            `  `  `            \n");
    printf("           `   `  ````-:o+o.       `-`````` `````   `      \n");
    printf("                 `  ``-/+++        /o+/:...  ```` `        \n");
    printf("             `    ` `-+oooo:     .ossooo+:- `` ` `         \n");
    printf("                  ```-++sss-    -o+:-/so+/-..````  `       \n");
    printf("                 ` ` .-+ooo`        -ooo++-`` ` `          \n");
    printf("                  `.`.:+soo`      .+oosoo/-`` `   `        \n");
    printf("                    `.-+ooo:     :sssoss+/.` ` `           \n");
    printf("                 `  --/+oooo.`   +sssosss+` `              \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``   `          \n");
    printf("                   .-+ossoss/.  ./sssoso/-.`` `            \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    printf("                                                            \n"); 
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                     `.-o-.                                \n");
    printf("                    ` `.s-                                 \n");
    printf("                 ``` `.:+++/            `  `               \n");
    printf("                  ````-:o+o.       `-`````` ``` `          \n");
    printf("                 `  ``-/+++        /o+/:...  `` `          \n");
    printf("                  ` `-+oooo:     .ossooo+:- `` `           \n");
    printf("                  ```-++sss-    -o+:-/so+/-..`` `          \n");
    printf("                 ` ` .-+ooo`        -ooo++-`` `            \n");
    printf("                  `.`.:+soo`      .+oosoo/-`` `            \n");
    printf("                    `.-+ooo:     :sssoss+/.` `             \n");
    printf("                 `  --/+oooo.`   +sssosss+` `              \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``              \n");
    printf("                   .-+ossoss/.  ./sssoso/-.``              \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    delay(2); 
system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                     `.-o-.                                \n");
    printf("                     ``.s-                                 \n");
    printf("                  ````.:+++/            ` `                \n");
    printf("                  ````-:o+o.       `-````````` `           \n");
    printf("                  ` ``-/+++        /o+/:...  ```           \n");
    printf("                  ```-+oooo:     .ossooo+:- ```            \n");
    printf("                  ```-++sss-    -o+:-/so+/-..```           \n");
    printf("                   ``.-+ooo`        -ooo++-```             \n");
    printf("                   ``.:+soo`      .+oosoo/-```             \n");
    printf("                    `.-+ooo:     :sssoss+/.``              \n");
    printf("                  ` --/+oooo.`   +sssosss+``               \n");
    printf("                  `.osyyyyyyo-  `/sssssso/-``              \n");
    printf("                   .-+ossoss/.  ./sssoso/-.``              \n");
    printf("                  `+ssssssssss. osssssssso/-`              \n");
    printf("                  `://////////.`://////////.               \n");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                      .-o-.                                \n");
    printf("                     ``.s-                                 \n");
    printf("                   ```.:+++/            ``                 \n");
    printf("                  ````-:o+o.       `-`````````             \n");
    printf("                    ``-/+++        /o+/:...  ``            \n");
    printf("                   ``-+oooo:     .ossooo+:- ``             \n");
    printf("                   ``-++sss-    -o+:-/so+/-..``            \n");
    printf("                    `.-+ooo`        -ooo++-```             \n");
    printf("                    `.:+soo`      .+oosoo/-``              \n");
    printf("                     .-+ooo:     :sssoss+/.`               \n");
    printf("                    --/+oooo.`   +sssosss+`                \n");
    printf("                   .osyyyyyyo-  `/sssssso/-`               \n");
    printf("                   .-+ossoss/.  ./sssoso/-.`               \n");
    printf("                   +ssssssssss. osssssssso/-               \n");
    printf("                   ://////////.`://////////.               \n");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                     .-o-.                                 \n");
    printf("                    ` `.s-              `  `  `            \n");
    printf("                  `` `.:+++/       `-`````` ``````         \n");
    printf("                 `````-:o+o...      /o+/:...  `````        \n");
    printf("                 ````-+oooo:::   .ossooo+:- `` ``          \n");
    printf("                  ```-++sss---  -o+:-/so+/-..`````         \n");
    printf("                   ` .-+ooo```      -ooo++-`` ``           \n");
    printf("                  `.`.:+soo```   .+oosoo/-`` ``            \n");
    printf("                    `.-+ooo:::   :ssss+/.```               \n");
    printf("                     -/+oooo.``  +sssoss+                  \n");
    printf("                      yyyyyyo-- `/ssssso/-                 \n");
    printf("                       soss/.. ./sssos/-.                  \n");
    printf("                        ssssss. osssssss                   \n");
    printf("                         /////.`://///                     \n");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                      `.s-              `  `               \n");
    printf("                     `.:+++///     `-`````` ```            \n");
    printf("                  ````-:o+o...  /////o+/:...``             \n");
    printf("                 ````-+oooo:::+=-.ossooo+:- ````           \n");
    printf("                 ````-++sss---  -o+:-/so+/-..``            \n");
    printf("                   ` .-+ooo```sssssssooo++-````            \n");
    printf("                  `.`.:+soo```oo0a``osoo/-````             \n");
    printf("                    `.-+ooo:::   :ssss+/.```               \n");
    printf("                     -/+oooo.``  +sssoss+''                \n");
    printf("                       yyyyyo-- `/ssssso/-                 \n");
    printf("                         ss/.. ./sssos/-                   \n");
    printf("                          ssss. ossssss                    \n");
    printf("                            //.`:////                      \n");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                     `.:+++/       `-`````` `              \n");
    printf("                  ````-:o+o+o+  /////o+/:...``             \n");
    printf("                 ````-+oooo:::+=-.ossooo++=:-``            \n");
    printf("                 ````-++sss---+o-o+:-/so+/--```            \n");
    printf("                   ` .-+ooo```sssssssooo++-```             \n");
    printf("                  `.`.:+soo```oo0a``osoo/-```              \n");
    printf("                    `.-+ooo:::==o:ssss+/````               \n");
    printf("                      /+oooo.``+o=+sssoss+'                \n");
    printf("                        yyyyo--o+`/sssss-                   \n");
    printf("                          s/..+./sssos                     \n");
    printf("                           sss. ossss                      \n");
    printf("                              .`://                        \n");
    printf ("                   B        y        e        !             ");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                      .:+++       //-`..                   \n");
    printf("                    ``-:o+o+o+  /////o+/:..                \n");
    printf("                   ``-+oooo:::+=-.ossooo++=:               \n");
    printf("                   ``-++sss---+o-o+:-/so+/--               \n");
    printf("                   ``-+ooo```sssssssooo++-`                \n");
    printf("                    `.:+soo```oo0a``osoo/`                 \n");
    printf("                      -+ooo:::==o:ssssss                   \n");
    printf("                       +oooo.``+o=+ssso                    \n");
    printf("                         yyyo--o+`/ss                      \n");
    printf("                           /..+./sss                       \n");
    printf("                             s. os                         \n");
    printf("                              `:`                          \n");
    printf ("                    B      y      e      !                  ");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                    .:+++       //-`..                     \n");
    printf("                       ``-:o+o+o+  /////o+/:..             \n");
    printf("                 ``-+oooo:::+=-.ossooo++=:                 \n");
    printf("                     ``-++sss---+o-o+:-/so+/--             \n");
    printf("                 ``-+ooo```sssssssooo++-`                  \n");
    printf("                      `.:+soo```oo0a``osoo/`               \n");
    printf("                  -+ooo:::==o:ssssss                       \n");
    printf("                         +oooo.``+o=+ssso                  \n");
    printf("                       yyyo--o+`/ss                        \n");
    printf("                             /..+./sss                     \n");
    printf("                           s. os                           \n");
    printf("                                `:`                        \n");
    printf ("                      B    y    e    !                      ");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                  .:+++       //-`..                       \n");
    printf("                         ``-:o+o+o+  /////o+/:..           \n");
    printf("               ``-+oooo:::+=-.ossooo++=:                   \n");
    printf("                       ``-++sss---+o-o+:-/so+/--           \n");
    printf("               ``-+ooo```sssssssooo++-`                    \n");
    printf("                        `.:+soo```oo0a``osoo/`             \n");
    printf("                -+ooo:::==o:ssssss                         \n");
    printf("                           +oooo.``+o=+ssso                \n");
    printf("                     yyyo--o+`/ss                          \n");
    printf("                               /..+./sss                   \n");
    printf("                         s. os                             \n");
    printf("                                  `:`                      \n");
    printf ("                       B   y   e   !                        ");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                 .:+++       //-`..                        \n");
    printf("                          ``-:o+o+o+  /////o+/:..          \n");
    printf("              ``-+oooo:::+=-.ossooo++=:                    \n");
    printf("                        ``-++sss---+o-o+:-/so+/--          \n");
    printf("              ``-+ooo```sssssssooo++-`                     \n");
    printf("                         `.:+soo```oo0a``osoo/`            \n");
    printf("               -+ooo:::==o:ssssss                          \n");
    printf("                            +oooo.``+o=+ssso               \n");
    printf("                    yyyo--o+`/ss                           \n");
    printf("                                /..+./sss                  \n");
    printf("                        s. os                              \n");
    printf("                                   `:`                     \n");
    printf("                                                           \n");  
    printf ("                        B  y  e  !                          ");
    delay(2); 
system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                .:+++       //-`..                         \n");
    printf("                           ``-:o+o+o+  /////o+/:..         \n");
    printf("             ``-+oooo:::+=-.ossooo++=:                     \n");
    printf("                         ``-++sss---+o-o+:-/so+/--         \n");
    printf("             ``-+ooo```sssssssooo++-`                      \n");
    printf("                          `.:+soo```oo0a``osoo/`           \n");
    printf("              -+ooo:::==o:ssssss                           \n");
    printf("                             +oooo.``+o=+ssso              \n");
    printf("                  yyyo--o+`/ss                             \n");
    printf("                                 /..+./sss                 \n");
    printf("                       s. os                               \n");
    printf("                                    `:`                    \n");
    printf("                                                           \n");  
    printf ("                           B y e !                          ");
    delay(2); 
system("cls");
     
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("      + + +         // - ` . .                             \n");
    printf("                     ` ` - : o +o + o +     / / / /        \n");
    printf("         + oo o o : : : + = - . o s s o o o                \n");
    printf("             ` ` - + +s s s- -- +o - o+ :- / s o+ / --     \n");
    printf("          `  o  `` ` s ss s s  o o                         \n");
    printf("                    s  o o` ` `   a ` ` os o o  / `        \n");
    printf("            -  : :  o : s                                  \n");
    printf("                   + o o oo . ` ` + o = +  s s s o         \n");
    printf("               - o + ` / s s                               \n");
    printf("                              / .. + . / s ss              \n");
    printf("                         s.   o s                          \n");
    printf("                                       `:`                 \n");
    printf("                                                           \n");  
    printf ("                            Bye!                            ");
    delay(8); 
system("cls");
}

void gameover(){
    printf("                                                                         ___     ___   __  _\n");
    printf("                                                                        / __|   /   \\ |  \\\n");
    printf("                                                                        | (_ |   | - | | |\\\n");
    printf("                                                                        \\___|   |_|_| |_|__\n");
    printf("                                                                      _|`````|_|`````|_|````\n");
    printf("                                                                      ``-0-0-```-0-0-```-0-0\n"); 
    delay (2); system ("cls");
    
    printf("                                                               ___     ___   __  __    ___  \n");
    printf("                                                              / __|   /   \\ |  \\/  |  | __\n");
    printf("                                                             | (_ |   | - | | |\\/| |  | _| \n");
    printf("                                                              \\___|   |_|_| |_|__|_|  |___|\n");
    printf("                                                            _|`````|_|`````|_|`````|_|`````|\n");
    printf("                                                            ``-0-0-```-0-0-```-0-0-```-0-0-`\n"); 
    delay (2); system ("cls");

    printf("                                                      ___     ___   __  __    ___           \n");
    printf("                                                     / __|   /   \\ |  \\/  |  | __|     o O\n");
    printf("                                                    | (_ |   | - | | |\\/| |  | _|     o    \n");
    printf("                                                     \\___|   |_|_| |_|__|_|  |___|   TS__[O\n");
    printf("                                                   _|`````|_|`````|_|`````|_|`````| {======|\n");
    printf("                                                   ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000`\n"); 
    delay (2); system ("cls");
    
    printf("                                              ___     ___   __  __    ___              ___  \n");
    printf("                                             / __|   /   \\ |  \\/  |  | __|     o O O  / _ \n");
    printf("                                            | (_ |   | - | | |\\/| |  | _|     o      | (_) \n");
    printf("                                             \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___\n");
    printf("                                           _|`````|_|`````|_|`````|_|`````| {======|_|`````|\n");
    printf("                                           ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-`\n"); 
    delay (2); system ("cls");

    printf("                                       ___     ___   __  __    ___              ___   __   _\n");
    printf("                                      / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \n");
    printf("                                     | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V\n");
    printf("                                      \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\\n");
    printf("                                    _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````\n");
    printf("                                    ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-\n"); 
    delay (2); system ("cls");
    
    printf("                                 ___     ___   __  __    ___              ___   __   __   __\n");
    printf("                                / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /\n");
    printf("                               | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   |\n");
    printf("                                \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   \n");
    printf("                              _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|```\n");
    printf("                              ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-\n"); 
    delay (2); system ("cls");

    printf("                            ___     ___   __  __    ___              ___   __   __   ___    \n");
    printf("                           / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | _\n");
    printf("                          | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|  \n");
    printf("                           \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|\n");
    printf("                         _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|\n");
    printf("                         ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```\n"); 
    delay (2); system ("cls");

    printf("                       ___     ___   __  __    ___              ___   __   __   ___     ___ \n");
    printf("                      / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   \n");
    printf("                     | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |  \n");
    printf("                      \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_\n");
    printf("                    _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````\n");
    printf("                    ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-\n"); 
    delay (2); system ("cls");
    
    printf("                   ___     ___   __  __    ___              ___   __   __   ___     ___     \n");
    printf("                  / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \n");
    printf("                 | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /  \n");
    printf("                  \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\\n");
    printf("                _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {=\n");
    printf("                ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o\n"); 
    delay (2); system ("cls");
    
    printf("               ___     ___   __  __    ___              ___   __   __   ___     ___         \n");
    printf("              / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \\  \n");
    printf("             | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /    o \n");
    printf("              \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\   T\n");
    printf("            _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {=====\n");
    printf("            ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o--00\n"); 
    delay (2); system ("cls"); 
    
    printf("            ___     ___   __  __    ___              ___   __   __   ___     ___            \n");
    printf("           / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \\     \n");
    printf("          | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /    o    \n");
    printf("           \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\   TS__\n");
    printf("         _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {======| \n");
    printf("         ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o--000` \n"); 
    delay (2); system ("cls");
    
    printf("         ___     ___   __  __    ___              ___   __   __   ___     ___               \n");
    printf("        / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \\     o O\n");
    printf("       | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /    o       \n");
    printf("        \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\   TS__[O]\n");
    printf("      _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {======|    \n");
    printf("      ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o--000`    \n"); 
    delay (2); system ("cls");

    printf("      ___     ___   __  __    ___              ___   __   __   ___     ___                  \n");
    printf("     / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \\     o O O \n");
    printf("    | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /    o          \n");
    printf("     \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\   TS__[O]   \n");
    printf("   _|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {======|       \n");
    printf("   ``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o--000`       \n"); 
    delay (2); system ("cls");
    
    printf("   ___     ___   __  __    ___              ___   __   __   ___     ___                     \n");
    printf("  / __|   /   \\ |  \\/  |  | __|     o O O  / _ \\  \\ \\ / /  | __|   | _ \\     o O O    \n");
    printf(" | (_ |   | - | | |\\/| |  | _|     o      | (_) |  \\ V /   | _|    |   /    o             \n");
    printf("  \\___|   |_|_| |_|__|_|  |___|   TS__[O]  \\___/   _\\_/_   |___|   |_|_\\   TS__[O]      \n");
    printf("_|`````|_|`````|_|`````|_|`````| {======|_|`````|_| ````|_|`````|_|`````| {======|          \n");
    printf("``-0-0-```-0-0-```-0-0-```-0-0-`./o--000```-0-0-```-0-0-```-0-0-```-0-0-`./o--000`          \n"); 
    delay (2); system ("cls");
}
