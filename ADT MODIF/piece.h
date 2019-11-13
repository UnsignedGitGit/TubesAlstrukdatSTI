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

void PieceCreateWPawn(piece *P, char Team, int X, int Y); //White
void PieceCreateBPawn(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Pawn 'P', tim piece Team, posisi piece X dan Y.

void PieceCreateWRook(piece *P, char Team, int X, int Y); //White
void PieceCreateBRook(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Rook 'R', tim piece Team, posisi piece X dan Y.

void PieceCreateWKnight(piece *P, char Team, int X, int Y); //White
void PieceCreateBKnight(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Horse 'H', tim piece Team, posisi piece X dan Y.

void PieceCreateWBishop(piece *P, char Team, int X, int Y); //White
void PieceCreateBBishop(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Bishop 'B', tim piece Team, posisi piece X dan Y.

void PieceCreateWQueen(piece *P, char Team, int X, int Y); //White
void PieceCreateBQueen(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Queen 'Q', tim piece Team, posisi piece X dan Y.

void PieceCreateWKing(piece *P, char Team, int X, int Y); //White
void PieceCreateBKing(piece *P, char Team, int X, int Y); //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece King 'K', tim piece Team, posisi piece X dan Y.

// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //
boolean PieceIsEmpty(piece P);
// Menghasilkan true jika piece kosong, yaitu tipe atau tim piece bernilai CharNil

// Cek Type Piece
boolean PieceIsPawn(piece P); // 'P' || 'p'
boolean PieceIsRook(piece P); // 'R' || 'r'
boolean PieceIsKnight(piece P); // 'N' || 'n'
boolean PieceIsBishop(piece P); // 'B' || 'b'
boolean PieceIsQueen(piece P); // 'Q' || 'q'
boolean PieceIsKing(piece P); // 'K' || 'k'
// Menghasilkan true jika sesuai dengan tipe piece

boolean PieceIsValidMove(int x, int y);
// Mengembalikan true jika x[1..8] dan y[1..8]

boolean PieceIsTeamWhite(piece P);
boolean PieceIsTeamBlack(piece P);
// Mengembalikan true jika P adalah Hitam atau Putih tergantung dengan semantik fungsi

// *** ============== *** //
// *** Selektor Piece *** //
// *** ============== *** //

void PieceMove(piece *P, int x, int y);
// Mengubah Posisi Piece Secara General
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. Nilai xPos dan yPos pada Piece P diubah menyesuaikan inputan x dan y 

void PieceDelete(piece *P, piece *P1);
// Menghapus piece P yang ada di board. menyimpan informasi piece P ke piece P1
// I.S. Piece P, P1 Terdefinisi
// F.S. Piece P menjadi empty, informasi P pindah ke P1 


// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void PiecePrintInfo(piece P);
// Menampilkan info dari Piece secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan Type, Team, X, dan Y Catur pada CLI

#endif
