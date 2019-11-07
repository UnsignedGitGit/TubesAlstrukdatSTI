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
		Info(P) = X;
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
	address P;
	if (First(L) == Nil) {
		return(Nil);
	} else {
		P = First(L);
		while ((Next(P) != Nil) && (X != Info(P))) {
			P = Next(P);
		}
		if (X == Info(P)) {
			return(P);
		} else {
			return(Nil);
		}
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	address P;
	P = Alokasi(X);
	if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P;
	}
}

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
			InsVFirst(L, X);
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
void DelVFirst (List *L, infotype *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
	address P;
	
	P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	
	(*X) = Info(P);
	Dealokasi(&P);
}

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

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	address Last;
	
	if (IsEmpty(*L)) {
		InsertFirst(L, P);
	} else {
		Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfter(L, P, Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	(*P) = First(*L);
	First(*L) = Next(First(*L));
	Next((*P)) = Nil;
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	address P, Prec, S;
	
	if (Search(*L, X) != Nil) {
		P = Search(*L, X);
		if (P == First(*L)) {
			DelFirst(L, &S);
		} else {
			Prec = First(*L);
			while (Next(Prec) != P) {
				Prec = Next(Prec);
			}
			DelAfter(L, &S, Prec);
		}
		Dealokasi(&S);
	}
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
	address Last, PrecLast;
	
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != Nil) {
		PrecLast = Last;
		Last = Next(Last);
	}
	
	(*P) = Last;
	
	if (PrecLast == Nil) {
		First(*L) = Nil;	
	} else {
		Next(PrecLast) = Nil;
	}
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	(*Pdel) = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next((*Pdel)) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	address P;
	
	if (IsEmpty(L)) {
		printf("[]");
	} else {
		P = First(L);
		
		printf("[%d", Info(P));
		while (Next(P) != Nil) {
			P = Next(P);
			printf(",%d", Info(P));
		}
		printf("]");
	}
}

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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
/* Mengirimkan nilai Info(P) yang maksimum */
	int cmax;
	address P;
	
	cmax = Info(First(L));
	P = Next(First(L));
	
	while(P != Nil) {
		if (Info(P) > cmax) {
			cmax = Info(P);
		}
		P = Next(P);
	}
	return cmax;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
	address Last1;
	
	CreateEmpty(L3);
	if (IsEmpty(*L1)) {
		First(*L3) = First(*L2);
		CreateEmpty(L2);
	} else {
		First(*L3) = First(*L1);
		
		Last1 =  First(*L1);
		while (Next(Last1) != Nil) {
			Last1 = Next(Last1);
		}
		Next(Last1) = First(*L2);
		
		CreateEmpty(L1);
		CreateEmpty(L2);
	}
	

}
