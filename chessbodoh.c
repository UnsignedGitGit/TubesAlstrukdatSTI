//Mencoba cara bodoh ngeprint chess board
#include <stdio.h>
#include <conio.h>
int main (){
    printf("         A       B       C       D       E       F       G      H    \n");
    printf("     _________________________________________________________________\n");
    for (int i=1;i<=8;i+=2){
        printf("     |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|       |\n");
        printf("  %d  |▓ A,%d ▓|  B,%d  |▓ C,%d ▓|  D,%d  |▓ E,%d ▓|  F,%d  |▓ G,%d ▓|  H,%d  |\n",i,i,i,i,i,i,i,i,i);
        printf("     |▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|_______|\n");
        printf("     |       |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|       |▓▓▓▓▓▓▓|\n");
        printf("  %d  |  A,%d  |▓ B,%d ▓|  C,%d  |▓ D,%d ▓|  E,%d  |▓ F,%d ▓|  G,%d  |▓ H,%d ▓|\n",i+1,i+1,i+1,i+1,i+1,i+1,i+1,i+1,i+1);
        printf("     |_______|▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|_______|▓▓▓▓▓▓▓|\n");
    } 
    




    return 0;
}