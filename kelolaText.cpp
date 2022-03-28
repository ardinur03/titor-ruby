#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "kelolaText.h"
#include "ansiEscapes.h"

void printText(int jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
	system("cls");
  	for(int i = 0; i < jmlBaris; i++){
  		printf(" | %-2d: ", i+1);
    	for(int j = 0; text[i][j]; j++){
    		putchar(text[i][j]);
		}
    	putchar('\n');
  	}
}

void print2DArr(char text[MAXBARIS][MAXKOLOMARR], int start, int end){
	for(int i = start; i<end; i++){
		printf("%s", text[i]);
	}
}

int findEndOfLine(char text[MAXBARIS][MAXKOLOMARR], int y){
	int i = 0;
	while(!text[y][i] == NULL){
		i++;
	}
	return i;
}

void setArr(char text[MAXBARIS][MAXKOLOMARR]){
	for(int i =0; i<MAXBARIS; i++){
		text[i][0] = NULL;
	}
}

void print1DArr(char text[MAXBARIS][MAXKOLOMARR], int row, int col, int limit){
	for(int i = col; i<limit; i++){
		printf("%c", text[row][i]);
	}
}

void printLabelCmdMode(){
	printf("\n                                      COMMAND MODE\n\n");
	printf("I: Move Row Up              E: Edit Line       BACKSPACE: Delete Line       CTRL+C: Copy Line\n");
	printf("K: Move Row Down            Q: Mode Insert     ENTER    : Add Line          CTRL+V: Paste Line\n\n");
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

void delLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){ 
	if((*jmlBaris)>1){
		for(int i = curBaris; i<(*jmlBaris)-1; i++){
			strcpy(text[i], text[i+1]);
		}
		(*jmlBaris)--;
	}
}

void addNewLine(int curBaris, int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
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

void copyBaris(int curBaris, char *temp, bool *isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]){
	strcpy(temp, text[curBaris]);
	*isClipboardEmpty = false;
	printf("The line has been copied\n");
}

void pasteBaris(int curBaris, int *jmlBaris, char *temp, bool isClipboardEmpty, char text[MAXBARIS][MAXKOLOMARR]){
	if(isClipboardEmpty == false){
		strcpy(text[curBaris], temp);
	}
}

void editLine(int curBaris, char text[MAXBARIS][MAXKOLOMARR]){
	printf("EDITING LINE| %-2d: ", curBaris+1);
	fgets(text[curBaris], MAXKOLOM, stdin);
	text[curBaris][strcspn(text[curBaris], "\n")] = 0;
}

void commandMode(int *jmlBaris, char text[MAXBARIS][MAXKOLOMARR]){
	int curBaris = (*jmlBaris)-1;
	bool done = false;
	bool isClipboardEmpty = true;
	char clipboard[MAXKOLOM];
	
	printText(*jmlBaris, text);
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
				editLine(curBaris, text);
				incCurBaris(&curBaris, *jmlBaris);
				printText(*jmlBaris, text);
				printLabelCmdMode();
				break;
			case BACKSPACE:
				delLine(curBaris, jmlBaris, text);
				printText(*jmlBaris, text);
				printLabelCmdMode();
				break;
			case ENTER:
				addNewLine(curBaris, jmlBaris, text);
				printText(*jmlBaris, text);
				printLabelCmdMode();
				break;
			case CTRL_C:
				copyBaris(curBaris, clipboard, &isClipboardEmpty, text);
				break;
			case CTRL_V:
				pasteBaris(curBaris, jmlBaris, clipboard, isClipboardEmpty, text);
				printText(*jmlBaris, text);
				printLabelCmdMode();
				break;
			case 'q':
				done = true;
				break;
		}
	}while(done == false);
}


