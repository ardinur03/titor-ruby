#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include "loading.h"

void gotoxy(int X, int y) {
 COORD coord; //struct yang berisikan dua variabel bertipe SHORT, yaitu X dan Y
 coord.X = X;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Menetapkan posisi cursor di layar.
}

void loading_screen() {
 int i;
 gotoxy(40, 10);
 printf("Loading...");
 gotoxy(40, 12);
 for (i = 0; i <= 17; i++) {
  Sleep(90);
  printf("%c", 177);
 }
 printf("\n\n");
 //system("pause");
 system("cls");
}
