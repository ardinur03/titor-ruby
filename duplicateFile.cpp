/*
 * Nama file duplicateFile.cpp
 * sumber_source_code : https://forgetcode.com/c/577-copy-one-file-to-another-file
 * di edit oleh : Naufal Salman Mulyadi
*/
#include "helper.h"

void duplicateFile()
{
   char ch, sourceFile[100], targetFile[100];
   FILE *source, *target;
   showCursor();
   backErrorSource:
   gotoxy(5, 5);
   printf("Enter name of file to copy : ");
   scanf("%s", sourceFile);
	for(int i=0; i<strlen(sourceFile); i++){
		if(validateChar(sourceFile[i])){
         gotoxy(5, 6);
			printf("Name File can't have %c ", sourceFile[i]);
         gotoxy(27, 5);
         printf("        ");
			goto backErrorSource;
		}
	}
   source = fopen(sourceFile, "r");

   if (source == NULL)
   {
      gotoxy(5, 6);
      printf("Error opening file");
      gotoxy(27, 5);
      printf("        ");
      goto backErrorSource;
   } 

   backError:
   gotoxy(5, 6);
   printf("Enter name of target file : ");
   scanf("%s", targetFile);
   	for(int i=0; i<strlen(targetFile); i++){
		if(validateChar(targetFile[i])){
         gotoxy(5, 7);
			printf("Name File can't have %c ", targetFile[i]);
			goto backError;
		}
	}
   target = fopen(targetFile, "w");

   if (target == NULL)
   {
      fclose(source);
      gotoxy(5, 7);
      printf("Error opening file");
      goto backError;
   } 

   while ((ch = fgetc(source)) != EOF){
      fputc(ch, target);
   }
   gotoxy(5, 8);
   printf("File copied successfully.");
   
   getch();
   fclose(source);
   fclose(target);

   	gotoxy(5, 9);
    system("pause");
    system("cls");
}
