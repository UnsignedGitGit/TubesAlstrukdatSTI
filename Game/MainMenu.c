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
system("clear");    
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
    system("cls");
system("clear"); */
    
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
system("clear");
        play(S);
    }else if (pil=='L'){
        load(g, S);
        //jalankan fungsi load
    }else if (pil=='B'){
        //jalankan fungsi print leaderboard
        system("cls");
system("clear");
        //printleaderboard();
    }else if (pil=='E'){
            *g = true;
            eksit();
    }
    else {
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

    /*ALGORITMA*/
    
    /*INISIALISASI*/
    CreateBoard(&B);
	
    MakeEmptyArrPMove(&black);
    
    for (i=1; i<= 8; i++) {
        black.arr[i].p = BoardCell(B)[i][8];
        CreateEmptyList(&black.arr[i].possmove);
    }
    
    for (i=9; i<= 16; i++) {
        black.arr[i].p = BoardCell(B)[i-8][7];
        CreateEmptyList(&black.arr[i].possmove);
    }
    
    MakeEmptyArrPMove(&white);
    for (i=1; i<= 8; i++) {
        white.arr[i].p = BoardCell(B)[i][1];
        CreateEmptyList(&white.arr[i].possmove);
    }
    for (i=9; i<= 16; i++) {
        white.arr[i].p = BoardCell(B)[i-8][2];
        CreateEmptyList(&white.arr[i].possmove);
    }

	init_turn(*S, &turn);
    
    /*PERMAINAN DIMULAI*/	
	turncounter = 1;
    while (turncounter <= 100) {
        BoardPrintInfo(B);

        currentteam = get_turn(&turn);
        i = 1;

        /*Cek skakmat*/
        if (currentteam == 'W') {
            while (white.arr[i].p.type != 'K') {
                i++;
            }

            if (isCheckmate(B, white.arr[i].p.xpos, white.arr[i].p.ypos, currentteam)) {
                break;
            }
        } else {
            while (black.arr[i].p.type != 'k') {
                i++;
            }

            if (isCheckmate(B, black.arr[i].p.xpos, black.arr[i].p.ypos, currentteam)) {
                break;
            }
        }

        printf("Masukkan command: ");
        scanf("%s", str);

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

        if (currentteam == 'W') {
            if (strcmp(str, "MOVE") == 0) {

                move(S, currentteam, &white, &black, &B);
                turncounter++;

            } else if (strcmp(str, "SPECIAL_MOVE") == 0) {

                special_move(&white, &black, &B, S, currentteam);
                turncounter++;

            } else if (strcmp(str, "UNDO") == 0) {

                Undo(&white, &black, S, &B);
                turncounter = turncounter - 2;
                currentteam = get_turn(&turn); /*Agar saat masuk ke loop, turn tetap tim W*/
            }
        } else {
            if (strcmp(str, "MOVE") == 0) {

                move(S, currentteam, &black, &white, &B);
                turncounter++;

            } else if (strcmp(str, "SPECIAL_MOVE") == 0) {

                special_move(&white, &black, &B, S, currentteam);
                turncounter++;

            } else if (strcmp(str, "UNDO") == 0) {

                Undo(&white, &black, S, &B);
                turncounter = turncounter - 2;
                currentteam = get_turn(&turn); /*Agar saat masuk ke loop, turn tetap tim B*/
            }
        }
    }
    printf("Game telah berakhir.\n");
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
system("clear");
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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");
    

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
    delay(2); system("cls");
system("clear");
    
    
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
    delay(2); system("cls");
system("clear");
    

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
    delay(2); system("cls");
system("clear");
    

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
    delay(2); system("cls");
system("clear");
    

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
    delay(2); system("cls");
system("clear");
    

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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");
    
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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");

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
    delay(2); system("cls");
system("clear");
     
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
    delay(8); system("cls");
system("clear");
}
