#ifndef KELOLA_TEXT_H
#define KELOLA_TEXT_H

#define MAXBARIS 80
#define MAXKOLOM 40
#define MAXBUFFER 128
#define BACKSPACE 8
#define ENTER 13

extern char text[MAXBARIS][MAXKOLOM];

void printText(int jmlBaris);
void commandMode(int *jmlBaris);
void insertMode(int jmlBaris);
void editBaris(int curBaris);
void printLabelCmdMode();
void incCurBaris(int *curBaris, int jmlBaris);
void decCurBaris(int *curBaris, int jmlBaris);
void delBaris(int curBaris, int *jmlBaris);
void addNewBaris(int curBaris, int *jmlBaris);

#endif