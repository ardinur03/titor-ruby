#ifndef KELOLA_TEXT_H
#define KELOLA_TEXT_H

#define MAXBARIS 80
#define MAXKOLOM 40
#define MAXKOLOMARR MAXKOLOM+1 //Ditambah 1 sebagai tempat untuk NULL
#define MAXBUFFER 128

/*Keybind*/
#define BACKSPACE 8 //Menghapus character
#define ENTER 13 //Menambah baris baru
#define CTRL_C 3 //Copy baris
#define CTRL_E 5 //Memasuki command mode
#define CTRL_Q 17 //Keluar dari kelola 
#define CTRL_V 22 //Paste konten baris
#define CTRL_I 9 //Memindahkan kursor keatas
#define CTRL_J 10 //Memindahkan kursor kekiri
#define CTRL_K 11 //Memindahkan kursor kebawah
#define CTRL_L 12 //Memindahkan kursor ke kiri

/*Command Mode*/

void commandMode(int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
/*Memasuki command mode (Mengelola text per baris)*/

void printText(int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
/*Print array per baris pada command mode (Terdapat no baris)*/

void editLine(int curBaris, char text[MAXBARIS][MAXKOLOMARR]);
/*Overwrite isi array pada baris tertentu seusai input user (terdapat pada command mode)*/

void printLabelCmdMode();
/*Print label pada command mode*/

void incCurBaris(int *curBaris, int jmlBaris);
/*Memindahkan baris keatas pada command mode dengan menambahkan curBaris dengan 1*/

void decCurBaris(int *curBaris, int jmlBaris);
/*Memindahkan baris bawah pada conmand mode dengan mengurangi curBaris dengan 1*/

void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]);
/*Menyalin isi dari baris yang dipilih, kemudian dimasukan kedalam var temp*/
/*Mengisi isClipboardEmpty dengan false*/

void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]);
/*isClipboardEmpty harus bernilai true*/
/*Mengisi array pada index baris yang dipilih dengan temp*/


/* Insert Mode*/

int insertMode(char text[MAXBARIS][MAXKOLOMARR], int jmlBaris);
/*Memasuki insert mode (Mengelola text per char)*/

void print2DArr(char text[MAXBARIS][MAXKOLOMARR], int start, int end);
/*Print array per baris tanpa no baris*/

int findEndOfLine(char text[MAXBARIS][MAXKOLOMARR], int y);
/*Mencari index array yang berisi null pada suatu baris*/

void setArr(char text[MAXBARIS][MAXKOLOMARR]);
/*Mengisi index 0 pada setiap baris dengan NULL*/

void print1DArr(char text[MAXBARIS][MAXKOLOMARR], int row, int col, int limit);
/*Print array per character apda baris tertentu*/


/*Digunakan di kedua mode*/


void addNewLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
/*Menambahkan baris baru*/
/*User memilih pada baris mana baris baru akan ditambahkan*/
/*Menggeser array baris kekanan dimulai dari index baris yang dipilih*/
/*Mengisi index baris yang dipilih dengan null*/

void delLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
/*User memilih baris yang akan dihapus, kemudian menggeser array baris kekiri*/
/*dari baris terakhir hingga index baris yang dihapus*/

#endif