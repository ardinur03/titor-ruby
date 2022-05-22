/**
 * @file app.cpp
 * @author 
 * Lolla Mariah - 211511018
 * Luthfie Yannuardy - 211511019
 * Muhamad Ardi Nur Insan - 211511022
 * Muhammad Zidan Hidayat - 211511026
 * Naufal Salman Mulyadi - 211511028
 * Shofiyah - 211511031
 * @version 2.0
 * @date 14 Februari 2022
 * 
 * @copyright Copyright (c) 2022
 * 
*/

#include "helper.h"
#include "header.h"
#include "kelolaText.h"

void app()
{
    home();
}

// menu utama home
void home()
{
    int choose;
    printf("+===========================================================+\n");
    printf("|                       TITOR APPS TEMP                     |\n");
    printf("+===========================================================+\n");
    printf("|                                                           |\n");
    printf("| 1. Run                                                    |\n");
    printf("| 2. About                                                  |\n");
    printf("| 3. Shorcut                                                |\n");
    printf("| 4. Exit                                                   |\n");
    printf("|                                                           |\n");
    printf("+===========================================================+\n");
    printf("|   Copyright (c) 2022 Kelompok RUBY. All rights reserved.  |\n");
    printf("+===========================================================+\n");

    printf("Choose Menu : ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        run();
        break;
    case 2:
        printf("About...\n");
        procedure();
        backMenuHome();
        break;
    case 3:
        printf("Shorcut...\n");
        procedureShorcut();
        backMenuHome();
        break;
    case 4:
        printf("Exit...\n");
        exit(0);
        break;
    default:
        printf("\n Wrong Input!");
        getch();
        system("cls");
        home();
        break;
    }
}

// prosedure about application TiTOR
void procedure()
{
    system("cls");
    printf("+==================================================================+\n");
    printf("|                            About TiTOR                           |\n");
    printf("+==================================================================+\n");
    printf("|                                                                  |\n");
    printf("| TiTOR or Text Editor is an application that can make it easier   |\n");
    printf("| for users to add, change, and save text with a simple and        |\n");
    printf("| easy-to-use interface. This application is based on a console    |\n");
    printf("| made using the C++ language. The making of this application was  |\n");
    printf("| compiled by :                                                    |\n");
    printf("| Lolla Mariah                                                     |\n");
    printf("| Luthfie Yannuardy                                                |\n");
    printf("| Muhamad Ardi Nur Insan                                           |\n");
    printf("| Muhammad Zidan Hidayat                                           |\n");
    printf("| Naufal Salman Mulyadi                                            |\n");
    printf("| Shofiyah                                                         |\n");
    printf("|                                                                  |\n");
    printf("|                                                   --Titor2022    |\n");
    printf("|+================================================================+|\n");
}

// prosedure shorcut application TiTOR
void procedureShorcut()
{
    system("cls");
    printf("+==================================================================+\n");
    printf("|                          Shorcut TiTOR                           |\n");
    printf("+==================================================================+\n");
    printf("|                                                                  |\n");
    printf("| ctrl + n : Used to create file                                   |\n");
    printf("| ctrl + d : Used to duplicate file                                |\n");
    printf("| ctrl + x : Used to delete file                                   |\n");
    printf("| ctrl + o : Used to open file                                     |\n");
    printf("| ctrl + n : Used to rename file                                   |\n");
    printf("| ctrl + q : Used to go out                                        |\n");
    printf("| ctrl + s : Used for save                                         |\n");
    printf("| ctrl + v : Used for paste                                        |\n");
    printf("| ctrl + y : Used for redo                                         |\n");
    printf("| ctrl + z : Used for undo                                         |\n");
    printf("|+================================================================+|\n");
}

void textEditor()
{
    printf(" TiTOR APPS\n");
    printf("\t  ctrl+n   : New File                    ctrl+o : Open File\n");
    printf("\t  ctrl+d   : Duplicate File              ctrl+r : Rename File\n");
    printf("\t  ctrl+x   : Delete File                 ctrl+q : Quit\n");
    printf("\t  ctrl+f   : Find and Replace\n");
}

void run()
{
    int choose;

    system("cls");
    // View menu text editor
    do
    {
        textEditor();
        choose = getch();
        switch (choose)
        {
        case NEWFILE: // ctrl + n = New file
            newFile();
            system("cls");
            break;
        case DUPLICATEFILE:
            duplicateFile(); // ctrl + d = Duplicate File
            break;
        case RENAMEFILE:
            renameFile(); // ctrl + r = Rename File
            break;
        case OPENFILE: // ctrl + o =  Open File
            openFileTwoDimensi();
            system("cls");
            break;
        case DELETEFILE: // ctrl + x = Delete File
            deleteFile();
            break;
        case QUIT: // ctrl + q = Quit
            backMenuHome();
            break;
        case SAVE_FILE:
            // ctrl + s = Save File
            break;
        case FIND_REPLACE:
            findAndReplaceFile();
            system("cls");
            break;
        default:
            system("cls");
            printf("\t\t\t\tWrong Input!\n");
            break;
        }
    } while (choose != QUIT);
}



void backMenuHome()
{
    printf("Press Enter to return to the home menu ...\n");
    getch();
    system("cls");
    home();
}
