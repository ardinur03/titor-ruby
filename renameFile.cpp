/*
 * Nama file renameFile.cpp
 * sumber_source_code : ... 
 * di edit oleh : ...
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>

void renameFile()
{
    // File lama ke file baru
    char oldName[100], newName[100];

    // Input nama file lama dan baru
    system ("cls");
    printf("Enter the name of the file you want to change: ");
    scanf("%s", oldName);

    backAgainNewName:
    printf("enter new file name: ");
    scanf("%s", newName);
    // Validasi jika ektensi .exe 
	if(strcmp(newName, "exe")==0){
		printf("\nInvalid file extension name.\n");
		getch();
		system("cls");
		goto backAgainNewName;
	}else if(fopen(newName, "r") != NULL){
		printf("File already exists.\n");
		printf("Press any key to continue...\n");
		getch();
		system("cls");
		goto backAgainNewName;
	}

    // Ganti nama file lama dengan nama baru
    if (rename(oldName, newName) == 0)
    {
        printf("The file was renamed successfully.\n");
    }
    else
    {
        printf("Unable to rename file. Please check the file exists and you have permission to modify the file.\n");
    }

}
