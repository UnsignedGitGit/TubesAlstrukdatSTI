#include "boolean.h"

#ifndef PIECE_H
#define PIECE_H

#define Nil 0
#define CharNil ' '

typedef struct {
    char type; // P = pion, R = Rook, H = Horse/Knight, B = Bishop, Q = Queen, K = King 
    char team; // W = White, B = Black
    int xpos; // Possible int: 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'. 
    int ypos; // Possible int: '1', '2', '3', '4', '5', '6', '7', '8'.
} piece;

#define ChessType(P) (P).type
#define ChessTeam(P) (P).team
#define ChessPosX(P) (P).xpos
#define ChessPosY(P) (P).ypos

// *** ================= *** //
// *** Konstruktor Piece *** //
// *** ================= *** //
void PieceCreate(piece *P, char Tipe, char Team, int X, int Y);
// Membuat piece baru pada variabel P.
// I.S. P Sembarang
// F.S. Terbentuk P dengan tipe piece Type, tim piece Team, posisi piece X dan posisi piece Y.

void PieceCreateEmpty(piece *P, int X, int Y);
// Membuat piece kosong pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Charnil, tim piece Charnil, posisi piece X dan posisi piece Y. 

void PieceCreatePawn(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Pawn 'P', tim piece Team, posisi piece X dan Y.

void PieceCreateRook(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Rook 'R', tim piece Team, posisi piece X dan Y.

void PieceCreateHorse(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Horse 'H', tim piece Team, posisi piece X dan Y.

void PieceCreateBishop(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Bishop 'B', tim piece Team, posisi piece X dan Y.

void PieceCreateQueen(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Queen 'Q', tim piece Team, posisi piece X dan Y.

void PieceCreateKing(piece *P, char Team, int X, int Y);
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece King 'K', tim piece Team, posisi piece X dan Y.

// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //
boolean PieceIsEmpty(piece P);
// Menghasilkan true jika piece kosong, yaitu tipe atau tim piece bernilai CharNil


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void PiecePrintInfo(piece P);
// Menampilkan info dari Piece secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan Type, Team, X, dan Y Catur pada CLI

#endif