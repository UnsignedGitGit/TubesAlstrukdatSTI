#include "piece.h"

#ifndef CELL_H 
#define CELL_H

typedef struct {
    piece cellPiece;
    char cellColor;
    char cellDisplay;
} cell;

#define CellColor(C) (C).cellColor // input C : char
#define CellPiece(C) (C).cellPiece // input C : piece
#define CellDisplay(C) (C).cellDisplay // input C : char


// *** ================= *** //
// *** Konstruktor Cell  *** //
// *** ================= *** //

void CellCreate(cell *C, piece *P);
// Membuat Cell yang ada Bidaknya
// I.S. Cell C Terdefinisi, Piece P Terdefinisi
// F.S. Membuat cell C dengan Warna sesuai dengan posisi Piece P

void CellCreateEmpty(cell *C, int X, int Y);
// Membuat Cell yang bidaknya empty, X[0..8], Y[0..8]
// I.S. Cell C Terdefinisi, Piece P Terdefinisi
// F.S. Membuat cell C dengan Warna sesuai dengan posisi cell

void CellCreateOffset(cell *C, int X, int Y);
// Membuat Cell yang bidaknya empty, X[0..8], Y[0..8]
// I.S. Cell C Terdefinisi, X[0..8], Y[0..8]
// F.S. Membuat cell C diluar papan permainan


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void CellPrintInfo(cell C);
// Menampilkan info dari Cell secara lengkap
// I.S. C Terdefinisi
// F.S. Menampilkan Seluruh Info Cell pada CLI

#endif