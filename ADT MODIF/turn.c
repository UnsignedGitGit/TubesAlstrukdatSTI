#include "stack.h"
#include "queue.h"

/*PROTOTIPE*/
void init_turn (Stack S, Queue* Q);
/* I.S. S terdefinisi dan bisa kosong.
 * F.S. Queue yang berisi dua elemen ('B' dan 'W') terbentuk. Head queue
		menandakan giliran pemain sekarang (tim hitam atau putih) dan
		tail menandakan giliran pemain selanjutnya. */

char get_turn (Queue* Q);
/* Mengirimkan 'W' jika giliran sedang berada pada pemain tim putih.
   Mengirimkan 'B' jika giliran sedang berada pada pemain tim hitam. */


/*IMPLEMENTASI*/
void init_turn (Stack S, Queue* Q)
/* I.S. S terdefinisi dan bisa kosong.
 * F.S. Queue yang berisi dua elemen ('B' dan 'W') terbentuk. Head queue
		menandakan giliran pemain sekarang (tim hitam atau putih) dan
		tail menandakan giliran pemain selanjutnya. */
{
	/*KAMUS*/
	/*ALGORITMA*/
	CreateEmptyQueue(Q,2);
	
	if (IsStackEmpty(S)) {	/*Jika new game*/
		Add(Q,'W');
		Add(Q,'B');
	} else {	/*Jika load game*/
		if (S.T[S.TOP].turn == 'W') {
			Add(Q,'W');
			Add(Q,'B');
		} else {
			Add(Q,'B');
			Add(Q,'W');
		}
	}
}

char get_turn (Queue* Q)
/* Mengirimkan 'W' jika giliran sedang berada pada pemain tim putih.
   Mengirimkan 'B' jika giliran sedang berada pada pemain tim hitam. */
{
	/*KAMUS*/
	char g;
	
	/*ALGORITMA*/
	Del(Q, &g);
	Add(Q, g);
	
	return g;
}
