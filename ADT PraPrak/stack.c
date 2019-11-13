#include "stack.h"
#include "boolean.h"

void CreateEmpty (Stack *S) {
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
	/* Kamus Lokal */
	/* Algoritma */
	(*S).TOP = Nil;
}

boolean IsEmpty (Stack S) {
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
	/* Kamus Lokal */
	/* Algoritma */
	return (S.TOP==Nil);
}
boolean IsFull(Stack S) {
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
	/* Kamus Lokal */
	/* Algoritma */
	return(S.TOP==MaxEl);
}
void Push (Stack *S, infotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
	/* Kamus Lokal */
	/* Algoritma */
	(*S).TOP++;
	(*S).T[(*S).TOP-1].turn = X.turn;		//ED
	(*S).T[(*S).TOP-1].type = X.type;
	(*S).T[(*S).TOP-1].x0 = X.x0;
	(*S).T[(*S).TOP-1].y0 = X.y0;
	(*S).T[(*S).TOP-1].xt = X.xt;
	(*S).T[(*S).TOP-1].yt = X.yt;
	(*S).T[(*S).TOP-1].targettype = X.targettype;
	(*S).T[(*S).TOP-1].IsCastling = X.IsCastling;		//
}
void Pop (Stack *S, infotype *X) {
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	/* Kamus Lokal */
	/* Algoritma */
	(*X).turn = (*S).T[(*S).TOP-1].turn;		//ED
	(*X).type = (*S).T[(*S).TOP-1].type;
	(*X).x0 = (*S).T[(*S).TOP-1].x0;
	(*X).y0 = (*S).T[(*S).TOP-1].y0;
	(*X).xt = (*S).T[(*S).TOP-1].xt;
	(*X).yt = (*S).T[(*S).TOP-1].yt;
	(*X).targettype = (*S).T[(*S).TOP-1].targettype;
	(*X).IsCastling = (*S).T[(*S).TOP-1].IsCastling;		//
	(*S).TOP--;
}
