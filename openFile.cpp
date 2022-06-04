/*
 * @file openFile.cpp
 * sumber_source_code  dari pembelajaran ddp semester 1 dan ada yang meng explore di link https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/

#include "helper.h"
#include "manageText.h"
#include "saveToFile.h"
#include <cstring>

void openFromFile();

text readFromFile(FILE *filePath){
	text textFromFile;
	char c;
	
	CreateList(&(textFromFile.charList));
	CreateListOfRows(&(textFromFile.rowList));
	InsertRow(&(textFromFile.rowList), NULL, 0); //Insert baris pertama

	while((c=fgetc(filePath))!=EOF){			
		Insert(&(textFromFile.charList), c);
		if(c == '\n'){
			/*Param posX diisi dengan AmounOfChar(Current(rows)) agar selalu insert last*/				
			InsertRow(&(textFromFile.rowList), Current(textFromFile.charList), AmountOfChar(Current(textFromFile.rowList)));
		}else{
			AmountOfChar(Current(textFromFile.rowList))++;
		}	
	}
	
	system("cls");
	PrintList(textFromFile.charList);
	return textFromFile;
}

void openFromFile(){
	FILE *read;
    char choice;
	text textFromFile;
    char *fileName;
	boolean isExtensionValid;

	showCursor();
	
	do{
		gotoxy(5, 5);	
		printf("Enter file name: ");
		fileName=(char*) malloc(20* sizeof(char)); 
		scanf("%s", fileName);
		isExtensionValid = getLast4Char(fileName);
		read = fopen(fileName, "r");

		if(read == NULL)
		{
			gotoxy(5, 6);
			printf("WARNING : %s not found", fileName);
			gotoxy(5, 7);
			system("pause");
			gotoxy(5, 6);
			printf("                                                                 ");
			gotoxy(5, 7); 
			printf("                                    ");
		} else if(read != NULL && isExtensionValid){
			gotoxy(5, 6);
			printf("WARNING : extension cannot be .exe");
			gotoxy(5, 7);
			system("pause");
			gotoxy(5, 6);
			printf("                                    ");
			gotoxy(5, 7);
			printf("                                    ");
		}
		gotoxy(5, 5);
		printf("                                                      ");
	}while(read == NULL || isExtensionValid == true);

	textFromFile = readFromFile(read); 
	insertTextMode(&(textFromFile.charList),  &(textFromFile.rowList));

    while (1)
    {
		system("cls");
		gotoxy(5, 2);
		printf("Do you want to save the file? (y/n) : ");
        choice = getch();
        if (choice == 'y' || choice == 'Y')
        {
            updateFile(fileName, textFromFile.charList);
			gotoxy(5, 3);
			printf("File saved successfully");
			gotoxy(5, 4);
			system("pause");
			system("cls");
            break;
        } else if (choice == 'n' || choice == 'N') {
			gotoxy(5, 3);
            printf("WARNING : Your file is not save !");
			gotoxy(5, 4);
			system("pause");
			system("cls");
            break;
        } else {
			gotoxy(5, 3);
            printf("WARNING : Wrong Input !");
			system("pause");
			system("cls");
        }
    }

	fclose(read);

}

