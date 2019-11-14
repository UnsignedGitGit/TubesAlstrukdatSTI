#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (List L) {
/* Mengirim true jika list kosong */
	/*ALGORITMA*/
	return (First(L) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	/*ALGORITMA*/
	First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
address AlokasiElmtList (Linfotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

	/*KAMUS*/
	address P;
	
	/*ALGORITMA*/
	P = (ElmtList*) malloc (sizeof(ElmtList));
	if (P == NULL) {
		return(NULL);
	} else {
		Info(P).x = X.x;
		Info(P).y = X.y;
		Next(P) = NULL;
		return(P);
	}
}

void DealokasiElmtList (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
	/*ALGORITMA*/
	free(*P);
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast (List *L, Linfotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	/*KAMUS*/
	address Last;
	address P;
	
	/*ALGORITMA*/
	P = AlokasiElmtList(X);
	
	if (P != NULL) {
		if (IsListEmpty(*L)) {
			Next(P) = First(*L);
			First(*L) = P;
		} else {
			Last = First(*L);
			while (Next(Last) != NULL) {
				Last = Next(Last);
			}
			Next(P) = Next(Last);
			Next(Last) = P;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVLast (List *L, Linfotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
	/*KAMUS*/
	address Last, PrecLast;
	
	/*ALGORITMA*/
	Last = First(*L);
	PrecLast = NULL;
	while (Next(Last) != NULL) {
		PrecLast = Last;
		Last = Next(Last);
	}
	
	(*X) = Info(Last);
	
	if (PrecLast == NULL) {
		First(*L) = NULL;
	} else {
		Next(PrecLast) = NULL;
	}
	
	DealokasiElmtList(&Last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmtList (List L) {
/* Mengirimkan banyaknya elemen list ; mengirimkan 0 jika list kosong */
	/*KAMUS*/
	int count = 0;
	address P;
	
	/*ALGORITMA*/
	if (First(L) == NULL) {
		return 0;
	} else {
		P = First(L);
		do {
			count++;
			P = Next(P);
		} while (P != NULL);
		return count;
	}
}
