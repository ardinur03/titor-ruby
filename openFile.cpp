#include <stdio.h>
#include <cstring>
#include "kelolaText.h"
#include "findReplace.h"
#include <windows.h>
#include <conio.h>
#include "saveToFIle.h"

//void openFile(){
//	char choice;
//    system("cls");
//    char *fileName;
//
//	printf("Enter file name: ");
//	fileName=(char*) malloc(20* sizeof(char)); 
//    scanf("%s", fileName);
//    
//    FILE *file = fopen(fileName, "r");
//    if (!file) {
//        printf("File not found!\n");
//        printf("Press enter to go back ...");
//        getch();
//        openFile();
//    } else {
//        char text[100];
//        while (fgets(text, 100, file) != NULL) {
//            printf("%s", text);
//        }
//        fclose(file);
//    }
//    printf("Do you want to edit the text? (y/n)\n");
//    getch();
//    choice = getche();
//    if(choice == 'y'){
//        findReplace(fileName);
//        getch();
//    }else{
//        printf("\nWrong Input!");
//    }
//}

void printFromFile(char path[50]){
	char text[80];
	FILE *read = fopen(path, "r");
	
	while (fgets(text, 80, read) != NULL) {
        printf("%s", text);
    }	
	
    fclose(read);
}

// open file and print to array 2 dimensi
void openFileTwoDimensi(){
    char choice;
    system("cls");
    char *fileName;
    char text[MAXBARIS][MAXKOLOMARR];
    setArr(text);
    printf("TitorApps\n");
    printf("Enter file name: ");
    fileName=(char*) malloc(20* sizeof(char)); 
    scanf("%s", fileName);
    
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("File not found!\n");
        printf("Press enter to go back ...");
        getch();
        // openFile();
    } else {
        system("cls");

        int i = 0;
        int jmlBaris;
        while (fgets(text[i], MAXKOLOMARR, file) != NULL) {
            i++;
        }
        fclose(file);

        print2DArr(text, 0, i);

        // insert mode
        jmlBaris = insertMode(text, i);

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

}

