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

// DEFINISI CELL
// Cell Empty adalah Cell yang memiliki Piece Empty
// Cell Offset adalah Cell Empty yang memiliki display khusus

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


// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //

boolean CellIsEmpty(cell C);
// Menghasilkan true jika cell empty


// *** ============== *** //
// *** Selektor Piece *** //
// *** ============== *** //

void CellDelete(cell *C, cell *C1);
// Menghapus cell C, menyimpan informasi cell C di cell C1
// I.S. Cell C, C1 Terdefinisi
// F.S. Cell C menjadi empty, informasi C pindah ke C1 

void CellMove(cell *C, cell *C1, cell *CTemp);
// Memindahkan isi cell C ke cell C1, nilai cell C1 jika tidak kosong akan dipindahkan ke CTemp
// I.S. C, C1, dan CTemp terdefinisi. C dan C1 bagian dari board
// F.S. C menjadi cell kosong, C1 menyimpan informasi C, dan CTemp menyimpan informasi C1 jika C1 bukan cell kosong


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void CellPrintInfo(cell C);
// Menampilkan info dari Cell secara lengkap
// I.S. C Terdefinisi
// F.S. Menampilkan Seluruh Info Cell pada CLI

#endif