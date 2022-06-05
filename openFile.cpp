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

	/*Buat list of char dan list baris*/
	CreateList(&(textFromFile.charList));
	CreateListOfRows(&(textFromFile.rowList));

	/*Insert node pertama pada list baris*/
	InsertRow(&(textFromFile.rowList), NULL, 0); 

	/*Buka file pada mode read*/
	read=fopen(filePath, "r");

	/*Baca setiap char pada file hingga EOF kemudian masukan ke linked list*/
	while((c=fgetc(read))!=EOF){		
		/*Insert char ke list of char*/
		Insert(&(textFromFile.charList), c);

		/*Check jika c adalah baris baru*/
		if(c != '\n'){
			/*Tambah jml huruf pada current node di list baris*/
			AmountOfChar(Current(textFromFile.rowList))++;
		}else{
			/*Tambah node baru pada list baris*/
			/*Param posX diisi dengan AmounOfChar(Current(rows)) agar selalu insert last*/				
			InsertRow(&(textFromFile.rowList), Current(textFromFile.charList), AmountOfChar(Current(textFromFile.rowList)));
		}

	}
	fclose(read); /*Tutup file*/

	/*Tampilkan list of char ke layar*/
	system("cls");
	PrintList(textFromFile.charList);

	/*Kembalikan list*/
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

