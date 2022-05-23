/* Deskripsi  		 : Pendefinisian Modul-modul berkaitan dengan operasi-operasi terhadap */
/*				 	   sebuah Non Restricted Doubly Linked List Non Circular*/
/* Source 			 : https://pintarkom.com/double-linked-list-pada-c-plus/
/* Dimodifikasi oleh : 1A_Luthfie Yannuardy_211511019
/* Tanggal     		 : 31-03-2022 */

#include "helper.h"
#include "manageText.h"

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty (List L) {
    return (First(L)==NIL);
}

bool ListOfRowsEmpty (RowsList L) {
    return (First(L)==NIL);
}
/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L) {
	First(*L)=NIL;
}

void CreateListOfRows (RowsList * L) {
	First(*L)=NIL;
}

/**** Manajemen Memory ****/
address Alocate (infotype X) {
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P!=NIL){
        Info(P) = X;
        Next(P) = NIL;
        Prev(P) = NIL;
    }
    return P;
}

rowAddr AlocateRow (address X) {
	rowAddr P;
	P = (rowAddr)malloc(sizeof(ListOfRows));
	if(P!=NIL){
		Info(P) = X;
		Next(P) = NULL;
		Prev(P) = NULL;
		AmountOfChar(P) = 0;
	}
	return P;
}

void DeAlocate (address P) {
	free(P);
}

void DeAlocateRow (rowAddr P) {
	free(P);
}


/**** PRIMITIF BERDASARKAN NILAI ****/
void Insert (List *L, infotype X, address *current){
	address P;
	P = Alocate(X);
	if(P != NIL){
		if(*current == NULL){ /* Jika cursor berada di awal*/
			InsertFirst(L, P);
			*current = First(*L);
			system("cls");
			PrintInfo(*L);
		}else if(Next(*current)==NULL){ /*Jika cursor berada di akhir*/
			InsertLast(L, P, *current);
			*current = Next(*current);
		}else{ /*Jika cursor berada di tengah*/
			InsertAfter(L, P, *current);
			*current = Next(*current);
			system("cls");
			PrintInfo(*L);
		}
	}
}

void InsertRow (RowsList *L, address X, rowAddr *current, int posX){
	int temp;
	rowAddr P;
	P = AlocateRow(X);
	if(P != NIL){
		if(!ListOfRowsEmpty(*L)){ /*Jika list tidak kosong*/
			if(posX == 0){ /* Jika cursor berada di awal*/
					InsertRowAfter(L, P, *current); 
					*current = Next(*current);
					/*Swap Amount of char new line yang baru dengan yang lama*/
					temp = AmountOfChar(*current);
					AmountOfChar(*current) = AmountOfChar(Prev(*current));
					AmountOfChar(Prev(*current)) = temp;					
			}else if(posX == AmountOfChar(*current)){ /*Jika cursor berada di akhir*/
				InsertRowLast(L, P, *current);
				*current = Next(*current);
			}else{ /*Jika cursor berada di tengah*/
				InsertRowAfter(L, P, *current);
				*current = Next(*current);
				AmountOfChar(*current) = AmountOfChar(Prev(*current)) - posX;
				AmountOfChar(Prev(*current)) = posX;
			}
		}else{
			InsertRowFirst(L, P);
			*current = First(*L);
		}
	}
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X) {
	address P;
	DelFirst(L, &P);
	*X = Info(P);
	Next(P) = NIL;
	DeAlocate(P);
}

