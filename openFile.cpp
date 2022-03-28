#include <stdio.h>
#include <cstring>
#include "kelolaText.h"
#include "findReplace.h"
#include <windows.h>
#include <conio.h>
#include "saveToFIle.h"

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

// open file and print to array 2 dimensi
void openFileTwoDimensi(){
    char choice;
    system("cls");
    char *fileName;
    char text[MAXBARIS][MAXKOLOMARR];
    printf("TitorApps\n");
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
        system("cls");

        int i = 0;
        while (fgets(text[i], MAXKOLOMARR, file) != NULL) {
            i++;
        }
        fclose(file);

        // insert mode
        int jmlBaris = insertMode(text, i);

        // update file fileName
        while (1)
        {
            printf("Do you want to update the file? (y/n) : ");
            choice = getch();
            if (choice == 'y')
            {
                updateFile(fileName, jmlBaris, text);
                break;
            } else if (choice == 'n') {
                printf("\nYour file is not updated!");
                getch();
                break;
            } else {
                printf("\n");
                printf("Wrong Input!\n");
            }
            
        }

    }

    // printf("Do you want to edit the text? (y/n)\n");
    // getch();
    // choice = getche();
    // if(choice == 'y'){
    //     findReplace(fileName);
    //     getch();
    // }else{
    //     printf("\nWrong Input!");
    // }
}