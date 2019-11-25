// Driver ADT Piece
// gcc -o piecedriver piecedriver.c piece.c
#include <stdio.h>
#include "../Game/piece.h"

int main(){
    piece P;

    printf("Membentuk Piece Sembarang\n");
    PieceCreate(&P, 'R', 'S', 13, 10);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Kosong\n");
    PieceCreateEmpty(&P, 1, 8);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece White Pawn\n");
    PieceCreateWPawn(&P, 'W', 4, 7);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Black Pawn\n");
    PieceCreateBPawn(&P, 'B', 3, 7);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece White Knight\n");
    PieceCreateWKnight(&P, 'W', 2, 4);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Black Knight\n");
    PieceCreateBKnight(&P, 'B', 4, 2);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece White Bishop\n");
    PieceCreateWBishop(&P, 'W', 7, 4);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Black Bishop\n");
    PieceCreateBBishop(&P, 'B', 8, 6);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece White Queen\n");
    PieceCreateWQueen(&P, 'W', 1, 1);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Black Queen\n");
    PieceCreateBQueen(&P, 'B', 2, 2);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece White King\n");
    PieceCreateWKing(&P, 'W', 3, 3);
    PiecePrintInfo(P);

    printf("\n");
    printf("Membentuk Piece Black King\n");
    PieceCreateBKing(&P, 'B', 4, 4);
    PiecePrintInfo(P);

    printf("\n");
    printf("Mengecek Tipe Bidak P sekarang\n");
    printf("1. Is Pawn? %d\n", PieceIsPawn(P));
    printf("2. Is Rook? %d\n", PieceIsRook(P));
    printf("3. Is Knight? %d\n", PieceIsKnight(P));
    printf("4. Is Bishop? %d\n", PieceIsBishop(P));
    printf("5. Is Queen? %d\n", PieceIsQueen(P));
    printf("6. Is King? %d\n", PieceIsKing(P));

    printf("\n");
    printf("Mengecek Tim Bidak P sekarang\n");
    printf("1. Is Putih? %d\n", PieceIsTeamWhite(P));
    printf("2. Is Hitam? %d\n", PieceIsTeamBlack(P));

    printf("\n");
    printf("Memindahkan Bidak P\n");
    PieceMove(&P, 1, 1);
    PiecePrintInfo(P);

    printf("\n");
    printf("Memindahkan Bidak P ke tempat ilegal\n");
    PieceMove(&P, 10, 21);
    PiecePrintInfo(P);
}