#ifndef specialmove_H
#define specialmove_H

#include "boolean.h"
#include "array.h"
#include "stack.h"
#include "board.h"

typedef struct {
	int x;
	int y;
	boolean canEnpassant;
} pawn_enpassant;

/*PROTOTIPE*/
void special_move(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char T);
/* I.S. M, S, B, dan T terdefinisi. */
/* F.S. Special move pilihan pemain dilakukan. Gerakan dilakukan di B dan dicatat di S */
void DoCastling(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char id, char T);
/* I.S. B, S, id, dan T terdefinisi. */
/* F.S. Castling dilakukan di B dan dicatat di S */
void DoEnpassant(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char T, pawn_enpassant p);
/* I.S. B, S, id, T, dan p terdefinisi. */
/* F.S. En passant dilakukan di B dan dicatat di S */
void EnpassantL(board B, Stack S, pawn_enpassant* C);
/* Prosedur ini mengecek keberadaan pion tim sendiri di 
 * alamat (x-1, y). x dan y adalah posisi pion musuh yang 
 * baru saja bergerak maju dua langkah.
 * I.S. B dan S terdefinisi. C sembarang.
 * F.S. Jika en passant dapat dilakukan, alamat pion yang dapat
 * 		melaksanakannya, yaitu (x-1, y), akan disimpan di C. */
void EnpassantR(board B, Stack S, pawn_enpassant* C);
/* Prosedur ini mengecek keberadaan pion tim sendiri di 
 * alamat (x+1, y). x dan y adalah posisi pion musuh yang 
 * baru saja bergerak maju dua langkah.
 * I.S. B dan S terdefinisi. C sembarang.
 * F.S. Jika en passant dapat dilakukan, alamat pion yang dapat
 * 		melaksanakannya, yaitu (x+1, y), akan disimpan di C. */
boolean canNearCastling(board B, char T);
/* Castling ini melibatkan:
 * - raja di (e,1) dan benteng di (h,1) untuk tim putih atau
 * - raja di (e,8) dan benteng (h,8) untuk tim hitam.
 * Menghasilkan nilai true jika semua syarat Castling terpenuhi.*/
boolean canFarCastling(board B, char T);
/* Castling ini melibatkan:
 * - raja di (e,1) dan benteng di (a,1) untuk tim putih atau
 * - raja di (e,8) dan benteng (a,8) untuk tim hitam.
 * Menghasilkan nilai true jika semua syarat Castling terpenuhi.*/
boolean isLeftEmpty(board B, piece k);
/* Menghasilkan true jika kotak-kotak di antara kedua bidak berikut kosong.
 * - raja di (e,1) dan benteng di (a,1) untuk tim putih atau 
 * - raja di (e,8) dan benteng (a,8) untuk tim hitam. */
boolean isRightEmpty(board B, piece k);
/* Menghasilkan true jika kotak-kotak di antara kedua bidak berikut kosong.
 * - raja di (e,1) dan benteng di (h,1) untuk tim putih atau 
 * - raja di (e,8) dan benteng (h,8) untuk tim hitam. */
boolean isCellAttacked(board B, int x, int y, char T);
/* Menghasilkan true jika kotak beralamat (x,y) sedang diserang.*/
boolean hasAttacker(board B, int iterator, char enemyteam, char team, int x, int y);
/* Menghasilkan true jika (x,y) memenuhi kondisi ke-'interator'.*/

boolean isCheckmate(board B, int kingxpos, int kingypos, char T, arr_possible_move disruptor);
/* Menghasilkan true jika ada raja tim T berada dalam kondisi skakmat. */
void generateThreatLane(board B, arr_check* C, piece attacker, piece king);
/* I.S. B, C, attacker, dan king terdefinisi
 * F.S. C berisi koordinat posisi awal penyekak dan alamat kotak-kotak di antara
 * posisi awal penyekak dan raja yang sedang diserangnya. */
boolean canDisrupt(arr_possible_move disruptor, board B, arr_check C);
/* Menghasilkan true jika ada bidak tim T yang dapat berpindah atau makan ke salah satu alamat
 * di C */

#endif