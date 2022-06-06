#include <stdio.h>
#include "helper.h"
#include "manageText.h"
#include "LinkedList.h"
#include "ansiEscapes.h"

void insertTextMode(List *text, RowsList *rows){
    char buffer;
	int posX=0, posY=0, CharTemp;
    
	if(ListOfRowsEmpty(*rows)){ //Jika file baru/ text kosong
		InsertRow(rows, NULL, posX);
	}

	/*Set cursor*/
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
				SpecialKeyHandle(text, rows, &posX, &posY);
				break;
			case ENTER:
				Insert(text, '\n');
				InsertRow(rows, Current(*text), posX);
				posY++;
				posX = 0;
				break;
			case BACKSPACE:
				if(posX != 0 || posY != 0){
					CharTemp = AmountOfChar(Current(*rows));
					if(Info(Current(*text)) == '\n'){
						Current(*rows) = Prev(Current(*rows));
						posX = AmountOfChar(Current(*rows));
						posY--;
						AmountOfChar(Current(*rows)) = AmountOfChar(Current(*rows)) + CharTemp;

						/*Delete node di list rows*/
						DeleteRow(rows, &Current(*rows));
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

	/*Check jika alokasi gagal*/
	if(P == NIL){
		printf("Gagal mengalokasi node");
		return;
	}
	
	/*Insert node ke list*/
	if(Current(*L) == NULL){ /* Jika cursor menunjuk ke null*/
		InsertFirst(L, P);
		Current(*L) = First(*L);
		if(X =='\n'){ /*Jika menambah baris baru*/
			clearScreenToBottom(); /*Clear layar dari pos cursor ke bawah*/
			PrintToNULL(Current(*L));
			return;
		}
		PrintToEOL(Current(*L));
	}else if(Next(Current(*L))==NULL){ /*Jika cursor berada di akhir list*/
		InsertLast(L, P);
		Current(*L) = Next(Current(*L));
		printf("%c", X);
	}else{ /*Jika cursor berada di tengah list*/
		InsertAfter(L, P);
		Current(*L) = Next(Current(*L));
		if(X == '\n'){ /*Jika menambah baris baru*/
			clearScreenToBottom(); /*Clear layar dari pos cursor ke bawah*/
			PrintToNULL(Current(*L));
			return;
		}
		PrintToEOL(Current(*L));
	}
}

void InsertRow (RowsList *L, address X, int posX){
	rowAddr P;
	P = AlocateRow(X);
	
	/*Check jika alokasi gagal*/
	if(P == NIL){
		printf("Gagal mengalokasi node");
		return;
	}

	/**Insert node ke list**/
	/*Jika list kosong*/
	if(ListOfRowsEmpty(*L)){
		InsertRowFirst(L, P);
		Current(*L) = First(*L);
		return;
	}

	if(posX == 0){ /* Jika cursor berada di awal*/
		InsertRowAfter(L, P); 
		Current(*L) = Next(Current(*L));
		/*Isi jumlah huruf baris baru dengan baris yg lama, isi yg lama dengan 0*/
		AmountOfChar(Current(*L)) = AmountOfChar(Prev(Current(*L)));
		AmountOfChar(Prev(Current(*L))) = 0;					
	}else if(posX == AmountOfChar(Current(*L))){ /*Jika cursor berada di akhir*/
		InsertRowLast(L, P);
		Current(*L) = Next(Current(*L));
	}else{ /*Jika cursor berada di tengah*/
		InsertRowAfter(L, P);
		Current(*L) = Next(Current(*L));

		/**Hitung jumlah huruf pada baris**/
		/*Jumlah huruf baris baru = jumlah huruf baris lama - posisi cusor*/
		AmountOfChar(Current(*L)) = AmountOfChar(Prev(Current(*L))) - posX;
		/*Jumlah huruf baris lama = posisi cursor*/
		AmountOfChar(Prev(Current(*L))) = posX;
	}
}

void DeleteRow(RowsList *L, rowAddr *current){
	rowAddr P;
	if(*current != NULL){
		if(Next(*current) != NULL){ 
			DelRowAfter(L, &P, *current);
 		} 
	}else if(*current == NULL){
		DelRowFirst(L, &P);
	}

	// dealokasi elemen yang dihapus
	DeAlocateRow(P);
}


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

void SpecialKeyHandle(List *text, RowsList *rows, int *posX, int *posY){
	int CharCountTemp;
	switch(getch()){
		case ARROW_UP:
			if(Prev(Current(*rows)) != NULL){ /*Check jika ada baris di atas*/
	        	/*Pindahkan cursor ke node pertama di baris bawah*/
				Current(*rows) = Prev(Current(*rows));
	        	Current(*text) = Info(Current(*rows));
				
				/*Bandingkan posisi cursor sebelumnya dengan banyak huruf di baris atas*/
				if(AmountOfChar(Current(*rows)) < *posX){ 
					*posX = AmountOfChar(Current(*rows));
				}

				/*Traverse hingga posX sebelumnya atau ke akhir baris*/
	        	for(int i=0; i < *posX; i++){
	        		if(Current(*text) == NULL){ /*Handle jika cursor menunjuk null*/
	        			Current(*text) = First(*text);
					}else{
						Current(*text) = Next(Current(*text));
					}
				}
				(*posY)--;
			}
			break;
		case ARROW_DOWN:
	        if(Next(Current(*rows)) != NULL){ /*Check jika ada baris di bawah*/
				/*Pindahkan cursor ke node pertama di baris bawah*/
	        	Current(*rows) = Next(Current(*rows));
	        	Current(*text) = Info(Current(*rows));
				
				/*Bandingkan posisi cursor sebelumnya dengan banyak huruf di baris bawah*/
				if(AmountOfChar(Current(*rows)) < *posX){ 
					*posX = AmountOfChar(Current(*rows));
				}

				/*Traverse hingga posisi posX sebelumnya atau hingga akhir baris*/
	        	for(int i=0; i< *posX; i++){
					Current(*text) = Next(Current(*text));
				}
				(*posY)++;
			}
			break;
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
			break;
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
			break;
		case HOME:
			Current(*text) = Info(Current(*rows));
			*posX = 0;
			break;
		case END:
			if(ListEmpty(*text)){
				break;
			}
			if(Current(*text) == NULL){
				Current(*text) = First(*text);
			}
			while(Next(Current(*text)) != NULL){
				if(Info(Next(Current(*text))) == '\n'){
					break;
				}else{
					Current(*text) = Next(Current(*text));
				}
			}
			*posX = AmountOfChar(Current(*rows));
		break;
		case DELETE_BUTTON:
			CharCountTemp = AmountOfChar(Current(*rows)); // tampung banyak nilai sekarang di baris
			if(Info(Next(Current(*text))) == '\n'){
				Current(*rows) = Next(Current(*rows));
				*posX = AmountOfChar(Current(*rows));
				posY--;
				AmountOfChar(Current(*rows)) = AmountOfChar(Current(*rows)) + CharCountTemp;
			}
			else{
				AmountOfChar(Current(*rows)) = AmountOfChar(Current(*rows)) - 1;
			}
			DeleteChar(text, &Current(*text));
		break;
	}
}


