//leaderboard.h

#ifndef leaderboart_H
#define leaderboart_H

#include<stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
<<<<<<< HEAD
    // int pos;       urutan gaperlu rasanya
=======
>>>>>>> ac77d15a1a52cf70c946c29ab2375225deaa09a5
    char name[4];   //nama
    int score;      //score
}leaderboard;

typedef struct{
    int neff;       //t.neff -> kalau t.neff nya 0 biar ditampilin tulisan LEADERBOARD KOSONG
    leaderboard info[6]; //isinya info dari leaderboard
}leaderboards; //ini array of leaderboard

//wacana pake priolist aja biar masukinnya urut

void printleaderboard(leaderboards l);
void inputleaderboard(leaderboards l, char (*str), int scr);



void createemptyLB(leaderboards * LB);

#endif
