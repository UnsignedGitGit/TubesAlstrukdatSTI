#include "boolean.h"

#ifndef PIECE_H
#define PIECE_H

#define Nil 0
#define CharNil ' '

typedef struct {
    char type; // P = pion, R = Rook, H = Horse/Knight, B = Bishop, Q = Queen, K = King 
    char team; // W = White, B = Black
    int xpos; // Possible int: [0..8] 
    int ypos; // Possible int: [0..8]
    boolean hasmoved;
    boolean isdead;
} piece;

#define PieceType(P) (P).type
#define PieceTeam(P) (P).team
#define PiecePosX(P) (P).xpos
#define PiecePosY(P) (P).ypos
#define PieceHasMoved(P) (P).hasmoved

// DEFINISI PIECE
// Piece Empty adalah Piece yang memiliki Piece.type Charnil dan Piece.team Charnil 

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

// Cek Type Piece
boolean PieceIsPawn(piece P); // 'P'
boolean PieceIsRook(piece P); // 'R'
boolean PieceIsHorse(piece P); // 'H'
boolean PieceIsBishop(piece P); // 'B'
boolean PieceIsQueen(piece P); // 'Q'
boolean PieceIsKing(piece P); // 'K'
// Menghasilkan true jika sesuai dengan tipe piece

boolean PieceIsValidMove(int x, int y);
// Mengembalikan true jika x[1..8] dan y[1..8]

boolean PieceIsTeamWhite(piece P);
boolean PieceIsTeamBlack(piece P);
// Mengembalikan true jika P adalah Hitam atau Putih tergantung dengan semantik fungsi

// *** ============== *** //
// *** Selektor Piece *** //
// *** ============== *** //
void PieceDelete(piece *P, piece *P1);
// Menghapus piece P yang ada di board. menyimpan informasi piece P ke piece P1
// I.S. Piece P, P1 Terdefinisi
// F.S. Piece P menjadi empty, informasi P pindah ke P1 

void PieceMove(piece *P, int x, int y);
// Mengubah Posisi Piece Secara General
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. Nilai xPos dan yPos pada Piece P diubah menyesuaikan inputan x dan y 


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void PiecePrintInfo(piece P);
// Menampilkan info dari Piece secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan Type, Team, X, dan Y Catur pada CLI

#endif