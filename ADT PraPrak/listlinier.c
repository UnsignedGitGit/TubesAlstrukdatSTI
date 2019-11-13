#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
	return (First(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	address P;
	
	P = (ElmtList*) malloc (sizeof(ElmtList));
	if (P == NULL) {
		return(Nil);
	} else {
		Info(P).x = X.x;		//ED
		Info(P).y = X.y;		//
		Next(P) = Nil;
		return(P);
	}
}

void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

	free(*P);
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	address Last;
	address P;
	
	P = Alokasi(X);
	
	if (P != Nil) {
		if (IsEmpty(*L)) {
			Next(P) = First(*L);
			First(*L) = P;
		} else {
			Last = First(*L);
			while (Next(Last) != Nil) {
				Last = Next(Last);
			}
			Next(P) = Next(Last);
			Next(Last) = P;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVLast (List *L, infotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

	address Last, PrecLast;
	
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != Nil) {
		PrecLast = Last;
		Last = Next(Last);
	}
	
	(*X) = Info(Last);
	
	if (PrecLast == Nil) {
		First(*L) = Nil;
	} else {
		Next(PrecLast) = Nil;
	}
	
	Dealokasi(&Last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmt (List L) {
/* Mengirimkan banyaknya elemen list ; mengirimkan 0 jika list kosong */
		int count = 0;
		address P;
		
		if (First(L) == Nil) {
			return 0;
		} else {
			P = First(L);
			do {
				count++;
				P = Next(P);
			} while (P != Nil);
			return count;
		}
}
