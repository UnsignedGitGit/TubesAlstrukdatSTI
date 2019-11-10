// Realisasi seluruh fungsi pada allfungsi.h


#include <stdio.h>
#include <stdlib.h>
#include "Allfungsi.h"

// Fungsi Pembentuk Tipe
void Makebidak(Bidak *B, char simbol, int tim){
    (*B).Name = simbol;
    (*B).Team = tim;
}



// Pengolahan Array

void initarray(Arrbidak *T){
    int i,j;

    for(i=1;i<9;i++){
        for(j=1;j<9;j++){
            (*T).TabBidak[i][j].Name = ' ';
            (*T).TabBidak[i][j].Team = teamundef;
        }
    }
}


void SetEl (Arrbidak *T, int brow, int bcolumn, Bidak Bx)
{
    (*T).TabBidak[brow][bcolumn] = Bx;
}



void printdisplay(Arrbidak B){
    printf("         A       B       C       D       E       F       G      H    \n");
    printf("     _________________________________________________________________\n");
    for (int i=1;i<=8;i++){
        printf("     |       |       |       |       |       |       |       |       |\n");
        printf("  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",i,B.TabBidak[i][1].Name,B.TabBidak[i][2].Name,B.TabBidak[i][3].Name,B.TabBidak[i][4].Name,B.TabBidak[i][5].Name,B.TabBidak[i][6].Name,B.TabBidak[i][7].Name,B.TabBidak[i][8].Name);
        printf("     |_______|_______|_______|_______|_______|_______|_______|_______|\n");
}




