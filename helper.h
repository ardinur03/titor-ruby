#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ansiEscapes.h"

/*Keybind*/
#define BACKSPACE 8 //Menghapus character
#define ENTER 13 //Menambah baris baru
#define CTRL_C 3 //Copy baris
#define CTRL_E 5 //Memasuki command mode
#define CTRL_V 22 //Paste konten baris
#define CTRL_I 9 //Memindahkan kursor keatas
#define CTRL_J 10 //Memindahkan kursor kekiri
#define CTRL_K 11 //Memindahkan kursor kebawah
#define CTRL_L 12 //Memindahkan kursor ke kiri
#define F1 59 //Memindahkan kursor ke kiri
#define TAB 6 // menambahkan tab

#define SAVE_FILE 19 // ctrl + s
#define QUITAPP 17 // ctrl + q 
#define PASTE 22 // ctrl + v
#define REDO 25 // ctrl + y
#define UNDO 26 // ctrl + z
#define FIND_REPLACE 6 //ctrl + f

#define NEWFILE 14 // ctrl + n
#define OPENFILE 15 // ctrl + o
#define EDITFILE 5 // ctrl + e
#define DUPLICATEFILE 4 // ctrl + d
#define DELETEFILE 24 // ctrl + x
#define RENAMEFILE 18 // ctrl + r
#define QUIT 17 // ctrl + q

#define ARROW_UP 72 // arrow up
#define ARROW_DOWN 80 // arrow down
#define ARROW_LEFT 75 // arrow left
#define ARROW_RIGHT 77 // arrow right
#define HOME 71 // home key on keyboard
#define END 79 // end button on keyboard 
#define DELETE_BUTTON 83 // delete button on keyboard 


// prototype
int validateChar(char ektensiFileTemp);	
void SetCursorPosition(int x, int y);
void gotoxy(int X, int y); //fungsi yang digunakan untuk memindahkan, di layar ke posisi yang diinginkan

/**
 * @include {modul} app.cpp
*/
void color(int color); // prosedure yang digunakan untuk mengubah warna
/**
 * @param int color 
 */
void hideCursor(); // prosedure yang digunakan untuk menyembunyikan cursor
void menusBar(int menuKe, bool hilangMenu); // prosedure yang digunakan untuk menampilkan menu bar pulldown
/**
 * @param int menuKe
 * @param bool hilangMenu 
 */
void menuBarApp(); // prosedure yang digunakan untuk menampilkan menu bar app
void index(); // base index untuk menampilkan keseluruhan modul yang di gunakan dari menu bar, pulldown
void showCursor(); // prosedure yang digunakan untuk menampilkan cursor
void clearPage(); // prosedure yang digunakan untuk menghapus layar
int setTitleComandLine(); // fungsi yang digunakan untuk mengubah title bar
/**
 * fungsi yang digunakan untuk mengambil 4 karakter terakhir dari nama file
 * @param char str 
 * @return boolean 
*/
boolean getLast4Char(char *str); 
/**
 * @brief prosedure yang digunakan untuk mengubah warna background dan text
 * @param int bgCodeTemp 
 * @param int textCodeTemp 
*/
void setBgColor(int bgCodeTemp, int textCodeTemp); 
void SetConsoleScreenBuffer(); // prosedure yang digunakan untuk mengubah ukuran buffer
/**
 * @end {modul} app.cpp
*/

#endif