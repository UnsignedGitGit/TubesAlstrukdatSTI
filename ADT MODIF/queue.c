#include "queue.h"
#include <stdlib.h> 

/* ********* Prototype ********* */
boolean IsQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	/*KAMUS*/
	return ((Q.HEAD == Nil) && (Q.TAIL == Nil));
}

boolean IsQueueFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	/*KAMUS*/
	return (NBElmtQueue(Q) == Q.MaxEl);
}

int NBElmtQueue(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	/*KAMUS*/
	if (IsQueueEmpty(Q)) {
		return 0;
	} else {
		if (Q.TAIL > Q.HEAD) {
			return (Q.TAIL - Q.HEAD + 1);
		}
		else if (Q.TAIL < Q.HEAD) {
			return (Q.MaxEl - (Q.HEAD - Q.TAIL - 1));
		} else {
			return 1;
		}
	}
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	/*KAMUS*/
	(*Q).T = (Qinfotype *) malloc ((Max + 1) * sizeof(Qinfotype));
	if ((*Q).T == NULL) {
		(*Q).MaxEl = 0;
	} else {
		(*Q).MaxEl = Max;
		(*Q).HEAD = Nil;
		(*Q).TAIL = Nil;
	}
}

/* *** Destruktor *** */
void DeAlokasiQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	/*KAMUS*/
	free((*Q).T);
	(*Q).MaxEl = 0;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, Qinfotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	/*KAMUS*/
	if (IsQueueEmpty(*Q)) {
		(*Q).HEAD = 1;
		(*Q).TAIL = 1;
	} else if ((*Q).TAIL == (*Q).MaxEl) {
		(*Q).TAIL = 1;
	} else {
		(*Q).TAIL++;
	}
	(*Q).T[(*Q).TAIL] = X;
}

void Del (Queue * Q, Qinfotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	/*KAMUS*/
	(*X) = (*Q).T[(*Q).HEAD];
	if ((*Q).HEAD == (*Q).TAIL) {
		(*Q).HEAD = Nil;
		(*Q).TAIL = Nil;
	} else if ((*Q).HEAD == (*Q).MaxEl) {
		(*Q).HEAD = 1;
	} else {
		(*Q).HEAD++;
	}
}
