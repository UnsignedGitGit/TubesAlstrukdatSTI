#include <stdio.h>
#include <stdlib.h>
#include "../Game/leaderboard.h"
#include <string.h>


// Instruksi kompilasi driver gcc -o leaderboarddriver leaderboarddriver.c leaderboard.c 

int main(){
    leaderboards LB;
    char contoh[4];
    int contohskor;
    
    printf("Prosedur createdefault akan dipanggil\n ");
    createdefault(&LB);
    printf("Setelah prosedur dipanggil dan dieksekusi, nilai Neff leaderboards akan menjadi default yaitu %d\n",LB.neff);
    printf("Contoh hasil dari data dummy yaitu data pertama yang berisi nama default %s dan skor default %d\n",LB.info[1].name,LB. info[1].score);

    printf("Setelah ini, akan dimasukkan pasangan skor dan nama yang tidak terurut secara manual ke leaderboard\n");
    strcpy(LB.info[3].name,"Coy");
    LB.info[3].score = 30;

    printf("Hasil masukkan yang tidak terurut akan di tamplikan dengan prosedur printleaderboard\n");
    printleaderboard(LB);


    printf("selanjutnya, isi leaderboard akan diurutkan berdasarkan skor secara menurun dengan fungsi sortLB\n");
    sortLB(&LB);
    printleaderboard(LB);

    printf("Terakhir, apabila pengguna ingin memasukkan input secara terurut, gunakan prosedur inputleaderboard\n");
    printf(" Contoh data yang dimasukkan secara terurut adalah User Bernama Adi dengan skor 50\n");
    strcpy(contoh,"Adi");
    contohskor = 50;

    inputleaderboard(&LB,contoh,contohskor);
    printf("Hasil Update leaderboard dengan input yang diatur terurut\n");
    printleaderboard(LB);

    

}