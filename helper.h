#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "manageText.h"

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

// prototype
int validateChar(char ektensiFileTemp);	
void SetCursorPosition(int x, int y);
void gotoxy(int X, int y); //fungsi yang digunakan untuk memindahkan, di layar ke posisi yang diinginkan

/**
 * @include {modul} manageText.cpp
*/
int insertTextMode(List textTemp, int postYTemp);

/**
 * @include {modul} app.cpp
 * 
 */
void color(int color); // fungsi yang digunakan untuk mengubah warna
void hideCursor(); // fungsi yang digunakan untuk menyembunyikan cursor
void menusBar(int menuKe, bool hilangMenu); // fungsi yang digunakan untuk menampilkan menu bar pulldown
void menuBarApp(); // fungsi yang digunakan untuk menampilkan menu bar app
void index(); // base index untuk menampilkan keseluruhan modul yang di gunakan dari menu bar, pulldown
void showCursor(); // fungsi yang digunakan untuk menampilkan cursor

#endif