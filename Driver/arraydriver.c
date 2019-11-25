// Instruksi kompilasi driver : gcc -o arraydriver arraydriver.c array.c listlinier.c piece.c board.c


#include <stdio.h>
#include "../Game/array.h"
#include "../Game/boolean.h"
#include "../Game/piece.h"
#include "../Game/board.h"
#include "../Game/listlinier.h"

int main(){
    TabChar tc;\
    piece_choice pc;
    arr_possible_move ap;

    int Maxelement = 5;

    printf("Membentuk sebuah tabchar kosong  dengan neff 5...\n");
    MakeEmptyArraySpecMove (&tc,Maxelement);

    printf("Setelah pemanggilan prosedur MakeEmptyArraySpecMove, nilai MaxEl Tabchar menjadi %d dan nilai Neff menjadi %d\n",tc.MaxEl,tc.Neff);

    printf("Mendealokasi TabChar yang baru saja di buat....\n");
    DealokasiArray(&tc);
    printf("Setelah dealokasi, nilai MaxEl Tabchar menjadi %d dan nilai neff menjadi %d\n",tc.MaxEl,tc.Neff);

    printf("Membentuk sebuah piece_choice kosong...\n");
    MakeEmptyArrChoice(&pc);
    printf("Setelah pemanggilan prosedur MakeEmptyArrChoice, nilai neff array choice menjadi : %d\n",pc.neff);

    printf("Membentuk sebuah arr_possible_move kosong...\n");
    MakeEmptyArrPMove(&ap);
    printf("Setelah pemanggilan prosedur MakeEmptyArrPMOve, nilai neff arr_possible_move menjadi : %d\n",ap.neff);


}