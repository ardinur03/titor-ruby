
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
	Current(*L)=NIL;
}

void CreateListOfRows (RowsList * L) {
	First(*L)=NIL;
	Current(*L)=NIL;
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

void InsertAfter(List * L, address P) {
    Next(P) = Next(Current(*L));
    Prev(P) = Current(*L);
    Prev(Next(Current(*L))) = P;
    Next(Current(*L)) = P;
}

void InsertRowAfter (RowsList *L, rowAddr P) {
    if(Next(Current(*L))==NULL){
    	InsertRowLast(L, P);
	}else{
		Next(P) = Next(Current(*L));
    	Prev(P) = Current(*L);
    	Prev(Next(Current(*L))) = P;
    	Next(Current(*L)) = P;	
	}
}

void InsertLast (List * L, address P) {
	Next(Current(*L)) = P;
	Prev(P) = Current(*L);
}

void InsertRowLast (RowsList *L, rowAddr P) {
	Next(Current(*L)) = P;
	Prev(P) = Current(*L);
}

/**** Penghapusan sebuah address ****/
void DelFirst (List * L, address * P) {
	if(First(*L)==NIL){
		printf("List kosong.\n");
	}else{
		*P = First(*L);
		First(*L) = Next(First(*L));
		if(First(*L) != NULL){
			Prev(First(*L)) = NIL;	
		}
		Next(*P) = NIL;
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

/**** PRINT ELEMEN LIST ****/
void PrintList (List L) { 
	address P;
	P = First(L);
	while(P != NIL){
		printf("%c", Info(P));	
		P = Next(P);
	}
}

void PrintToEOL(address start){
	address P;
	P = start;
	while(P != NIL){
		if(Info(P) != '\n'){
			printf("%c", Info(P));	
			P = Next(P);
		}else{
			break;
		}
	}
}

void PrintToNULL(address start){
	address P;
	P = start;
	while(P != NIL){
		printf("%c", Info(P));	
		P = Next(P);
	}
}
