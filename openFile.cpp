/*
 * @file openFile.cpp
 * sumber_source_code  dari pembelajaran ddp semester 1 dan ada yang meng explore di link https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/

#include <stdio.h>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include "manageText.h"
#include "helper.h"

text readFromFile(char *filePath){
	FILE *read;
	text textFromFile;
	char c;
	
	CreateList(&(textFromFile.charList));
	CreateListOfRows(&(textFromFile.rowList));
	InsertRow(&(textFromFile.rowList), NULL, 0); //Insert baris pertama
	
	read=fopen(filePath, "r");
	while((c=fgetc(read))!=EOF){			
		Insert(&(textFromFile.charList), c);
		if(c == '\n'){
			/*Param posX diisi dengan AmounOfChar(Current(rows)) agar selalu insert last*/				
			InsertRow(&(textFromFile.rowList), Current(textFromFile.charList), AmountOfChar(Current(textFromFile.rowList)));
		}else{
			AmountOfChar(Current(textFromFile.rowList))++;
		}	
	}
	
	fclose(read);
	system("cls");
	PrintList(textFromFile.charList);
	return textFromFile;
}

void openFromFile(){
    char choice;
	text textFromFile;
    char *fileName;

	system("cls");
	showCursor();
    printf("Enter file name: ");
    fileName=(char*) malloc(20* sizeof(char)); 
    scanf("%s", fileName);
	textFromFile = readFromFile(fileName); 
	insertTextMode(&(textFromFile.charList),  &(textFromFile.rowList));

    while (1)
    {
        printf("Do you want to update the file? (y/n) : ");
        choice = getch();
        if (choice == 'y' || choice == 'Y')
        {
            // updateFile(fileName, jmlBaris, text);
            break;
        } else if (choice == 'n' || choice == 'N') {
            printf("\nYour file is not updated!");
            getch();
            break;
        } else {
            printf("\n");
            printf("Wrong Input!\n");
        }
    }
}

