/*
 * Nama file renameFile.cpp
 * sumber_source_code : https://www.tutorialspoint.com/c_standard_library/c_function_rename.htm
 * di edit oleh : Naufal Salman Mulyadi
				  Muhammad Ardi Nur Insan (validasi)
*/
#include "helper.h"

void renameFile()
{
    // File lama ke file baru
    char oldName[100], newName[100];

    // Input nama file lama dan baru

    backAgainOldName:
    gotoxy(5, 5);
    printf("Enter the name of the file you want to change: ");
    scanf("%s", oldName);

	for(int i=0; i<strlen(oldName); i++){
		if(validateChar(oldName[i])){
			gotoxy(5, 6);
			printf("Name File can't have %c", oldName[i]);
			goto backAgainOldName;
		}
	}
	
    backAgainNewName:
    gotoxy(5, 6);
    printf("enter new file name: ");
    scanf("%s", newName);
    
    for(int i=0; i<strlen(newName); i++){
		if(validateChar(newName[i])){
			gotoxy(5, 6);
			printf("Name File can't have %c", newName[i]);
			goto backAgainNewName;
		}
	}
    // Validasi jika ektensi .exe 
	if(strcmp(newName, "exe")==0){
		gotoxy(5, 7);
		printf("Invalid file extension name.");
		getch();
		system("cls");
		goto backAgainNewName;
	}else if(fopen(newName, "r") != NULL){
		gotoxy(5, 7);
		printf("File already exists.");
		system("cls");
		goto backAgainNewName;
	}

    // Ganti nama file lama dengan nama baru
    if (rename(oldName, newName) == 0)
    {
    	gotoxy(5, 8);
        printf("The file was renamed successfully.");
    }
    else
    {
    	gotoxy(5, 8);
        printf("Unable to rename file. Please check the file exists and you have permission to modify the file.");
    }
	
	gotoxy(5, 9);
    system("pause");
    system("cls");
}
