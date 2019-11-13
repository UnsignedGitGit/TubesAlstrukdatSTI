//ASUMSI:
// -array of movement elemennya punya 2 atribut: list of possible move (limo) dan piece
// -insVfirst, alokasi X nya udh sizeof koordinat 


/*DEKLARASI TIPE BENTUKAN*/
typedef struct {
	int x;
	int y;
	} koordinat;


/*PROTOTIPE*/
void raja(array_of_movement* M, piece P, board B, char giliran);
void add_coor_valid(array_of_movement* M, int x, int y, board B, piece P, char giliran);
void add_to_list_posmove(array_of_movement* M, piece P, int x, int y);


/*IMPLEMENTASI*/
void raja(array_of_movement* M, piece P, board B, char giliran) {
	/*KAMUS*/
	/*ALGORITMA*/
	add_coor_valid(&M, P.xpos, P.ypos+1, B, P, giliran);
	add_coor_valid(&M, P.xpos+1, P.ypos, B, P, giliran);
	add_coor_valid(&M, P.xpos, P.ypos-1, B, P, giliran);
	add_coor_valid(&M, P.xpos-1, P.ypos, B, P, giliran);
	
	add_coor_valid(&M, P.xpos+1 , P.ypos+1, B, P, giliran);
	add_coor_valid(&M, P.xpos+1 , P.ypos-1, B, P, giliran);
	add_coor_valid(&M, P.xpos-1, P.ypos-1, B, P, giliran);
	add_coor_valid(&M, P.xpos-1, P.ypos+1, B, P, giliran);
}

void add_coor_valid(array_of_movement* M, int x, int y, board B, piece P, char giliran) {
	/*KAMUS*/
	/*ALGORITMA*/
	
	/*Cek koordinat tujuan ada di luar papan atau tidak*/
	if (PieceIsValidMove(x, y)) {
		
			/* jika bidak di posisi tujuan adalah bidak lawan atau kosong
			 * , koordinat tujuan valid dan dapat ditambahkan ke list-of-
			 * possible-moves bidak tersebut*/
			if (B.boardCell[x][y].cellPiece.team != giliran) {
				add_to_list_posmove(&(M.list_of_possible_move), P, x, y);
			}
			
	}
}

void add_to_list_posmove(array_of_movement* M, piece P, int x, int y) {
	/*KAMUS*/
	int i;
	koordinat k;
	/*ALGORITMA*/
	
	/*Mencari bidak yang ingin diakses list-of-possible-movenya*/
	i = 0;
	while ((M[i].piece.xpos != P.xpos) && (M[i].piece.ypos != P.ypos)) {
		i++;
	}
	
	/*Menambahkan koordinat ke list-of-possible-movenya*/
	k.x = x;
	k.y = y;
	InsVLast (&(M[i].limo), k);
}
