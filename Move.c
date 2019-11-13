

#include <stdio.h>
#include <stdlib.h>


void move(char team, Stack *S){
    int i;
    int j;
    int k;
    
    piece Pilihan[16];
    Piece piecepilihan

    if (team = 'B'){
        generate_valid_move(&Hitam); // Traversal mengakses satu' bidak
        
    }
    else{
        generate_valid_move(&Putih); // Traversal mengakses satu' bidak
        
    }
    printf("Daftar bidak yang bisa bergerak:\n")
    if (team = 'B'){
        show_movable_piece(Hitam, &Pilihan);  
    }
    else{
        show_movable_piece(Putih, &Pilihan);   
    }
    

    printf("Pilih bidak yang ingin digerakan:");
    scanf("%d",&j);   // Input nomor bidak yang dipilih pengguna untuk digerakkan

    piecepilihan = Pilihan[j-1];
    printf("Daftar posisi tujuan yang mungkin:\n");
    show_list_pmove(piecepilihan);
    

    printf("Pilih posisi tujuan bidak: ");
    scanf("%d",&k); // Input nomor posisi yang dipilih pengguna untuk dituju


    if (team = 'B'){
        do_move(piecepilihan,boardkece,move_history,Hitam,k-1);
    }
    else{
        do_move(piecepilihan,boardkece,move_history,Putih,k-1);   
    }

    printf("Bidak %c telah berpindah dari (%d,%d) ke(%d,%d)\n",piecepilihan.Type,/*Awal posisi,akhirpoisii dari stack move_history*/);
}

void generate_valid_move(/*Elemen array of possible move team*/); // Edit setelah Hardy udah tentuin nama tipe
//di dalam prosedur ini akan dilakukan traversal seluruh elemen array team tersebut
//Elemen yang sudah mati masih diproses

void show_movable_piece(/*Array of piece pilihan sebagai masukan*/){
    int i;
    
    for (i=0;i<=NbElmt-1;i++){
        
        if(Pilihan[i].Type == 'P'){
        printf("    %d. Pion (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }
        else if(Pilihan[i].Piece.Type == 'Q'){
        printf("    %d. Ratu (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }
        else if(Pilihan[i].Piece.Type == 'K'){
        printf("    %d. Raja (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }
        else if(Pilihan[i].Piece.Type == 'H'){
        printf("    %d. Kuda (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }
        else if(Pilihan[i].Piece.Type == 'R'){
        printf("    %d. Benteng (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }
        else if(Pilihan[i].Piece.Type == 'B'){
        printf("    %d. Menteri (%d,%d)",i+1,translatex(Pilihan[i].Piece.xpos),Pilihan[i].Piece.ypos)
        }

    }
}

void special_move()





