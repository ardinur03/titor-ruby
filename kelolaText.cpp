#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
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

void editMode(int jmlBaris){
	int input;
	int barisEdit = 0;
	char curText[MAXKOLOM];
	
	if(jmlBaris>1){
		printf("Baris keberapa yang akan diubah dari (1-%d): ", jmlBaris);
		scanf("%d", &input);
		barisEdit = input - 1;	
	}
	
	do{
		printText(jmlBaris);
		printf("\nE| %-2d: ", barisEdit+1);
		fflush(stdin);
		gets(curText);
		
		if(strcmp(curText, "^a")==0){
			printText(jmlBaris);
			break;
		}else if(curText[1] == '~' || curText[2] == '~'){
			barisEdit = atoi(curText) - 1;
		}else{
			strcpy(text[barisEdit], curText);
			barisEdit++;	
		}
	}while(barisEdit < jmlBaris);
	printText(jmlBaris);
}

void appendMode(int jmlBaris){
	char curText[MAXKOLOM];
	do{
    	printf("A| %-2d: ", jmlBaris+1);
    	gets(curText);
    	
		if(strcmp(curText, "^e")==0){
			editMode(jmlBaris);
		}else if(strcmp(curText, "^p")==0){
			printText(jmlBaris);
		}else if(strcmp(curText, "^q")==0){
			break;	
		}else{
			strcpy(text[jmlBaris], curText);
			jmlBaris++;
		}
	}while(jmlBaris <= MAXBARIS);
}

		
