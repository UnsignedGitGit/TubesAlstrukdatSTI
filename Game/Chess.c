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

// PROTOTIPE
void welcome(); 
//Animasi singkat saat pemain pertama menjalankan program

void mainscreen();
//UI untuk bagian main menu

void readmain(boolean* g, Stack *S, int* scorewhite, int* scoreblack, char *team1, char *team2, leaderboards *LB);
//Input user memilih new game, load game, leaderboard, atau exit
// I.S. g, S, scorewhite, scoreblack, team1, team2, LB terdefinisi. Stack S bisa kosong
// F.S. Operasi menampilkan leaderboard, masuk ke game, keluar program dijalankan sesuai masukan pemain

void delay(int number_of_seconds);

void play(Stack* S, boolean* checkmate);
//Menjalankan game
// I.S. S terdefinisi dan kosong. Checkmate terdefinisi.
// F.S. Jika game berakhir dengan skakmat, checkmate diset menjadi true. Stack terisi.
 
void countscore(Stack S, int* scorewhite, int* scoreblack, boolean checkmate);
//Mengitung skor pemain
// I.S. S dan checkmate terdefinisi. scorewhite dan scoreblack sembarang
// F.S. scorewhite dan scoreblack terisi dengan skor masing-masing pemain

void gamelog(int tc, char ct);
//(tc untuk turncounter, ct untuk current team.)
//Menampilkan kondisi game sekarang (tim yang sedang mendapat giliran dan turn ke-berapa) 

void gameover();
//Animasi saat game selesai (ditampilkan saat tepat akan kembali ke main menu)

void eksit();
//Animasi saat pemain keluar dari game


int main(){
    //KAMUS
    boolean gameover = false;
    Stack movehistory;
    int whitescore = 0;
    int blackscore = 0;
    char player1[4];
    char player2[4];

    leaderboards LB;
    createdefault(&LB);

    //ALGORITMA
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
        readmain(&gameover, &movehistory, &whitescore, &blackscore, player1, player2, &LB);
    }
    
    return 0;
}


// IMPLEMENTASI
void readmain(boolean* g, Stack* S, int* scorewhite, int* scoreblack, char * team1, char *team2, leaderboards *LB) {
//Input user memilih new game, load game, leaderboard, atau exit
// I.S. g, S, scorewhite, scoreblack, team1, team2, LB terdefinisi. Stack S bisa kosong
// F.S. Operasi menampilkan leaderboard, masuk ke game, keluar program dijalankan sesuai masukan pemain

    //KAMUS
    char pil;
    boolean lastgame_checkmate = false;
    int correct = 0; // untuk cek apakah inputan sudah benar

    //ALGORITMA
    printf("Enter your command: ");
    scanf("%c", &pil);
    
    while (correct==0){
        if (pil=='N' || pil=='L' || pil=='B' || pil=='E' ){
            correct=1;
        } else{
            printf("Please input the correct command. (N/L/B/E)");
            printf("Enter your command: ");
            scanf("%c", &pil);
        }
    }

    if (pil=='N'){   
        printf("Player 1 (White Team) name: \n");
        scanf("%s", team1);
        
        printf("Player 2 (Black Team) name: \n");
        scanf("%s", team2);
        
        system("cls");
        play(S, &lastgame_checkmate);        
        countscore(*S, scorewhite, scoreblack, lastgame_checkmate);
        printf("Nama Player 1: %s - Skor: %d\n",team1,(*scorewhite));
        printf("Nama player 2: %s - Skor: %d\n",team2, (*scoreblack));

        if((*scorewhite) != (*scoreblack)){
        inputleaderboard(LB, team1, (*scorewhite));
        inputleaderboard(LB, team2, (*scoreblack));
        }
        printleaderboard(*LB);

    } else if(pil=='L'){
        printf("Sorry, load function is not available yet...\n");
        delay(10);
        system("cls");
    } else if (pil=='B'){       
        system("cls");        
        printleaderboard((*LB));

    } else if (pil=='E'){
        *g = true;
        eksit();
    }
}

void play(Stack* S, boolean* checkmate) {
//Menjalankan game
// I.S. S terdefinisi dan kosong. Checkmate terdefinisi.
// F.S. Jika game berakhir dengan skakmat, checkmate diset menjadi true. Stack terisi.

    //KAMUS
    board B;
    arr_possible_move black, white;
    int i, turncounter;
    Queue turn;
    char currentteam;
    char str[20];
    boolean donemove;

    //ALGORITMA
    

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
        currentteam = get_turn(&turn);
        
        gamelog(turncounter, currentteam);
        BoardPrintInfo(B);

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
                    *checkmate = true;
                    break;
                }
            } else {
                while (black.arr[i].p.type != 'k') {
                    i++;
                }
                if (isCheckmate(B, black.arr[i].p.xpos, black.arr[i].p.ypos, currentteam, black)) {
                    *checkmate = true;
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

void countscore(Stack S, int* scorewhite, int* scoreblack, boolean checkmate) {
//Mengitung skor pemain
// I.S. S dan checkmate terdefinisi. scorewhite dan scoreblack sembarang
// F.S. scorewhite dan scoreblack terisi dengan skor masing-masing pemain

    //KAMUS
    int dummy;
    Sinfotype x;

    //ALGORITMA
    if (checkmate){	
        dummy = 20;
        Pop(&S, &x);
        if (x.turn == 'W') {
           (*scorewhite) += dummy;
        } else {
            (*scorewhite) += dummy;
        }
    } 
    
    while (!IsStackEmpty(S)) {
        Pop(&S, &x);
        if (x.turn == 'W') {
            if(x.targettype =='p'){
                (*scorewhite) += 1;
            }
            else if(x.targettype =='h'){
                (*scorewhite) += 2;
            }
            else if(x.targettype =='r'){
                (*scorewhite) += 4;
            }
            else if(x.targettype =='b'){
                (*scorewhite) += 4;
            }
            else if(x.targettype =='q'){
                (*scorewhite) += 8;
            }
            else if(x.targettype =='k'){
                (*scorewhite) += 10;
            }
            
        } else if(x.turn == 'B') {
            if(x.targettype =='P'){
                (*scoreblack) += 1;
            }
            else if(x.targettype =='H'){
                (*scoreblack) += 2;
            }
            else if(x.targettype =='R'){
                (*scoreblack) += 4;
            }
            else if(x.targettype =='B'){
                (*scoreblack) += 4;
            }
            else if(x.targettype =='Q'){
                (*scoreblack) += 8;
            }
            else if(x.targettype =='K'){
                (*scoreblack) += 10;
            }
        }
    }
    
}

void delay(int number_of_seconds){ 

    //ALGORITMA
    // Converting time into milli_seconds 
    int milli_seconds = 100 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void welcome(){
//Animasi singkat saat pemain pertama menjalankan program

    //ALGORITMA
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
//UI untuk bagian main menu

    //ALGORITMA
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

void gamelog(int tc, char ct){
//Menampilkan kondisi game sekarang (tim yang sedang mendapat giliran dan turn ke-berapa)

    //ALGORITMA
    if (ct=='W'){
        printf("     =================================================================\n");
        printf("               WHITE TEAM'S TURN                PLY : %d / 100        \n",tc);
        printf("     =================================================================\n");
    }else{
        printf("     =================================================================\n");
        printf("               BLACK TEAM'S TURN                PLY : %d / 100        \n",tc);
        printf("     =================================================================\n");
    }
}

void eksit(){
//Animasi saat pemain keluar dari game
    
    //ALGORITMA
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
//Animasi saat game selesai (ditampilkan saat tepat akan kembali ke main menu)
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
