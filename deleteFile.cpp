#include <stdio.h>
#include <conio.h>
#include "stdlib.h"

// prototype
int destroyFile(char nama_file_temp[30]);

void deleteFile(){
    char namaFile[30];
    bool statusFile;
    printf("\t\tMasukkan nama file yang akan dihapus: ");
    scanf("%s", namaFile);
    statusFile = destroyFile(namaFile);
    if (statusFile == true){
        printf("File %s berhasil dihapus\n", namaFile);
    } else  {
        printf("File %s gagal dihapus\n", namaFile);
    }
}

int destroyFile(char nama_file_temp[30]) {
    system("cls");
    if (remove(nama_file_temp) == 0) {
        return true;
    } else {
        return false;
    }
}