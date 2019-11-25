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
    }
    else if ((*l).neff == 5){ //saat array terisi penuh, dan sudah terurut
        int minimum;
        minimum = (*l).info[5].score;

        // Apabila skor masukan lebih dar atau sama dengan skor minimum dari top skor, skor minimum top skor akan dipisah
        if (scr >= minimum){
            (*l).info[5].score = scr;
            strcpy((*l).info[5].name,str);
            sortLB(l);
        }

    }
    // }else if ((*l).neff==5){ //kondisi leaderboard penuh
    //     while (cek=0){
    //         for(i=1;i<=5;i++){ //check apakah score baru dapat menggantikan salah satu score lama
    //             if ((*l).info[i].score<scr){
    //                 cek=1;
    //                 temp=i; //menyimpan di urutan ke berapa skor baru akan diinsert
    //             }
    //         }
    //     }
    //     if (cek=1){
    //         while(i+1!=6){
    //             (*l).info[i+1]=(*l).info[i];
    //             i++;
    //         }
    //         strcpy((*l).info[temp].name,str);
    //         (*l).info[temp].score=scr;            
    //     }
    /* }else{
        for (i=((*l).neff);(i>=1 && (*l).info[i].score>=scr); i--){
            (*l).info[i+1]=(*l).info[i];            
        }
        strcpy((*l).info[i+1].name,str);
        (*l).info[i+1].score=scr;
        (*l).neff+=1;
    } */
}
void createdefault(leaderboards *LB){
    // I.S sudah di deklarasi
    // F.S leaderboard diisi dengan nilai default leaderboard (data dummy)
    
    (*LB).neff = 5;
    int j;

    for(j=1;j<(*LB).neff + 1; j++){
        strcpy((*LB).info[j].name,"AAA");
        (*LB).info[j].score = 0;
    }
}

void sortLB(leaderboards * LB){

    // Prosedur ini akan melakukan sorting pada array leaderboard menurun berdasarkan skor
    // Algoritma sorting yang dipilih adalah bubble sort
    leaderboard dummy;
    int i, j; 
    for (i = 0; i < 5 ; i++){           
       for (j = 1; j < 6 - i - 1; j++){  
           if ((*LB).info[j].score < (*LB).info[j+1].score){

              strcpy(dummy.name,(*LB).info[j].name);
              dummy.score = (*LB).info[j].score;

              strcpy((*LB).info[j].name,(*LB).info[j+1].name);
              (*LB).info[j].score = (*LB).info[j+1].score;

              strcpy((*LB).info[j+1].name,dummy.name);
              (*LB).info[j+1].score = dummy.score; 
           }   
       }
    
   }

}
