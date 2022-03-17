#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_SIZE 1000


void findReplace(char *fileName_param)
{
    /* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count;
    
//    printf("pilih file yang akan di edit: ");
//    scanf("%s", path);

    printf("Enter line number to replace : ");
    scanf("%d", &line);

    /* Remove extra new line character from stdin */
    fflush(stdin);

    printf("Replace '%d' the line be changed to ?: ", line);
    fgets(newline, BUFFER_SIZE, stdin);


    /*  Open all required files */
    fPtr  = fopen(fileName_param, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(fileName_param);

    /* Rename temporary file as original file */
    rename("replace.tmp", fileName_param);

    printf("\nSuccessfully replaced '%d' line with '%s'.", line, newline);

}