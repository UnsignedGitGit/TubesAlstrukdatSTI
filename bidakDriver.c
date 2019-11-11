#include "ADT/board.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    board B;
    CreateBoard(&B);

    BoardPrintInfo(B);
}