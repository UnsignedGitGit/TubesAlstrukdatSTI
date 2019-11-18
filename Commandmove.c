#include <stdio.h>
#include <stdlib.h>
#include "commandmove.h"
#include "kamus.h"




/*IMPLEMENTASI*/
void king(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak raja tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */

{	
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);

	addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+1, P.ypos, B, T);
	addValidCoor(M, i, P.xpos, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos, B, T);
	
	addValidCoor(M, i, P.xpos+1 , P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+1 , P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-1, P.ypos+1, B, T);
}

void horse(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak kuda tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{	
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);
	
	addValidCoor(M, i, P.xpos-1, P.ypos+2, B, T);
	addValidCoor(M, i, P.xpos+1, P.ypos+2, B, T);
	addValidCoor(M, i, P.xpos+2, P.ypos+1, B, T);
	addValidCoor(M, i, P.xpos+2, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos+1 , P.ypos-2, B, T);
	addValidCoor(M, i, P.xpos-1 , P.ypos-2, B, T);
	addValidCoor(M, i, P.xpos-2, P.ypos-1, B, T);
	addValidCoor(M, i, P.xpos-2, P.ypos+1, B, T);
}
void pawn(arr_possible_move* M, piece P, board B, char T)
/* I.S. M, P, B, dan T terdefinisi. List possmove di M kosong */
/* F.S. Di dalam array-possible-move (M), list-of-possible-move piece P 
 * 		(bidak pion tim putih atau hitam) berisi semua alamat kotak
 *  	yang dapat dituju piece P */
{
	/*KAMUS*/
	int i;
	Linfotype k;
	
	/*ALGORITMA*/
	i = findPieceIdx(*M, P);
	

	if (T == 'W'){ 
        if (P.hasmoved) {
	    	addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
	    } else {
	    	addValidCoor(M, i, P.xpos, P.ypos+1, B, T);
	    	addValidCoor(M, i, P.xpos, P.ypos+2, B, T);
	    }
    
	    /* Mengecek alamat kotak di depan kiri dan depan kanan. Jika ada 
	     * bidak lawan, alamat kotak tersebut akan ditambahkan
	     * ke list-of-possible-move */
    
	    if (PieceIsValidMove(P.xpos+1, P.ypos+1)) {
	    	if (B.boardCell[P.xpos+1][P.ypos+1].team != T) {
	    		k.x = P.xpos+1;
	    		k.y = P.ypos+1;
	    		InsVLast (&(*M).arr[i].possmove, k);
	    	}
	    }
    
	    if (PieceIsValidMove(P.xpos-1, P.ypos+1)) {
	    	if (B.boardCell[P.xpos-1][P.ypos+1].team != T) {
	    		k.x = P.xpos-1;
	    		k.y = P.ypos+1;
	    		InsVLast (&(*M).arr[i].possmove, k);
	    	}
	    }
    }
    else{
        if (P.hasmoved) {
	    	addValidCoor(M, i, P.xpos, P.ypos-1, B, T);
	    } else {
	    	addValidCoor(M, i, P.xpos, P.ypos-1, B, T);
	    	addValidCoor(M, i, P.xpos, P.ypos-2, B, T);
	    }
    
	    /* Mengecek alamat kotak di depan kiri dan depan kanan. Jika ada 
	     * bidak lawan, alamat kotak tersebut akan ditambahkan
	     * ke list-of-possible-move */
    
	    if (PieceIsValidMove(P.xpos+1, P.ypos-1)) {
	    	if (B.boardCell[P.xpos+1][P.ypos-1].team != T) {
	    		k.x = P.xpos+1;
	    		k.y = P.ypos-1;
	    		InsVLast (&(*M).arr[i].possmove, k);
	    	}
	    }
    
	    if (PieceIsValidMove(P.xpos-1, P.ypos-1)) {
	    	if (B.boardCell[P.xpos-1][P.ypos-1].team != T) {
	    		k.x = P.xpos-1;
	    		k.y = P.ypos-1;
	    		InsVLast (&(*M).arr[i].possmove, k);
	    	}
	    }
    }
}
void rook(arr_possible_move *M, piece P,board B,char T){
    int i;
    int j;

    i = findPieceIdx (*M,P);

    //kanan
    j = P.xpos + 1;
    while(j<9){
        addValidCoor(M ,i, j, P.ypos, B, T);
        if (!Iscellempty(B,j,P.ypos)){
            break;
        }
        else{
            j++;
        }
    }

    // Kiri
    j = P.xpos-1;
    while(j>0){
        addValidCoor(M ,i, j, P.ypos, B, T);
        if (!Iscellempty(B,j,P.ypos)){
            break;
        }
        else{
            j--;
        }
    }

    // Atas
    j = P.ypos + 1;
    while(j<9){
         addValidCoor(M ,i, P.xpos, j, B, T);
        if (!Iscellempty(B,P.xpos,j)){
            break;
        }
        else{
            j++;
        }
    }
    //Bawah
    j = P.xpos-1;
    while(j>0){
        addValidCoor(M ,i, P.xpos, j, B, T);
        if (!Iscellempty(B,P.xpos,j)){
            break;
        }
        else{
            j--;
        }
    }
}

