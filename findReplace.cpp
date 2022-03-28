#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "findReplace.h"
#include "openFile.h"

#define BUFFER_SIZE 100


/* Function declaration */
void findAndReplaceFile(){
	system("cls");
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];

    printf("Enter path of source file: ");
    scanf("%s", path);
		        
    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    printf("\n");
	/* print text sebelum */
	printFromFile(path); 

    printf("\n\nEnter word to replace: ");
    scanf("%s", oldWord);

    printf("Replace '%s' with: ", oldWord);
    scanf("%s", newWord);

    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        findReplace(buffer, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
    }

    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);

   /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("replace.txt", path);

    // print sesudah di find replaca
	printFromFile(path); 

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.\n", oldWord, newWord);
    system("Pause");
    //print text sesudah
}



/**
 * Replace all occurrences of a given a word in string.
 */
void findReplace(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: If oldWord and newWord are same it goes to infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }


    /*
     * Repeat till all occurrences are replaced. 
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Backup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
}