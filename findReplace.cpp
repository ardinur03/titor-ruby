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
	system("cls");
    /* Buka semua file yang dibutuhkan */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];
	backAgainPath:
		
    printf("Enter path of source file: ");
    scanf("%s", path);
    
	for(int i=0; i<strlen(path); i++){
	  if(validateChar(path[i])){
	   printf("Name File can't have %c \n", path[i]);
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
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    printf("\n");
	/* print text sebelum */
//	printFromFile(path); 

    printf("\n\nEnter word to replace: ");
    scanf("%s", oldWord);

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
//	printFromFile(path); 

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.\n", oldWord, newWord);
    system("Pause");
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