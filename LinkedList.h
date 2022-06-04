#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define NIL NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define AmountOfChar(P) (P)->amountOfChar
#define Current(L) (L).Current
#define First(L) (L).First

typedef char infotype;
typedef struct tElmtList *address;
typedef struct tElmtList
{
    infotype info;
    address next;
    address prev;
} ElmtList;

typedef struct tRow *rowAddr;
typedef struct tRow
{
    address info; // pointer to first char in a row "\n"
    rowAddr next;
    rowAddr prev;
    int amountOfChar;
} ListOfRows;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct
{
    address First;
    address Current;
} List;

typedef struct
{
    rowAddr First;
    rowAddr Current;
} RowsList;

typedef struct{
	List charList;
	RowsList rowList;
} text;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty(List L);
bool ListOfRowsEmpty(RowsList L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List * L);
void CreateListOfRows(RowsList * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
address Alocate(infotype X);
rowAddr AlocateRow(address X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlocate(address P);
void DeAlocateRow(rowAddr P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst(List *L, address P);
void InsertRowFirst(RowsList *L, rowAddr P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter(List *L, address P);
void InsertRowAfter(RowsList *L, rowAddr P);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen bernilai Prec */

void InsertLast(List *L, address P);
void InsertRowLast(RowsList *L, rowAddr P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsertRowBefore(RowsList *L, rowAddr P);
/**** Penghapusan sebuah elemen ****/
void DelFirst(List *L, address *P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelVMid(List *L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast(List *L, address *P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void DelAfter (List * L, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

/**** PRINT ELEMEN LIST  ****/
void PrintList(List L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
void PrintToEOL(address start);
void PrintToNULL(address start);

#endif