#include "Commandspecialmove.h"
#include "Commandmove.h"
#include <stdio.h>

/*IMPLEMENTASI*/
void special_move(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char T)
/* I.S. player, enemy, S, B, dan T terdefinisi. */
/* F.S. Special move pilihan pemain dilakukan. Gerakan dilakukan di B dan dicatat di S */
{	
	/*KAMUS*/
	TabChar choice; /* Index yang digunakan [1..4] */

	pawn_enpassant p1;
	pawn_enpassant p2;

	boolean isFCPossible, isNCPossible;

	int i;

	/*ALGORITMA*/
	MakeEmptyArraySpecMove(&choice, 4);

	p1.canEnpassant = false;
	p2.canEnpassant = false;

	EnpassantL(*B, *S, &p1);
	EnpassantR(*B, *S, &p2);

	isFCPossible = canFarCastling(*B, T);
	isNCPossible = canNearCastling(*B, T);

	i = 1;


	if ((isFCPossible) || (isNCPossible) || (p1.canEnpassant) || (p2.canEnpassant)) {
		printf("Daftar gerakan khusus yang bisa dilakukan:\n");

		if (isFCPossible) {
			printf("%d. Castling with farthest rook\n", i);
			choice.T[i] = 'F';
			choice.Neff++;
			i++;
		}

		if (isNCPossible) {
			printf("%d. Castling with nearest rook\n", i);
			choice.T[i] = 'N';
			choice.Neff++;
			i++;
		}
		
		if (p1.canEnpassant) {
			printf("%d. En passant with pawn (%c, %c)\n", i, translatex(p1.x), p1.y);
			choice.T[i] = 'L';
			choice.Neff++;
			i++;
		}
		
		if (p2.canEnpassant) {
			printf("%d. En passant with pawn (%c, %c)\n", i, translatex(p2.x), p2.y);
			choice.T[i] = 'R';
			choice.Neff++;
			i++;

		printf("Pilih gerakan khusus yang ingin dilakukan:");
		scanf("%d\n", &i);

		if (choice.T[i] == 'F')
			DoCastling(white, black, B, S, 'F', T);
		} else if (choice.T[i] == 'N') {
			DoCastling(white, black, B, S, 'N', T);
		} else if (choice.T[i] == 'L') {
			DoEnpassant(white, black, B, S, T, p1);
		} else {
			DoEnpassant(white, black, B, S, T, p2);
		}
	} else {
		printf("Tidak ada gerakan khusus yang bisa dilakukan.\n");
	}
}

