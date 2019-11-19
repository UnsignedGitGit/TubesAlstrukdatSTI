/* MODUL TABEL KARAKTER */
/* Penempatan elemen selalu rapat kiri */

#ifndef ARRAY_H 
#define ARRAY_H

#include "boolean.h"
#include "piece.h"
#include "listlinier.h"

typedef struct {
	char* T;  /* Index yang digunakan [1..4] */
	int Neff;
	int MaxEl;
} TabChar;

typedef struct {
	piece arrpiece[17]; // Index yang digunakan [1..16]
	int neff;
} piece_choice;

typedef struct {
	piece* p;
	List possmove;
} elmt_arrpossmove;

typedef struct {
	elmt_arrpossmove arr[17]; /*Index yang digunakan [1..16]*/
	int neff;
} arr_possible_move;

/* ********** KONSTRUKTOR ********** */
void MakeEmptyArraySpecMove (TabChar* T, int maxel);
/* I.S. T sembarang , maxel >= 0
 * F.S. Terbentuk tabel T kosong dengan kapasitas maxel+1 */

void DealokasiArray (TabChar* T);
/* I.S. T terdefinisi 
 * F.S. TI(T) dikembalikan ke system, MaxEl (T)=0; Neff(T)=0 */

void MakeEmptyArrChoice (piece_choice *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel "arr" kosong dengan kapasitas 16 elemen*/

void MakeEmptyArrPMove (arr_possible_move *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel "arr" kosong dengan kapasitas 16 elemen*/

#endif
