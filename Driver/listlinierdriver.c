#include <stdio.h>
#include "listlinier.h"

int main () {
	/*KAMUS*/
	List L;
	Linfotype inserthis, infodelete;

	/*ALGORITMA*/
	CreateEmptyList(&L);

	if (IsListEmpty(L)) {
		printf("List kosong!\n");
	}

	inserthis.x = 7;
	inserthis.y = 2;

	InsVLast(&L, inserthis);
	printf("Menambahkan 1 elemen\n");
	printf("Jumlah elemen L: ");
	printf("%d\n", NbElmtList(L));

	inserthis.x = 2;
	inserthis.y = 2;

	InsVLast(&L, inserthis);
	printf("Menambahkan 1 elemen\n");
	printf("Jumlah elemen L: ");
	printf("%d\n", NbElmtList(L));


	inserthis.x = 2;
	inserthis.y = 4;

	InsVLast(&L, inserthis);
	printf("Menambahkan 1 elemen\n");
	printf("Jumlah elemen L: ");
	printf("%d\n", NbElmtList(L));

	PrintInfo(L);

	DelVLast(&L, &infodelete);
	printf("Alamat kotak (%d,%d) dihapus dari list. \n", infodelete.x, infodelete.y);

	DelVFirst(&L, &infodelete);
	printf("Alamat kotak (%d,%d) dihapus dari list. \n", infodelete.x, infodelete.y);

	DelList(&L);

	if (IsListEmpty(L)) {
		printf("List kosong!\n");
	}
	return 0;
}