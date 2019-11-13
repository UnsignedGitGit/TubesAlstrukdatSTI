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
	boolean isdead;
} piece;

#define Nil 0
#define CharNil ' '

#define PieceType(P) (P).type
#define PieceTeam(P) (P).team
#define PiecePosX(P) (P).xpos
#define PiecePosY(P) (P).ypos
#define PieceHasMoved(P) (P).hasmoved


// STACK : HISTORY OF EACH MOVEMENT 		----------------------------------------
typedef struct {
	char turn; 
	char type; // P = pion, R = Rook, H = Horse/Knight, B = Bishop, Q = Queen, K = King
	int x0; // Posisi horizontal bidak sebelum bergerak
	int y0; // Posisi Vertical bidak sebelum bergerak 
	int xt; // Posisi horizontal bidak setelah bergerak
	int yt; // Posisi vertical bidak setelah bergerak
	char targettype; // type bidak yang ada di posisi setelah bergerak
	boolean IsCastling;
} infotype; // Isi stack "History"


// ARRAY : PIECE and POSSIBLE MOVE ----------------------------------------
typedef struct {
	piece p;
	List possmove;
} elmt_arrpossmove; // Isi array of possible move tiap bidak

typedef struct {
	elmt_arrpossmove arr[16];
} arr_possible_move;

	//LIST of POSSIBLE MOVE
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


// ARRAY : PILIHAN BIDAK yang DAPAT BERGERAK	-----------------------------------------------------
typedef struct {
	piece P[16];
} piece_choice;


// RAJA		---------------------------------------------------------
typedef struct {
	int x;
	int y;
} koordinat;
