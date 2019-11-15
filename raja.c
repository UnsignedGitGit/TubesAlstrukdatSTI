#include "board.h"
#include "array_possible_move.h"

/*PROTOTIPE*/
void raja (arr_possible_move* M, piece P, board B, char T);
/* I.S. M, P, B, dan T terdefinisi. List */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak raja tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

void add_coor_valid (arr_possible_move* M, int idx, int x, int y, board B, char T);
/* I.S. M, x, y, B, P, dan T terdefinisi */
/* F.S. Alamat kotak (x dan y) yang valid akan dimasukkan ke list
 * 		-of-possible-move */
/* Alamat kotak valid jika tidak berada di luar papan dan tidak 
 * sedang ditempati bidak tim sendiri */


/*IMPLEMENTASI*/
void raja(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak raja tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{	
	/*KAMUS*/
	int i;
	Linfotype x;
	
	/*ALGORITMA*/
	/*Mencari bidak yang ingin diakses list-of-possible-movenya*/
	i = 0;
	while (((*M).arr[i].p.xpos != P.xpos) || ((*M).arr[i].p.ypos != P.ypos)) {
		i++;
	}
	
	/*Jika list tidak kosong, hapus semua isinya terlebih dahulu*/
	if (!IsListEmpty((*M).arr[i].possmove)) {
		for (i=1; i<= NbElmtList((*M).arr[i].possmove); i++) {
			DelVLast(&(*M).arr[i].possmove, &x);
		}
	}
	
	add_coor_valid(M, i, P.xpos, P.ypos+1, B, T);
	add_coor_valid(M, i, P.xpos+1, P.ypos, B, T);
	add_coor_valid(M, i, P.xpos, P.ypos-1, B, T);
	add_coor_valid(M, i, P.xpos-1, P.ypos, B, T);
	
	add_coor_valid(M, i, P.xpos+1 , P.ypos+1, B, T);
	add_coor_valid(M, i, P.xpos+1 , P.ypos-1, B, T);
	add_coor_valid(M, i, P.xpos-1, P.ypos-1, B, T);
	add_coor_valid(M, i, P.xpos-1, P.ypos+1, B, T);
}

void add_coor_valid(arr_possible_move* M, int idx, int x, int y, board B, char T)
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
