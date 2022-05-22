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

int SetMenu1[] = {7, 7, 7, 7, 7}; 
int SetMenu2[] = {7, 7, 7, 7, 7, 7}; 
bool menuFile = false;

void app()
{
    index();
}

void index(){
    int counter1 = 1;
    int counter2 = 1;
    char key;

     for (int i = 0;;){
        menuBarApp();
        hideCursor();
        key = getch();

        // pindah kursor ke kiri & kanan
        if (key == 75 && (counter1 >= 2 && counter1 <= 5))
        {
            system("cls");
            counter1--;
        }

        if (key == 77 && (counter1 >= 1 && counter1 <= 4))
        {
            system("cls");
            counter1++;
        }
        if (key == '\r') // /r adalah carriage return
        {
            gotoxy(10, 5);
            if (counter1 == 1)
            {
                menuFile = true;
                menusBar(1, menuFile);
                
                int counter2 = 1;
                for (int i = 0;;)
                {
                    menuBarApp();
                    hideCursor();
                    menusBar(1, menuFile);
                    key = getch();
                    if(key == 72 && (counter2 >=2 && counter2 <= 6))
                    {
                        counter2--;
                    }
                    if(key == 80 && (counter2 >=1 && counter2 <= 5))
                    {
                        counter2++;
                    }
                    if (key == '\r') // /r adalah carriage return
                    {
                        if (counter2 == 1)
                        {
                            menuBarApp();
                            hideCursor();
                            newFile();
                        }
                        if (counter2 == 2)
                        {
                            gotoxy(25, 5);
                            printf("Open File");
                        }
                        if (counter2 == 3)
                        {
                            gotoxy(25, 5);
                            printf("Rename File");
                        }
                        if (counter2 == 4)
                        {
                            gotoxy(25, 5);
                            printf("Delete File");
                        }
                        if (counter2 == 5)
                        {
                            gotoxy(25, 5);
                            printf("Duplicate File");
                        }
                        if (counter2 == 6)
                        {
                            system("cls");
                            menuFile = false;
                            break;
                        }
                    }

                    // logika if ternary operator
                    SetMenu2[0] = (counter2 == 1) ? 8 : 7;
                    SetMenu2[1] = (counter2 == 2) ? 8 : 7;
                    SetMenu2[2] = (counter2 == 3) ? 8 : 7;
                    SetMenu2[3] = (counter2 == 4) ? 8 : 7;
                    SetMenu2[4] = (counter2 == 5) ? 8 : 7;
                    SetMenu2[5] = (counter2 == 6) ? 8 : 7;
                }
            }
            if (counter1 == 2){
                // menusBar(1, menuFile);
                printf("About");
            }
            if (counter1 == 3){
                printf("Help");
            }
            if (counter1 == 4){
                printf("Exit");
            }
            if (counter1 == 5){
                printf("asss");
            } 
        }

        SetMenu1[0] = (counter1 == 1) ? 8 : 7;
        SetMenu1[1] = (counter1 == 2) ? 8 : 7;
        SetMenu1[2] = (counter1 == 3) ? 8 : 7;
        SetMenu1[3] = (counter1 == 4) ? 8 : 7;
        SetMenu1[4] = (counter1 == 5) ? 8 : 7;
    }
}

/**
 * @detail - Prosedure untuk menampilkan kotak dropdown menu
 * @param menuKe 
 * @param hilangMenu 
*/
void menusBar(int menuKe, bool hilangMenu){
    // MENU 1 => FILE & kotak ascii
    if(menuKe == 1 && hilangMenu){
        for (int i = 3; i <20; i++) {
            if(i <  10){ // 2 garis vertical 
                gotoxy(3, i);
                if (i == 2){
                    printf("%c", 218);
                } else {                
                    printf("%c", 179);
                }
                gotoxy(19, i);
                printf("%c", 179);
            }
            gotoxy(i, 10);// garis horizontal dropdown 
            if (i == 3){
                printf("%c", 192);
            } else if (i == 19) {
                printf("%c", 217);
            }else if(i < 20){
                printf("%c", 196);
            }
        }
        // submenu di dalam kotak
        gotoxy(4, 3);
        color(SetMenu2[0]);
        printf("New File\n");
        gotoxy(4, 4);
        color(SetMenu2[1]);
        printf("Open File\n");
        gotoxy(4, 5);
        color(SetMenu2[2]);
        printf("Rename File\n");
        gotoxy(4, 6);
        color(SetMenu2[3]);
        printf("Delete File\n");
        gotoxy(4, 7);
        color(SetMenu2[4]);
        printf("Duplicate File\n");
        gotoxy(4, 9);
        color(SetMenu2[5]);
        printf("Back To MenuBar\n");
    } else if (menuKe == 1 && !hilangMenu){
       // clear menu ke 1 
        for (int i = 3; i <20; i++) {
            if(i <  10){ // 2 garis vertical 
                gotoxy(3, i);
                if (i == 2){
                    printf(" ");
                } else {                
                    printf(" ");
                }
                gotoxy(19, i);
                printf(" ");
            }
            gotoxy(i, 10);// garis horizontal dropdown 
            if (i == 3){
                printf(" ");
            } else if (i == 19) {
                printf(" ");
            }else if(i < 20){
                printf(" ");
            }
        }
        gotoxy(4, 3);
        printf("               ");
        gotoxy(4, 4);
        printf("               ");
        gotoxy(4, 5);
        printf("               ");
        gotoxy(4, 6);
        printf("               ");
        gotoxy(4, 7);
        printf("               ");
        gotoxy(4, 9);
        printf("             ");
    }
}

void menuBarApp(){
    // horizontal line ke satu
    for (int i = 0; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 0);
        // garis gabung horizontal dengan garis vertical
        if(i == 0){
            printf("%c", 201);
        }else if(i == 108){
            printf("%c", 175);
        }else if(i == 109){
            printf(" ");
        }else if(i == 110){
            printf("T");
        }else if(i == 111){
            printf("i");
        }else if(i == 112){
            printf("T");
        }else if(i == 113){
            printf("o");
        }else if(i == 114){
            printf("r");
        }else if(i == 115){
            printf("A");
        }else if(i == 116){
            printf("p");
        }else if(i == 117){
            printf("p");
        }else if(i == 118){
            printf("s");
        }else if (i == 119){
            printf(" ");
        }else if (i == 120){
            printf("%c", 174);
        }else if (i == 128){
            printf("%c", 187);
        } else {
            printf("%c", 205);
        }
    }

    // horizontal line ke dua
    for (int i = 1; i < 129; i++)
    {
        gotoxy(i, 2);
        if(menuFile && i == 3){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }

    // vertical line kiri
    for (int i = 1; i < 24; i++)
    {
        // garis vertical
        color(7);
        gotoxy(0, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
    }

    // vertical line kanan
    for (int i = 1; i < 24; i++)
    {
        // garis vertical
        color(7);
        gotoxy(128, i);
        if(i == 2){
            printf("%c", 185);
        }else{
            printf("%c", 186);
        }
    }

    gotoxy(3, 1);
    color(SetMenu1[0]);
    printf("File");
    gotoxy(9, 1);
    color(SetMenu1[1]);
    printf("About");
    gotoxy(16, 1);
    color(SetMenu1[2]);
    printf("Help");
    gotoxy(22, 1);
    color(SetMenu1[3]);
    printf("Exit");
    gotoxy(28, 1);
    color(SetMenu1[4]);
    printf("asss");
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
