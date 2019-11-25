#ifndef UNDO_H 
#define UNDO_H

#include "stack.h"
#include "piece.h"
#include "board.h"
#include "Commandmove.h"
#include <stdio.h>

void Undo (arr_possible_move* white, arr_possible_move* black, Stack *S, board* B);

void UndoBoardPieceMove(arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X);
// 

void UndoEnpassan (arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X);
// Prosedur yang khusus melakukan undo en passant

boolean UndoHasMoved(Sinfotype SI, Stack S,piece P);
//I.S bidak yang baru pertama kali bergerak, atribut hasmovednya di set ke true
// F.S bidak yang baru sekali bergerak di undo, dan atribut hasmovednya di set kembali ke false

#endif
