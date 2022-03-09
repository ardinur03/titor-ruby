#include <stdio.h>

int main6()
{
    // Path to old and new files
    char oldName[100], newName[100];

    // Input old and new file name
    printf("masukan nama file yang akan diubah: ");
    scanf("%s", oldName);

    printf("masukan nama file baru: ");
    scanf("%s", newName);


    // rename old file with new name
    if (rename(oldName, newName) == 0)
    {
        printf("File berhasil diganti namanya.\n");
    }
    else
    {
        printf("Tidak dapat mengganti nama file. Silakan periksa file yang ada dan Anda memiliki izin untuk memodifikasi file.\n");
    }

    return 0;
}