void DoCastling(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char id, char T)
/* I.S. white, black, B, S, id, dan T terdefinisi. */
/* F.S. Castling dilakukan di B dan dicatat di S */
{
	/*KAMUS*/
	Sinfotype H;
	int i;
	
	/*ALGORITMA*/

	printf("Castling berhasil dilakukan\n");

	if (T == 'W') {
		if (id == 'F') {
			/*Pencatatan gerakan raja ke stack movement history*/
			H.turn = T;
			H.type = 'K';
			H.x0 = 5;
			H.y0 = 1;
			H.xt = 3;
			H.yt = 1;
			H.targettype = CharNil;
			H.specialmove = 'N';

			Push(S, H);

			/*Pencatatan gerakan benteng ke stack movement history*/
			H.turn = T;
			H.type = 'R';
			H.x0 = 1;
			H.y0 = 1;
			H.xt = 4;
			H.yt = 1;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/* Pembaruan info piece raja di array of possible move. */
			i = findPieceIdx(*white, BoardCell(*B)[5][1]);
			(*white).arr[i].p.xpos = 3;
			(*white).arr[i].p.ypos = 1;

			/* Pembaruan info piece benteng di array of possible move. */
			i = findPieceIdx(*white, BoardCell(*B)[1][1]);
			(*white).arr[i].p.xpos = 4;
			(*white).arr[i].p.ypos = 1;

			/*Pemindahan raja lalu benteng di board B.*/
			BoardPieceMove(&BoardCell(*B)[5][1], B, 3, 1);
			BoardPieceMove(&BoardCell(*B)[1][1], B, 4, 1);

			printf("Bidak Raja telah berpindah dari (e,1) ke (c,1)\n");
			printf("Bidak Benteng telah berpindah dari (a,1) ke (d,1)\n");
			
		} else {
			/*Pencatatan gerakan raja ke stack movement history*/
			H.turn = T;
			H.type = 'K';
			H.x0 = 5;
			H.y0 = 1;
			H.xt = 7;
			H.yt = 1;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/*Pencatatan gerakan benteng ke stack movement history*/
			H.turn = T;
			H.type = 'R';
			H.x0 = 8;
			H.y0 = 1;
			H.xt = 6;
			H.yt = 1;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/* Pembaruan info piece raja di array of possible move. */
			i = findPieceIdx(*white, BoardCell(*B)[5][1]);
			(*white).arr[i].p.xpos = 7;
			(*white).arr[i].p.ypos = 1;

			/* Pembaruan info piece benteng di array of possible move. */
			i = findPieceIdx(*white, BoardCell(*B)[8][1]);
			(*white).arr[i].p.xpos = 6;
			(*white).arr[i].p.ypos = 1;

			/*Pemindahan  lalu raja di board B.*/
			BoardPieceMove(&BoardCell(*B)[5][1], B, 7, 1);
			BoardPieceMove(&BoardCell(*B)[8][1], B, 6, 1);

			printf("Bidak Raja telah berpindah dari (e,1) ke (g,1)\n");
			printf("Bidak Benteng telah berpindah dari (h,1) ke (f,1)\n");
		}

	} else {
		if (id == 'F') {
			/*Pencatatan gerakan raja ke stack movement history*/
			H.turn = T;
			H.type = 'k';
			H.x0 = 5;
			H.y0 = 8;
			H.xt = 3;
			H.yt = 8;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/*Pencatatan gerakan benteng ke stack movement history*/
			H.turn = T;
			H.type = 'r';
			H.x0 = 1;
			H.y0 = 8;
			H.xt = 4;
			H.yt = 8;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/* Pembaruan info piece raja di array of possible move. */
			i = findPieceIdx(*black, BoardCell(*B)[5][8]);
			(*black).arr[i].p.xpos = 3;
			(*black).arr[i].p.ypos = 8;

			/* Pembaruan info piece benteng di array of possible move. */
			i = findPieceIdx(*black, BoardCell(*B)[1][8]);
			(*black).arr[i].p.xpos = 4;
			(*black).arr[i].p.ypos = 8;

			/*Pemindahan raja lalu benteng di board B.*/
			BoardPieceMove(&BoardCell(*B)[5][8], B, 3, 8);
			BoardPieceMove(&BoardCell(*B)[1][8], B, 4, 8);

			printf("Bidak Raja telah berpindah dari (e,8) ke (c,8)\n");
			printf("Bidak Benteng telah berpindah dari (a,8) ke (d,8)\n");
		} else {
			/*Pencatatan gerakan raja ke stack movement history*/
			H.turn = T;
			H.type = 'k';
			H.x0 = 5;
			H.y0 = 8;
			H.xt = 7;
			H.yt = 8;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/*Pencatatan gerakan benteng ke stack movement history*/
			H.turn = T;
			H.type = 'r';
			H.x0 = 8;
			H.y0 = 8;
			H.xt = 6;
			H.yt = 8;
			H.targettype = CharNil;
			H.specialmove = 'C';

			Push(S, H);

			/* Pembaruan info piece raja di array of possible move. */
			i = findPieceIdx(*black, BoardCell(*B)[5][8]);
			(*black).arr[i].p.xpos = 7;
			(*black).arr[i].p.ypos = 8;

			/* Pembaruan info piece benteng di array of possible move. */
			i = findPieceIdx(*black, BoardCell(*B)[8][8]);
			(*black).arr[i].p.xpos = 6;
			(*black).arr[i].p.ypos = 8;

			/*Pemindahan raja lalu benteng di board B.*/
			BoardPieceMove(&BoardCell(*B)[5][8], B, 7, 8);
			BoardPieceMove(&BoardCell(*B)[8][8], B, 6, 8);

			printf("Bidak Raja telah berpindah dari (e,8) ke (g,8)\n");
			printf("Bidak Benteng telah berpindah dari (h,8) ke (f,8)\n");
		}
	}
}

