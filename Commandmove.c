#include <stdio.h>
#include <stdlib.h>
#include "commandmove.h"
#include "kamus.h"


void move(Stack *S, char team, arr_possible_move *T, board bb){
    int i;
    int j;
    int k;
    int l;
    piece_choice Pilihan;
    piece piecepilihan;

    
    generate_valid_move(T); // Traversal mengakses satu' bidak di arr_possible_move


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


    

    printf("Bidak %c telah berpindah dari (%d,%d) ke(%d,%d)\n"/*Awal posisi,akhirpoisii dari stack move_history*/);
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







