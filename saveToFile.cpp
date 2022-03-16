#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include "kelolaText.h"

void storeFile(char *filename, int jmlBaris, char text[MAXBARIS][MAXKOLOM]){
	FILE *file;
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%s\n", text[i]);
	}
	fclose(file);
}

void saveFile(int jmlBaris, char text[MAXBARIS][MAXKOLOM]){
	char *namaFile, *ektensiFile, *namaFileTemp;
	system("cls");

	printf("Masukkan nama file: ");
	namaFile=(char*) malloc(20* sizeof(char)); 
	scanf("%s", namaFile);
	printf("Masukkan nama ektensi file (tanpa titik): ");
	ektensiFile=(char*) malloc(5* sizeof(char));
	scanf("%s", ektensiFile);

	strcat(namaFile, ".");
	namaFileTemp = strcat(namaFile, ektensiFile);

	storeFile(namaFileTemp, jmlBaris, text);
	printf("File sudah berhasil di simpan\n");
	printf("Tekan tombol apapun untuk kembali");
	getch();
}