void DoEnpassant(arr_possible_move* white, arr_possible_move* black, board* B, Stack* S, char T, pawn_enpassant p)
/* I.S. white, black, B, S, id, T, dan p terdefinisi. */
/* F.S. En passant dilakukan di B dan dicatat di S */
{
	/*KAMUS*/
	Sinfotype H;
	piece emptypiece;
	int xenemy, yenemy;
	int i;

	/*ALGORITMA*/
	xenemy = (*S).T[(*S).TOP].xt;
	yenemy =(*S).T[(*S).TOP].yt;

	H.turn = T;
	H.x0 = p.x;
	H.y0 = p.y;

	if (T == 'W') {
		H.xt = xenemy;
		H.yt = yenemy+1;
		H.type = 'P';
		H.targettype = 'p';

		/* Pembaruan info pion di array of possible move. Info isdead pion
		 * lawan di array-possible-move diset menjadi true. */

		i = findPieceIdx(*white, BoardCell(*B)[p.x][p.y]);
		(*white).arr[i].p.xpos = H.xt;
		(*white).arr[i].p.ypos = H.yt;

		i = findPieceIdx(*black, BoardCell(*B)[xenemy][yenemy]);
    	(*black).arr[i].p.isdead = true;

	} else {
		H.xt = xenemy;
		H.yt = yenemy-1;
		H.type = 'p';
		H.targettype = 'P';

		/* Pembaruan info pion di array of possible move. Info isdead pion
		 * lawan di array-possible-move diset menjadi true. */

		i = findPieceIdx(*black, BoardCell(*B)[p.x][p.y]);
		(*black).arr[i].p.xpos = H.xt;
		(*black).arr[i].p.ypos = H.yt;

		i = findPieceIdx(*white, BoardCell(*B)[xenemy][yenemy]);
  	  	(*white).arr[i].p.isdead = true;
	}
	
	H.specialmove = 'E';
	Push(S, H);

	printf("En passant berhasil dilakukan\n");
	printf("Bidak Pion telah berpindah dari (%c,%c) ke (%c,%c)\n", translatex(H.x0), H.y0, translatex(H.xt), H.yt);

	/* Pemindahan pion di board B. */
	PieceCreateEmpty(&emptypiece, xenemy, yenemy);
	BoardCell(*B)[xenemy][yenemy] = emptypiece;

	BoardPieceMove(&BoardCell(*B)[H.x0][H.y0], B, H.xt, H.yt);
}

void EnpassantL(board B, Stack S, pawn_enpassant* C)
/* Prosedur ini mengecek keberadaan pion tim sendiri di 
 * alamat (x-1, y). x dan y adalah posisi pion musuh yang 
 * baru saja bergerak maju dua langkah.
 * I.S. B dan S terdefinisi. C sembarang.
 * F.S. Jika en passant dapat dilakukan, alamat pion yang dapat
 * 		melaksanakannya, yaitu (x-1, y), akan disimpan di C. */
{
	/*KAMUS*/
	Sinfotype lastmove;
	char enemyteam;

	/*ALGORITMA*/
	lastmove = S.T[S.TOP];
	if (lastmove.turn == 'B') {
		enemyteam = 'W';
	} else {
		enemyteam = 'B';
	}
	
	if ((lastmove.type == 'P') || (lastmove.type == 'p')) {
		if (PieceIsValidMove(lastmove.xt-1, lastmove.yt)) {
			if (((lastmove.yt - lastmove.y0) == 2) || ((lastmove.yt - lastmove.y0) == (-2))) {
				if ((PieceIsPawn(BoardCell(B)[lastmove.xt-1][lastmove.yt]) && 
				(BoardCell(B)[lastmove.xt-1][lastmove.yt].team == enemyteam))) {
					(*C).x = lastmove.xt-1;
					(*C).y = lastmove.yt;
					(*C).canEnpassant = true;					
				}
			} 
		}
	} 
}

