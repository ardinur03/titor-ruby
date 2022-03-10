#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAXBARIS 80
#define MAXKOLOM 40
#define BACKSPACE 8

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
	printf("I: Pindah Baris Keatas      E: Edit Baris\n");
	printf("K: Pindah Baris Kebawah     Q: Mode Insert\n\n");	
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

void editBaris(int curBaris){
	printf("EDITING LINE| %-2d: ", curBaris+1);
	gets(text[curBaris]);
}

void commandMode(int jmlBaris){
	int curBaris = jmlBaris-1;
	bool done = false;
	
	printText(jmlBaris);
	printLabelCmdMode();
	
	do{
		printf("Line: %-2d \r", curBaris+1);
		switch(getch()){
			case 'i':
				decCurBaris(&curBaris, jmlBaris);
				break;
			case 'k':
				incCurBaris(&curBaris, jmlBaris);
				break;
			case 'e':
				editBaris(curBaris);
				incCurBaris(&curBaris, jmlBaris);
				printText(jmlBaris);
				printLabelCmdMode();
				break;
			case 'q':
				done = true;
				break;
		}	
	}while(done == false);
	
	printText(jmlBaris);
}

void insertMode(int jmlBaris){
	char curText[MAXKOLOM];
	do{
    	printf("I| %-2d: ", jmlBaris+1);
    	gets(curText);
    	
		if(strcmp(curText, "^e")==0){
			commandMode(jmlBaris);
		}else if(strcmp(curText, "^q")==0){
			break;
		}else{
			strcpy(text[jmlBaris], curText);
			jmlBaris++;
		}
	}while(jmlBaris <= MAXBARIS);
}
