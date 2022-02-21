#include <stdio.h>
#include "createFile.h"
#define MAXBARIS 80
#define MAXKOLOM 40

/*
Note:
+ Membuat input ke array text
- Array text belum disave ke file
- Masih menggunakan variabel global
*/

/*Variabel Global*/
char text[MAXBARIS][MAXKOLOM];
int banyakBaris;
/*---------------*/

void createFile(){
  int banyakBaris, i, j;
  printf("Masukan baris kosong untuk keluar.\n");

  for(banyakBaris = 0; banyakBaris < MAXBARIS; banyakBaris++) {
    printf("%d: ", banyakBaris+1);
    gets(text[banyakBaris]);
    if(!*text[banyakBaris]){
   		break; /* Keluar jika baris kosong */	
	}
  }
}
