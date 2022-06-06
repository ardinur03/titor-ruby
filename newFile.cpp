#include "helper.h"
#include "manageText.h"
#include "saveToFile.h"

void newFile()
{
    system("cls");
    CharsList textNow;
    RowsList rows;
    char choice;
    
	showCursor();
	CreateList(&textNow);
	CreateListOfRows(&rows);
    insertTextMode(&textNow, &rows);
    while (1)
    {
        printf("Do you want to save the file? (y/n) : ");
        choice = getch();
        if (choice == 'y')
        {
            saveFile(textNow);
            break;
        }
        else if (choice == 'n')
        {
            system("cls");
            printf("\nYour file is not saved!");
            getch();
            break;
        }
        else
        {
            printf("\n");
            printf("Wrong Input!\n");
        }
    }
    system("cls");
}