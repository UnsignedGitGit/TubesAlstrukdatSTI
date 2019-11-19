#ifndef UNDO_H 
#define UNDO_H

#include "stack.h"
#include "piece.h"
#include "board.h"

void Undo (Stack *S);
void UndoBoardPieceMove(piece *P,  board *B, Sinfotype X);

#endif
