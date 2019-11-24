#ifndef UNDO_H 
#define UNDO_H

#include "stack.h"
#include "piece.h"
#include "board.h"
#include "Commandmove.h"
#include <stdio.h>

void Undo (arr_possible_move* white, arr_possible_move* black, Stack *S, board* B);

void UndoBoardPieceMove(arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X);

void UndoEnpassan (arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X);

boolean UndoHasMoved(Sinfotype SI, Stack S,piece P);
#endif
