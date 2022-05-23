/*
 * @file deleteFile.cpp
 * sumber_source_code : https://www.tutorialspoint.com/c_standard_library/c_function_remove.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/
#include "helper.h"

// prototype function
int destroyFile(char nama_file_temp[30]);

void deleteFile(){
    char namaFile[30];
    bool statusFile;
    gotoxy(25, 5);
    showCursor();
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", namaFile);
    statusFile = destroyFile(namaFile);
    gotoxy(25, 6);
    if (statusFile == true){
        printf("File : %s successfully deleted", namaFile);
    } else  {
        printf("File : %s failed to delete or the file is not in the directory", namaFile);
    }
    getch();
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
