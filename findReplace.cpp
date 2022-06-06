/*
 * file findReplace.cpp
 * sumber_source_code : https://codeforwin.org/2018/02/c-program-find-and-replace-a-word-in-file.html 
 * di edit oleh : lolla mariah
*/

#include "header.h"
#include "helper.h"
#define BUFFER_SIZE 100

/* Deklarasi Fungsi */
void findAndReplaceFile(){
    /* Buka semua file yang dibutuhkan */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];
	backAgainPath:
	gotoxy(5, 5);	
    printf("Enter path of source file: ");
    scanf("%s", path);
    
	for(int i=0; i<strlen(path); i++){
	  if(validateChar(path[i])){
		gotoxy(5, 6);
	   printf("Name File can't have %c", path[i]);
	   goto backAgainPath;
	  }
	 }  
	       
    /* Buka semua file yang dibutuhkan */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w"); 

   /* fopen() mengembalikan NULL jika tidak dapat membuka file dalam mode yang diberikan. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Tidak dapat membuka file maka keluar */
        gotoxy(5, 7);
        printf("\nUnable to open file.");
        gotoxy(5, 8);
        printf("Please check whether file exists and you have read/write privilege.");
        goto backAgainPath;
    }
	/* print text sebelum */
	gotoxy(5, 6);
    printf("Enter word to replace: ");
    scanf("%s", oldWord);
	gotoxy(5, 7);
    printf("Replace '%s' with: ", oldWord);
    scanf("%s", newWord);

    /*
     * Baca baris dari file sumber dan tulis ke tujuan
     * file setelah mengganti kata yang diberikan.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Ganti semua kemunculan kata dari baris saat ini
        findReplace(buffer, oldWord, newWord);

        // Setelah diganti tulis ke file temp.
        fputs(buffer, fTemp);
    }

    /* Tutup semua file untuk melepaskan sumber */
    fclose(fPtr);
    fclose(fTemp);

    /* Hapus file sumber */
    remove(path);

    /* Ganti nama file temp sebagai file asli */
    rename("replace.txt", path);

    // print sesudah di find replace
	gotoxy(5, 8);
    printf("Successfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);
    gotoxy(5, 9);
    system("Pause");
    system("cls");
    //print text sesudah
}

/**
* Ganti semua kemunculan kata yang diberikan dalam string.
 */
void findReplace(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: Jika oldWord dan newWord sama maka akan menuju infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }


    /*
     * Ulangi sampai semua kejadian diganti. 
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Cadangkan baris saat ini
        strcpy(temp, str);

        // Indeks kata yang ditemukan saat ini
        index = pos - str;

        
		// Hentikan str setelah kata ditemukan indeks
        str[index] = '\0';

        /// Gabungkan str dengan kata baru 
        strcat(str, newWord);
        
        // Gabungkan str dengan kata-kata yang tersisa setelahnya
        // kata lama ditemukan indeks.
        strcat(str, temp + index + owlen);
    }
}