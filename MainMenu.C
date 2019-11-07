#include<stdio.h>

void readmain();

int main(){

    printf("##################################################################\n\n");
    printf("       _________ __     __ ________  ________ ________    __      \n");
    printf("      /   ______|  |   |  |  ______|/  ______/  ______|  |  |     \n");
    printf("      |  |      |  |___|  |  |__   |  (_____ |  (_____   |  |     \n");
    printf("      |  |      |   ___   |   __|   \\_____   \\______  \\  |__| \n");  
    printf("      |  |______|  |   |  |  |_____  _____)  | _____)  |  __      \n");
    printf("      \\_________|__|   |__|________|/________/________/  |__|   \n\n");
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
    printf("%d", pil);
    if (&pil=="N"){
        printf ("Loading...");
    }else if (&pil=="L"){
        printf("Input your file name: ");
    }else if (&pil=="B"){
        printf("Leaderboards Empty");
    }else if (&pil=="E"){
        printf("Exiting...");
    }
    else{
        printf("Please input the correct command.\n");
        readmain();
    }         
}