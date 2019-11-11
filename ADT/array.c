#include <stdlib.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/*KAMUS*/
	/*ALGORITMA*/
	(*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
	/*KAMUS*/
	int i;
	/*ALGORITMA*/
	for (i=0;i<=99;i++) {
		(*Tout).TI[i] = Tin.TI[i]; 
	}
	(*Tout).Neff = Tin.Neff;
}
void SetEl (TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
	(*T).TI[i] = v;
}

void SetNeff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return((i>=IdxMin)&&(i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	if (T.Neff == 0)
		return false;
	else
		return ((i>=IdxMin)&&(i<=T.Neff));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return(T.Neff==0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/*KAMUS*/
	/*ALGORITMA*/
	return(T.Neff==IdxMax);
}
