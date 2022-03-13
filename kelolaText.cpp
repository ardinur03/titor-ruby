#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "kelolaText.h"

char text[MAXBARIS][MAXKOLOM];

void printText(int jmlBaris){
	system("cls");
  	for(int i = 0; i < jmlBaris; i++){
  		printf(" | %-2d: ", i+1);
    	for(int j = 0; text[i][j]; j++){
    		putchar(text[i][j]);
		}
    	putchar('\n');
  	}
}

void printLabelCmdMode(){
	printf("\n                                      COMMAND MODE\n\n");
	printf("I: Pindah Baris Keatas      E: Edit Baris      BACKSPACE: Hapus Baris       CTRL+C: Salin Baris\n");
	printf("K: Pindah Baris Kebawah     Q: Mode Insert     ENTER    : Tambah Baris      CTRL+V: Tempel Baris\n\n");
}

void incCurBaris(int *curBaris, int jmlBaris){
	if(*curBaris<jmlBaris-1){
		(*curBaris)++;
	}
}

void decCurBaris(int *curBaris, int jmlBaris){
	if(*curBaris>0){
		(*curBaris)--;
	}
}

void delBaris(int curBaris, int *jmlBaris){ 
	if((*jmlBaris)>1){
		for(int i = curBaris; i<(*jmlBaris)-1; i++){
			strcpy(text[i], text[i+1]);
		}
		(*jmlBaris)--;
	}
}

void addNewBaris(int curBaris, int *jmlBaris){
	int i = *jmlBaris - 1;
	int PrecI = i - 1;
	int lastIdx = i;
	char* last;
	last = text[lastIdx];
	if((*jmlBaris)<MAXBARIS){
		(*jmlBaris)++;
		strcpy(text[*jmlBaris-1], last);
		while(i != curBaris){
			strcpy(text[i], text[PrecI]);
			PrecI--;
			i--;
		}	
		memset(text[curBaris], 0, MAXKOLOM);
	}
}

void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty){
	strcpy(temp, text[curBaris]);
	*isClipboardEmpty = false;
	printf("Baris telah disalin\n");
}

void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty){
	if(isClipboardEmpty == false){
		addNewBaris(curBaris, jmlBaris);
		strcpy(text[curBaris], temp);
	}
}

void editBaris(int curBaris){
	printf("EDITING LINE| %-2d: ", curBaris+1);
	fgets(text[curBaris], MAXKOLOM, stdin);
	text[curBaris][strcspn(text[curBaris], "\n")] = 0;
}

void commandMode(int *jmlBaris){
	int curBaris = (*jmlBaris)-1;
	bool done = false;
	bool isClipboardEmpty = true;
	char clipboard[MAXKOLOM];
	
	printText(*jmlBaris);
	printLabelCmdMode();
	do{
		printf("Line: %-2d \r", curBaris+1);
		switch(getch()){
			case 'i':
				decCurBaris(&curBaris, *jmlBaris);
				break;
			case 'k':
				incCurBaris(&curBaris, *jmlBaris);
				break;
			case 'e':
				editBaris(curBaris);
				incCurBaris(&curBaris, *jmlBaris);
				printText(*jmlBaris);
				printLabelCmdMode();
				break;
			case BACKSPACE:
				delBaris(curBaris, jmlBaris);
				decCurBaris(&curBaris, *jmlBaris);
				printText(*jmlBaris);
				printLabelCmdMode();
				break;
			case ENTER:
				addNewBaris(curBaris, jmlBaris);
				printText(*jmlBaris);
				printLabelCmdMode();
				break;
			case CTRL_C:
				copyBaris(curBaris, clipboard, &isClipboardEmpty);
				break;
			case CTRL_V:
				pasteBaris(curBaris, jmlBaris, clipboard, isClipboardEmpty);
				printText(*jmlBaris);
				printLabelCmdMode();
				break;
			case 'q':
				done = true;
				break;
		}
	}while(done == false);
	
	if(barisPenuh(*jmlBaris) == false){
		printText(*jmlBaris);
	}
}

bool barisPenuh(int jmlBaris){
	if(jmlBaris==MAXBARIS){
		return true;
	}
	return false;
}

int insertMode(int jmlBaris){
	char choice;
	char buffer[MAXKOLOM];
	bool done = false;
	do{	
		if(barisPenuh(jmlBaris)==false){
			printf("I| %-2d: ", jmlBaris+1);
			fflush(stdin);
	    	fgets(buffer, MAXKOLOM, stdin);
	    	buffer[strcspn(buffer, "\n")] = 0;
	    	
			if(strcmp(buffer, "^e")==0){
				commandMode(&jmlBaris);
			}else if(strcmp(buffer, "^q")==0){
				done = true;
				break;
			}else{
				strcpy(text[jmlBaris], buffer);
				jmlBaris++;
			}
		}else{	
			while(1){
				system("cls");
				printf("Anda telah mencapai batas baris, apakah anda ingin mengedit teks kembali? (y/n)\n");
				choice = getche();
				if(choice == 'y'){
					commandMode(&jmlBaris);
					if(barisPenuh(jmlBaris)==false){
						break;
					}
				}else if(choice == 'n'){
					done = true;
					break;
				}else{
					printf("\nPilihan tidak seusai");
					Sleep(1000);
				}
			}
		}
	}while(done == false);
	
	return jmlBaris;
}


void storeFile(char *filename, int jmlBaris){
	FILE *file;
	file = fopen(filename, "w");
	for(int i=0; i<jmlBaris; i++){
		fprintf(file, "%s\n", text[i]);
	}
	fclose(file);
}

void saveFile(int jmlBaris){
	FILE *fp;
	char *namaFile, *ektensiFile, *namaFileTemp;


	system("cls");

	printf("Masukkan nama file: ");
	fscanf(stdin, "%s", namaFile);
	printf("Masukkan nama ektensi file: ");
	fscanf(stdin, "%s", ektensiFile);

	// gabungkan variabel namaFile dan ektensiFile
	char* name_with_extension;
	namaFileTemp = malloc(strlen(namaFile)+1+4); /* make space for the new string (should check the return value ...) */
	strcpy(name_with_extension, ektensiFile); /* copy name into the new var */
	strcat(name_with_extension, ektensiFile); /* add the extension */
	
	fp = fopen(namaFileTemp, "w");
	if(fp == NULL){
		printf("Gagal membuka file %s\n", namaFileTemp);
		exit(1);
	}
	
	for(int i=0; i<jmlBaris; i++){
		fprintf(fp, "%s\n", text[i]);
	}
	
	fclose(fp);
	
	printf("File %s berhasil disimpan\n", namaFileTemp);
	
	free(namaFileTemp);

	

	// // buat file baru fopen("data_transaksi.dat","ab+");
	// fp = fopen(namaFileTemp, "w");


	// storeFile(namaFile, jmlBaris);
	// fclose(fp);
}
