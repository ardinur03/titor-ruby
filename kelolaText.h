#ifndef KELOLA_TEXT_H
#define KELOLA_TEXT_H

#define MAXBARIS 80
#define MAXKOLOM 40
#define MAXBUFFER 128
#define BACKSPACE 8
#define ENTER 13
#define CTRL_C 3
#define CTRL_V 22

void printText(int jmlBaris, char text[MAXBARIS][MAXKOLOM]);
void commandMode(int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]);
int insertMode(int jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]);
void editBaris(int curBaris, char (*text)[MAXBARIS][MAXKOLOM]);
void printLabelCmdMode();
void incCurBaris(int *curBaris, int jmlBaris);
void decCurBaris(int *curBaris, int jmlBaris);
void delBaris(int curBaris, int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]);
void addNewBaris(int curBaris, int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]);
bool barisPenuh(int jmlBaris);
void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty, char text[MAXBARIS][MAXKOLOM]);
void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty, char (*text)[MAXBARIS][MAXKOLOM]);

#endif