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
    PieceType(*P) = Tipe;
    PieceTeam(*P) = Team;
    PiecePosX(*P) = X;
    PiecePosY(*P) = Y;
}

void PieceCreateEmpty(piece *P, int X, int Y)
// Membuat piece kosong pada variabel P.
// I.S. P Terdefinisi X[0 .. 8], Y[0 .. 8]
// F.S. Terbentuk P dengan tipe piece Charnil, tim piece Charnil, posisi piece X dan posisi piece Y. 
{
    PieceCreate(P, CharNil, CharNil, X, Y);
}

void PieceCreateWPawn(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Pawn 'P', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'P', Team, X, Y);
}

void PieceCreateBPawn(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Pawn 'P', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'p', Team, X, Y);
}

void PieceCreateWRook(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Rook 'R', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'R', Team, X, Y);
}

void PieceCreateBRook(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Rook 'R', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'r', Team, X, Y);
}

void PieceCreateWKnight(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Horse 'H', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'N', Team, X, Y);
}

void PieceCreateBKnight(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Horse 'H', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'n', Team, X, Y);
}

void PieceCreateWBishop(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Bishop 'B', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'B', Team, X, Y);
}

void PieceCreateBBishop(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Bishop 'B', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'b', Team, X, Y);
}

void PieceCreateWQueen(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Queen 'Q', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'Q', Team, X, Y);
}

void PieceCreateBQueen(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece Queen 'Q', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'q', Team, X, Y);
}

void PieceCreateWKing(piece *P, char Team, int X, int Y) //White
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece King 'K', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'K', Team, X, Y);
}

void PieceCreateBKing(piece *P, char Team, int X, int Y) //Black
// Membuat piece bertipe pawn pada variabel P.
// I.S. P Terdefinisi
// F.S. Terbentuk P dengan tipe piece King 'K', tim piece Team, posisi piece X dan Y.
{
    PieceCreate(P, 'k', Team, X, Y);
}

// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //
boolean PieceIsEmpty(piece P)
// Menghasilkan true jika piece kosong, yaitu tipe atau tim piece bernilai CharNil
{
    return ((PieceTeam(P) == CharNil) || (PieceType(P) == CharNil));
}

// Cek Type Piece
boolean PieceIsPawn(piece P)
{
    return (PieceType(P) == 'P' || PieceType(P) == 'p');    
}
boolean PieceIsRook(piece P)
{
    return (PieceType(P) == 'R' || PieceType(P) == 'r');    
}
boolean PieceIsKnight(piece P)
{
    return (PieceType(P) == 'N' || PieceType(P) == 'n');    
}
boolean PieceIsBishop(piece P)
{
    return (PieceType(P) == 'B' || PieceType(P) == 'b');    
}
boolean PieceIsQueen(piece P)
{
    return (PieceType(P) == 'Q' || PieceType(P) == 'q');    
}
boolean PieceIsKing(piece P)
{
    return (PieceType(P) == 'K' || PieceType(P) == 'k');    
}
// Menghasilkan true jika sesuai dengan tipe piece

boolean PieceIsValidMove(int x, int y)
// Mengembalikan true jika x[1..8] dan y[1..8]
{
    if (x >= 1 && x <= 8) {
        if (y >= 1 && y <= 8){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

boolean PieceIsTeamWhite(piece P)
{
    return (PieceTeam(P) == 'W');
}

boolean PieceIsTeamBlack(piece P)
{
    return (PieceTeam(P) == 'B');
}
// Mengembalikan true jika P adalah Hitam atau Putih tergantung dengan semantik fungsi

// *** ============== *** //
// *** Selektor Piece *** //
// *** ============== *** //

void PieceMove(piece *P, int x, int y)
// Mengubah Posisi Piece Secara General
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. Nilai xPos dan yPos pada Piece P diubah menyesuaikan inputan x dan y 
{
    if (PieceIsValidMove(x, y)){
        PiecePosX(*P) = x;
        PiecePosY(*P) = y;
    }
}

void PieceDelete(piece *P, piece *P1)
// Menghapus piece P yang ada di board. menyimpan informasi piece P ke piece P1
// I.S. Piece P, P1 Terdefinisi
// F.S. Piece P menjadi empty, informasi P pindah ke P1 
{
    *P1 = *P;
    PieceCreateEmpty(P, PiecePosX(*P), PiecePosY(*P));
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
    printf("Type: %c\n", PieceType(P));
    printf("Team: %c\n", PieceTeam(P));
    printf("XPos: %d\n", PiecePosX(P));
    printf("YPos: %d\n", PiecePosY(P));
}


// Movement(*B)