void EnpassantR(board B, Stack S, pawn_enpassant* C)
/* Prosedur ini mengecek keberadaan pion tim sendiri di 
 * alamat (x+1, y). x dan y adalah posisi pion musuh yang 
 * baru saja bergerak maju dua langkah.
 * I.S. B dan S terdefinisi. C sembarang.
 * F.S. Jika en passant dapat dilakukan, alamat pion yang dapat
 * 		melaksanakannya, yaitu (x+1, y), akan disimpan di C. */
{
	/*KAMUS*/
	Sinfotype lastmove;
	char enemyteam;

	/*ALGORITMA*/
	lastmove = S.T[S.TOP];
	if (lastmove.turn == 'B') {
		enemyteam = 'W';
	} else {
		enemyteam = 'B';
	}
	
	if ((lastmove.type == 'P') || (lastmove.type == 'p')) {
		if (PieceIsValidMove(lastmove.xt+1, lastmove.yt)) {
			if (((lastmove.yt - lastmove.y0) == 2) || ((lastmove.yt - lastmove.y0) == (-2))) {
				if ((PieceIsPawn(BoardCell(B)[lastmove.xt+1][lastmove.yt])) && 
				((BoardCell(B)[lastmove.xt+1][lastmove.yt].team) == enemyteam)) {
					(*C).x = lastmove.xt+1;
					(*C).y = lastmove.yt;
					(*C).canEnpassant = true;					
				}
			}
		}
	}
}

