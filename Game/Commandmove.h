// File Commandmove.h
// Berisi deklarasi prosedur Do_move, Move, show_moveable_piece,generate_valid_move
// Fungsi-fungsi/Prosedur selain move adalah turunan fungsi move, maka Move memanggil fungsi lainnya

#ifndef move_H
#define move_H

#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "queue.h"
#include "stack.h"
#include "array.h"

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

void rook(arr_possible_move *M, piece P,board B,char giliran);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak benteng tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

void bishop(arr_possible_move *M, piece P,board B,char T);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak benteng tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

void queen(arr_possible_move *M, piece P,board B,char T);
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak benteng tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
 
void addValidCoor(arr_possible_move* M, int idx, int x, int y, board B, char T);
/* I.S. M, x, y, B, P, dan T terdefinisi */
/* F.S. Alamat kotak (x dan y) yang valid akan dimasukkan ke list
 * 		-of-possible-move */
/* Alamat kotak valid jika tidak berada di luar papan dan tidak 
 * sedang ditempati bidak tim sendiri */

int findPieceIdx(arr_possible_move M, piece P);
/* Mengembalikan index alamat P di M. */

boolean Iscellempty (board B, int x, int y);
/*Mengecek apakah kotak dengan korrdinat x,y berisi atau kosong*/

void doMove(arr_possible_move* player, arr_possible_move* enemy, piece* P, board* B, Stack* S, int choicenb, List* L);
/* I.S. M, P, B, S, dan choicenb terdefinisi */
/* F.S. Posisi piece P di papan diperbarui. S berisi catatan gerakan 
 * bidak tersebut. */

void move(Stack *S, char team, arr_possible_move* player, arr_possible_move* enemy, board* B);
/* Secara Berurutan, Prosedur ini Akan melakukan :
            1. Generate Valid Move untuk seluruh bidak dari 1 tim
            2. Mengcopy bidak yang mungkin bergerak ke array of pilihan possible
            3. Menampilkan array of pilihan possible dan meminta input untuk pilihan bidak
            4. Menampilkan gerakan yang mungkin dari bidak pilihan dan meminta input pilihan gerakan
            5. Melakukan gerakan dari pilihan pengguna (do move)
*/

void generate_valid_move(arr_possible_move *T,board B); 
// I.S arr_possible_move sudah ada, dan list possible move dikosongkan
// F.S. arr_possible_move sudah terisi

void show_movable_piece(piece_choice pc);
// I.S sembarang
// F.S Menampilkan seluruh piece yang mungkin digerakkan sesuai spek tubes tercinta

#endif