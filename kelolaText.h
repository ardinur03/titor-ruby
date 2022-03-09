#ifndef KELOLA_TEXT_H
#define KELOLA_TEXT_H

#define MAXBARIS 80
#define MAXKOLOM 40

extern char text[MAXBARIS][MAXKOLOM];

void printText(int jmlBaris);
void editMode(int jmlBaris);
void appendMode(int jmlBaris);

#endif