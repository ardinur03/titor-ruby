#ifndef SAVE_TO_FILE_H
#define SAVE_TO_FILE_H
#include "LinkedList.h"

/**
 * saveToFile ini digunakan untuk menyimpan file yang ada di dalam direktori secara dinamis 
 * berdasarkan inputan pengguna yang di parsing by address di parameter filename
 * @param filename 
 * @param jmlBaris 
 * @param text 
 */
void storeFile(char *filename, List text);

/**
 * modul saveFile digunakan untuk menyimpan file dengan memanggil fungsi storeFile
 * 
 * @param jmlBaris 
 * @param text 
*/
void saveFile(List text);

/**
 * modul updateFile digunakan untuk mengupdate file degan dilakukan perulangan berdaarkan jumlah baris 
 *        dan mencetak kedalam file
 * @param filename 
 * @param jmlBaris 
 * @param text 
*/
void updateFile(char *filename, int jmlBaris, List text);
#endif
