#include <stdio.h>
#include <stdlib.h>
#include "../Game/mesin_kata.h"

int main () {
	/*KAMUS*/
	char* filename;
	int count, i;

	/*ALGORITMA*/
	filename = (char *) malloc (50 * sizeof(char));
	printf("Masukkan nama file eksternal: \n");
	scanf("%s", filename);

	printf("Isi teks: \n");
	STARTKATA(filename);
	count = 0;
	while (!EndKata) {
		count++;
		for (i=1; i<=CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}
		ADVKATA();
		if (!EndKata) {
			printf(" ");
		}
	}

	printf(".\n");
	if (count == 0) {
		printf("Pita karakter kosong\n");
	} else {
		printf("Pita berisi %d kata\n", count);
	}
	return 0;
}