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
    system ("cls");
    backAgainOldName:
    printf("Enter the name of the file you want to change: ");
    scanf("%s", oldName);

	for(int i=0; i<strlen(oldName); i++){
		if(validateChar(oldName[i])){
			printf("Name File can't have %c \n", oldName[i]);
			goto backAgainOldName;
		}
	}
	
    backAgainNewName:
    printf("enter new file name: ");
    scanf("%s", newName);
    
    for(int i=0; i<strlen(newName); i++){
		if(validateChar(newName[i])){
			printf("Name File can't have %c \n", newName[i]);
			goto backAgainNewName;
		}
	}
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
