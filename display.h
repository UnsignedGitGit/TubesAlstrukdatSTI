#ifndef __display__
#define __display__

/*KONSTANTA*/
#define wsel 9
#define hsel 5
#define wbolong (wsel-2)
#define wpapan (wsel + (wsel-1)*7)

/*typedef biar parameter fungsi bisa berupa array of char*/
typedef struct {
	char B[8][8];
} Tab;

/*PROTOTIPE*/
/*parameter 'char c' diisi dengan karakter yang akan dipakai untuk border*/

void garis(char c);
void berselang(char c);
void isi(char c, Tab T, int b);
void display(char c, Tab T);

#endif
