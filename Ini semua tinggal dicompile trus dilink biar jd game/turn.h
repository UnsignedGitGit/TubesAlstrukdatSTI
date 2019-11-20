#ifndef TURN_H 
#define TURN_H

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

#endif
