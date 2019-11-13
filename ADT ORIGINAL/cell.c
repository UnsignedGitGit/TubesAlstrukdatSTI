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

void CellCreateEmpty(cell *C, int X, int Y)
// Membuat Cell yang bidaknya empty, X[0..8], Y[0..8]
// I.S. Cell C Terdefinisi, Piece P Terdefinisi
// F.S. Membuat cell C dengan Warna sesuai dengan posisi cell
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '*';    
}

void CellCreateOffset(cell *C, int X, int Y)
// Membuat Cell yang bidaknya empty, X[0..8], Y[0..8]
// I.S. Cell C Terdefinisi, X[0..8], Y[0..8]
// F.S. Membuat cell C diluar papan permainan
{
    piece P;
    PieceCreateEmpty(&P, X, Y);
    CellCreate(C, &P);
    CellDisplay(*C) = '#';
}

// *** ============== *** //
// *** Predikat Piece *** //
// *** ============== *** //

boolean CellIsEmpty(cell C)
// Menghasilkan true jika cell empty
{
    return (PieceIsEmpty(CellPiece(C)));
}

// *** ============== *** //
// *** Selektor Piece *** //
// *** ============== *** //

void CellDelete(cell *C, cell *C1)
// Menghapus cell C, menyimpan informasi cell C di cell C1
// I.S. Cell C, C1 Terdefinisi
// F.S. Cell C menjadi empty, informasi C pindah ke C1
{
    piece P;
    *C1 = *C;
    PieceCreateEmpty(&P, PiecePosX(CellPiece(*C)), PiecePosY(CellPiece(*C)));
    CellCreate(C, &P);
    CellDisplay(*C) = '*';
}

void CellMove(cell *C, cell *C1, cell *CTemp)
// Memindahkan isi cell C ke cell C1, nilai cell C1 jika tidak kosong akan dipindahkan ke CTemp
// I.S. C, C1, dan CTemp terdefinisi. C dan C1 bagian dari board
// F.S. C menjadi cell kosong, C1 menyimpan informasi C, dan CTemp menyimpan informasi C1 jika C1 bukan cell kosong
{
    // Cek jika C1 Kosong atau tidak, jika tidak kosong, maka informasi C1 dipindah ke CTemp
    if (!CellIsEmpty(*C1)) {
        CellDelete(C1, CTemp);
    }
    CellDelete(C, C1);
    CellDisplay(*C1) = PieceType(CellPiece(*C1));
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