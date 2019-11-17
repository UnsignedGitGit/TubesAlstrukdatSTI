#include "stack.h"
#include "boolean.h"

void CreateEmptyStack (Stack *S) {
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
	/* Kamus Lokal */
	/* Algoritma */
	(*S).TOP = Nil;
}

boolean IsStackEmpty (Stack S) {
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
	/* Kamus Lokal */
	/* Algoritma */
	return (S.TOP == Nil);
}

boolean IsStackFull(Stack S) {
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
	/* Kamus Lokal */
	/* Algoritma */
	return(S.TOP == MaxElStack);
}

void Push (Stack *S, Sinfotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
	/* Kamus Lokal */
	/* Algoritma */
	(*S).TOP++;
	(*S).T[(*S).TOP].turn = X.turn;
	(*S).T[(*S).TOP].type = X.type;
	(*S).T[(*S).TOP].x0 = X.x0;
	(*S).T[(*S).TOP].y0 = X.y0;
	(*S).T[(*S).TOP].xt = X.xt;
	(*S).T[(*S).TOP].yt = X.yt;
	(*S).T[(*S).TOP].targettype = X.targettype;
	(*S).T[(*S).TOP].specialmove = X.specialmove;
}

void Pop (Stack *S, Sinfotype *X) {
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	/* Kamus Lokal */
	/* Algoritma */
	(*X).turn = (*S).T[(*S).TOP].turn;
	(*X).type = (*S).T[(*S).TOP].type;
	(*X).x0 = (*S).T[(*S).TOP].x0;
	(*X).y0 = (*S).T[(*S).TOP].y0;
	(*X).xt = (*S).T[(*S).TOP].xt;
	(*X).yt = (*S).T[(*S).TOP].yt;
	(*X).targettype = (*S).T[(*S).TOP].targettype;
	(*X).specialmove = (*S).T[(*S).TOP].specialmove;
	(*S).TOP--;
}