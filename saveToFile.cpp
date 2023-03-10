#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include "kelolaText.h"

void storeFile(char *filename, int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
	FILE *file;
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%s\n", text[i]);
	}
	fclose(file);
}

void saveFile(int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
	char *namaFile, *ektensiFile, *namaFileTemp;
	system("cls");
	backAgainNameFile:
	printf("Enter file name: ");
	namaFile=(char*) malloc(20* sizeof(char)); 
	scanf("%s", namaFile);
	backAgain:
	printf("Enter the file extension name (without full stop): ");
	ektensiFile=(char*) malloc(5* sizeof(char));
	scanf("%s", ektensiFile);
	// validasi jika ektensi .exe 
	if(strcmp(ektensiFile, "exe")==0){
		printf("\nInvalid file extension name.\n");
		getch();
		system("cls");
		goto backAgain;
	}

	// validasi jangan input titik di dalam string
	for(int i=0; i<strlen(ektensiFile); i++){
		if(ektensiFile[i] =='.'){
			printf("Extension name can't have full stop.\n");
			getch();
			system("cls");
			goto backAgain;
		}else if(ektensiFile[i] ==' '){
			printf("Extension name can't have space.\n");
			getch();
			system("cls");
			goto backAgain;
		}
	}
	
	
	strcat(namaFile, ".");
	namaFileTemp = strcat(namaFile, ektensiFile);
	// cek jika file ada maka kembalikan
	if(fopen(namaFileTemp, "r") != NULL){
		printf("File already exists.\n");
		printf("Press any key to continue...\n");
		getch();
		system("cls");
		goto backAgainNameFile;
	}

	storeFile(namaFileTemp, jmlBaris, text);
	printf("File has been saved successfully\n");
	printf("Press any button to go back");
	getch();
}

void updateFile(char *filename, int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
	FILE *file;
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%s\n", text[i]);
	}
	fclose(file);
}