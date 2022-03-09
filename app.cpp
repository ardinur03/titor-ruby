#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "app.h"

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
        printf("Running...\n");
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


// prosedure about application TiTOR

// prosedure shorcut application TiTOR


// Sub-menu Run
void run(){

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
        printf("Running...\n");
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

void backMenuHome(){
    printf("Tekan Enter untuk kembali ke menu home ...\n");
    getch();
    system("cls");
    home();
}

