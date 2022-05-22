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
   system ("cls");

   backErrorSource:
   printf("Enter name of file to copy\n");
   scanf("%s", sourceFile);
	for(int i=0; i<strlen(sourceFile); i++){
		if(validateChar(sourceFile[i])){
			printf("Name File can't have %c \n", sourceFile[i]);
			goto backErrorSource;
		}
	}
   source = fopen(sourceFile, "r");

   if (source == NULL)
   {
      printf("\nError opening file\n");
      goto backErrorSource;
   } 

   backError:
   printf("Enter name of target file\n");
   scanf("%s", targetFile);
   	for(int i=0; i<strlen(targetFile); i++){
		if(validateChar(targetFile[i])){
			printf("Name File can't have %c \n", targetFile[i]);
			goto backError;
		}
	}
   target = fopen(targetFile, "w");

   if (target == NULL)
   {
      fclose(source);
      printf("\nError opening file\n");
      goto backError;
   } 

   while ((ch = fgetc(source)) != EOF){
      fputc(ch, target);
   }
   printf("File copied successfully.\n");
   printf("Press any key to continue...");
   getch();
   fclose(source);
   fclose(target);

   system("cls");
}
