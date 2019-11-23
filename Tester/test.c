#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "array.h"
#include "turn.h"

#include "Commandmove.h"
#include "Commandspecialmove.h"
#include "Undo.h"
#include "leaderboard.h"

int main(){
    piece P;
    board B;

    CreateBoard(&B);
    BoardPrintInfo(B);

    PiecePrintInfo(BoardCell(B)[1][2]);
    PiecePrintInfo(BoardCell(B)[1][4]);
    printf("\n");
    
    BoardPieceMove(&(BoardCell(B)[1][2]), &B, 1, 4);
    doMove()
    PiecePrintInfo(BoardCell(B)[1][2]);
    PiecePrintInfo(BoardCell(B)[1][4]);

    BoardPrintInfo(B);
}