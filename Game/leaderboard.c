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

void inputleaderboard(leaderboards l, char (*str), int scr){
    int i, temp;   
    int cek=0; //cek false
    if (l.neff==0){ //kondisi leaderboard awal kosong
        l.info[1].name=str;
        l.info[1].score=scr;
    }else if (l.neff=5){ //kondisi leaderboard penuh
        while (cek=0){
            for(i=0;i<=5;i++){ //check apakah score baru dapat menggantikan salah satu score lama
                if (l.info[i].score<scr){
                    cek=1;
                    temp=i; //menyimpan di urutan ke berapa skor baru akan diinsert
                }
            }
        }
        if (cek=1){
            while(i+1!=6){
                l.info[i+1]=l.info[i];
                i++;
            }
            l.info[temp].name=str;
            l.info[temp].score=scr;            
        }
    }else{
        for (i=(l.neff);(i>=1 && l.info[i].score>=scr); i--){
            l.info[i+1]=l.info[i];            
        }
        l.info[i+1].name=str;
        l.info[i+1].score=scr;
        l.neff+=1;
}