void bishop(arr_possible_move *M, piece P,board B,char T){
    int i;
    int j;
    int k;

    k = findPieceIdx (*M,P);

    //kanan atas
    i = P.xpos + 1;
    j = P.ypos + 1;
    while(i<9 && j < 9){
        addValidCoor(M ,k , i, j, B, T);
        if (!Iscellempty(B,i,j)){
            break;
        }
        else{    
            i++;
            j++;
        }
    }

    // Kiri atas
    i = P.xpos-1;
    j = P.ypos + 1;
    while(i>0 && j <9){
        addValidCoor(M ,k , i, j, B, T);
        if (!Iscellempty(B,i,j)){
            break;
        }
        else{    
            i--;
            j++;
        }
    }

    // Kiri bawah
    i = P.xpos - 1;
    j = P.ypos -1;
    while(i>0 && j>0){
        addValidCoor(M ,k , i, j, B, T);
        if (!Iscellempty(B,i,j)){
            break;
        }
        else{    
            i--;
            j--;
        }
        
    }
    //Kanan Bawah
    i = P.xpos + 1;
    j = P.ypos - 1;
    while(i<9 && j>0){
        addValidCoor(M ,k , i, j, B, T);
        if (!Iscellempty(B,i,j)){
            break;
        }
        else{    
            i++;
            j--;
        }
    }
}
void queen(arr_possible_move *M, piece P,board B,char T){
    bishop(M,P,B,T);
    rook(M,P,B,T);
}

void addValidCoor(arr_possible_move* M, int idx, int x, int y, board B, char T)
/* I.S. M, x, y, B, P, dan T terdefinisi */
/* F.S. Alamat kotak (x dan y) yang valid akan dimasukkan ke list
 * 		-of-possible-move */
/* Alamat kotak valid jika tidak berada di luar papan dan tidak 
 * sedang ditempati bidak tim sendiri */
{
	/*KAMUS*/
	Linfotype k;
	
	/*ALGORITMA*/
	/*Cek alamat kotak tujuan ada di luar papan atau tidak*/
	if (PieceIsValidMove(x, y)) {
		
		/*Cek ada bidak tim sendiri atau tidak di alamat kotak tujuan */
		if (B.boardCell[x][y].team != T) {
			k.x = x;
			k.y = y;
			InsVLast (&(*M).arr[idx].possmove, k);
		}
	}
}

int findPieceIdx(arr_possible_move M, piece P)
/* Mengembalikan index alamat P di M. */
{
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	i = 0;
	while ((M.arr[i].p.xpos != P.xpos) || (M.arr[i].p.ypos != P.ypos)) {
		i++;
	}
	
	return i;
}

boolean Iscellempty (board B, int x, int y){
    return((B.boardCell[x][y].type == CharNil) && (B.boardCell[x][y].team == CharNil));
}


void doMove(arr_possible_move* player, arr_possible_move* enemy, piece* P, board* B, Stack* S, int choicenb)
/* I.S. P, B, S, choicenb, array player, dan array enemy terdefinisi */
/* F.S. Posisi piece P di papan diperbarui. S berisi catatan gerakan 
 * bidak tersebut. */
{
	/*KAMUS*/
	int i, xtarget, ytarget;
	address coorchoice;
	Sinfotype H;
	
	/*ALGORITMA*/
	i = findPieceIdx(*player, *P);
	
	/*Pencatatan ke stack movement history*/
	H.turn = (*P).team;
	H.type = (*P).type;
	H.x0 = (*P).xpos;
	H.y0 = (*P).ypos;
	H.IsCastling = false;
	
	/* Mencari koordinat kotak tujuan pilihan pemain di 
	 * list-possible-move */
	coorchoice = First((*player).arr[i].possmove);
	for (i=1; i<= choicenb-1; i++) {
		coorchoice =  Next(coorchoice);
	}
	xtarget = (*coorchoice).info.x;
	ytarget = (*coorchoice).info.y;
	
	/*Lanjutan pencatatan stack movement history*/
	H.xt = xtarget;
	H.yt = ytarget;
	H.targettype = BoardCell(*B)[xtarget][ytarget].type;
	
	Push(S, H);
	
	/* Pemindahan piece P di board B. Jika ada bidak lawan, info isdead
	 * bidak lawan di array-possible-move diset menjadi true. */
	if (BoardCell(*B)[xtarget][ytarget].type != CharNil) {
		i = findPieceIdx(*enemy,BoardCell(*B)[xtarget][ytarget]);
		(*enemy).arr[i].p.isdead = true;
	}
	
	BoardPieceMove(P, B, xtarget, ytarget);

	/*Pengubahan info piece P*/
	PieceMove(P, xtarget, ytarget);
}


