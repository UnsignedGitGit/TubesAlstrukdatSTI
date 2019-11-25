#include <stdio.h>
#include "../Game/queue.h"

int main () {
	/*KAMUS*/
	Queue Q;
	Qinfotype X;

	/*ALGORITMA*/
	CreateEmptyQueue(&Q, 2);

	if (IsQueueEmpty(Q)) {
		printf("Queue kosong!\n");
	}

	Add(&Q, 'W');
	printf("Menambahkan 1 elemen\n");
	printf("Jumlah elemen Q: ");
	printf("%d\n", NBElmtQueue(Q));

	Add(&Q, 'B');
	printf("Menambahkan 1 elemen\n");
	printf("Jumlah elemen Q: ");
	printf("%d\n", NBElmtQueue(Q));

	if (IsQueueFull(Q)) {
		printf("Queue penuh!\n");
	}
	
	Del(&Q, &X);
	printf("%c\n", X);

	Del(&Q, &X);
	printf("%c\n", X);

	DeAlokasiQueue(&Q);
	printf("%d\n", Q.MaxEl);

	return 0;
}