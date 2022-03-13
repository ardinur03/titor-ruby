#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "kelolaText.h"



void printText(int jmlBaris, char text[MAXBARIS][MAXKOLOM]){
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

void delBaris(int curBaris, int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]){ 
	if((*jmlBaris)>1){
		for(int i = curBaris; i<(*jmlBaris)-1; i++){
			strcpy((*text)[i], (*text)[i+1]);
		}
		(*jmlBaris)--;
	}
}

void addNewBaris(int curBaris, int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]){
	int i = *jmlBaris - 1;
	int PrecI = i - 1;
	int lastIdx = i;
	char* last;
	last = (*text)[lastIdx];
	if((*jmlBaris)<MAXBARIS){
		(*jmlBaris)++;
		strcpy((*text)[*jmlBaris-1], last);
		while(i != curBaris){
			strcpy((*text)[i], (*text)[PrecI]);
			PrecI--;
			i--;
		}
		memset((*text)[curBaris], 0, MAXKOLOM);
	}
}

void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty, char text[MAXBARIS][MAXKOLOM]){
	strcpy(temp, text[curBaris]);
	*isClipboardEmpty = false;
	printf("Baris telah disalin\n");
}

void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty, char (*text)[MAXBARIS][MAXKOLOM]){
	if(isClipboardEmpty == false){
		addNewBaris(curBaris, jmlBaris, text);
		strcpy((*text)[curBaris], temp);
	}
}

void editBaris(int curBaris, char (*text)[MAXBARIS][MAXKOLOM]){
	printf("EDITING LINE| %-2d: ", curBaris+1);
	fgets((*text)[curBaris], MAXKOLOM, stdin);
	(*text)[curBaris][strcspn((*text)[curBaris], "\n")] = 0;
}

void commandMode(int *jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]){
	int curBaris = (*jmlBaris)-1;
	bool done = false;
	bool isClipboardEmpty = true;
	char clipboard[MAXKOLOM];
	
	printText(*jmlBaris, *text);
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
				editBaris(curBaris, text);
				incCurBaris(&curBaris, *jmlBaris);
				printText(*jmlBaris, *text);
				printLabelCmdMode();
				break;
			case BACKSPACE:
				delBaris(curBaris, jmlBaris, text);
				decCurBaris(&curBaris, *jmlBaris);
				printText(*jmlBaris, *text);
				printLabelCmdMode();
				break;
			case ENTER:
				addNewBaris(curBaris, jmlBaris, text);
				printText(*jmlBaris, *text);
				printLabelCmdMode();
				break;
			case CTRL_C:
				copyBaris(curBaris, clipboard, &isClipboardEmpty, *text);
				break;
			case CTRL_V:
				pasteBaris(curBaris, jmlBaris, clipboard, isClipboardEmpty, text);
				printText(*jmlBaris, *text);
				printLabelCmdMode();
				break;
			case 'q':
				done = true;
				break;
		}
	}while(done == false);
	
	if(barisPenuh(*jmlBaris) == false){
		printText(*jmlBaris, *text);
	}
}

bool barisPenuh(int jmlBaris){
	if(jmlBaris==MAXBARIS){
		return true;
	}
	return false;
}

void insertMode(int jmlBaris, char (*text)[MAXBARIS][MAXKOLOM]){
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
				commandMode(&jmlBaris, text);
			}else if(strcmp(buffer, "^q")==0){
				done = true;
				break;
			}else{
				strcpy((*text)[jmlBaris], buffer);
				jmlBaris++;
			}
		}else{	
			while(1){
				system("cls");
				printf("Anda telah mencapai batas baris, apakah anda ingin mengedit teks kembali? (y/n)\n");
				choice = getche();
				if(choice == 'y'){
					commandMode(&jmlBaris, text);
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
}