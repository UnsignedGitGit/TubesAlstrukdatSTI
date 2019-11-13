void benteng(arrayofpossiblemoveteam *M, piece P,board B,char giliran){
    int i;
    //kanan
    i = P.xpos + 1;
    while(i<9){
        if(B.Boardcell[i][P.ypos].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[i][P.ypos].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,P.ypos);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,P.ypos);
            i++;
        }
    }

    // Kiri
    i = P.xpos-1;
    while(i>0){
        if(B.Boardcell[i][P.ypos].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[i][P.ypos].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,P.ypos);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,P.ypos);
            i--;
        }
    }

    // Atas
    i = P.ypos +1;
    while(i<9){
        if(B.Boardcell[P.xpos][i].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[P.xpos][i].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,P.xpos,i);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,P.xpos,i);
            i++;
        }
    }
    //Bawah
    i = P.xpos-1;
    while(i>0){
        if(B.Boardcell[P.xpos][i].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board.[P.xpos][i]CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,P.xpos,i);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,P.xpos,i);
            i--;
        }
    }
}

void Bishop(arrayofpossiblemoveteam *M, piece P,board B,char giliran){
    int i;
    int j;

    //kanan atas
    i = P.xpos + 1;
    j = P.ypos + 1
    while(i<9 && j < 9){
        if(B.Boardcell[i][j].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[i][j].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,j);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,j);
            i++;
            j++;
        }
    }

    // Kiri atas
    i = P.xpos-1;
    j = P.ypos + 1;
    while(i>0 && j <9){
        if(B.Boardcell[i][j].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[i][j].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,j);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,j);
            i--;
            j++;
        }
    }

    // Kiri bawah
    i = P.xpos - 1;
    j = P.ypos -1;
    while(i>0 && j>0){
        if(B.Boardcell[i][j].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board[i][j].CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,j);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,j);
            i--;
            y--;
        }
    }
    //Kanan Bawah
    i = P.xpos + 1;
    j = P.ypos - 1;
    while(i<9 && j>0){
        if(B.Boardcell[i][j].cellPiece.team != Undef){ // Undef berarti kosong
            if(Board.[i][j]CellPiece.team == P.team){
                break;
            }
            else{
                InsVlast(Listpossiblemoveperbidak,i,j);
                break;
            } 
        }
        else{
            InsVlast(Listpossiblemoveperbidak,i,j);
            i++;
            j--;
        }
    }
}