boolean canNearCastling(board B, char T)
/* Castling ini melibatkan:
 * - raja di (e,1) dan benteng di (h,1) untuk tim putih atau
 * - raja di (e,8) dan benteng (h,8) untuk tim hitam.
 * Menghasilkan nilai true jika semua syarat Castling terpenuhi.*/
{
	/*ALGORITMA*/
	if (T == 'W') {
		if ((PieceIsKing(BoardCell(B)[5][1])) && (BoardCell(B)[5][1].team == 'W') && (!BoardCell(B)[5][1].hasmoved)) {
			if ((PieceIsRook(BoardCell(B)[8][1])) && (BoardCell(B)[8][1].team == 'W') && (!BoardCell(B)[8][1].hasmoved)) {
				if (isRightEmpty(B, BoardCell(B)[5][1])) {
					return (
					(!isCellAttacked(B, 5, 1, T)) &&
					(!isCellAttacked(B, 6, 1, T)) &&
					(!isCellAttacked(B, 7, 1, T))
					);
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		if ((PieceIsKing(BoardCell(B)[5][8])) && (BoardCell(B)[5][8].team == 'B') && (!BoardCell(B)[5][8].hasmoved)) {
			if ((PieceIsRook(BoardCell(B)[8][8])) && (BoardCell(B)[8][1].team == 'B') && (!BoardCell(B)[8][8].hasmoved)) {
				if (isRightEmpty(B, BoardCell(B)[5][8])) {
					return (
					(!isCellAttacked(B, 5, 8, T)) &&
					(!isCellAttacked(B, 6, 8, T)) &&
					(!isCellAttacked(B, 7, 8, T))
					);
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
}

boolean canFarCastling(board B, char T)
/* Castling ini melibatkan:
 * - raja di (e,1) dan benteng di (a,1) untuk tim putih atau
 * - raja di (e,8) dan benteng (a,8) untuk tim hitam.
 * Menghasilkan nilai true jika semua syarat Castling terpenuhi.*/
{
	/*ALGORITMA*/
	if (T == 'W') {
		if ((PieceIsKing(BoardCell(B)[5][1])) && (BoardCell(B)[5][1].team == 'W') && (!BoardCell(B)[5][1].hasmoved)) {
			if ((PieceIsRook(BoardCell(B)[1][1])) && (BoardCell(B)[1][1].team == 'W') && (!BoardCell(B)[1][1].hasmoved)) {
				if (isRightEmpty(B, BoardCell(B)[5][1])) {
					return (
					(!isCellAttacked(B, 5, 1, T)) &&
					(!isCellAttacked(B, 4, 1, T)) &&
					(!isCellAttacked(B, 3, 1, T))
					);
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		if ((PieceIsKing(BoardCell(B)[5][8])) && (BoardCell(B)[5][8].team == 'B') && (!BoardCell(B)[5][8].hasmoved)) {
			if ((PieceIsRook(BoardCell(B)[1][8])) && (BoardCell(B)[1][8].team == 'B') && (!BoardCell(B)[1][8].hasmoved)) {
				if (isRightEmpty(B, BoardCell(B)[5][8])) {
					return (
					(!isCellAttacked(B, 5, 8, T)) &&
					(!isCellAttacked(B, 4, 8, T)) &&
					(!isCellAttacked(B, 3, 8, T))
					);
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
}

boolean isLeftEmpty(board B, piece k)
/* Menghasilkan true jika kotak-kotak di antara kedua bidak berikut kosong.
 * - raja di (e,1) dan benteng di (a,1) untuk tim putih atau 
 * - raja di (e,8) dan benteng (a,8) untuk tim hitam. */
{
	/*ALGORITMA*/
	return (
	(BoardCell(B)[k.xpos-1][k.ypos].type == CharNil) &&
	(BoardCell(B)[k.xpos-2][k.ypos].type == CharNil) &&
	(BoardCell(B)[k.xpos-3][k.ypos].type == CharNil)
	);
}

boolean isRightEmpty(board B, piece k)
/* Menghasilkan true jika kotak-kotak di antara kedua bidak berikut kosong.
 * - raja di (e,1) dan benteng di (h,1) untuk tim putih atau 
 * - raja di (e,8) dan benteng (h,8) untuk tim hitam.
 */
{
	/*ALGORITMA*/
	return (
	(BoardCell(B)[k.xpos+1][k.ypos].type == CharNil) &&
	(BoardCell(B)[k.xpos+2][k.ypos].type == CharNil)
	);
}

boolean isCellAttacked(board B, int x, int y, char T)
/* Menghasilkan true jika kotak beralamat (x,y) sedang diserang.*/
{
	/*KAMUS*/
	char enemyteam;
	int i;
	
	/*ALGORITMA*/
	if (T == 'B') {
		enemyteam = 'W';
	} else {
		enemyteam = 'B';
	}
	
	i = 1;
	while (!hasAttacker(B, i, enemyteam, T, x, y)) {
		i++;
	}
	return (i != 19);
	
}

boolean hasAttacker(board B, int iterator, char enemyteam, char team, int x, int y)
/* Menghasilkan true jika (x,y) memenuhi kondisi ke-'interator'.*/
{
	/*KAMUS*/
	int cek, xcek, ycek;
	
	/*ALGORITMA*/
	switch (iterator) {
    case 1:
		//Cek keberadaan ratu atau benteng lawan di arah atas
		cek = y + 1;
		while(cek < 9){
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				cek++;
			}
		}
		return ((cek < 9) && 
		(BoardCell(B)[x][y].team == enemyteam) && 
		(PieceIsQueen(BoardCell(B)[x][y]) || PieceIsRook(BoardCell(B)[x][y])));
        break;

    case 2:
		//Cek keberadaan ratu atau benteng lawan di arah kanan
		cek = x + 1;
		while(cek < 9) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				cek++;
			}
		}
        return (cek < 9) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsRook(BoardCell(B)[x][y]));
        break;

    case 3:
		//Cek keberadaan ratu atau benteng lawan di arah bawah
		cek = y - 1;
		while(cek > 0) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				cek--;
			}
		}
        return (cek > 0) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsRook(BoardCell(B)[x][y]));
        break;

    case 4:
		//Cek keberadaan ratu atau benteng lawan di arah kiri
		cek = x - 1;
		while(cek > 0) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				cek--;
			}
		}
        return (cek > 0) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsRook(BoardCell(B)[x][y]));
        break;

    case 5:
		//Cek keberadaan ratu atau menteri lawan di arah diagonal kanan atas
		xcek = x + 1;
		ycek = y + 1;
		while (xcek < 9) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				xcek++;
				ycek++;
			}
		}
        return (xcek < 9) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsBishop(BoardCell(B)[x][y]));
        break;

    case 6:
		//Cek keberadaan ratu atau menteri lawan di arah diagonal kanan bawah
		xcek = x + 1;
		ycek = y - 1;
		while (xcek < 9) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				xcek++;
				ycek--;
			}
		}
        return (xcek < 9) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsBishop(BoardCell(B)[x][y]));
        break;

    case 7:
		//Cek keberadaan ratu atau menteri lawan di arah diagonal kiri bawah
		xcek = x - 1;
		ycek = y - 1;
		while (xcek > 0) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				xcek--;
				ycek--;
			}
		}
        return (xcek > 0) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsBishop(BoardCell(B)[x][y]));
        break;

    case 8:
		//Cek keberadaan ratu atau menteri lawan di arah diagonal kiri atas
		xcek = x - 1;
		ycek = y + 1;
		while (xcek > 0) {
			if (BoardCell(B)[x][y].team != CharNil) {
				break;
			} else {
				xcek--;
				ycek++;
			}
		}
        return (xcek > 0) && (BoardCell(B)[x][y].team == enemyteam) && (PieceIsQueen(BoardCell(B)[x][y]) || PieceIsBishop(BoardCell(B)[x][y]));
        break;
    
    case 9:
		//Cek keberadaan kuda lawan di (x+1,y+2)
        return (
			(PieceIsValidMove(x+1, y+2)) &&
			(BoardCell(B)[x+1][y+2].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x+1][y+2]))
        );
        break;
    
    case 10:
		//Cek keberadaan kuda lawan di (x+2,y+1)
        return (
			(PieceIsValidMove(x+2, y+1)) &&
			(BoardCell(B)[x+2][y+1].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x+2][y+1]))
        );
        break;
    
    case 11:
		//Cek keberadaan kuda lawan di (x+2,y-1)
        return (
			(PieceIsValidMove(x+2, y-1)) &&
			(BoardCell(B)[x+1][y+2].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x+2][y-1]))
        );
        break;
    
    case 12:
		//Cek keberadaan kuda lawan di (x+1,y-2)
        return (
			(PieceIsValidMove(x+1, y-2)) &&
			(BoardCell(B)[x+1][y+2].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x+1][y+2]))
        );
        break;
    
    case 13:
		//Cek keberadaan kuda lawan di (x-1,y-2)
        return (
			(PieceIsValidMove(x-1, y-2)) &&
			(BoardCell(B)[x-1][y-2].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x-1][y-2]))
        );
        break;
    
    case 14:
		//Cek keberadaan kuda lawan di (x-2,y-1)
        return (
			(PieceIsValidMove(x-2, y-1)) &&
			(BoardCell(B)[x-2][y-1].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x-2][y-1]))
        );
        break;
    
    case 15:
		//Cek keberadaan kuda lawan di (x-2,y+1)
        return (
			(PieceIsValidMove(x-2, y+1)) &&
			(BoardCell(B)[x-2][y+1].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x-2][y+1]))
        );
        break;
    
    case 16:
		//Cek keberadaan kuda lawan di (x-1,y+2)
        return (
			(PieceIsValidMove(x-1, y+2)) &&
			(BoardCell(B)[x-1][y+2].team == enemyteam) && 
			(PieceIsKnight(BoardCell(B)[x-1][y+2]))
        );
        break;
    
    case 17:
		//Cek keberadaan pion lawan
		if (enemyteam == 'B') {
			return ((
				(PieceIsValidMove(x+1, y+1)) &&
				(BoardCell(B)[x+1][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x+1][y+1]))
			) || (
				(PieceIsValidMove(x-1, y+1)) &&
				(BoardCell(B)[x-1][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x-1][y+1]))
			));
		} else {
			return ((
				(PieceIsValidMove(x+1, y-1)) &&
				(BoardCell(B)[x+1][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x+1][y+1]))
			) || (
				(PieceIsValidMove(x-1, y-1)) &&
				(BoardCell(B)[x-1][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x-1][y+1]))
			));
		}
        break;
    
    case 18:
		//Cek keberadaan raja lawan
		return ((
				(PieceIsValidMove(x, y+1)) &&
				(BoardCell(B)[x][y+1].team == enemyteam) && 
				(PieceIsKing(BoardCell(B)[x][y+1]))
			) || (
				(PieceIsValidMove(x+1, y+1)) &&
				(BoardCell(B)[x+1][y+1].team == enemyteam) && 
				(PieceIsKing(BoardCell(B)[x+1][y+1]))
			) || (
				(PieceIsValidMove(x+1, y)) &&
				(BoardCell(B)[x+1][y].team == enemyteam) && 
				(PieceIsKing(BoardCell(B)[x+1][y]))
			) || (
				(PieceIsValidMove(x+1, y-1)) &&
				(BoardCell(B)[x+1][y-1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x+1][y-1]))
			) || (
				(PieceIsValidMove(x, y-1)) &&
				(BoardCell(B)[x][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x][y+1]))
			) || (
				(PieceIsValidMove(x-1, y-1)) &&
				(BoardCell(B)[x-1][y-1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x-1][y-1]))
			) || (
				(PieceIsValidMove(x-1, y)) &&
				(BoardCell(B)[x-1][y].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x-1][y]))
			) || (
				(PieceIsValidMove(x-1, y+1)) &&
				(BoardCell(B)[x-1][y+1].team == enemyteam) && 
				(PieceIsPawn(BoardCell(B)[x-1][y+1]))
			));
        break;

    default:
        return true;
        break;
    }
}

