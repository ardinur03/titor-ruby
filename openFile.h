#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include "LinkedList.h"

void openFromFile();
/*Procedure untuk membuka file pada teks editor*/

text readFromFile(FILE *filePath);
/*Fungsi untuk membaca membaca character pada file dan memasukannya ke linked list, 
mengembalikan tipe data teks yang berisi list of char dan list baris*/ 

#endif