#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

void duplicateFile()
{
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
   system ("cls");

   printf("Enter name of file to copy\n");
   fflush(stdin);
   gets(source_file);

   source = fopen(source_file, "r");

   if (source == NULL)
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   printf("Enter name of target file\n");
   gets(target_file);

   target = fopen(target_file, "w");

   if (target == NULL)
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);

   printf("File copied successfully.\n");

   fclose(source);
   fclose(target);
}
