#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

void CellPrintInfo(cell C)
// Menampilkan info dari Cell secara lengkap
// I.S. P Terdefinisi
// F.S. Menampilkan cellColor dan cellPiece pada CLI
{
    printf("Cell Info\n");
    printf("Cell Color: %c\n", CellColor(C));
    printf("Cell Piece:\n");
    printf("\tType: %c\n", ChessType(CellPiece(C)));
    printf("\tTeam: %c\n", ChessTeam(CellPiece(C)));
    printf("\tXPos: %d\n", ChessPosX(CellPiece(C)));
    printf("\tYPos: %d\n", ChessPosY(CellPiece(C)));
}

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
    if (ChessPosX(*P) % 2){ // jika X ganjil {1, 3, 5, 7}
        if (ChessPosY(*P) % 2) { // Jika Y ganjil {1, 3, 5, 7}, maka cell color Hitam
            CellColor(*C) = 'B';
        } else { // Jika Y genap {2, 4, 6, 8}, maka cell color Putih
            CellColor(*C) = 'W';
        }
    } else { // jika X genap {2, 4, 6, 8}
        if (ChessPosY(*P) % 2) { // Jika Y ganjil {1, 3, 5, 7}, maka cell color Hitam
            CellColor(*C) = 'W';
        } else { // Jika Y genap {2, 4, 6, 8}, maka cell color Putih
            CellColor(*C) = 'B';
        }
    }

    // Membuat Piece Terdefinisi di posisi X dan Y
    CellPiece(*C) = *P;
    CellDisplay(*C) = ChessType(*P);
}

void CellCreateEmpty(cell *C, int X, int Y)
//
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '*';    
}

void CellCreateOffset(cell *C, int X, int Y)
//
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '#';
}