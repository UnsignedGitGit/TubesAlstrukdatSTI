// Driver ADT Board
// gcc -o boarddriver boarddriver.c piece.c board.c
#include <stdio.h>
#include "board.h"

int main(){
    board B;

    CreateBoard(&B);
    printf("Print Info dari Board B\n");
    BoardPrintInfo(B);

    printf("Test Fungsi translate\n");
    printf("Input\tX\tY\n"
    );
    printf("=======================\n");
    for(int i = 1; i <= 10; i++){
        printf("%d\t%c\t%c\n", i, translatex(i), translatey(i));
    }

    printf("Memindahkan piece P \n");
    BoardPieceMove(&(BoardCell(B)[4][2]), &B, 4, 4);
    BoardPrintInfo(B);
}