//leaderboard.h

#ifndef leaderboart_H
#define leaderboart_H

#include<stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
    // int pos;       urutan gaperlu rasanya
    char name[4];   //nama
    int score;      //score
}leaderboard;

typedef struct{
    int neff;       //t.neff -> kalau t.neff nya 0 biar ditampilin tulisan LEADERBOARD KOSONG
    leaderboard info[6]; //isinya info dari leaderboard
}leaderboards; //ini array of leaderboard

//wacana pake priolist aja biar masukinnya urut

void printleaderboard(leaderboards l);
// I.S leaderboard terdefinisi
// Prosedur akan menampilkan leaderboard yang telah terdeklarasi di main

void inputleaderboard(leaderboards *l, char (*str), int scr);
// I.S leaderboard terdefinisi, char nama dan skor dari permain sudah terdefinisi
// F.S Data yang diinput akan dicatat ke dalam leaderboard 

void createdefault(leaderboards *LB);
// I.S sembarang
// F.S akan dibuat sebuah leaderboard dengan neff = 0

void sortLB (leaderboards * LB);
// I.S leaderboards belum terurut menurun

#endif
