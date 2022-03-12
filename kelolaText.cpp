#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> naufal_save_file
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
	printf("\n\tCOMMAND MODE\n\n");
	printf("I: Pindah Baris Keatas      E: Edit Baris       BACKSPACE: Hapus Baris\n");
<<<<<<< HEAD
	printf("K: Pindah Baris Kebawah     Q: Mode Insert\n\n");	
=======
	printf("K: Pindah Baris Kebawah     Q: Mode Insert      ENTER    : Tambah Baris\n\n");	
>>>>>>> naufal_save_file
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

<<<<<<< HEAD
void delBaris(int curBaris, int *jmlBaris){
=======
void delBaris(int curBaris, int *jmlBaris){ 
>>>>>>> naufal_save_file
	if((*jmlBaris)>1){
		for(int i = curBaris; i<(*jmlBaris)-1; i++){
			strcpy(text[i], text[i+1]);
		}
		(*jmlBaris)--;
	}
}

<<<<<<< HEAD
=======
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

>>>>>>> naufal_save_file
void editBaris(int curBaris){
	printf("EDITING LINE| %-2d: ", curBaris+1);
	gets(text[curBaris]);
}

void commandMode(int *jmlBaris){
	int curBaris = (*jmlBaris)-1;
	bool done = false;
	
	printText(*jmlBaris);
	printLabelCmdMode();
<<<<<<< HEAD
	
=======
>>>>>>> naufal_save_file
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
<<<<<<< HEAD
			case 'q':
				done = true;
				break;
		}	
=======
			case ENTER:
				addNewBaris(curBaris, jmlBaris);
				printText(*jmlBaris);
				printLabelCmdMode();
				break;
			case 'q':
				done = true;
				break;
		}
>>>>>>> naufal_save_file
	}while(done == false);
	
	printText(*jmlBaris);
}

void insertMode(int jmlBaris){
<<<<<<< HEAD
	char curText[MAXKOLOM];
	do{
    	printf("I| %-2d: ", jmlBaris+1);
    	gets(curText);
    	
		if(strcmp(curText, "^e")==0){
			commandMode(&jmlBaris);
		}else if(strcmp(curText, "^q")==0){
			break;
		}else{
			strcpy(text[jmlBaris], curText);
			jmlBaris++;
		}
	}while(jmlBaris <= MAXBARIS);
=======
	char buffer[MAXBUFFER];
	do{
    	printf("I| %-2d: ", jmlBaris+1);
    	gets(buffer);
    	
		if(strcmp(buffer, "^e")==0){
			commandMode(&jmlBaris);
		}else if(strcmp(buffer, "^q")==0){
			break;
		}else{
			strcpy(text[jmlBaris], buffer);
			jmlBaris++;
		}
	}while(jmlBaris <= MAXBARIS);
}

int main(){
	insertMode(0);
>>>>>>> naufal_save_file
}