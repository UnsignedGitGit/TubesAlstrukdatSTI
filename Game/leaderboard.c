//Leaderboards
#include <stdio.h>
#include "leaderboard.h"



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

void printleaderboard(leaderboards l){

    printf("===================================== \n");
    printf("         CURRENT LEADERBOARDS         \n");
    printf("===================================== \n");
    printf("  No. | Name           | Score       \n");
    printf("-------------------------------------\n");
    if (l.neff==0){  // kalau kosong ini yang di print
        printf("          LEADERBOARD EMPTY          \n");
        printf(" ------------------------------------\n");
    }else{
        for (int i=1;i<=l.neff;i++){
        printf("  %d   | %c              | %d        \n",
            l.info[i].pos, l.info[i].name, l.info[i].score);
        printf("-------------------------------------\n");
        }
    }  
}
