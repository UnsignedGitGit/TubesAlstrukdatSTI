#include "board.h"
#include <stdio.h>
#include <stdlib.h>

// *** =================== *** //
// *** Input/Output Screen *** //
// *** =================== *** //

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
        for (int x = 0; x < 9; x++){
            if ((y == 0) && (x == 0)) { 
                // The topmost leftmost cell
                CellCreateOffset(&(BoardCell(*B)[y][x]), x, y);
            } else if ((y == 0) && (x != 0)){ 
                // The main axis
                CellCreateEmpty(&(BoardCell(*B)[y][x]), x, y);
                CellDisplay(BoardCell(*B)[y][x]) = TranslateX(x);
            } else if ((y != 0) && (x == 0)){ 
                // The cross axis
                CellCreateEmpty(&(BoardCell(*B)[y][x]), x, y);
                CellDisplay(BoardCell(*B)[y][x]) = TranslateY(y);
            } else { 
                // Mengisi Bidak pada Board jika x[1 .. 8] dan y [1 .. 8]
                if (y == 8){
                    if ((x == 1) || (x == 8)){
                        // Create Black Rook
                        PieceCreateRook(&P, 'B', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if ((x == 2) || (x == 7)){
                        // Create Black Knight 
                        PieceCreateHorse(&P, 'B', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if ((x == 3) || (x == 6)){
                        // Create Black Bishop
                        PieceCreateBishop(&P, 'B', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if (x == 4){
                        // Create Black Queen
                        PieceCreateQueen(&P, 'B', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if (x == 5){
                        // Create Black King
                        PieceCreateKing(&P, 'B', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    }
                } else if (y == 7){
                    // Create Black Pawn
                    PieceCreatePawn(&P, 'B', x, y);
                    CellCreate(&(BoardCell(*B)[y][x]), &P);
                } else if (y == 2){
                    // Create White Pawn
                    PieceCreatePawn(&P, 'W', x, y);
                    CellCreate(&(BoardCell(*B)[y][x]), &P);
                } else if (y == 1){
                    if ((x == 1) || (x == 8)){
                        // Create White Rook
                        PieceCreateRook(&P, 'W', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if ((x == 2) || (x == 7)){
                        // Create White Knight 
                        PieceCreateHorse(&P, 'W', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if ((x == 3) || (x == 6)){
                        // Create White Bishop
                        PieceCreateBishop(&P, 'W', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if (x == 4){
                        // Create White Queen
                        PieceCreateQueen(&P, 'W', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    } else if (x == 5){
                        // Create White King
                        PieceCreateKing(&P, 'W', x, y);
                        CellCreate(&(BoardCell(*B)[y][x]), &P);
                    }
                } else {
                    PieceCreateEmpty(&P, x, y);
                    CellCreateEmpty(&(BoardCell(*B)[y][x]), x, y);
                }
            }
        }
    }
}