#include<stdio.h>

int main(){

    int pil;

    printf("####################################################################\n\n");
    printf("              SELAMAT DATANG DI CHESS KACANG BUNCHESS\n");
    printf("___________________________________________________________________\n\n");
    printf("                          1. New Game\n");
    printf("                         2. Load Game\n");
    printf("                        3. Leaderboards\n");
    printf("                           4. Exit\n");
    printf("___________________________________________________________________\n");

    scanf("Masukan nomor pilihan: %d", &pil);
    if (pil==1){
        printf ("Loading...");
    }else if (pil==2){
        printf("Input your file name: ");
    }else if (pil==3){
        printf("Papan SKOR KOSONG HEHE");
    }

    scanf("%d",&pil);
        return 0;
}