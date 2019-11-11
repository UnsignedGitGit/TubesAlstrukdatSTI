#include "ADT/board.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    board B;
    CreateBoard(&B);

    for(int y = 8; y >= 0; y--){
        for (int x = 0; x < 9; x++){
            printf("%c", CellDisplay(BoardCell(B)[y][x]));
        }
        printf("\n");
    }

    CellPrintInfo(BoardCell(B)[2][4]);
}