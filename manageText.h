#ifndef manageText_H
#define manageText_H

#include "LinkedList.h"

void Insert(CharsList *L, infotype X);
/*Insert char ke linked list of char*/
/*IS: L mungkin kosong*/
/*FS: Melakukan alokasi sebuah elemen dan menambahkan elemen 
dengan nilai X pada list apabila alokasi berhasil*/

void InsertRow(RowsList *L, address X, int posX);
/*Insert address dari node char ke list baris*/
/*IS: L mungking kosong dan posX >= 0*/
/*FS: Melakukan alokasi sebuah elemen dan menambahkan elemen dengan
      nilai X pada list apabila alokasi berhasil, 
      posisi dari elemen pada list bergantung nilai posX*/

void insertTextMode(CharsList *text, RowsList *rows);
/* Mode insert pada text editor*/

void SpecialKeyHandle(CharsList *text, RowsList *rows, int *posX, int *posY);
/* Handle apabila input merupakan special key*/

void DeleteChar(CharsList *L, address *current);
/*  IS : 
    L sembarang  
    current terdefinisi bisa di awal, di tengah, akhir
*/
/* FS : Jika ada elemen list, maka elemen terakhir dihapus */

void DeleteRow(RowsList *L, rowAddr *current);

#endif