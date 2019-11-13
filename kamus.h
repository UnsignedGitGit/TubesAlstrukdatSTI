// BOARD	---------------------------------------------------------
typedef struct {
    cell boardCell [9][9];
} board;

#define BoardCell(B) (B).boardCell


// CELL	-tidak kepakai ----------------------------------------------
typedef struct {
    piece cellPiece;
    char cellColor;
    char cellDisplay;
} cell;

#define CellColor(C) (C).cellColor // input C : char
#define CellPiece(C) (C).cellPiece // input C : piece
#define CellDisplay(C) (C).cellDisplay // input C : char


// PIECE	---------------------------------------------------------
typedef struct {
    char type; // P = pion, R = Rook, H = Horse/Knight, B = Bishop, Q = Queen, K = King 
    char team; // W = White, B = Black
    int xpos; // Possible int: [0..8] 
    int ypos; // Possible int: [0..8]
    boolean hasmoved;
} piece;

#define Nil 0
#define CharNil ' '

#define PieceType(P) (P).type
#define PieceTeam(P) (P).team
#define PiecePosX(P) (P).xpos
#define PiecePosY(P) (P).ypos
#define PieceHasMoved(P) (P).hasmoved


// STACK : MOVEMEMORY 		----------------------------------------
typedef struct {
	char turn;
	char type;
	int x0;
	int y0;
	int xt;
	int yt;
	char targettype;
	boolean IsCastling;
} movehistory;


// ARRAY : POSSIBLE MOVE	----------------------------------------
typedef struct {
	elmt_arrposspove arraypiece[16];
} arr_possible_move;

typedef struct {
	piece p;
	List possmove;
} elmt_arrposspove;

typedef struct {
	int x;
	int y;
} infotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
} List;


// PILIHAN 		-----------------------------------------------------
typedef struct {
	piece P[16];
} piece_choice;


// RAJA		---------------------------------------------------------
typedef struct {
	int x;
	int y;
} koordinat;
