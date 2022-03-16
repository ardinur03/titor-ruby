#include <stdio.h>
#include <cstring>
#include "kelolaText.h"
#include "findReplace.h"
#include <windows.h>
#include <conio.h>

void openFile(){
	char choice;
    system("cls");
    char *fileName;

	printf("Masukkan nama file: ");
	fileName=(char*) malloc(20* sizeof(char)); 
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("File tidak ditemukan!\n");
    } else {
        char text[100];
        while (fgets(text, 100, file) != NULL) {
            printf("%s", text);
        }
        fclose(file);
    }
    printf("Apakah anda ingin mengedit teks ? (y/n)\n");
    getch();
    choice = getche();
				if(choice == 'y'){
					findReplace(fileName);
					getch();
				}else{
					printf("\nPilihan tidak seusai");
				}
}

