// Semua primitif fungsi dimasukin aja ke sini, termasuk funsgi + prosedur ADT


#ifndef ALLFUNGSI_H 
#define ALLFUNGSI_H

#define true 1
#define false 0
#define boolean unsigned char



#include <stdlib.h>

#define chessrow 9
#define chesscolumn 9
#define teamundef 3

typedef struct{
    int Team; //Bidaknya miliki tim siapa, 1 atau 2 terserah
    char Name; //Berisi character nama bidak, 1 huruf
}Bidak;

// Misalnya, Queen hitam, Teamnya =1, Namenya "Q"

typedef struct {
    Bidak TabBidak [chessrow][chesscolumn];
}Arrbidak;
// Array of bidak


//Fungsi Fungsi dan prosedur





//Pengolah Tipe
void Makebidak(Bidak *B, char simbool, int tim);



// Pengolah Array
void SetEl (Arrbidak *T, int row, int column, Bidak Bx);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-row dan column bernilai bidak */
/* Mengeset nilai elemen tabel yang ke-row dan column sehingga bernilai Bx yang bertipe Bidak */

void initarray(Arrbidak *T);
// Inisialisasi agar array semua nilainya null

void printdisplay(Arrbidak B);
// Menampilkan Board, masukannya Array of Bidak




#endif