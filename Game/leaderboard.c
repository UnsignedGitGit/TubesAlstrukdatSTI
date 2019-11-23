//Leaderboards
#include <stdio.h>
#include "leaderboard.h"

void printleaderboard(leaderboards L);

/*
leaderboards L;
int main (){

    leaderboards hoho;
    hoho.neff=2;
    hoho.info[1].pos=1;
    hoho.info[1].name='A';
    hoho.info[1].score=100;
    hoho.info[2].pos=2;
    hoho.info[2].name='B';
    hoho.info[2].score=90;
    printleaderboard(hoho);
    return 0;
}
*/

void printleaderboard(leaderboards L){

    printf("===================================== \n");
    printf("         CURRENT LEADERBOARDS         \n");
    printf("===================================== \n");
    printf("  No. | Name           | Score       \n");
    printf("-------------------------------------\n");
    if (L.neff==0){  // kalau kosong ini yang di print
        printf("          LEADERBOARD EMPTY          \n");
        printf(" ------------------------------------\n");
    }else{
        for (int i=1;i<=L.neff;i++){
        printf("  %d   | %c              | %d        \n",
            L.info[i].pos, L.info[i].name, L.info[i].score);
        printf("-------------------------------------\n");
        }
    }  
}
