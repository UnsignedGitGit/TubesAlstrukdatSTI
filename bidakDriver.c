#include "ADT/board.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    board B;
    CreateBoard(&B);

    BoardPrintInfo(B);
}