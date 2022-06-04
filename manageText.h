#ifndef manageText_H
#define manageText_H

#include "LinkedList.h"

void Insert(List *L, infotype X);
void InsertRow(RowsList *L, address X, int posX);
void insertTextMode(List *text, RowsList *rows);
void CursorHandle(List *text, RowsList *rows, int *posX, int *posY);
void DeleteChar(List *L, address *current);
/*  IS : 
    L sembarang  
    current terdefinisi bisa di awal, di tengah, akhir
*/
/* FS : Jika ada elemen list, maka elemen terakhir dihapus */




#endif
