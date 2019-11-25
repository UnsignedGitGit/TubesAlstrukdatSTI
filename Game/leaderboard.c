//Leaderboards
#include <stdio.h>
#include <stdlib.h>
#include "leaderboard.h"
#include "string.h"


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
            i, l.info[i].name, l.info[i].score);
        printf("-------------------------------------\n");
        }
    }  
}

void UpdateLB(leaderboards *l, int * score1, int* score2, char * name1, char * name2){
    if ((*l).neff == 0){
        if((*score1) > (*score2)){
            strcpy((*l).info[1].name,name1);
            (*l).info[1].score = (*score1);
            strcpy((*l).info[2].name,name2);
            (*l).info[2].score = (*score2);
            (*l).neff = 2;
        }
        else if ((*score2) > (*score1)){
            strcpy((*l).info[1].name,name2);
            (*l).info[1].score = (*score2);
            strcpy((*l).info[2].name,name1);
            (*l).info[2].score = (*score1);
            (*l).neff = 2;
        }
    }
    else{
        int i = 1;
                
    }
}