void move(Stack *S, char team, arr_possible_move *T, board bb){
    int i;
    int j;
    int k;
    int l;
    piece_choice Pilihan;
    piece piecepilihan;

    // Inisialisasi


    // Traversal mengakses satu' bidak di arr_possible_move


    // Mengcopy bidak yang bisa ke array of pilihan
    i = 1;
    j = 1;   
    while(i<17){
        if(((*T).arr[i].p.isdead == false) && ((*T).arr[i].possmove.First != Nil)){
            Pilihan.arrpiece[j] = (*T).arr[i].p;
            j++; 
        }
    }
    
    printf("Daftar bidak yang bisa bergerak:\n");
    show_movable_piece(Pilihan);   
    
    

    printf("Pilih bidak yang ingin digerakan:");
    scanf("%d",&l);   // Input nomor bidak yang dipilih pengguna untuk digerakkan

    piecepilihan = (*T).arr[l].p;
    printf("Daftar posisi tujuan yang mungkin:\n");
    PrintInfo((*T).arr[l].possmove);
    

    printf("Pilih posisi tujuan bidak: ");
    scanf("%d",&k); // Input nomor posisi yang dipilih pengguna untuk dituju


    

    printf("Bidak %c telah berpindah dari (%d,%d) ke(%d,%d)\n");
}




void show_movable_piece(piece_choice pc){
    int i;
    
    for (i=1;i<=pc.neff/*Harus diupdate TNeffnya*/;i++){
        
        if((pc.arrpiece[i].type == 'P') || (pc.arrpiece[i].type == 'p')){
        printf("    %d. Pion (%d,%d)\n",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        else if((pc.arrpiece[i].type == 'Q') || (pc.arrpiece[i].type == 'q')){
        printf("    %d. Ratu (%d,%d)\n",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        else if((pc.arrpiece[i].type == 'K') || (pc.arrpiece[i].type == 'k')){
        printf("    %d. Raja (%d,%d)\n",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        else if((pc.arrpiece[i].type == 'H') || (pc.arrpiece[i].type == 'h')){
        printf("    %d. Kuda (%d,%d)\n",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        else if((pc.arrpiece[i].type == 'B') || (pc.arrpiece[i].type == 'b')){
        printf("    %d. Menteri (%d,%d)\n",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        else if((pc.arrpiece[i].type == 'R') || (pc.arrpiece[i].type == 'r')){
        printf("    %d. Benteng (%d,%d)",i,translatex(pc.arrpiece[i].xpos),pc.arrpiece[i].ypos);
        }
        

    }
}


void generate_valid_move(arr_possible_move *T, board B){
    int i;
    int j;

    for (i=1;i<17;i++){
        if ((*T).arr[i].p.isdead == false){
            if (((*T).arr[i].p.type == 'K') || ((*T).arr[i].p.type == 'K')){
                king(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }
            else if (((*T).arr[i].p.type == 'Q') || ((*T).arr[i].p.type == 'q')){
                queen(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }
            else if (((*T).arr[i].p.type == 'R') || ((*T).arr[i].p.type == 'r')){
                rook(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }
            else if (((*T).arr[i].p.type == 'B') || ((*T).arr[i].p.type == 'b')){
                bishop(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }
            else if (((*T).arr[i].p.type == 'P') || ((*T).arr[i].p.type == 'p')){
                pawn(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }    
            else if (((*T).arr[i].p.type == 'H') || ((*T).arr[i].p.type == 'h')){
                horse(T,(*T).arr[i].p,B,(*T).arr[i].p.team);
            }
        }
    } 
}




