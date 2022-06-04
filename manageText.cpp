#include <stdio.h>
#include "helper.h"
#include "manageText.h"
#include "LinkedList.h"
#include "ansiEscapes.h"

void insertTextMode(List *text, RowsList *rows){
    char buffer;
	int posX=0, posY=0;
    bool done = false;
    
	if(ListOfRowsEmpty(*rows)){ //Jika file baru/ text kosong
		InsertRow(rows, NULL, posX);
	}
	Current(*text) = NULL;
	Current(*rows) = First(*rows);
    do{
    	// Debugging
		SetCursorPosition(0, 15);
	    printf("x: %-3d\n", posX);
	    printf("y: %-3d\n", posY);
	    printf("amount of char in a row: %-3d\n", AmountOfChar(Current(*rows)));
	    printf("Pointer cursor: %p\n", Current(*text));
	    printf("Pointer row: %p\n", Current(*rows));
	    printf("Pointer in a row: %p", Info(Current(*rows)));
    	
		SetCursorPosition(posX, posY);
		buffer = getch();

		if(buffer == QUITAPP){
			return;
		}

		switch(buffer){
			case -32:
				CursorHandle(text, rows, &posX, &posY);
				break;
			case ENTER:
				Insert(text, '\n');
				InsertRow(rows, Current(*text), posX);
				posY++;
				posX = 0;
				break;
			case BACKSPACE:
				if(posX != 0 || posY != 0){
					if(Info(Current(*text)) == '\n'){
						Current(*rows) = Prev(Current(*rows));
						posX = AmountOfChar(Current(*rows));
						posY--;
					}else{
						posX--;
						AmountOfChar(Current(*rows))--;
					}
					Current(*text) = Prev(Current(*text));
					DeleteChar(text, &Current(*text));
				}
				break;
			default:
				Insert(text, buffer);
	       		posX++;
	        	AmountOfChar(Current(*rows))++;
		}
    }while(true);
}

void Insert (List *L, infotype X){
	address P;
	P = Alocate(X);
	if(P != NIL){
		if(Current(*L) == NULL){ /* Jika cursor berada di awal*/
			InsertFirst(L, P);
			Current(*L) = First(*L);
			if(X =='\n'){
				clearLineToRight();
				PrintToNULL(Current(*L));
			}else{
				PrintToEOL(Current(*L));
			}
		}else if(Next(Current(*L))==NULL){ /*Jika cursor berada di akhir*/
			InsertLast(L, P);
			Current(*L) = Next(Current(*L));
			printf("%c", X);
		}else{ /*Jika cursor berada di tengah*/
			InsertAfter(L, P);
			Current(*L) = Next(Current(*L));
			if(X == '\n'){
				clearLineToRight();
				PrintToNULL(Current(*L));
			}else{
				PrintToEOL(Current(*L));
			}
		}
	}
}

void InsertRow (RowsList *L, address X, int posX){
	int temp;
	rowAddr P;
	P = AlocateRow(X);
	if(P != NIL){
		if(!ListOfRowsEmpty(*L)){ /*Jika list tidak kosong*/
			if(posX == 0){ /* Jika cursor berada di awal*/
					InsertRowAfter(L, P); 
					Current(*L) = Next(Current(*L));
					/*Swap Amount of char new line yang baru dengan yang lama*/
					temp = AmountOfChar(Current(*L));
					AmountOfChar(Current(*L)) = AmountOfChar(Prev(Current(*L)));
					AmountOfChar(Prev(Current(*L))) = temp;					
			}else if(posX == AmountOfChar(Current(*L))){ /*Jika cursor berada di akhir*/
				InsertRowLast(L, P);
				Current(*L) = Next(Current(*L));
			}else{ /*Jika cursor berada di tengah*/
				InsertRowAfter(L, P);
				Current(*L) = Next(Current(*L));
				AmountOfChar(Current(*L)) = AmountOfChar(Prev(Current(*L))) - posX;
				AmountOfChar(Prev(Current(*L))) = posX;
			}
		}else{
			InsertRowFirst(L, P);
			Current(*L) = First(*L);
		}
	}
}

/** 
 * Dibuat oleh Muhamad Ardi Nur Insan 211511022
 * module local : DeleteChar
*/ 

void DeleteChar(List *L, address *current){
	address P;
	if(*current != NULL){
		if(Next(*current) != NULL){ // jika cursor tidak berada di akhir
			DelAfter(L, &P, *current);
 		} 
	}else if(*current == NULL){
		DelFirst(L, &P);
	}

	system("cls");
	PrintList(*L);	

	// dealokasi elemen yang dihapus
	DeAlocate(P);
}

/**
 * @note insertTextMode untuk mengeloka char yang akan diketik
 * @param textTemp 
 * @return int 
 */


void CursorHandle(List *text, RowsList *rows, int *posX, int *posY){
	switch(getch()){
		case ARROW_UP:
			if(Prev(Current(*rows)) != NULL){
	        	Current(*rows) = Prev(Current(*rows));
	        	Current(*text) = Info(Current(*rows));
	        	for(int i=0; i < *posX && AmountOfChar(Current(*rows)) != 0; i++){
	        		if(Current(*text) == NULL){
	        			Current(*text) = First(*text);	
					}else if(Info(Next(Current(*text))) == '\n'){
						*posX = AmountOfChar(Current(*rows));
						break;
					}else{
						Current(*text) = Next(Current(*text));
					}
				}
				if((AmountOfChar(Current(*rows))) == 0){
					*posX = AmountOfChar(Current(*rows));//tab belum di Handle
				}
				(*posY)--;
			}
			return;
		case ARROW_DOWN:
	        if(Next(Current(*rows)) != NULL){
	        	Current(*rows) = Next(Current(*rows));
	        	Current(*text) = Info(Current(*rows));
	        	for(int i=0; i<*posX;i++){
	        		if(AmountOfChar(Current(*rows))==0 || Next(Current(*text))==NULL || Info(Next(Current(*text)))=='\n'){
	        			*posX = AmountOfChar(Current(*rows));
						break;
					}
					Current(*text) = Next(Current(*text));
				}
				(*posY)++;
			}
			return;
		case ARROW_RIGHT:
	        if(!ListEmpty(*text)){
	        	if(Current(*text) == NULL){ //Handle jika cursor berada di awal teks
		       		Current(*text) = First(*text);
		       		if(Info(First(*text))== '\n'){
		       			*posX = 0;
						(*posY)++;
						Current(*rows) = Next(Current(*rows));
					}else{
						(*posX)++;
					}
				}else if(Next(Current(*text)) != NULL){
					Current(*text) = Next(Current(*text));
					if(Info(Current(*text))  == '\n'){ //Handle apabila cursor di akhir baris
						*posX = 0;
						(*posY)++;
						Current(*rows) = Next(Current(*rows));
					}else{
		       			(*posX)++;
					}
				}
			}
			return;
		case ARROW_LEFT:
	        if(Current(*text) != NULL){
	        	if(Info(Current(*text)) == '\n'){
	        		Current(*rows) = Prev(Current(*rows));
					*posX = AmountOfChar(Current(*rows));
	        		(*posY)--;
				}else{
	        		(*posX)--;
				}
				Current(*text) = Prev(Current(*text));
			}
			return;
	}
}

