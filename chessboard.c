// COBA BIKIN KOTAK

#include <stdio.h>
#include <stdlib.h>

const int ROW = 9;
const int COLUMN = 9;

int main(){
    int add_kotak[9][9]={{0}};
    int i,j,n;
//    n=1;
//    for (i=1;i<=ROW;i++){
//        for (j=1;i<=COLUMN;j++){
//            add_kotak[i][j]=0;
//        }
//    n++;    
//    }
    
    for (i=1;i<=ROW;i++){
        for (j=1;j<=COLUMN;j++){
            printf("%d", add_kotak[i][j]);
            if (j==COLUMN){
                printf("\n");
            }
        }
    }

    return 0;
}