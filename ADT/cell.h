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
// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void CellPrintInfo(cell C);
// Menampilkan info dari Cell secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan cellColor dan cellPiece pada CLI

// *** ================= *** //
// *** Konstruktor Cell  *** //
// *** ================= *** //

void CellCreate(cell *C, piece *P);
// Membuat Cell yang ada Bidaknya
// I.S. Cell C Terdefinisi, Piece P Terdefinisi
// F.S. Membuat cell C dengan Warna sesuai dengan posisi Piece P

void CellCreateEmpty(cell *C, int X, int Y);

void CellCreateOffset(cell *C, int X, int Y);

#endif