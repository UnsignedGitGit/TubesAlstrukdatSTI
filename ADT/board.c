#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char TranslateX(int X)
// Menerjemahkan axis pada sel board
// x tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '
{
    switch (X){
    case 1:
        return 'a';
        break;

    case 2:
        return 'b';
        break;

    case 3:
        return 'c';
        break;

    case 4:
        return 'd';
        break;

    case 5:
        return 'e';
        break;

    case 6:
        return 'f';
        break;

    case 7:
        return 'g';
        break;

    case 8:
        return 'h';
        break;
    
    default:
        return ' ';
        break;
    }
}

char TranslateY(int Y)
// Menerjemahkan ordinat pada sel board
// y tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '
{
    switch (Y){
    case 1:
        return '1';
        break;

    case 2:
        return '2';
        break;

    case 3:
        return '3';
        break;

    case 4:
        return '4';
        break;

    case 5:
        return '5';
        break;

    case 6:
        return '6';
        break;

    case 7:
        return '7';
        break;

    case 8:
        return '8';
        break;
    
    default:
        return ' ';
        break;
    }
}


// *** ================= *** //
// *** Konstruktor Board *** //
// *** ================= *** //

void CreateBoard(board *B)
// BoardCell(*B)[X][Y]
// Membuat Board lengkap dengan bidak caturnya
// I.S. B Sembarang terinisialisasi
// F.S. Board Kosong 9x9 dengan indikator pada x = 0 dan y = 0. Tersusun bidak caturnya.
{
    piece P;

    for(int y = 8; y >= 0; y--){
        for (int x = 0; x <= 8; x++){
            if (y == 8){
                if ((x == 1) || (x == 8)){
                    // Create Black Rook
                    PieceCreateBRook(&P, 'B', x, y);
                } else if ((x == 2) || (x == 7)){
                    // Create Black Knight 
                    PieceCreateBKnight(&P, 'B', x, y);
                } else if ((x == 3) || (x == 6)){
                    // Create Black Bishop
                    PieceCreateBBishop(&P, 'B', x, y);
                } else if (x == 4){
                    // Create Black Queen
                    PieceCreateBQueen(&P, 'B', x, y);
                } else if (x == 5){
                    // Create Black King
                    PieceCreateBKing(&P, 'B', x, y);
                }
                CellCreate(&(BoardCell(*B)[x][y]), &P);
            } else if (y == 7){
                // Create Black Pawn
                PieceCreateBPawn(&P, 'B', x, y);
                CellCreate(&(BoardCell(*B)[x][y]), &P);
            } else if (y == 2){
                // Create White Pawn
                PieceCreateWPawn(&P, 'W', x, y);
                CellCreate(&(BoardCell(*B)[x][y]), &P);
            } else if (y == 1){
                if ((x == 1) || (x == 8)){
                    // Create White Rook
                    PieceCreateWRook(&P, 'W', x, y);
                } else if ((x == 2) || (x == 7)){
                    // Create White Knight 
                    PieceCreateWKnight(&P, 'W', x, y);
                } else if ((x == 3) || (x == 6)){
                    // Create White Bishop
                    PieceCreateWBishop(&P, 'W', x, y);
                } else if (x == 4){
                    // Create White Queen
                    PieceCreateWQueen(&P, 'W', x, y);
                } else if (x == 5){
                    // Create White King
                    PieceCreateWKing(&P, 'W', x, y);
                }
                CellCreate(&(BoardCell(*B)[x][y]), &P);
            } else {
                PieceCreateEmpty(&P, x, y);
                if (( (x%2) && (y%2) ) || ( (x%2==0) && (y%2==0) )){ //hitam jika (x ganjil dan y ganjil) atau (x genap dan y genap )
                    CellCreateBEmpty(&(BoardCell(*B)[x][y]), x, y);
                }else{ //putih jika (x ganjil dan y genap) atau (x genap dan y ganjil)
                    CellCreateWEmpty(&(BoardCell(*B)[x][y]), x, y);
                }
                
            }
        }
    }
}

// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

// #define asciiwhiteblk 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178, 178,178,178,178,178,178,178,178
void BoardPrintInfo(board B)
// Menampilkan info dari Board secara lengkap
// I.S. B Terdefinisi
// F.S. Menampilkan Seluruh Info Board pada CLI
{
    printf("         A       B       C       D       E       F       G       H    \n");
    printf("     _________________________________________________________________\n");
    for (int y=8;y>0;y-=2){
        printf("     |#######|       |#######|       |#######|       |#######|       |\n"); //▓ adalah ascii 178
        printf("  %d  |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |\n",
        y,
        (CellDisplay(BoardCell(B)[1][y])),
        (CellDisplay(BoardCell(B)[2][y])),
        (CellDisplay(BoardCell(B)[3][y])),
        (CellDisplay(BoardCell(B)[4][y])),
        (CellDisplay(BoardCell(B)[5][y])),
        (CellDisplay(BoardCell(B)[6][y])),
        (CellDisplay(BoardCell(B)[7][y])),
        (CellDisplay(BoardCell(B)[8][y])));
        
        printf("     |#######|_______|#######|_______|#######|_______|#######|_______|\n");
        printf("     |       |#######|       |#######|       |#######|       |#######|\n");
        printf("  %d  |   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|\n",
        y-1,
        (CellDisplay(BoardCell(B)[1][y-1])),
        (CellDisplay(BoardCell(B)[2][y-1])),
        (CellDisplay(BoardCell(B)[3][y-1])),
        (CellDisplay(BoardCell(B)[4][y-1])),
        (CellDisplay(BoardCell(B)[5][y-1])),
        (CellDisplay(BoardCell(B)[6][y-1])),
        (CellDisplay(BoardCell(B)[7][y-1])),
        (CellDisplay(BoardCell(B)[8][y-1])));
        printf("     |_______|#######|_______|#######|_______|#######|_______|#######|\n");
    } 
}