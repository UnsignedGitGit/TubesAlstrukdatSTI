#include <stdio.h>
#include "stack.h"

int main () {
	/*KAMUS*/
	Stack S;
	Sinfotype pushthis, popinfo;

	/*ALGORITMA*/
	CreateEmptyStack(&S);

	if (IsStackEmpty(S)) {
		printf("Stack kosong!\n");
	}

	pushthis.turn = 'W';
	pushthis.type = 'P';
	pushthis.x0 = 2;
	pushthis.y0 = 2;
	pushthis.xt = 3;
	pushthis.yt = 3;
	pushthis.targettype = 'q';
	pushthis.specialmove = 'N';

	Push(&S, pushthis);
	printf("Menambahkan 1 elemen ke S\n");
	printf("Elemen teratas S: ");
	printf("%c, %c, %d, %d, %d, %d, %c, %c\n", S.T[S.TOP].turn, S.T[S.TOP].type, S.T[S.TOP].x0, S.T[S.TOP].y0, S.T[S.TOP].xt, S.T[S.TOP].yt, S.T[S.TOP].targettype, S.T[S.TOP].specialmove);

	pushthis.turn = 'B';
	pushthis.type = 'p';
	pushthis.x0 = 2;
	pushthis.y0 = 7;
	pushthis.xt = 3;
	pushthis.yt = 6;
	pushthis.targettype = 'Q';
	pushthis.specialmove = 'N';

	Push(&S, pushthis);
	printf("Menambahkan 1 elemen ke S\n");
	printf("Elemen teratas S: ");
	printf("%c, %c, %d, %d, %d, %d, %c, %c\n", S.T[S.TOP].turn, S.T[S.TOP].type, S.T[S.TOP].x0, S.T[S.TOP].y0, S.T[S.TOP].xt, S.T[S.TOP].yt, S.T[S.TOP].targettype, S.T[S.TOP].specialmove);
	
	printf("Menambahkan 1 elemen ke S\n");
	Pop(&S, &popinfo);
	printf("%c, %c, %d, %d, %d, %d, %c, %c\n", popinfo.turn, popinfo.type, popinfo.x0, popinfo.y0, popinfo.xt, popinfo.yt, popinfo.targettype, popinfo.specialmove);

	printf("Menambahkan 1 elemen ke S\n");
	Pop(&S, &popinfo);
	printf("%c, %c, %d, %d, %d, %d, %c, %c\n", popinfo.turn, popinfo.type, popinfo.x0, popinfo.y0, popinfo.xt, popinfo.yt, popinfo.targettype, popinfo.specialmove);

	if (IsStackEmpty(S)) {
		printf("Stack kosong!\n");
	}
	return 0;
}