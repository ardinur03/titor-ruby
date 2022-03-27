#ifndef KELOLA_TEXT_H
#define KELOLA_TEXT_H

#define MAXBARIS 80
#define MAXKOLOM 40
#define MAXKOLOMARR MAXKOLOM+1
#define MAXBUFFER 128
#define BACKSPACE 8
#define ENTER 13
#define CTRL_C 3
#define CTRL_E 5
#define CTRL_Q 17
#define CTRL_V 22
#define CTRL_I 9
#define CTRL_J 10
#define CTRL_K 11
#define CTRL_L 12

void printText(int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
void commandMode(int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
int insertMode(char text[MAXBARIS][MAXKOLOMARR], int jmlBaris);
void editLine(int curBaris, char text[MAXBARIS][MAXKOLOMARR]);
void printLabelCmdMode();
void incCurBaris(int *curBaris, int jmlBaris);
void decCurBaris(int *curBaris, int jmlBaris);
void delLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
void addNewLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]);
void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]);
void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]);
void print2DArr(char text[MAXBARIS][MAXKOLOMARR], int start, int end);
int findEndOfLine(char text[MAXBARIS][MAXKOLOMARR], int y);
void setArr(char text[MAXBARIS][MAXKOLOMARR]);
void print1DArr(char text[MAXBARIS][MAXKOLOMARR], int row, int col, int limit);

#endif