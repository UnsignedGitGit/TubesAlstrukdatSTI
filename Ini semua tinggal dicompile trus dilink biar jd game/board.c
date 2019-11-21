#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void BoardPieceMove(piece *P,  board *B, int x, int y)
// Mengubah posisi piece P di board
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. P berpindah ke posisi x dan y di board
{
	//KAMUS
	piece emptypiece;
	
	//ALGORITMA
	BoardCell(*B)[x][y] = P;
	
	PieceCreateEmpty(&emptypiece, PiecePosX(*P), PiecePosY(*P));
	BoardCell(*B)[PiecePosX(*P)][PiecePosY(*P)] = &emptypiece;
	
	PieceMove(P, x, y);
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
	//KAMUS
    piece P;
	int y, x;
	
	//ALGORITMA
    for (y = 8; y >= 1; y--) {
        for (x = 1; x <= 8; x++) {
            if (y == 8) {
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
                BoardCell(*B)[x][y] = &P;
                
            } else if (y == 7){
                // Create Black Pawn
                PieceCreateBPawn(&P, 'B', x, y);
                BoardCell(*B)[x][y] = &P;
                
            } else if (y == 2){
                // Create White Pawn
                PieceCreateWPawn(&P, 'W', x, y);
				BoardCell(*B)[x][y] = &P;
				
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
				BoardCell(*B)[x][y] = &P;
				
            } else {
                PieceCreateEmpty(&P, x, y);
				BoardCell(*B)[x][y] = &P;
            }

            // PiecePrintInfo(*(BoardCell(*B)[x][y]));
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
	int y;
	
	//ALGORITMA
	
	printf("%c\n",BoardCell(B)[1][1]->type);
	printf("%c\n",BoardCell(B)[2][1]->type);
	printf("%c\n",BoardCell(B)[3][1]->type);
	printf("%c\n",BoardCell(B)[4][1]->type);
	
    printf("         A       B       C       D       E       F       G       H    \n");
    printf("     _________________________________________________________________\n");
    for (y=8;y>0;y-=2){
        printf("     |#######|       |#######|       |#######|       |#######|       |\n"); //▓ adalah ascii 178
        printf("  %d  |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |\n",
        y,
        BoardCell(B)[1][1]->type,
        BoardCell(B)[2][1]->type,
        BoardCell(B)[3][1]->type,
        BoardCell(B)[4][1]->type,
        BoardCell(B)[5][1]->type,
        BoardCell(B)[6][1]->type,
        BoardCell(B)[7][1]->type,
        BoardCell(B)[8][1]->type);
        
        printf("     |#######|_______|#######|_______|#######|_______|#######|_______|\n");
        printf("     |       |#######|       |#######|       |#######|       |#######|\n");
        printf("  %d  |   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|   %c   |## %c ##|\n",
        y-1,
        BoardCell(B)[1][8-1]->type,
        BoardCell(B)[2][8-1]->type,
        BoardCell(B)[3][8-1]->type,
        BoardCell(B)[4][8-1]->type,
        BoardCell(B)[5][8-1]->type,
        BoardCell(B)[6][8-1]->type,
        BoardCell(B)[7][8-1]->type,
        BoardCell(B)[8][8-1]->type);
        printf("     |_______|#######|_______|#######|_______|#######|_______|#######|\n");
    } 
}

char translatex(int X)
// Menerjemahkan axis pada sel board
// x tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '
{
	//ALGORITMA
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

char translatey(int Y)
// Menerjemahkan ordinat pada sel board
// y tipe bentukan int yang terdefinisi [1 .. 8] dengan default char ' '
{
	//ALGORITMA
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
