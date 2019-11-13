#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include "ADT/board.h"

void readmain();
void delay(int number_of_seconds); 
void initiate();

int main(){
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
void readmain(){
    char pil;
    printf("Enter your command: ");
    scanf("%c", &pil);
    if (pil=='N'){
        for(int i=1;i<=3;i++){
            delay (7);
            system("cls");
            printf ("Loading.");
            delay (5);
            system("cls");
            printf ("Loading..");
            delay(5);
            system("cls");
            printf ("Loading...");
        }
    delay (10);
    system("cls");
    initiate();    
    }else if (pil=='L'){
        printf("Input your file name: ");
    }else if (pil=='B'){
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