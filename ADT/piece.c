#include "piece.h"
#include <stdio.h>
#include <stdlib.h>

// *** ================= *** //
// *** Konstruktor Piece *** //
// *** ================= *** //
void PieceCreate(piece *P, char Tipe, char Team, int X, int Y)
// Membuat piece baru pada variabel P.
// I.S. P Terdefinisi, X[0 .. 8], Y[0 .. 8]
// F.S. Terbentuk P dengan tipe piece Type, tim piece Team, posisi piece X dan posisi piece Y. 
{
    ChessType(*P) = Tipe;
    ChessTeam(*P) = Team;
    ChessPosX(*P) = X;
    ChessPosY(*P) = Y;
}

void PieceCreateEmpty(piece *P, int X, int Y)
// Membuat piece kosong pada variabel P.
// I.S. P Terdefinisi X[0 .. 8], Y[0 .. 8]
// F.S. Terbentuk P dengan tipe piece Charnil, tim piece Charnil, posisi piece X dan posisi piece Y. 
{
    PieceCreate(P, CharNil, CharNil, X, Y);
}

void PieceCreatePawn(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Pawn 'P', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'P', Team, X, Y);
}
void PieceCreateRook(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Rook 'R', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'R', Team, X, Y);
}

void PieceCreateHorse(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Horse 'H', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'H', Team, X, Y);
}

void PieceCreateBishop(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Bishop 'B', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'B', Team, X, Y);
}

void PieceCreateQueen(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Queen 'Q', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'Q', Team, X, Y);
}

void PieceCreateKing(piece *P, char Team, int X, int Y)
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece King 'K', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'K', Team, X, Y);
}

// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //
boolean PieceIsEmpty(piece P)
// Menghasilkan true jika piece kosong, yaitu tipe atau tim piece bernilai CharNil
{
    return ((ChessTeam(P) == CharNil) || (ChessType(P) == CharNil));
}

// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //
void PiecePrintInfo(piece P)
// Menampilkan info dari Piece secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan Type, Team, X, dan Y Catur pada CLI
{
    printf("Piece Info\n");
    printf("Type: %c\n", ChessType(P));
    printf("Team: %c\n", ChessTeam(P));
    printf("XPos: %d\n", ChessPosX(P));
    printf("YPos: %d\n", ChessPosY(P));
}


// Movement(*B)

// void PrintPiece(piece B)
// // Menuliskan status piece pada CLI
// // I.S. Sembarang
// // F.S. Output Type, Team, Posisi X, dan Posisi Y piece
// {
//     // printf("%c %c %d %d\n", ChessType(B), CheTeam(B), X(B), Y(B));
// }