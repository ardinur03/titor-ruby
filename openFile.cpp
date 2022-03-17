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

	printf("Enter file name: ");
	fileName=(char*) malloc(20* sizeof(char)); 
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("File not found!\n");
        printf("Press enter to go back ...");
        getch();
        openFile();
    } else {
        char text[100];
        while (fgets(text, 100, file) != NULL) {
            printf("%s", text);
        }
        fclose(file);
    }
    printf("Do you want to edit the text? (y/n)\n");
    getch();
    choice = getche();
    if(choice == 'y'){
        findReplace(fileName);
        getch();
    }else{
        printf("\nWrong Input!");
    }
}

