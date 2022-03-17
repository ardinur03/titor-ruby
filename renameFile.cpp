#include <stdio.h>
#include <windows.h>

void renameFile()
{
    // Path to old and new files
    char oldName[100], newName[100];

    // Input old and new file name
    system ("cls");
    printf("Enter the name of the file you want to change: ");
    scanf("%s", oldName);

    printf("enter new file name: ");
    scanf("%s", newName);


    // rename old file with new name
    if (rename(oldName, newName) == 0)
    {
        printf("The file was renamed successfully.\n");
    }
    else
    {
        printf("Unable to rename file. Please check the file exists and you have permission to modify the file.\n");
    }

}
