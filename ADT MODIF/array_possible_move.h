#ifndef ARRAYPOSMO_H 
#define ARRAYPOSMO_H

#include "boolean.h"
#include "listlinier.h"
#include "piece.h"

typedef struct {
	piece* p;
	List possmove;
} elmt_arrpossmove;

typedef struct {
	elmt_arrpossmove arr[17]; /*Index yang digunakan [1..16]*/
	int neff;
} arr_possible_move;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrPMove (arr_possible_move *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel "arr" kosong dengan kapasitas 16 elemen*/

#endif