int insertMode(char text[MAXBARIS][MAXKOLOMARR], int jmlBaris){
	int y = 0;
	int x = 0;
	int curEOL = 0;
	int prevEOL = 0;
	int nextEOL = 0;
	int amountOfLine = jmlBaris;
	int remainder = 0;
	bool done = false;
	char buffer;
	setupConsole();
	
	do{
//		printf("\n\n\n\ny: %d", y);
//		printf("\nx: %d", x);
		moveTo(y, x);
		buffer = getch();
		switch(buffer){
			case CTRL_J: /*Pindah cursor ke kiri*/
				if(x>0){
					x--;
				}else if(x == 0 && y > 0){ /*Jika cursor pada ujung kiri*/
					prevEOL = findEndOfLine(text, y-1);
					y--;
					x = prevEOL;
				}
				break;
			case CTRL_L: /*Pindah cursor ke kanan*/
				curEOL = findEndOfLine(text, y);
				if(x == curEOL && y+1 < amountOfLine){ /*Jika curosr pada ujung kanan*/
					x = 0;
					y++;
				}else if(x < curEOL){
					x++;
				}
				break;
			case CTRL_I: /*Pindah cursor ke atas*/
				prevEOL = findEndOfLine(text, y-1);
				if(y>0){
					if(x<=prevEOL){
						y--;
					}else{ /*Jika panjang baris atas lebih pendek*/
						y--;
						x=prevEOL;
					}
				}
				break;
			case CTRL_K: /*Pindah cursor ke bawah*/
				nextEOL = findEndOfLine(text, y+1);
				if(y+1<amountOfLine){ 	//y+1 karena amountOfLine mulainya dari 1 & y mulai dari 0
					if(x<=nextEOL){
						y++;
					}else{ 	/*Jika garis bawah lebih panjang*/
						y++;
						x=nextEOL;
					}
				}
				break;
			case ENTER: /*Tambah baris baru*/
				curEOL = findEndOfLine(text, y);
				if(amountOfLine < MAXBARIS){
					if(x == curEOL){ /*Jika cursor berada di akhir baris*/
						x = 0;
						if(y+1<amountOfLine){ /*Jika dibawah cursor terdapat baris lain*/
							addNewLine(y+1, &amountOfLine, text); //penambahan jumlah baris terjadi disini
							moveTo(y,0);
							clearScreenToBottom();
							print2DArr(text, y, amountOfLine);
						}else{ /*Jika dibawah cursor tidak terdapat baris lain*/
							amountOfLine++;
							text[y+1][0]=NULL;
						}
						y++;		
					}else if(x == 0){ /*Jika cursor berada di awal baris*/
						addNewLine(y, &amountOfLine, text);
						moveTo(y,0);
						clearScreenToBottom();
						print2DArr(text, y, amountOfLine);
					}else{ /*Jika cursor berada di tengah baris*/
						curEOL = findEndOfLine(text, y);
						remainder = curEOL - x; /*Menghitung banyak char di digeser ke garis baru*/
						if(y+1<amountOfLine){ /*Jika dibawah cursor terdapat baris lain*/
							addNewLine(y+1, &amountOfLine, text);
						}else{ /*Jika dibawah cursor tidak terdapat baris lain*/
							amountOfLine++;
							text[y+1][remainder] = NULL;
						}
						for(int i = x, j = 0; i < curEOL; i++, j++){ /*Geser char di kanan cursor ke garis baru */
							text[y+1][j] = text[y][i];
						}
						text[y][curEOL-remainder] = NULL;
						moveTo(y, 0);
						clearScreenToBottom();
						print2DArr(text, y, amountOfLine);
						y++;
						x = 0;
					}
				}
				break;
			case BACKSPACE: /*Hapus char*/
				curEOL = findEndOfLine(text, y);
				prevEOL = findEndOfLine(text, y-1);
				if(x>0){ /*Jika cursor tidak di awal baris*/
					x--;
					for(int i=x; i < curEOL; i++){ /*Geser char ke kiri*/
						text[y][i] = text[y][i+1];
					}
					moveTo(y, x);
					clearLineToRight();
					print1DArr(text, y, x, curEOL);
				}else if(x==0 && y != 0){ /*Jika cursor berada di awal baris*/
					remainder = MAXKOLOM - prevEOL; /*Menghitung berapa ruang yang tersisa di baris atas cursor*/
					if(remainder > 0){ /*Jika terdapat ruang*/
						if(curEOL > remainder){ /*Jika ruang di baris atas tidak cukup untuk menampung char di baris yang ditunjuk cursor*/
							for(int i=0; i<remainder; i++){
								text[y-1][prevEOL+i] = text[y][i];
							}
							for(int i=0; i<curEOL-remainder;i++){
								text[y][i] = text[y][i+remainder];
							}
							text[y][curEOL-remainder] = NULL;
							text[y-1][MAXKOLOM] = NULL;
							y--;
							x = prevEOL;
							moveTo(y,0);
							clearScreenToBottom();
							print2DArr(text, y, amountOfLine);
						}else{ /*Jika ruang di baris atas cukup menampung char di baris yang ditunjuk cursor*/
							for(int i=0; i<curEOL; i++){
								text[y-1][prevEOL+i] = text[y][i];
							}
							text[y-1][prevEOL+remainder] = NULL;
							if(y+1<amountOfLine){ /*Jika dibawah cursor terdapat baris lain*/
								delLine(y, &amountOfLine, text); //geser baris bawah ke atas
							}else{ /*Jika dibawah cursor tidak terdapat baris lain*/
								amountOfLine--;
								text[y+1][0] = NULL;
							}
							y--;
							x = prevEOL;
							moveTo(y, 0);
							clearScreenToBottom();
							print2DArr(text, y, amountOfLine);
						}
					}else if(remainder == 0 && y != 0){ /*Jika tidak terdapat ruang di baris atas*/
						if(curEOL != 0){ /*Jika baris saat ini tidak kosong*/
							text[y-1][prevEOL-1] = text[y][0];
							for(int i = 0; i < curEOL; i++){
								text[y][i]=text[y][i+1];
							}
							curEOL = findEndOfLine(text, y);
							if(curEOL == 0){ //Jika char di baris ini habis maka hapus baris
								delLine(y, &amountOfLine, text);
							}
							y--;
							x = prevEOL-1;
							moveTo(y,0);
							clearScreenToBottom();
							print2DArr(text, y, amountOfLine);
						}else{ /*Jika baris yang ditunjuk cursor kosong */
							if(y < amountOfLine){ /*Jika terdapat baris lain di bawah cursor*/
								delLine(y, &amountOfLine, text);
								clearScreenToBottom();
								print2DArr(text, y, amountOfLine);
								x = prevEOL;
								y--;
							}else{ /*Jika tidak terdapat baris lain di bawah cursor*/
								y--;
								x = prevEOL;
								amountOfLine--;
								text[y+1][0] = NULL;
							}
						}		
					}
				}
				break;
			case CTRL_E: /*Masuk ke command mode*/
				commandMode(&amountOfLine, text);
				system("cls");
				print2DArr(text, 0, amountOfLine);
				x = 0;
				y = 0;
				break;
			case CTRL_Q: /*Keluar */
				done = true;
				system("cls");
				break;
			default:
				if(x < MAXKOLOM){
					text[y][x] = buffer;
					text[y][x+1] = NULL;
					putc(buffer, stdout);
					x++;
				}else if(x >= MAXKOLOM && amountOfLine < MAXBARIS){ //Apabila melebihi batas kolom
					amountOfLine++;
					y++;
					x = 0;
					moveTo(y, x);
					putc(buffer, stdout);
					text[y][x] = buffer;
					x++;
				}
			break;
		}
	}while(!done);
	restoreConsole();
	return amountOfLine;
}
