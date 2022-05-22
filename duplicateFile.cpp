/*
 * Nama file duplicateFile.cpp
 * sumber_source_code : https://forgetcode.com/c/577-copy-one-file-to-another-file
 * di edit oleh : Naufal Salman Mulyadi
*/
#include "helper.h"

void duplicateFile()
{
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
   system ("cls");

   backErrorSource:
   printf("Enter name of file to copy\n");
   scanf("%s", source_file);

   source = fopen(source_file, "r");

   if (source == NULL)
   {
      printf("\nError opening file\n");
      goto backErrorSource;
   } 

   backError:
   printf("Enter name of target file\n");
   scanf("%s", target_file);
   target = fopen(target_file, "w");

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
