#ifndef stack_H
#define stack_H

#include "boolean.h"

#define Nil 0
#define MaxElStack 110

typedef int address;

typedef struct {
	char turn; 
	char type;
    /* P/p = pion, R/r = Rook, H/h = Horse/Knight, B/b = Bishop,
     * Q/q = Queen, K/k = King */
    
	int x0; /*Posisi horizontal bidak sebelum bergerak */
	int y0; /* Posisi Vertical bidak sebelum bergerak  */
	int xt; /* Posisi horizontal bidak setelah bergerak */
	int yt; /* Posisi vertical bidak setelah bergerak */
	char targettype; /* type bidak yang ada di posisi setelah bergerak */
	boolean IsCastling;
} infotype;

typedef struct {
    Sinfotype T[MaxElStack];
    address TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsStackFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, Sinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, Sinfotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


#endif
