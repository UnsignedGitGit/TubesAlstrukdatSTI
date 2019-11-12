void benteng(arrayofpossiblemoveteam *M, piece P,board B,char giliran){
    int i;
    int j;
    int k;

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