/*
 * @file deleteFile.cpp
 * sumber_source_code : https://www.tutorialspoint.com/c_standard_library/c_function_remove.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/
#include "helper.h"

// prototype function
int destroyFile(char nama_file_temp[30]);

void deleteFile(){
    char *fileName = (char*) malloc(20* sizeof(char));
    bool statusFile;
    gotoxy(25, 5);
    showCursor();
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", fileName);
    statusFile = destroyFile(fileName);
    gotoxy(25, 6);
    if (statusFile){
        printf("File : %s successfully deleted", fileName);
    } else  {
        printf("File : %s failed to delete or the file is not in the directory", fileName);
    }

    gotoxy(25, 7);
    system("pause");
    system("cls");
}

int destroyFile(char nama_file_temp[30]) {
    system("cls");
    if (remove(nama_file_temp) == 0) {
        return true;
    } else {
        return false;
    }
}
