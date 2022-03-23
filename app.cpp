#include "stdlib.h"
#include <stdio.h>
#include <conio.h>
#include "app.h"
#include "deleteFile.h"
#include "kelolaText.h"
#include "saveToFile.h"
#include "openFile.h"
#include "duplicateFile.h"
#include "renameFile.h"

void app() {
    home();
}

// menu utama home
void home(){
    int choose;

    printf("+===========================================================+\n");
    printf("|                       TITOR APPS                          |\n");
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
        exit(-1);
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
void procedure(){
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
void procedureShorcut(){
	printf("+==================================================================+\n");
    printf("|                            About TiTOR                           |\n");
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


// Sub-menu Run
void run1(){

    int choose;

    printf("+===========================================================+\n");
    printf("|                       Menu TiTOR                          |\n");
    printf("+===========================================================+\n"); 
    printf("|                                                           |\n");
    printf("| 1. Create File                                            |\n");
    printf("| 2. Open File                                              |\n");
    printf("| 3. Edit File                                              |\n");
    printf("| 4. Delete File                                            |\n");
    printf("| 5. Rename File                                            |\n");
    printf("| 6. Exit                                                   |\n");
    printf("|                                                           |\n");
    printf("+===========================================================+\n");
    printf("|   Copyright (c) 2022 Kelompok RUBY. All rights reserved.  |\n");
    printf("+===========================================================+\n");

    printf("Choose Menu :");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        backMenuHome();
        break;
    case 2:
        printf("About...\n");
        backMenuHome();
        break;
    case 3:
        printf("Shorcut...\n");
        backMenuHome();
        break;
    case 4:
        printf("Exit...\n");
        backMenuHome();
        break;
    default:
        break;
    }
}

void textEditor(){
    printf(" TiTOR APPS\n");
    printf("\t  ctrl+n   : New File                    ctrl+o : Open File\n");
    printf("\t  ctrl+d   : Duplicate File              ctrl+r : Rename File\n");
    printf("\t  ctrl+x   : Delete File                 ctrl+q : Quit\n");
}

void newFile(){
	system("cls");
    char choice;
    char text[MAXBARIS][MAXKOLOM];
    int jmlBaris = insertMode(0, text);
    while (1)
    {
        printf("Do you want to save the file? (y/n) : ");
        choice = getch();
        if (choice == 'y')
        {
            saveFile(jmlBaris, text);
            break;
        } else if (choice == 'n') {
        	system("cls");
        	printf("\nYour file is not saved!");
        	getch();
            break;
        } else {
            printf("\n");
            printf("Wrong Input!\n");
        }
    }   
}

void run(){
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
        case DUPLICATE:
        	duplicateFile(); // ctrl + d = Duplicate File
        	break;
        case RENAMEFILE:
        	renameFile(); // ctrl + r = Rename File
        	break;
        case OPENFILE: // ctrl + o =  Open File
            openFile();
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
        
        default:
        system("cls");
		printf("\t\t\t\tWrong Input!\n");
		break;
        }
    } while (choose != QUIT );
    

}

void backMenuHome(){
    printf("Press Enter to return to the home menu ...\n");
    getch();
    system("cls");
    home();
}
