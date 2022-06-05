#ifndef header_h
#define header_h

#include <windows.h>

/**
 * @include {modul} main.cpp
*/
void app(); //  modul menu utama home
void loading_screen(); // modul tampilan 

/**
 * @include {modul} app.cpp  Start
*/
void home(); // modul menu utama home
void backMenuHome(); // modul kembali ke modul home()
void run(); // modul untuk menjalan kan aplikasi titorApps
void procedure(); // prosedur yang berisi tentang aplikasi TiTOR
void procedureShorcut(); // prosedur yang berisi shorcut aplikasi TiTOR
void newFile(); // modul untuk memanggil newFile dan berisi manageText 
void deleteFile();
/** deleteFile ini digunakan untuk menghapus file yang ada di dalam direktori secara dinamis berdasarkan nama file yang di inputkan pengguna */

void duplicateFile();
/**  duplicateFile ini digunakan untuk menduplikasi file yang ada di dalam direktori secara dinamis */

void findAndReplaceFile();
/** modul findAndReplaceFile digunakan untuk mencari kata dan mengganti kata dalam file */

void findReplace(char *str, const char *oldWord, const char *newWord);
/** modul findAndReplaceFile digunakan untuk mencari kata lama dan mengganti kata baru dalam file 
 * @param str 
 * @param oldWord 
 * @param newWord 
*/
void openFileTwoDimensi();
/** open file menjadi array 2 dimensi dengan kolom dan baris terdapat validasi kosong di penginputan nama file hitung baris, text kemdian di tampilkan ke layar menggunakan modul insertMode */

void printFromFile(char path[50]);
/** printFromFile di gunakan untuk menampilkan isi file digunakan di find & replace (include findReplace.cpp & openFile.cpp)*/

void renameFile();
/** renameFile ini digunakan untuk mengganti nama file yang ada di dalam direktori secara dinamis */

void vWelcome();
/** vWelcome ini digunakan untuk menampilkan welcome screen */
void vAbout();
/** vAbout ini digunakan untuk menampilkan tentang aplikasi TiTOR */ 
void vHelp();
/** vHelp ini digunakan untuk menampilkan bantuan penggunaan aplikasi TiTOR */
void vConfirmExit();
/** vConfirmExit ini digunakan untuk menampilkan konfirmasi exit aplikasi TiTOR */
/**
 * @include {modul} app.cpp  End
*/
#endif