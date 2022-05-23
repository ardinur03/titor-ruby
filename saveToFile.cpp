/*
 * @file saveToFile.cpp
 * sumber_source_code : mencoba sendiri dan di explore di link https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
 * di edit oleh : Muhamad Ardi Nur Insan
*/

#include "helper.h"

void storeFile(char *filename, int jmlBaris, List text){
	FILE *file;
	address tempList;
	tempList = First(text);
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%c", Info(tempList));
		// fprintf(file, "%s\n", text.First);
	}
	fclose(file);
}

void saveFile(int jmlBaris, List text){
	char *namaFile, *ektensiFile, *namaFileTemp;
	system("cls");
	backAgainNameFile:
	printf("Enter file name: ");
	namaFile=(char*) malloc(20* sizeof(char)); 
	scanf("%s", namaFile);
	// na/mafile
	for(int i=0; i<strlen(namaFile); i++){
		if(validateChar(namaFile[i])){
			printf("Name File can't have %c \n", namaFile[i]);
			goto backAgainNameFile;
		}
	}

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

	for(int i=0; i<strlen(ektensiFile); i++){
		if(validateChar(ektensiFile[i])){ 
			printf("Extension name can't have %c \n", ektensiFile[i]);
			getch();
			system("cls");
			goto backAgain;
		}else if(ektensiFile[i] == '.'){
			printf("Extension name can't have full stop.\n");
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

void updateFile(char *filename, int jmlBaris, List text){
	FILE *file;
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%s\n", text.First[i]);
	}
	fclose(file);
}

