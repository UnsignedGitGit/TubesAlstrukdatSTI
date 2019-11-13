#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

// *** ================= *** //
// *** Konstruktor Cell  *** //
// *** ================= *** //

void CellCreate(cell *C, piece *P)
// Membuat Cell yang ada Bidaknya
// I.S. Cell C Terdefinisi, Piece P Terdefinisi
// F.S. Membuat cell C dengan Warna sesuai dengan posisi Piece P
{
    // ALGORITMA
    // Menentukan Color dari board cell dengan X, Y
    if (PiecePosX(*P) % 2){ // jika X ganjil {1, 3, 5, 7}
        if (PiecePosY(*P) % 2) { // Jika Y ganjil {1, 3, 5, 7}, maka cell color Hitam
            CellColor(*C) = 'B';
        } else { // Jika Y genap {2, 4, 6, 8}, maka cell color Putih
            CellColor(*C) = 'W';
        }
    } else { // jika X genap {2, 4, 6, 8}
        if (PiecePosY(*P) % 2) { // Jika Y ganjil {1, 3, 5, 7}, maka cell color Hitam
            CellColor(*C) = 'W';
        } else { // Jika Y genap {2, 4, 6, 8}, maka cell color Putih
            CellColor(*C) = 'B';
        }
    }

    // Membuat Piece Terdefinisi di posisi X dan Y
    CellPiece(*C) = *P;
    CellDisplay(*C) = PieceType(*P);
}

void CellCreateWEmpty(cell *C, int X, int Y) //White
//
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '#';    
}

void CellCreateBEmpty(cell *C, int X, int Y) //Black
//
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = ' ';    
}

void CellCreateOffset(cell *C, int X, int Y)
//
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '#';
}

// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void CellPrintInfo(cell C)
// Menampilkan info dari Cell secara lengkap
// I.S. C Terdefinisi
// F.S. Menampilkan Seluruh Info Cell pada CLI
{
    printf("Cell Info\n");
    printf("Cell Color: %c\n", CellColor(C));
    printf("Cell Piece:\n");
    printf("\tType: %c\n", PieceType(CellPiece(C)));
    printf("\tTeam: %c\n", PieceTeam(CellPiece(C)));
    printf("\tXPos: %d\n", PiecePosX(CellPiece(C)));
    printf("\tYPos: %d\n", PiecePosY(CellPiece(C)));
}