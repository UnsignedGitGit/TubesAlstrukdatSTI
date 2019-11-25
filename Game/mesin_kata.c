#include "mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata;
Kata CKata;

//{ ***** Primitif-Primitif Mesin Kata ***** }
void Ignore_Blank() {
/*{ Mengabaikan satu atau beberapa BLANK }
{ I.S. : CC sembarang }
{ F.S. : CC != BLANK atau CC = MARK }*/
	while((CC==BLANK)&&(CC!=MARK)) {
		ADV();
	}
}

void STARTKATA(char* filename) {
/*{ I.S. : CC sembarang, filename merupakan string nama file pita kata yang akan dibaca }
{ F.S. : EndKata = true, dan CC = Mark; }
{        atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
         CC karakter pertama sesudah karakter terakhir kata }*/
START(filename);
Ignore_Blank();
	if (CC==MARK) {
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA() {
/*{ I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
         dari kata yg sudah diakuisisi }
{ F.S. : Jika CC = MARK, maka EndKata = true
         atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
         CC karakter pertama sesudah karakter terakhir kata }*/
	Ignore_Blank();
	if (CC==MARK) {
		EndKata = true;
	} else {
		SalinKata();
	}
}

void SalinKata() {
/*{ Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
         NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
         karakter sesudah karakter terakhir yang diakuisisi }*/
	/*KAMUS LOKAL*/
	int count, i;
	/*ALGORITMA*/
	count=0;
	i=1;
	while ((CC!=BLANK) && (CC!=MARK)) {
		CKata.TabKata[i] = CC;
		count+=1;
		i+=1;
		ADV();
	}
	CKata.Length = count;
}
