// BOARD ------------------------------------------------------------------------------------------------------------------
typedef struct {
    piece* boardCell [9][9];
} board;

#define BoardCell(B) (B).boardCell


// PIECE ------------------------------------------------------------------------------------------------------------------

// Definisi piece kosong: type dan team bernilai CharNil.
// Atribut isdead piece kosong diinisialisasi dengan false
// (supaya parameter PieceCreate tidak perlu ditambah)

typedef struct {
    char type; 
    // P/p = pion, R/r = Rook, H/h = Horse/Knight, B/b = Bishop,
    // Q/q = Queen, K/k = King
    // Huruf besar menandakan bidak tim putih, sedangkan huruf kecil
    // menandakan bidak tim hitam
     
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
#define PieceIsDead(P) (P).isdead


// STACK : MOVEMENT HISTORY ------------------------------------------------------------------------------------------------------------------
typedef struct {
	char turn; 
	char type;
    // P/p = pion, R/r = Rook, H/h = Horse/Knight, B/b = Bishop,
    // Q/q = Queen, K/k = King
    
	int x0; // Posisi horizontal bidak sebelum bergerak
	int y0; // Posisi Vertical bidak sebelum bergerak 
	int xt; // Posisi horizontal bidak setelah bergerak
	int yt; // Posisi vertical bidak setelah bergerak
	char targettype; // type bidak yang ada di posisi setelah bergerak
	char specialmove; // 'C' jika castling, 'E' jika en passant, 'N' jika gerakan biasa
} Sinfotype;

#define Nil 0
#define MaxElStack 110

typedef struct {
    Sinfotype T[MaxElStack];
    int TOP;
} Stack;


// ARRAY : PIECE DAN POSSIBLE MOVE-NYA ------------------------------------------------------------------------------------------------------------------
typedef struct {
	piece p;
	List possmove;
} elmt_arrpossmove;

typedef struct {
	elmt_arrpossmove arr[17]; //Index yang digunakan [1..16]
	int neff;
} arr_possible_move;

// LIST : POSSIBLE MOVE (digunakan di dalam arr_possible_move ------------------------------------------------------------------------------------------------------------------
typedef struct {
	int x;
	int y;
} Linfotype;

typedef struct tElmtlist *address;

typedef struct tElmtlist { 
	Linfotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
} List;


// ARRAY : PILIHAN BIDAK yang DAPAT BERGERAK ------------------------------------------------------------------------------------------------------------------
typedef struct {
	piece arrpiece[17]; // Index yang digunakan [1..16]
	int neff;
} piece_choice;


// ARRAY : PILIHAN ID SPECIAL MOVE yang DAPAT DILAKUKAN ------------------------------------------------------------------------------------------------------------------
typedef struct {
	char* T;  /* Index yang digunakan [1..4] */
	int Neff;
	int MaxEl;
} TabChar;


// QUEUE : TURN ------------------------------------------------------------------------------------------------------------------
typedef char Qinfotype;

typedef struct { 
	Qinfotype * T;
	int HEAD;
	int TAIL;
	int MaxEl;
} Queue;

#define Nil 0
