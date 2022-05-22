/*
 * @file openFile.cpp
 * sumber_source_code  dari pembelajaran ddp semester 1 dan ada yang meng explore di link https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/

#include <stdio.h>
#include <cstring>
#include "kelolaText.h"
#include <windows.h>
#include <conio.h>
#include "saveToFIle.h"

void printFromFile(char path[50]){
	char text[80];
	FILE *read = fopen(path, "r");
	
	while (fgets(text, 80, read) != NULL) {
        printf("%s", text);
    }	
	
    fclose(read);
}

void openFileTwoDimensi(){
    char choice;
    system("cls");
    char *fileName;
    char text[MAXBARIS][MAXKOLOMARR];
    setArr(text);
    printf("TitorApps\n");
    printf("Enter file name: ");
    fileName=(char*) malloc(20* sizeof(char)); 
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("File not found!\n");
        printf("Press enter to go back ...");
        getch();
    } else {
        system("cls");

        int i = 0;
        int jmlBaris;
        while (fgets(text[i], MAXKOLOMARR, file) != NULL) {
            i++;
        }
        fclose(file);
        
        // text, start, end
        print2DArr(text, 0, i);

        // insert mode
        jmlBaris = insertMode(text, i);

        // update file fileName
        while (1)
        {
            printf("Do you want to update the file? (y/n) : ");
            choice = getch();
            if (choice == 'y')
            {
                // updateFile(fileName, jmlBaris, text);
                break;
            } else if (choice == 'n') {
                printf("\nYour file is not updated!");
                getch();
                break;
            } else {
                printf("\n");
                printf("Wrong Input!\n");
            }
            
        }

    }

}

