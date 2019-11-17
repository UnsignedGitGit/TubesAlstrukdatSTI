#include <stdlib.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArraySpecMove (TabChar* Tab, int maxel)
/* I.S. Tab sembarang , maxel >= 0
/* F.S. Terbentuk tabel Tab kosong dengan kapasitas maxel+1 */
{
	/*ALGORITMA*/
	(*Tab).T = (char*) malloc ((maxel+1) * sizeof(char));

	if ((*Tab).T == NULL) {
		return(NULL);
		(*Tab).MaxEl = 0;
	} else {
		(*Tab).MaxEl = maxel;
	}
	(*Tab).Neff = 0;
}

void DealokasiArray (TabChar* Tab)
/* I.S. Tab terdefinisi 
 * F.S. TI(Tab) dikembalikan ke system, MaxEl (Tab)=0; Neff(Tab)=0 */
{
	/*ALGORITMA*/
	free((*Tab).T);
	(*Tab).Neff = 0;
	(*Tab).MaxEl = 0;
}

void MakeEmptyArrChoice (piece_choice *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/*KAMUS*/
	/*ALGORITMA*/
	(*T).neff = 0;
}

void MakeEmptyArrPMove (arr_possible_move *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/*KAMUS*/
	/*ALGORITMA*/
	(*T).neff = 0;
}