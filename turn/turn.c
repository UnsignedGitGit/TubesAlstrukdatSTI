//nama fungsi IsEmpty dan CreateEmpty stack dan queue perlu dibedain!

//bonus udh dimasukin. DELETE KLO GA KEKEJAR

//ASUMSI: 
// - ada stack "history" yg elemen2nya punya atribut "giliran" yg nilainya 'B' atau 'W' (nanti bisa diakses dengan S.TOP.giliran)
// - ada fungsi IsStackEmpty dan CreateEmptyQ

//FUNGSI:
// - queue "giliran" bakal dipake buat masukin 'B' atau 'W' di stack "history"
// - bakal dipake di movement (supaya command MOVE cuma perlu nampilin bidak tim 'h' atau 'p') 



/*PROTOTIPE*/
void init_giliran (Stack S, Queue* Q);
/* I.S. S terdefinisi dan bisa kosong.
 * F.S. Queue yang berisi dua elemen ('B' dan 'W') terbentuk. Head queue
		menandakan giliran pemain sekarang (tim hitam atau putih) dan
		tail menandakan giliran pemain selanjutnya. */

void ganti_giliran (Queue* Q);
/* Mengirimkan 'W' jika giliran sedang berada pada pemain tim putih.
   Mengirimkan 'B' jika giliran sedang berada pada pemain tim hitam. */


#include "stack.h"
#include "queue.h"

/*IMPLEMENTASI*/
void init_giliran (Stack S, Queue* Q)
/* I.S. S terdefinisi dan bisa kosong.
 * F.S. Queue yang berisi dua elemen ('B' dan 'W') terbentuk. Head queue
		menandakan giliran pemain sekarang (tim hitam atau putih) dan
		tail menandakan giliran pemain selanjutnya. */
{
	/*KAMUS*/
	/*ALGORITMA*/
	CreateEmptyQ(Q,2);
	
	if (IsStackEmpty(S)) {	/*Jika new game*/
		Add(Q,'W');
		Add(Q,'B');
	} else {	/*BONUS: Jika load game*/
		if (S.TOP.giliran == 'W') {
			Add(Q,'W');
			Add(Q,'B');
		} else {
			Add(Q,'B');
			Add(Q,'W');
		}
	}
}

char get_giliran (Queue* Q)
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