void DelVLast (List * L, infotype * X) {
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Next(P) = NIL;
	DeAlocate(P);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/

void InsertFirst (List * L, address P) {
	if(First(*L)==NULL){
		First(*L)=P;
	}else{
		Next(P) = First(*L);
		Prev(First(*L)) = P;
		First(*L) = P;
	}
}

void InsertRowFirst (RowsList *L, rowAddr P) {
	if(First(*L)==NULL){
		First(*L)=P;
	}else{
		Next(P) = First(*L);
		Prev(First(*L)) = P;
		First(*L) = P;
	}
}

void InsertAfter(List * L, address P, address current) {
    Next(P) = Next(current);
    Prev(P) = current;
    Prev(Next(current)) = P;
    Next(current) = P;
}

void InsertRowAfter (RowsList *L, rowAddr P, rowAddr current) {
    if(Next(current)==NULL){
    	InsertRowLast(L, P, current);
	}else{
		Next(P) = Next(current);
    	Prev(P) = current;
    	Prev(Next(current)) = P;
    	Next(current) = P;	
	}
}

void InsertRowBefore (RowsList *L, rowAddr P, rowAddr current) {
	if(Prev(current)==NULL){
		InsertRowFirst(L, P);
	}else{
		Next(P) = current;
		Prev(P) = Prev(current);
		Next(Prev(current)) = P;
		Prev(current) = P;
	}
}

void InsertLast (List * L, address P, address current) {
	Next(current) = P;
	Prev(P) = current;
}


void InsertRowLast (RowsList *L, rowAddr P, rowAddr current) {
	Next(current) = P;
	Prev(P) = current;
}

/**** Penghapusan sebuah address ****/
void DelFirst (List * L, address * P) {
	if(First(*L)==NIL){
		printf("List kosong.\n");
	}else{
		*P = First(*L);
		First(*L) = Next(First(*L));
		Prev(First(*L)) = NIL;
		Next(*P) = NIL;
	}
}

void DelVMid (List * L, infotype X) {
	address P;
	address temp;
	if(First(*L)==NIL){
		printf("List kosong.\n");
	}else{
		temp = First(*L);
		while((Info(Next(temp)) != X)){
			temp = Next(temp);
		}
		P = Next(temp);
		Prev(Next(Next(temp))) = temp;
		Next(temp) = Next(Next(temp));
		Next(P) = NIL;
		Prev(P) = NIL;
	}
}

void DelLast (List * L, address * P) {
	if(First(*L) == NIL){
		printf("Linked list kosong\n");
	}else if(Next(First(*L)) == NIL){
		DelFirst(L, P);
	}else{
		*P = First(*L);
		while(Next(*P) != NIL){
			*P=Next(*P);	
		}
		Next(Prev(*P)) = NIL;	
	}
}

void DelAfter (List * L, address * Pdel, address Prec) {
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L) { 
	address P;
	P = First(L);
	while(P != NIL){
		printf("%c", Info(P));	
		P = Next(P);
	}
}

void RevPrintInfo(List L){
	address P;
	P = First(L);
	if(P!=NIL){
		First(L) = Next(P);
		RevPrintInfo(L);
		printf("%c, ", Info(P));
	}
}

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/
void DelAll (List * L) {
	address P;
	
	P = First(*L);
	while(P!=NIL)
	{
		First(*L) = Next(First(*L));
		Next(P) = NIL;
		DeAlocate(P);
		P = First(*L);
	}
}

/** 
 * Dibuat oleh Muhamad Ardi Nur Insan 211511022
 * module local : enterNewLine, DeleteChar
*/ 
void enterNewLine(List *L, address *current){
	address P;
	P = Alocate('\n');
	if(P != NIL){
		if(*current == NULL){ /* Jika cursor berada di awal*/
			InsertFirst(L, P);
			*current = First(*L);
			system("cls");
			PrintInfo(*L);
		}else if(Next(*current)==NULL){ /*Jika cursor berada di akhir*/
			InsertLast(L, P, *current);
			*current = Next(*current);
		}else{ /*Jika cursor berada di tengah*/
			InsertAfter(L, P, *current);
			*current = Next(*current);
			system("cls");
			PrintInfo(*L);
		}
	}
}

void DeleteChar(List *L, address *current){
	address P;
	if(*current != NULL){
		if(Next(*current) != NULL){ // jika cursor tidak berada di akhir
			DelAfter(L, &P, *current);
 		}
	}
	system("cls"); // clear screen
	PrintInfo(*L); // print text
}

/**
 * @note insertTextMode untuk mengeloka char yang akan diketik
 * @param textTemp 
 * @param postYTemp 
 * @return int 
 */
int insertTextMode(List textTemp, int postYTemp){
//    List textTemp;
	RowsList rows;
    char buffer;
    address cursor;
    rowAddr curRow;
	int posX=0, posY=postYTemp, posInARow=0;
    bool done = false;
	
    CreateList(&textTemp);
    CreateListOfRows(&rows);
    
	cursor = NULL;
	curRow = NULL;
	
	InsertRow(&rows, NULL, &curRow, posX);

    do{
    	// Debugging
		// SetCursorPosition(0, 15);
	    // printf("x: %-3d\n", posX);
	    // printf("y: %-3d\n", posY);
	    // printf("pos in row: %-3d\n", posInARow);
	    // printf("amount of char in a row: %-3d\n", AmountOfChar(curRow));
	    // printf("Pointer cursor: %p\n", cursor);
	    // printf("Pointer row: %p\n", curRow);
	    // printf("Pointer in a row: %p", Info(curRow));
    	SetCursorPosition(posX, posY);
        buffer = getch();
        switch (buffer){
	        case ']':
	        	printf("\n\n\n");
	            PrintInfo(textTemp);
	            break;
	        case '[':
	        	SetCursorPosition(5, 10);
	        	printf("\n\n\n\n");
	        	printf("x: %d\n", posX);
	        	printf("y: %d\n", posY);
	        	printf("pos in row: %d\n", posInARow);
	        	printf("amount of char in a row: %d", AmountOfChar(curRow));
	        	SetCursorPosition(posX, posY);
            break;
	        case '/':
	        	printf("\n\n\n\n\n");
	        	printf("Char in Linked List: %d", AmountOfChar(curRow));
            break;
	        case 'i': //atas
	        	if(Prev(curRow) != NULL){
	        		curRow = Prev(curRow);
	        		cursor = Info(curRow);
	        		for(int i=0; i < posInARow && AmountOfChar(curRow) != 0; i++){
	        			if(cursor == NULL){
	        				cursor = First(textTemp);	
						}else if(Info(Next(cursor)) == '\n'){
							posInARow = AmountOfChar(curRow);
							posX = AmountOfChar(curRow);
							break;
						}else{
							cursor = Next(cursor);
						}
					}
					if(AmountOfChar(curRow) == 0){
						posInARow = AmountOfChar(curRow);
						posX = AmountOfChar(curRow);//tab belum di Handle
					}
					posY--;
				}
            break;
	        case 'k': //bawah
	        	if(Next(curRow) != NULL){
	        		curRow = Next(curRow);
	        		cursor = Info(curRow);
	        		for(int i=0; i<posInARow;i++){
	        			if(AmountOfChar(curRow)==0 || Next(cursor)==NULL || Info(Next(cursor))=='\n'){
	        				posInARow = AmountOfChar(curRow);
	        				posX = AmountOfChar(curRow);
							break;
						}
						cursor = Next(cursor);
					}
					posY++;
				}
            break;
	        case 'j': //kiri
	        	if(cursor != NULL){
	        		if(Info(cursor) == '\n'){
	        			curRow = Prev(curRow);
						posX = AmountOfChar(curRow);
	        			posInARow = AmountOfChar(curRow);
	        			posY--;
					}else{
	        			posX--;
	        			posInARow--;
					}
					cursor = Prev(cursor);
				}
            break;
	        case 'l': //kanan
	        	if(!ListEmpty(textTemp)){
	        		if(cursor == NULL){ //Handle jika cursor berada di awal teks
		        		cursor = First(textTemp);
		        		if(Info(First(textTemp))== '\n'){
		        			posX = 0;
							posInARow = 0;
							posY++;
							curRow = Next(curRow);
						}else{
							posX++;
		        			posInARow++;	
						}
					}else if(Next(cursor) != NULL){
						cursor = Next(cursor);
						if(Info(cursor)  == '\n'){ //Handle apabila cursor di akhir baris
							posX = 0;
							posInARow = 0;
							posY++;
							curRow = Next(curRow);
						}else{
		        			posX++;
		        			posInARow++;
						}
					}
				}
            break;
	        case ENTER: // new feature
	        	printf("%c", buffer);
				enterNewLine(&textTemp, &cursor);
				InsertRow(&rows, cursor, &curRow, posX);
				posY++;
				posX = 0;
				posInARow = 0;
            break;
			case BACKSPACE: //backspace
				if(posX == 0 && posY == 0){
					continue;
				}else{
					if(Info(cursor) == '\n'){
						curRow = Prev(curRow);
						posX = AmountOfChar(curRow);
						posInARow = AmountOfChar(curRow);
						posY--;
					}else{
						posX--;
						posInARow--;
					}
					cursor = Prev(cursor);
					DeleteChar(&textTemp, &cursor);
				}
            break;
            case QUITAPP: 
                done = true;
                system("cls");
			break;
	        default:
	        	printf("%c", buffer);
	            Insert(&textTemp, buffer, &cursor);
	            posX++;
	            posInARow++;
	            AmountOfChar(curRow)++;
            break;
        }
    }while(!done);

    // kembalikan jumlah baris
    return posY;

}
