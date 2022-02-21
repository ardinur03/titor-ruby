#include <stdio.h>
#include "createFile.h"

/*
Note:
+ Dapat menampilkan isi dari array text
- Array text belum dibaca dari file
*/

void displayFile(){
  for(int i = 0; i < banyakBaris; i++) {
  	printf("%d. ", i+1);
    for(int j = 0; text[ i ][ j ]; j++){
    	putchar(text[ i ][ j ]);
	}
    putchar('\n');
  }
}
