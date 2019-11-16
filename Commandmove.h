// File Commandmove.h
// Berisi deklarasi prosedur Do_move, Move, show_moveable_piece,generate_valid_move
// Fungsi-fungsi/Prosedur selain move adalah turunan fungsi move,   Maka Move memanggil fungsi Lainnya

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "piece.h"
#include "board.h"
#include "queue.h"
#include "listlinier.h"
#include "array.h"
#include "stack.h"







void move(Stack *S,char team, arr_possible_move *T, board bb);
/* Secara Berurutan, Prosedur ini Akan melakukan :
            1. Generate Valid Move untuk seluruh bidak dari 1 tim
            2. Mengcopy bidak yang mungkin bergerak ke array of pilihan possible
            3. Menampilkan array of pilihan possible dan meminta input untuk pilihan bidak
            4. Menampilkan gerakan yang mungkin dari bidak pilihan dan meminta input pilihan gerakan
            5. Melakukan gerakan dari pilihan pengguna (do move)
*/

void generate_valid_move(arr_possible_move *T); 
//di dalam prosedur ini akan dilakukan traversal seluruh elemen array team tersebut

void show_movable_piece(piece_choice pc);
// I.S sembarang
// F.S Menampilkan seluruh piece yang mungkin digerakkan sesuai spek tubes tercinta







