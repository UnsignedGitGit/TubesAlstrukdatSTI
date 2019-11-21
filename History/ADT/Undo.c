// NAMA : Adriel Gustino P 
// NIM : 18218047

#include "Undo.h"

void UndoBoardPieceMove(piece *P,  board *B, Sinfotype X)
// Mengubah posisi piece P di board
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. P berpindah ke posisi x dan y di board
{
	//KAMUS
	piece emptypiece,Q;
	
	//ALGORITMA
	BoardCell(*B)[X.x0][X.y0] = P;
	
	if (X.targettype == CharNil )
	{
		PieceCreateEmpty(&emptypiece, X.xt, X.yt);
		BoardCell(*B)[X.xt][X.yt] = &emptypiece;
	}
	else
	{
		if (X.turn == 'W')
		{	
			PieceCreate(&Q,X.targettype, 'B' , X.xt, X.yt);
			BoardCell(*B)[X.xt][X.yt] = &Q;		
		}
		else if (X.turn == 'B')
		{	
			PieceCreate(&Q,X.targettype, 'W' , X.xt, X.yt);
			BoardCell(*B)[X.xt][X.yt] = &Q;		
		}
	}

	PieceMove(P, X.x0, X.y0);
}

void Undo (Stack *S)
{
	// KAMUS
	Sinfotype X;
	piece P;
	board B;
	int i;

	// ALGORITMA
	i = 1;
	while (i!=2)
	{
		Pop(S,&X);
		PieceCreate(&P,X.type,X.turn,X.xt,X.yt);
		UndoBoardPieceMove(&P,&B,X);
		if (X.specialmove != 'C')
		{
			i++;
		}
	}
}
