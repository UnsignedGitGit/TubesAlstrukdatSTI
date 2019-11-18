#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

typedef struct {
	int x;
	int y;
} Linfotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist { 
	Linfotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = NULL */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)= NULL */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address AlokasiElmtList (Linfotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)= X, Next(P)= NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void DealokasiElmtList (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast (List *L, Linfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVLast (List *L, Linfotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

void DelVFirst (List *L, Linfotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
int NbElmtList (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

DelList(List* L)
/* I.S. List mungkin kosong */
/* F.S. Semua elemen L di-dealokasi */


#endif
