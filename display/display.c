#include <stdio.h>
#include "display.h"

void garis(char c)
/*
Mencetak border atas/bawah kotak: ########################
*/
{
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	for (i=1;i<=wpapan;i++){
		printf("%c", c);
	}
	printf("\n");
}

void berselang (char c)
/*
Mencetak bagian: #       #       #       #
*/
{
	/*KAMUS*/
	int i, j;
	
	/*ALGORITMA*/
	printf("%c", c);
	for (i=1;i<=8;i++) {
		for (j=1;j<=wbolong;j++) {
			printf(" ");
		}
		printf("%c", c);
	}
	printf("\n");
}

void isi(char c, Tab T, int b)
/*
Mencetak sebaris (baris ke-b) bagian isi kotak: 

#       #       #       #
#   Q   #   K   #   H   #
#       #       #       #

*/
{
	/*KAMUS*/
	int i, j;
	
	/*ALGORITMA*/
	berselang(c);
	
	printf("%c", c);
	for (i=1;i<=8;i++) {
		
		for (j=1;j<=(wbolong/2);j++) {
		printf(" ");
		}
		
		printf("%c", T.B[b-1][i-1]);
		
		for (j=1;j<=(wbolong/2);j++) {
		printf(" ");
		}
		
		printf("%c", c);
	}
	printf("\n");
	
	berselang(c);
}

void display(char c, Tab T)
/*

Mencetak papan. Cth sebagian hasil:
 
#########################
#       #       #       #
#   Q   #   K   #   H   #
#       #       #       #
#########################

*/
{
	/*KAMUS*/
	int i;
	
	/*ALGORITMA*/
	garis(c);
	
	for (i=1;i<=8;i++) {
		isi(c, T, i);
		garis(c);
	}
}
