#include <stdio.h>
#include <stdlib.h>
#include "leaderboard.h"
#include <string.h>


// Instruksi kompilasi driver gcc -o leaderboarddriver leaderboarddriver.c leaderboard.c 

int main(){
    leaderboards boardganteng;
    char contoh[4];
    int contohskor;
    
    printf("Prosedur createdefault akan dipanggil\n ");
    createdefault(&boardganteng);
    printf("Setelah prosedur dipanggil dan dieksekusi, nilai Neff leaderboards akan menjadi default yaitu %d\n",boardganteng.neff);
    printf("Contoh hasil dari data dummy yaitu data pertama yang berisi nama default %s dan skor default %s\n",boardganteng.info[1].name,boardganteng.info[1].score);

    printf("Setelah ini, akan dimasukkan pasangan skor dan nama yang tidak terurut secara manual ke leaderboard\n");
    strcpy(boardganteng.info[3].name,"Coy");
    boardganteng.info[3].score = 30;

    printf("Hasil masukkan yang tidak terurut akan di tamplikan dengan prosedur printleaderboard\n");
    printleaderboard(boardganteng);


    printf("selanjutnya, isi leaderboard akan diurutkan berdasarkan skor secara menurun dengan fungsi sortLB\n");
    sortLB(&boardganteng);
    printleaderboard(boardganteng);

    printf("Terakhir, apabila pengguna ingin memasukkan input secara terurut, gunakan prosedur inputleaderboard\n");
    printf(" Contoh data yang dimasukkan secara terurut adalah User Bernama Adi dengan skor 50\n");
    strcpy(contoh,"Adi");
    contohskor = 50;

    inputleaderboard(&boardganteng,contoh,contohskor);
    printf("Hasil Update leaderboard dengan input yang diatur terurut\n");
    printleaderboard(boardganteng);

    

}