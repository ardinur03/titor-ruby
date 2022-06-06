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
typedef struct tcharNode *address;
typedef struct tcharNode
{
    infotype info;
    address next;
    address prev;
} charNode;

typedef struct trowNode *rowAddr;
typedef struct trowNode
{
    address info; // pointer to first node in a row "\n"
    rowAddr next;
    rowAddr prev;
    int amountOfChar;
} rowNode;

/* Definisi list : */
/* CharsList kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct
{
    address First;
    address Current;
} CharsList;

typedef struct
{
    rowAddr First;
    rowAddr Current;
} RowsList;

typedef struct{
	CharsList charList;
	RowsList rowList;
} text;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty(CharsList L);
bool ListOfRowsEmpty(RowsList L);
/* Mengirim true jika CharsList Kosong */

/**** Konstruktor/Kreator CharsList Kosong ****/
void CreateList(CharsList * L);
void CreateListOfRows(RowsList * L);
/* IS : L sembarang */
/* FS : Terbentuk CharsList Kosong */

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
void InsertFirst(CharsList *L, address P);
void InsertRowFirst(RowsList *L, rowAddr P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter(CharsList *L, address P);
void InsertRowAfter(RowsList *L, rowAddr P);
/* IS : Prec pastilah elemen CharsList dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen bernilai Prec */

void InsertLast(CharsList *L, address P);
void InsertRowLast(RowsList *L, rowAddr P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

/**** Penghapusan sebuah elemen ****/
void DelFirst(CharsList *L, address *P);
void DelRowFirst (RowsList * L, rowAddr * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelLast(CharsList *L, address *P);
void DelRowLast (RowsList * L, rowAddr * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void DelAfter (CharsList * L, address * Pdel, address Prec);
void DelRowAfter (RowsList *L, rowAddr * Pdel, rowAddr Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota CharsList */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

/**** PRINT ELEMEN LIST  ****/
void PrintList(CharsList L);
/* IS : L mungkin kosong */
/* FS : Jika CharsList tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "CharsList Kosong" */

void PrintToEOL(address start);
/* IS: start berisi address dari node pertama yang akan di print*/
/* FS: Menampilkan info dari node beralamat start hingga node terakhir di baris*/

void PrintToNULL(address start);
/* IS: start berisi address dari node pertama yang akan di print*/
/* FS: Menampilkan info dari node beralamat start hingga node terakhir di list*/

#endif