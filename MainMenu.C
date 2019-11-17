#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "ADT/board.h"

void welcome(); //animasi singkat
void plyrname(); //input nama pemain
void readmain(); //input user memilih new game, load game, leaderboard, atau exit
void delay(int number_of_seconds); 
void initiate();

int main(){
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
    
    readmain();
    
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

void readmain(){
    char pil;
    printf("Enter your command: ");
    scanf("%c", &pil);
    if (pil=='N'){
        system("cls");
        initiate();    
    }else if (pil=='L'){
        printf("Input your file name: ");
        //jalankan fungsi load
    }else if (pil=='B'){
        //jalankan fungsi print leaderboard
        printf("Leaderboards Empty");
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
    }
    else{
        printf("Please input the correct command.\n");
        readmain();
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

void initiate(){
    board B;
    CreateBoard(&B);

    BoardPrintInfo(B);
}