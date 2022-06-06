
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty (CharsList L) {
    return (First(L)==NIL);
}

bool ListOfRowsEmpty (RowsList L) {
    return (First(L)==NIL);
}
/**** Konstruktor/Kreator CharsList Kosong ****/
void CreateList (CharsList * L) {
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
    P = (address)malloc(sizeof(charNode));
    if (P!=NIL){
        Info(P) = X;
        Next(P) = NIL;
        Prev(P) = NIL;
    }
    return P;
}

rowAddr AlocateRow (address X) {
	rowAddr P;
	P = (rowAddr)malloc(sizeof(rowNode));
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

void InsertFirst (CharsList * L, address P) {
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

void InsertAfter(CharsList * L, address P) {
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

void InsertLast (CharsList * L, address P) {
	Next(Current(*L)) = P;
	Prev(P) = Current(*L);
}

void InsertRowLast (RowsList *L, rowAddr P) {
	Next(Current(*L)) = P;
	Prev(P) = Current(*L);
}

/**** Penghapusan sebuah address ****/
void DelFirst (CharsList * L, address * P) {
	*P = First(*L);
	First(*L) = Next(First(*L));
	if(First(*L) != NULL){
		Prev(First(*L)) = NIL;	
	}
	Next(*P) = NIL;
	
}

void DelRowFirst (RowsList * L, rowAddr * P) {
	*P = First(*L);
	First(*L) = Next(First(*L));
	if(First(*L) != NULL){
		Prev(First(*L)) = NIL;	
	}
	Next(*P) = NIL;
}

void DelLast (CharsList * L, address * P) {
	if(Next(First(*L)) == NIL){
		DelFirst(L, P);
	}else{
		*P = First(*L);
		while(Next(*P) != NIL){
			*P=Next(*P);	
		}
		Next(Prev(*P)) = NIL;	
	}
}

void DelRowLast (RowsList * L, rowAddr * P) {
	*P = Current(*L);
	
	if(Next(First(*L)) == NIL){
		DelRowFirst(L, P);
	}else{
		Next(Prev(*P)) = NIL;	
	}
}

void DelAfter (CharsList * L, address * Pdel, address Prec) {
	if(Next(Next(Prec))==NULL){
		DelLast(L, Pdel);
	}else{
		*Pdel = Next(Prec);
		Prev(Next(Next(Prec))) = Prec;
		Next(Prec) = Next(Next(Prec));
	}
}

void DelRowAfter (RowsList *L, rowAddr * Pdel, rowAddr Prec) {
	*Pdel = Next(Prec);
	Prev(Next(Next(Prec))) = Prec;
	Next(Prec) = Next(Next(Prec));
}

/**** PRINT ELEMEN LIST ****/
void PrintList (CharsList L) { 
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
