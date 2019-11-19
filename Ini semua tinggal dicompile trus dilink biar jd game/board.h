#include "piece.h"

#ifndef BOARD_H 
#define BOARD_H

typedef struct {
    piece* boardCell [9][9];
} board;

#define BoardCell(B) (B).boardCell // input B : board


// **** Dictionary **** //
/*   (y)
      |8
    o |7
    r |6
    d |5
    i |4
    n |3
    a |2
    t |1 
      |  a b c d e f g h
      =================== (x)
             a x i s
*/


void BoardPieceMove(piece *P,  board *B, int x, int y);
// Mengubah posisi piece P di board
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. P berpindah ke posisi x dan y di board


// *** ================= *** //
// *** Konstruktor Board *** //
// *** ================= *** //

void CreateBoard(board *B);
// Membuat Board Tersusun bidak-bidaknya
// I.S. Sembarang
// F.S. Board Kosong 9x9 dengan indikator


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

char translatex(int x);
// Menerjemahkan axis pada sel board
// x tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '

char translatey(int y);
// Menerjemahkan ordinat pada sel board
// y tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '

void BoardPrintInfo(board B);
// Menampilkan info dari Board secara lengkap
// I.S. B Terdefinisi
// F.S. Menampilkan Seluruh Info Board pada CLI

#endif
