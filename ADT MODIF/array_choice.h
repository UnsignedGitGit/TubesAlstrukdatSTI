#ifndef ARRAYCHOICE_H 
#define ARRAYCHOICE_H

#include "boolean.h"

typedef struct {
	piece P[17]; // Index yang digunakan [1..16]
	int neff;
} piece_choice;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrChoice (piece_choice *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel "arr" kosong dengan kapasitas 16 elemen*/

#endif
