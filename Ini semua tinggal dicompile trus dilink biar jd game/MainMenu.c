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


int main(){
    /*KAMUS*/
    boolean gameover = false;
    Stack movehistory;

    /*ALGORITMA*/
    welcome();
        delay (7);
        printf ("Loading");
        delay (5);
        printf (".");
        delay (5);
        printf (".");
        delay(5);
        printf (".");
        delay (10);
        system("cls");    
    welcome();
        printf("Loading complete. Press enter to continue. \n");
        getchar();
    system("cls");   

    while (!gameover) {
        mainscreen();
        readmain(&gameover, &movehistory);
    }
    
    return 0;
}

void welcome(){
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

void readmain(boolean* g, Stack* S) {
    /*KAMUS*/
    char pil;

    /*ALGORITMA*/
    printf("Enter your command: ");
    scanf("%c", &pil);
    if (pil=='N'){
        system("cls");
        play(S);
    }else if (pil=='L'){
        load();
        //jalankan fungsi load
    }else if (pil=='B'){
        //jalankan fungsi print leaderboard
        system("cls");
        //printleaderboard();
    }else if (pil=='E'){
            delay (8);
            system("cls");
            printf ("Exiting");
            delay (7);
            system("cls");
            printf ("Exiting.");
            delay (6);
            system("cls");
            printf ("Exiting..");
            delay(10);
            system("cls");
            printf ("Bye!");
            delay(8);
            system("cls");

            *g = true;
    }
    else {
        printf("Please input the correct command.\n");
        readmain(g, S);
    }         
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 100 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
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
    for (i=1; i<= 8; i++) {
         black.arr[i].p = BoardCell(B)[i][7];
        CreateEmptyList(&black.arr[i].possmove);
    }
    
    MakeEmptyArrPMove(&white);
    for (i=1; i<= 8; i++) {
        white.arr[i].p = BoardCell(B)[i][1];
        CreateEmptyList(&white.arr[i].possmove);
    }
    for (i=1; i<= 8; i++) {
        white.arr[i].p = BoardCell(B)[i][2];
        CreateEmptyList(&white.arr[i].possmove);
    }

    init_turn(*S, &turn);

    /*PERMAINAN DIMULAI*/
    BoardPrintInfo(B);

    for (turncounter=1; turncounter<=100; i++) {
        printf("Masukkan command: ");
        scanf("%s", str);

        currentteam = get_turn(&turn);

        if (currentteam == 'W') {
            if (strcmp(str, "MOVE") == 0) {
                move(S, currentteam, &white, &B);
            } else if (strcmp(str, "SPECIAL_MOVE") == 0) {
                special_move(&B, S, currentteam);
            } else if (strcmp(str, "UNDO") == 0) {
                Undo(S);
            } else {
                printf("Command tidak dapat dilakukan.\n");
                printf("Command-command yang dapat dijalankan adalah 'MOVE', 'SPECIAL_MOVE', atau 'UNDO'.\n");
            }
        } else {
            if (strcmp(str, "MOVE") == 0) {
                move(S, currentteam, &black, &B);
            } else if (strcmp(str, "SPECIAL_MOVE") == 0) {
                special_move(&B, S, currentteam);
            } else if (strcmp(str, "UNDO") == 0) {
                Undo(S);
            } else {
                printf("Command tidak dapat dilakukan.\n");
                printf("Command-command yang dapat dijalankan adalah 'MOVE', 'SPECIAL_MOVE', atau 'UNDO'.\n");
            }
        } 
    }
    printf("Game telah berakhir.\n");
 }
