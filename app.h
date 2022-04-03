#ifndef app_h
#define app_h

void app(); // menu utama home
void home(); // menu utama home
void backMenuHome(); // modul kembali ke modul home()
/**
 * run ini digunakan untuk menjalankan aplikasi TiTOR
 * terdapat shorcut: new file, duplicate file, delete file, open file, rename file, find and replace text di dalam file
*/
void run();
void procedure(); // prosedur yang berisi tentang aplikasi TiTOR
void procedureShorcut(); // prosedur yang berisi shorcut aplikasi TiTOR

#define ENTER 13 // enter
#define SAVE_FILE 19 // ctrl + s
#define PASTE 22 // ctrl + v
#define REDO 25 // ctrl + y
#define UNDO 26 // ctrl + z
#define FIND_REPLACE 6 //ctrl + f

#define NEWFILE 14 // ctrl + n
#define OPENFILE 15 // ctrl + o
#define EDITFILE 5 // ctrl + e
#define DUPLICATE 4 // ctrl + d
#define DELETEFILE 24 // ctrl + x
#define RENAMEFILE 18 // ctrl + r
#define QUIT 17 // ctrl + q


#endif
