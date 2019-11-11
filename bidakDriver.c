#include "ADT/board.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    board B;
    cell C;

    CreateBoard(&B);
    BoardPrintInfo(B);

    CellDelete(&(BoardCell(B)[2][1]), &C);
    BoardPrintInfo(B);
}