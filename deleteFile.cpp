#include <stdio.h>

void deleteFile(){
    char namaFile[30];
    printf("Masukkan nama file yang akan dihapus: ");
    scanf("%s", namaFile);

    if (remove(namaFile) == 0) {
        printf("The file is deleted successfully.");
    } else {
        printf("The file is not deleted.");
    }
}