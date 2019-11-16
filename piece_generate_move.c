#include "board.h"
#include "array_possible_move.h"
#include "stack.h"


/*PROTOTIPE*/
void king(arr_possible_move* M, piece P, board B, char T);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak raja tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

void horse(arr_possible_move* M, piece P, board B, char T);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak kuda tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

void pawn(arr_possible_move* M, piece P, board B, char T);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak pion tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
 
void addValidCoor(arr_possible_move* M, int idx, int x, int y, board B, char T);
/* I.S. M, x, y, B, P, dan T terdefinisi */
/* F.S. Alamat kotak (x dan y) yang valid akan dimasukkan ke list
 * 		-of-possible-move */
/* Alamat kotak valid jika tidak berada di luar papan dan tidak 
 * sedang ditempati bidak tim sendiri */

int findPieceIdx(arr_possible_move M, piece P);
/* Mengembalikan index alamat P di M. */

void doMove(arr_possible_move* M, arr_possible_move* enemy, piece* P, board* B, Stack* S, int choicenb);
/* I.S. M, P, B, S, dan choicenb terdefinisi */
/* F.S. Posisi piece P di papan diperbarui. S berisi catatan gerakan 
 * bidak tersebut. */

/*IMPLEMENTASI*/
void king(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak raja tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{	
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);

	addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+1, P.ypos, B, T);
	addValidCoor(M, i, P.xpos, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos, B, T);
	
	addValidCoor(M, i, P.xpos+1 , P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+1 , P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos+1, B, T);
}

void horse(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak kuda tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{	
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);
	
	addValidCoor(M, i, P.xpos-1, P.ypos+2, B, T);
	addValidCoor(M, i, P.xpos+1, P.ypos+2, B, T);
	addValidCoor(M, i, P.xpos+2, P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+2, P.ypos-1, B, T);
	
	addValidCoor(M, i, P.xpos+1 , P.ypos-2, B, T);
	addValidCoor(M, i, P.xpos-1 , P.ypos-2, B, T);
	addValidCoor(M, i, P.xpos-2, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-2, P.ypos+1, B, T);
}

void pawn(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak pion tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{
	/*KAMUS*/
	int i;
	Linfotype k;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);
	
	if (P.hasmoved) {
		addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
	} else {
		addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
		addValidCoor(M, i, P.xpos, P.ypos+2, B, T);
	}
	
	/* Mengecek alamat kotak di depan kiri dan depan kanan. Jika ada 
	 * bidak lawan, alamat kotak tersebut akan ditambahkan
	 * ke list-of-possible-move */
	 
	if (PieceIsValidMove(P.xpos+1, P.ypos+1)) {
		if (B.boardCell[P.xpos+1][P.ypos+1].team != T) {
			k.x = P.xpos+1;
			k.y = P.ypos+1;
			InsVLast (&(*M).arr[i].possmove, k);
		}
	}
	
	if (PieceIsValidMove(P.xpos-1, P.ypos+1)) {
		if (B.boardCell[P.xpos-1][P.ypos+1].team != T) {
			k.x = P.xpos-1;
			k.y = P.ypos+1;
			InsVLast (&(*M).arr[i].possmove, k);
		}
	}
}

void addValidCoor(arr_possible_move* M, int idx, int x, int y, board B, char T)
/* I.S. M, x, y, B, P, dan T terdefinisi */
/* F.S. Alamat kotak (x dan y) yang valid akan dimasukkan ke list
 * 		-of-possible-move */
/* Alamat kotak valid jika tidak berada di luar papan dan tidak 
 * sedang ditempati bidak tim sendiri */
{
	/*KAMUS*/
	Linfotype k;
	
	/*ALGORITMA*/
	/*Cek alamat kotak tujuan ada di luar papan atau tidak*/
	if (PieceIsValidMove(x, y)) {
		
		/*Cek ada bidak tim sendiri atau tidak di alamat kotak tujuan */
		if (B.boardCell[x][y].team != T) {
			k.x = x;
			k.y = y;
			InsVLast (&(*M).arr[idx].possmove, k);
		}
	}
}

int findPieceIdx(arr_possible_move M, piece P)
/* Mengembalikan index alamat P di M. */
{
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = 0;
	while ((M.arr[i].p.xpos != P.xpos) || (M.arr[i].p.ypos != P.ypos)) {
		i++;
	}
	
	return i;
}


void doMove(arr_possible_move* player, arr_possible_move* enemy, piece* P, board* B, Stack* S, int choicenb)
/* I.S. P, B, S, choicenb, array player, dan array enemy terdefinisi */
/* F.S. Posisi piece P di papan diperbarui. S berisi catatan gerakan 
 * bidak tersebut. */
{
	/*KAMUS*/
	int i, xtarget, ytarget;
	address coorchoice;
	Sinfotype H;
	
	/*ALGORITMA*/
	i = findPieceIdx(*player, *P);
	
	/*Pencatatan ke stack movement history*/
	H.turn = (*P).team;
	H.type = (*P).type;
	H.x0 = (*P).xpos;
	H.y0 = (*P).ypos;
	H.IsCastling = false;
	
	/* Mencari koordinat kotak tujuan pilihan pemain di 
	 * list-possible-move */
	coorchoice = First((*player).arr[i].possmove);
	for (i=1; i<= choicenb-1; i++) {
		coorchoice =  Next(coorchoice);
	}
	xtarget = (*coorchoice).info.x;
	ytarget = (*coorchoice).info.y;
	
	/*Lanjutan pencatatan stack movement history*/
	H.xt = xtarget;
	H.yt = ytarget;
	H.targettype = BoardCell(*B)[xtarget][ytarget].type;
	
	Push(S, H);
	
	/* Pemindahan piece P di board B. Jika ada bidak lawan, info isdead
	 * bidak lawan di array-possible-move diset menjadi true. */
	if (BoardCell(*B)[xtarget][ytarget].type != CharNil) {
		i = findPieceIdx(*enemy, BoardCell(*B)[xtarget][ytarget]);
		(*enemy).arr[i].p.isdead = true;
	}
	
	BoardPieceMove(P, B, xtarget, ytarget);

	/*Pengubahan info piece P*/
	PieceMove(P, xtarget, ytarget);
}
