//Leaderboards
#include <stdio.h>
#include <stdlib.h>
#include "leaderboard.h"
#include <string.h>


void printleaderboard(leaderboards l){
// I.S. leaderboard sudah terdefinisi
// F.S. Leaderboard yang sudah ada akan di print
    printf("===================================== \n");
    printf("         CURRENT LEADERBOARDS         \n");
    printf("===================================== \n");
    printf("  No. | Name            | Score       \n");
    printf("-------------------------------------\n");
    if (l.neff==0){  // kalau kosong ini yang di print
        printf("          LEADERBOARD EMPTY          \n");
        printf(" ------------------------------------\n");
    }else{
        for (int i=1;i<=l.neff;i++){
        printf("  %d   | %s              | %d        \n",
            i, l.info[i].name, l.info[i].score);
        printf("-------------------------------------\n");
        }
    }  
}

void inputleaderboard(leaderboards* l, char *str, int scr){
// I.S leaderboard sudah terdefinisi, str sebagai nama input dan scr 
// F.S input skor dan nama akan masuk dengan terurut, apabila skor input tidak mencapai leaderboard, maka masukan tidak akan ditambahkan ke leaderboard. 
    int i, temp;   
    int cek=0; //cek false
    if ((*l).neff==0){ //kondisi leaderboard awal kosong
        strcpy((*l).info[1].name,str);
        (*l).info[1].score = scr;
        (*l).neff=1;
    }else if ((*l).neff==5){ //kondisi leaderboard penuh
        while (cek=0){
            for(i=0;i<=5;i++){ //check apakah score baru dapat menggantikan salah satu score lama
                if ((*l).info[i].score<scr){
                    cek=1;
                    temp=i; //menyimpan di urutan ke berapa skor baru akan diinsert
                }
            }
        }
        if (cek=1){
            while(i+1!=6){
                (*l).info[i+1]=(*l).info[i];
                i++;
            }
            strcpy((*l).info[temp].name,str);
            (*l).info[temp].score=scr;            
        }
    }else{
        for (i=((*l).neff);(i>=1 && (*l).info[i].score>=scr); i--){
            (*l).info[i+1]=(*l).info[i];            
        }
        strcpy((*l).info[i+1].name,str);
        (*l).info[i+1].score=scr;
        (*l).neff+=1;
    }
}
void createemptyLB(leaderboards *LB){
// I.S sembarang
// F.S akan dibuat sebuah leaderboard dengan neff = 0
    (*LB).neff = 0;
}
