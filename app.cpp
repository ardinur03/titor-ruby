#include "stdlib.h"
#include <stdio.h>
#include <conio.h>
#include "app.h"
#include "deleteFile.h"
#include "kelolaText.h"

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

    printf("Choose Menu :");
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
        backMenuHome();
        break;
    default:
        break;
    }
}   


// prosedure about application TiTOR
void procedure(){
	printf("+==================================================================+\n");
    printf("|                            About TiTOR                           |\n");
    printf("+==================================================================+\n"); 
    printf("|                                                                  |\n");
    printf("| TiTOR atau Text EdiTOR adalah aplikasi yang dapat mempermudah    |\n");
	printf("| user dalam menambah, mengubah,  dan menyimpan text dengan        |\n");
    printf("| tampilan yang sederhana dan mudah digunakan.Aplikasi ini berbasis|\n");
    printf("| console yang dibuat menggunakan bahasa c++. Pembuatan aplikasi   |\n");
    printf("| ini disusun oleh :                                               |\n");
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
    printf("| ctrl + n : Digunakan untuk membuat File                          |\n");
	printf("| ctrl + d : Digunakan untuk menduplikat File                      |\n");
    printf("| ctrl + x : Digunakan untuk delete File                           |\n");
    printf("| ctrl + o : Digunakan untuk membuka File                          |\n");
    printf("| ctrl + n : Digunakan untuk rename File                           |\n");
    printf("| ctrl + q : Digunakan untuk keluar                                |\n");
    printf("| ctrl + s : Digunakan untuk save                                  |\n");
    printf("| ctrl + v : Digunakan untuk paste                                 |\n");
    printf("| ctrl + y : Digunakan untuk redo                                  |\n");
    printf("| ctrl + z : Digunakan untuk undo                                  |\n");
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
    insertMode(0);
}

void run(){
    system("cls");
    int choose;

    textEditor();
    
    // View menu text editor
    do
    {
        choose = getch();
        switch (choose)
        {
        case NEWFILE: // ctrl + n = new file
            newFile();
            break;
        case OPENFILE: // ctrl + o =  Open File
            printf("Open File...\n");
            break;
        case DELETEFILE: // ctrl + d = Delete File
            deleteFile();   
            break;
        case QUIT: // ctrl + q = Quit
            backMenuHome();
            break;
        // tambahin shortcutnya fi app.h gais
        default:
            
            break;
        }
    } while (choose != QUIT);
    

}

void backMenuHome(){
    printf("Tekan Enter untuk kembali ke menu home ...\n");
    getch();
    system("cls");
    home();
}

