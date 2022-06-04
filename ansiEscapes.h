#ifndef ANSI_ESCAPES_H
#define ANSI_ESCAPES_H
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4

/*
Source: https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
		https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
*/
#include "stdio.h"
enum clearScreenCodes{ //Kode untuk clear screen
	CLEAR_FROM_CURSOR_TO_END,
	CLEAR_FROM_CURSOR_TO_BEGIN,
	CLEAR_ALL
};

void setupConsole(); 
/*Mendapatkan output handle dari console dan set ENABLE_VIRTUAL_TERMINAL_PROCESSING*/
/*agar dapat mengunakan ANSI escape code di windows*/

void restoreConsole();
/*Restore Console mode ke default pada windows*/

// compiler yang memanggil intruksi dengan pemanggilaan sebelumnya (copy per baris)
static inline void clearScreen(){ //Menghapus seluruh layar
	printf("\x1b[%dJ", CLEAR_ALL);
}

static inline void clearScreenToBottom(){ //Menghapus layar dari kursor ke bawah
	printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearScreenToTop(){ //Menghapus layar dari kursor ke atas
	printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_BEGIN);
}

static inline void clearLine(void) { //Menghapus baris dimana kursor berada
    printf("\x1b[%dK", CLEAR_ALL);
}

static inline void clearLineToRight(){ //Menghapus char pada baris dari kursor ke kanan
	printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearLineToLeft(){ //Menghapus char pada baris dari kursor ke kiri
	printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_BEGIN);
}

static inline void clrToEOL(){ //Menghapus baris
	printf("\x1b[1J");
}

static inline void moveUp(int pos){ //Memindahkan kursor ke atas
	printf("\x1b[%dA", pos);
}

static inline void moveDown(int pos){ //Memindahkan kursor ke bawah
	printf("\x1b[%dB", pos);
}

static inline void moveRight(int pos){ //Memindahkan kursor ke kanan
	printf("\x1b[%dC", pos);
}

static inline void moveLeft(int pos){ //Memindahkan kursor ke kiri
	printf("\x1b[%dD", pos);
}

static inline void moveTo(int row, int col){ //Memindahkan kursor ke koordinat tertentu
	row++;
	col++;
	printf("\x1b[%d;%dH", row, col);
}

static inline void resetCursor(){ //Memindahkan kursor ke koordinat 0,0
	printf("\x1b[H");
}


#endif