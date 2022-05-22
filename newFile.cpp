#include "helper.h"
#include "manageText.h"
#include "saveToFile.h"

void newFile()
{
    system("cls");
    List textNow;
    char choice;

    int jmlBaris = insertTextMode(textNow, 0);
    while (1)
    {
        printf("Do you want to save the file? (y/n) : ");
        choice = getch();
        if (choice == 'y')
        {
            saveFile(jmlBaris, textNow);
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
}