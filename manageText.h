#ifndef manageText_H
#define manageText_H

#define NIL NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define AmountOfChar(P) (P)->amountOfChar
#define First(L) (L).First

typedef char infotype;
typedef struct tElmtList *address;
typedef struct tElmtList
{
    infotype info;
    address next;
    address prev;
} ElmtList;

/*Linked list untuk menyimpan jml char pada baris*/
typedef struct tJmlChar *address2;
typedef struct tJmlChar
{
    int info;
    address2 next;
    address2 prev;
} JmlChar;

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
} List;

typedef struct
{
    address2 First;
} List2;

typedef struct
{
    rowAddr First;
} RowsList;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty(List L);
bool ListOfRowsEmpty(RowsList L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List *L);
void CreateListOfRows(RowsList *L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
address Alocate(infotype X);
rowAddr AlocateRow(address *L);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlocate(address P);
void DeAlocateRow(rowAddr P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst(List *L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast(List *L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

void InsVAfter(List *L, infotype X, infotype Prec);
/* IS: L TIDAK Kosong */
/* FS: melakukan alokasi sebuah elemen dan */
/* meambahkan elemen sesudah nilai elemen tertentu*/

/**** Penghapusan Elemen ****/
void DelVFirst(List *L, infotype *X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

void DelVLast(List *L, infotype *X);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

void Insert(List *L, infotype X, address *current);
void InsertRow(RowsList *L, address X, rowAddr *current, int posX);
/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst(List *L, address P);
void InsertRowFirst(RowsList *L, rowAddr P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter(List *L, address P, address current);
void InsertRowAfter(RowsList *L, rowAddr P, rowAddr current);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen bernilai Prec */

void InsertLast(List *L, address P, address current);
void InsertRowLast(RowsList *L, rowAddr P, rowAddr current);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsertRowBefore(RowsList *L, rowAddr P, rowAddr current);
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

void DelAfter(List *L, address *Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo(List L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

void RevPrintInfo(List L);
/*IS : List TIDAK kosong */
/*FS: Jika List tidak kosong maka, semua info yang disimpan pada elemen list diprint dari tail */
/*    ke head*/

void DelAll(List *L);

/**** PROSES ENTER NEW LINE ****/
void enterNewLine(List *L, address *current);
/*  IS : 
    L sembarang 
    current terdefinisi bisa di awal, di tengah, akhir
*/
/* FS : L terdefinisi dan terisi dengan elemen baru */
/*      dengan info = '\n' dan Next = Nil */
void DeleteChar(List *L, address *current);
/*  IS : 
    L sembarang  
    current terdefinisi bisa di awal, di tengah, akhir
*/
/* FS : Jika ada elemen list, maka elemen terakhir dihapus */
#endif
