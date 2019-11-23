// NAMA : Adriel Gustino P 
// NIM : 18218047

#include "Undo.h"


void UndoBoardPieceMove(arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X)
// Mengubah posisi piece P di board
// I.S. Piece P terdefinisi, x dan y berada pada [1..8]
// F.S. P berpindah ke posisi x dan y di board
{
	//KAMUS
	piece emptypiece, Q;
	int i;
	
	//ALGORITMA
	BoardCell(*B)[X.x0][X.y0] = *P;

	if (X.targettype == CharNil) // Jika gerakan yang dicatat X adalah gerakan pindah tanpa memakan
	{
		PieceCreateEmpty(&emptypiece, X.xt, X.yt);
		BoardCell(*B)[X.xt][X.yt] = emptypiece;
	}
	else // Jika gerakan yang dicatat X adalah gerakan memakan
	{
		if (X.turn == 'W')
		{	
			PieceCreate(&Q, X.targettype, 'B', X.xt, X.yt);
			BoardCell(*B)[X.xt][X.yt] = Q;
			
			i = findPieceIdx(*black, Q);
			(*black).arr[i].p.isdead = false;
		}
		else if (X.turn == 'B')
		{	
			PieceCreate(&Q,X.targettype, 'W', X.xt, X.yt);
			BoardCell(*B)[X.xt][X.yt] = Q;
			
			i = findPieceIdx(*white, Q);
			(*white).arr[i].p.isdead = false;
		}
	}
}

void UndoEnpassan (arr_possible_move* white, arr_possible_move* black, piece *P,  board *B, Sinfotype X)
{
	//KAMUS
	piece emptypiece, Q;
	int i;
	
	//ALGORITMA
	BoardCell(*B)[X.x0][X.y0] = *P;
	if (X.turn == 'W')
	{	
		PieceCreateEmpty(&emptypiece, X.xt, X.yt);
		BoardCell(*B)[X.xt][X.yt] = emptypiece;

		PieceCreate(&Q, 'p', 'B', X.xt, X.yt - 1);
		BoardCell(*B)[X.xt][X.yt-1] = Q;
		
		i = findPieceIdx(*black, Q);
		(*black).arr[i].p.isdead = false;
	}
	else if (X.turn == 'B')
	{	
		PieceCreateEmpty(&emptypiece, X.xt, X.yt);
		BoardCell(*B)[X.xt][X.yt] = emptypiece;

		PieceCreate(&Q, 'P', 'W', X.xt, X.yt + 1);
		BoardCell(*B)[X.xt][X.yt+1] = Q;
		
		i = findPieceIdx(*white, Q);
		(*white).arr[i].p.isdead = false;
	}
}

void Undo (arr_possible_move* white, arr_possible_move* black, Stack *S, board* B)
{
	// KAMUS
	Sinfotype X;
	piece P, finder;
	int i, iterator;

	// ALGORITMA
	printf("Gerakan sampai giliran sebelumnya berhasil dibatalkan.\n");
	
	iterator=1;
	while (iterator <= 2) {
		Pop(S, &X);
		
		if (X.specialmove == 'C')
		{
			//Mengembalikan info piece di array-of-possible-move ke kondisi sebelum gerakan X terjadi 
			PieceCreate(&finder, X.type, X.turn, X.xt, X.yt);
			if (X.turn == 'W')
			{	
				i = findPieceIdx(*white, finder);
				(*white).arr[i].p.xpos = X.x0;
				(*white).arr[i].p.ypos = X.y0;
			}
			else if (X.turn == 'B')
			{
				i = findPieceIdx(*black, finder);
				(*black).arr[i].p.xpos = X.x0;
				(*black).arr[i].p.ypos = X.y0;
			}
			
			//Pengembalian posisi piece di papan
			PieceCreate(&P, X.type, X.turn, X.x0, X.y0);
			UndoBoardPieceMove(white, black, &P, B, X);

			Pop(S, &X);
			//Mengembalikan info piece di array-of-possible-move ke kondisi sebelum gerakan X terjadi 
			PieceCreate(&finder, X.type, X.turn, X.xt, X.yt);
			if (X.turn == 'W')
			{	
				i = findPieceIdx(*white, finder);
				(*white).arr[i].p.xpos = X.x0;
				(*white).arr[i].p.ypos = X.y0;
			}
			else if (X.turn == 'B')
			{
				i = findPieceIdx(*black, finder);
				(*black).arr[i].p.xpos = X.x0;
				(*black).arr[i].p.ypos = X.y0;
			}
			
			//Pengembalian posisi piece di papan
			PieceCreate(&P, X.type, X.turn, X.x0, X.y0);
			UndoBoardPieceMove(white, black, &P, B, X);
		}

		else if (X.specialmove == 'E')
		{
			//Mengembalikan info piece di array-of-possible-move ke kondisi sebelum gerakan X terjadi 
			PieceCreate(&finder, X.type, X.turn, X.xt, X.yt);
			if (X.turn == 'W')
			{	
				i = findPieceIdx(*white, finder);
				(*white).arr[i].p.xpos = X.x0;
				(*white).arr[i].p.ypos = X.y0;
			}
			else if (X.turn == 'B')
			{
				i = findPieceIdx(*black, finder);
				(*black).arr[i].p.xpos = X.x0;
				(*black).arr[i].p.ypos = X.y0;
			}

			//Pengembalian posisi piece di papan
			PieceCreate(&P, X.type, X.turn, X.x0, X.y0);
			UndoEnpassan(white, black, &P, B, X);
		}

		else if (X.specialmove == 'N')
		{
			
			//Mengembalikan info piece di array-of-possible-move ke kondisi sebelum gerakan X terjadi 
			PieceCreate(&finder, X.type, X.turn, X.xt, X.yt);
			if (X.turn == 'W')
			{	
				i = findPieceIdx(*white, finder);
				(*white).arr[i].p.xpos = X.x0;
				(*white).arr[i].p.ypos = X.y0;
			}
			else if (X.turn == 'B')
			{
				i = findPieceIdx(*black, finder);
				(*black).arr[i].p.xpos = X.x0;
				(*black).arr[i].p.ypos = X.y0;
			}
			
			//Pengembalian posisi piece di papan
			PieceCreate(&P, X.type, X.turn, X.x0, X.y0);
			UndoBoardPieceMove(white, black, &P, B, X);
		}

		else if (X.specialmove == 'P')
		{
			PieceCreate(&finder, X.type, X.turn, X.xt, X.yt);
			if (X.turn == 'W')
			{	
				i = findPieceIdx(*white, finder);
				(*white).arr[i].p.xpos = X.x0;
				(*white).arr[i].p.ypos = X.y0;
				PieceCreate(&P, 'P', X.turn, X.x0, X.y0);
			}
			else if (X.turn == 'B')
			{
				i = findPieceIdx(*black, finder);
				(*black).arr[i].p.xpos = X.x0;
				(*black).arr[i].p.ypos = X.y0;
				PieceCreate(&P, 'p', X.turn, X.x0, X.y0);
			}
			
			UndoBoardPieceMove(white, black, &P, B, X);
		}

		iterator++;
	}
}