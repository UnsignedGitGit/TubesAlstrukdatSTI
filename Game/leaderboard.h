//leaderboard.h

#ifndef leaderboart_H
#define leaderboart_H

#include<stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
    int pos;
    char name[4];   //nama
    int score;      //score
}leaderboard;

typedef struct{
    int neff;       //t.neff -> kalau t.neff nya 0 biar ditampilin tulisan LEADERBOARD KOSONG
    leaderboard info[6]; //isinya info dari leaderboard
}leaderboards; //ini array of leaderboard

//wacana pake priolist aja biar masukinnya urut

void printleaderboard(leaderboards l);

void UpdateLB(leaderboards *l, int * score1, int* score2, char * name1, char * name2);

#endif