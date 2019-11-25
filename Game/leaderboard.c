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
    hoho.info[1].name='A';
    hoho.info[1].score=100;
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
<<<<<<< HEAD
                i, l.info[i].name, l.info[i].score);
=======
            i, l.info[i].name, l.info[i].score);
>>>>>>> ac77d15a1a52cf70c946c29ab2375225deaa09a5
        printf("-------------------------------------\n");
        }
    }  
}

<<<<<<< HEAD
void inputleaderboard(leaderboards l, char (*str), int scr){
    if (l.neff==0){ //kondisi leaderboard awal kosong
        l.info[1].name=str;
        l.info[1].score=scr;
    }else{
        int i;
        for (int i=(l.neff);(i>=1 && l.info[i].score>=scr); i--){
            l.info[i+1]=l.info[i];            
        }
        l.info[i+1].name=str;
        l.info[i+1].score=scr;
}

  //ide : 
        // jika leaderboads.neff == 0 (belum ada isinya)
        // maka : 
        //     jika putih menang :
        //         isi leaderboards.info[1].name dgn nama player 1/tim putih
        //         isi leaderboards.info[1].score dgn scorenya
        //     else:
        //         isi leaderboards.info[1].name dgn nama player 2/tim putih
        //         isi leaderboards.info[1].score dgn scorenya
        // else:
        //     iterasi dari leaderboards.neff - 1:
        //         jika score> leaderboards.info[i].score maka:
        //             geser leaderboards.info tsb beserta skor2 dibawahnya sbnyk 1
        //             masukan leaderboards.info baru yang berisi skor yg lebih tinggi.
=======
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
>>>>>>> ac77d15a1a52cf70c946c29ab2375225deaa09a5