/* boolean isCheckmate(board B, int kingxpos, int kingypos, char T) {
	arr_check threat;

	if (isCellAttacked(B, kingxpos, kingypos, T)) {
		if (isCellAttacked(B, kingxpos, kingypos+1, T) && 
		isCellAttacked(B, kingxpos+1, kingypos+1, T) &&
		isCellAttacked(B, kingxpos+1, kingypos, T) &&
		isCellAttacked(B, kingxpos+1, kingypos-1, T) &&
		isCellAttacked(B, kingxpos, kingypos-1, T) &&
		isCellAttacked(B, kingxpos-1, kingypos-1, T) &&
		isCellAttacked(B, kingxpos-1, kingypos, T) &&
		isCellAttacked(B, kingxpos-1, kingypos+1, T)) {
			if 
		}
	} else {
		return false;
	}
}

void generateThreatLane(board B, arr_check* C, piece attacker, piece king) {
	int i, x, y;

	i=1;
	(*C).arrcheck[i].x = attacker.xpos;
	(*C).arrcheck[i].y = attacker.ypos;
	(*C).neff = 1;

	if (!PieceIsKnight(attacker) && (!PieceIsKing(attacker)) && (!PieceIsPawn(attacker))) {
		if ((king.xpos > attacker.xpos) && (king.ypos > attacker.ypos)) {
			x = attacker.xpos + 1;
			y = attacker.ypos + 1;
			
			while(x < 9) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x++;
					y++;
				}
			}
		} else if ((king.xpos < attacker.xpos) && (king.ypos > attacker.ypos)) {
			x = attacker.xpos - 1;
			y = attacker.ypos + 1;
			
			while(x > 0) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x--;
					y++;
				}
			}
		}  else if ((king.xpos < attacker.xpos) && (king.ypos < attacker.ypos)) {
			x = attacker.xpos - 1;
			y = attacker.ypos - 1;
			
			while(x > 0) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x--;
					y--;
				}
			}
		}  else if ((king.xpos > attacker.xpos) && (king.ypos < attacker.ypos)) {
			x = attacker.xpos + 1;
			y = attacker.ypos - 1;
			
			while(x < 9) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x++;
					y--;
				}
			}
		}  else if ((king.xpos > attacker.xpos) && (king.ypos = attacker.ypos)) {
			x = attacker.xpos + 1;
			y = attacker.ypos;
			
			while(x < 9) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x++;
				}
			}
		}  else if ((king.xpos = attacker.xpos) && (king.ypos > attacker.ypos)) {
			x = attacker.xpos;
			y = attacker.ypos + 1;
			
			while(y < 9) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					y++;
				}
			}
		}  else if ((king.xpos < attacker.xpos) && (king.ypos = attacker.xpos)) {
			x = attacker.xpos - 1;
			y = attacker.ypos;
			
			while(x > 0) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					x--;
				}
			}
		}  else if ((king.xpos = attacker.xpos) && (king.ypos < attacker.xpos)) {
			x = attacker.xpos;
			y = attacker.ypos - 1;
			
			while(y > 0) {
				if (PieceIsKing(BoardCell(B)[x][y])) {
					break;
				} else {
					(*C).arrcheck[(*C).neff + 1].x = attacker.xpos;
					(*C).arrcheck[(*C).neff + 1].y = attacker.ypos;
					(*C).neff++;
					y--;
				}
			}
		}




	}
}

boolean canDisrupt(board B, arr_check C, arr_possible_move white, arr_possible_move black, char T) {
	int i;
	char enemyteam;

	if (T == 'B') {
		enemyteam = 'W';
	} else {
		enemyteam = 'B';
	}

	i = 1;
	while (i <= C.neff) {
		if (isCellAttacked(B, C.arrcheck[i].x, C.arrcheck[i].y, enemyteam)) {

		}
	}
} */