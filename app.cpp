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
#include "openFile.h"

int SetMenu1[] = {7, 7, 7, 7, 7};  // set menu bar File About Help Exit
int SetMenu2[] = {7, 7, 7, 7, 7, 7, 7}; // set menu dropdown : New File, Open File, Rename File, Delete File, Duplicate File, Back to Menu Bar
int SetMenu3[] = {7, 7}; // set menu confirm
bool showWelcome = true;
bool menuFile    = false;
bool menuAbout   = false;
bool menuHelp    = false;
bool menuConfirm = false;

void app()
{
	setTitleComandLine();
    index();
}

void index(){
    int counter1 = 0; // counter untuk menu bar
    int counter2 = 0; // counter untuk menu dropdown
    int counter3 = 1; // counter untuk menu confirm
    char key;

    for (int i = 0;;){
        menuBarApp();
        hideCursor();

        if(showWelcome) vWelcome();

        key = getch();
        if (key == ARROW_LEFT && (counter1 >= 2 && counter1 <= 5))
        {
            showWelcome = true;
            clearScreenToBottom();
            counter1--;
        }
        if (key == ARROW_RIGHT && (counter1 >= 0 && counter1 <= 4))
        {
            showWelcome = true;
            clearScreenToBottom();
            counter1++;
        }
        if (key == '\r') // /r adalah carriage return
        {
            gotoxy(10, 5);
            if (counter1 == 1)
            {
                menuFile = true;
                menusBar(1, menuFile);
                for (int i = 0;;)
                {
                    menuBarApp();
                    hideCursor();
                    menusBar(1, menuFile);
                    key = getch();
                    if(key == ARROW_UP && (counter2 >=2 && counter2 <= 7))
                    {
                        counter2--;
                    }
                    if(key == ARROW_DOWN && (counter2 >=0 && counter2 <= 6))
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
                            menuFile = false;
                        	system("cls");
                        	showCursor();
                        	menuBarApp();
                            gotoxy(25, 5);
                            openFromFile();
                            menuFile = true;
                        }
                        if (counter2 == 3)
                        {
                            gotoxy(25, 5);
                            printf("Rename File");
                        }
                        if (counter2 == 4)
                        {
                        	menuFile = false;
                        	system("cls");
                        	showCursor();
                        	menuBarApp();
                            gotoxy(25, 5);
                            deleteFile();
                            menuFile = true;
                        }
                        if (counter2 == 5)
                        {
                            gotoxy(25, 5);
                            duplicateFile();
                        }
                        if (counter2 == 6)
                        {
                            menuFile = false;
                            system("cls");
                            showCursor();
                            menuBarApp();
                            gotoxy(25, 5);
                            system("pause");
                            menuFile = true;
                        }
                        if (counter2 == 7)
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
                    SetMenu2[6] = (counter2 == 7) ? 8 : 7;
                }
            }
            if (counter1 == 2){
                showWelcome = false;
                menuAbout = true;
                system("cls");
                menuBarApp();
                vAbout();
            }
            if (counter1 == 3){
                showWelcome = false;
                menuAbout = false;
                menuHelp = true;
                system("cls");
                menuBarApp();
                vHelp();
            }
            if (counter1 == 4){
                printf("Contact");
            }
            if (counter1 == 5){
                system("cls");
                key =1;
                for(int i;;){
                    menuBarApp();
                    vConfirmExit();
                    key = getch();
                    if(key == ARROW_LEFT && (counter3 >=2 && counter3 <= 3))
                    {
                        // system("cls");
                        counter3--;
                    }
                    if(key == ARROW_RIGHT && (counter3 >=0 && counter3 <= 1))
                    {
                        // system("cls");
                        counter3++;
                    }

                    if (key == '\r') // /r adalah carriage return
                    {
                        if (counter3 == 1)
                        {
                            color(7);
                            exit(0);
                        }
                        if (counter3 == 2)
                        {
                            system("cls");
                            break;
                        }
                    }
                    
                    // logika if ternary operator
                    SetMenu3[0] = (counter3 == 1) ? 8 : 7;
                    SetMenu3[1] = (counter3 == 2) ? 8 : 7;
                }

            } 
        }

        SetMenu1[0] = (counter1 == 1) ? menuAbout = false, 8 : 7; 
        SetMenu1[1] = (counter1 == 2) ? menuHelp = false, 8 : 7; // menu About
        SetMenu1[2] = (counter1 == 3) ? menuAbout = false, 8 : 7; // menu Help
        SetMenu1[3] = (counter1 == 4) ? menuHelp = false, 8 : 7; // menu Contact
        SetMenu1[4] = (counter1 == 5) ? 8 : 7; // menu Exit
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
        for (int i = 3; i <22; i++) {
            if(i <  11){ // 2 garis vertical 
                gotoxy(3, i);
                if (i == 2){
                    printf("%c", 218);
                } else {                
                    printf("%c", 179);
                }
                gotoxy(19, i);
                printf("%c", 179);
            }
            gotoxy(i, 11);// garis horizontal dropdown 
            if (i == 3)
            {
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
        printf("New File");
        gotoxy(4, 4);
        color(SetMenu2[1]);
        printf("Open File");
        gotoxy(4, 5);
        color(SetMenu2[2]);
        printf("Rename File");
        gotoxy(4, 6);
        color(SetMenu2[3]);
        printf("Delete File");
        gotoxy(4, 7);
        color(SetMenu2[4]);
        printf("Duplicate File");
        gotoxy(4, 8);
        color(SetMenu2[5]);
        printf("Find & Replace");
        gotoxy(4, 10);
        color(SetMenu2[6]);
        printf("Back To MenuBar");
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
        if(menuFile && i == 3 || menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuAbout && i == 8 || menuAbout && i == 14){ // munculin garis ╦
            printf("%c", 203);
        } else if(menuHelp && i == 15 || menuHelp && i == 20){ // munculin garis ╦
            printf("%c", 203);
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
        }
        else if(i == 1){
            printf("%c", 186);
        }
        else{
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
        }else if(i == 1){
            printf("%c", 186);
        }
        else{
            printf("%c", 186);
        }
    }

    // horizontal line bawah
    for (int i = 0; i < 129; i++)
    {
        gotoxy(i, 23);
        if( i == 0){ // munculin garis
            printf("%c", 200);
        } else if(i == 128){ // munculin garis 
            printf("%c", 188);
        } else { 
            printf("%c", 205); 
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
    printf("Contact");
    gotoxy(31, 1);
    color(SetMenu1[4]);
    printf("Exit");
}

// prosedure welcomeApp
void vWelcome(){
    // welcome atas
    // garis vertical kiri
    for (int i = 4; i < 12; i++){
    	color(7);
    	gotoxy(6, i);
        if(i == 4){
            printf("%c", 201);
        }
		else if(i == 11){
            printf("%c", 200);
        }
        else{
        	printf("%c", 186);
		}
	}

    //vertical kanan
	for (int i = 4; i < 12; i++){
    	color(7);
    	gotoxy(48, i);
        if(i == 4){
            printf("%c", 187);
        }
		else if(i == 11){
            printf("%c", 188);
        }
        else{
        	printf("%c", 186);
		}
	}

    // horizontal line bawah
    for (int i = 7; i < 48; i++)
    {
        gotoxy(i, 11);
            printf("%c", 205); 
    }

    // horizontal line atas
    for (int i = 7; i < 48; i++)
    {
        gotoxy(i, 4);
            printf("%c", 205); 
    }
	gotoxy(17, 6);
    printf("WELCOME To TiTOR APPS");
    gotoxy(23, 8);
    printf("RUBY TEAM");
    
    // Copyright bawah
    // garis vertical kiri
    for (int i = 20; i < 23; i++){
    	color(7);
    	gotoxy(88, i);
        if(i == 20){
            printf("%c", 201);
        }
		else if(i == 22){
            printf("%c", 200);
        }
        else{
        	printf("%c", 186);
		}
	}
		//vertical kanan
	for (int i = 20; i < 23; i++){
    	color(7);
    	gotoxy(125, i);
        if(i == 20){
            printf("%c", 187);
        }
		else if(i == 22){
            printf("%c", 188);
        }
        else{
        	printf("%c", 186);
		}
	}

    // horizontal line bawah
    for (int i = 89; i < 125; i++) {
        gotoxy(i, 22);
            printf("%c", 205); 
    }

    // horizontal line atas
    for (int i = 89; i < 125; i++){
        gotoxy(i, 20);
            printf("%c", 205); 
    }
    gotoxy(89, 21);
    printf("Copyright 2022 - Team Ruby TiTorApps");
}

// prosedure about
void vAbout(){
    // // vertical line about depan
    for (int i = 3; i < 20; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(8, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// horizontal line about bawah
    for (int i = 8; i < 118; i++)
    {
        gotoxy(i, 20);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // vertical line about belakang
    for (int i = 5; i < 20; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(117, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// horizontal line about atas
    for (int i = 15; i < 118; i++)
    {
        gotoxy(i, 4);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // vertical line about pendek
    for (int i = 3; i < 4; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(14, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// garis gabung about depan atas
	for (int i = 4; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 2);
        // garis gabung horizontal dengan garis vertical
        if(i == 8){
            printf("%c", 203);
        }
	}
	
	// garis gabung about tengah atas
	for (int i = 4; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 2);
        // garis gabung horizontal dengan garis vertical
        if(i == 14){
            printf("%c", 203);
        }
	}

	// garis gabung about tengah 
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 4);
        // garis gabung horizontal dengan garis vertical
        if(i == 14){
            printf("%c", 200);
        }
	}
	
	// garis gabung about tengah belakang
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 4);
        // garis gabung horizontal dengan garis vertical
        if(i == 117){
            printf("%c", 187);
        }
	}
	
	// garis gabung about depan bawah
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 20);
        // garis gabung horizontal dengan garis vertical
        if(i == 8){
            printf("%c", 200);
        }
	}
	
	// garis gabung about belakang bawah
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 20);
        // garis gabung horizontal dengan garis vertical
        if(i == 117){
            printf("%c", 188);
        }
	}

    gotoxy(14, 7);
    printf("TiTOR or Text Editor is an application that can make it easier for users to add, change, and save");
	gotoxy(14, 8);
    printf("text with a simple and easy-to-use interface. This application is based on a console made using the");
	gotoxy(14, 9);
    printf("C++ language. The making of this application was compiled by :");
	gotoxy(14, 10);
    printf("Lolla Mariah");
    gotoxy(14, 11);
    printf("Luthfie Yannuardy");
    gotoxy(14, 12);
    printf("Muhamad Ardi Nur Insan");
    gotoxy(14, 13);
    printf("Muhammad Zidan Hidayat");
    gotoxy(14, 14);
    printf("Naufal Salman Mulyadi");
    gotoxy(14, 15);
    printf("Shofiyah");
    gotoxy(100, 18);
    printf("--Titor2022");
}

// prosedure help
void vHelp(){
    // vertical line help depan
    for (int i = 3; i < 20; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(15, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// horizontal line about bawah
    for (int i = 16; i < 118; i++)
    {
        gotoxy(i, 20);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // vertical line about belakang
    for (int i = 5; i < 20; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(117, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// horizontal line help atas
    for (int i = 21; i < 118; i++)
    {
        gotoxy(i, 4);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // vertical line help pendek
    for (int i = 3; i < 4; i++)
    {
    	// garis vertical
    	color(7);
    	gotoxy(20, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
	}
	
	// garis gabung help depan atas
	for (int i = 4; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 2);
        // garis gabung horizontal dengan garis vertical
        if(i == 20){
            printf("%c", 203);
        }
	}
	
	// garis gabung file tengah atas
	for (int i = 4; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 2);
        // garis gabung horizontal dengan garis vertical
        if(i == 15){
            printf("%c", 203);
        }
	}

	// garis gabung help tengah 
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 4);
        // garis gabung horizontal dengan garis vertical
        if(i == 20){
            printf("%c", 200);
        }
	}
	
	// garis gabung help tengah belakang
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 4);
        // garis gabung horizontal dengan garis vertical
        if(i == 117){
            printf("%c", 187);
        }
	}
	
	// garis gabung about depan bawah
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 20);
        // garis gabung horizontal dengan garis vertical
        if(i == 15){
            printf("%c", 200);
        }
	}
	
	// garis gabung about belakang bawah
	for (int i = 8; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 20);
        // garis gabung horizontal dengan garis vertical
        if(i == 117){
            printf("%c", 188);
        }
	}

    gotoxy(20, 8);
    printf("1. Create file berfungsi untuk membuat file baru");
    gotoxy(20, 9);
    printf("2. Duplicate file berfungsi untuk menggandakan file ");
    gotoxy(20, 10);
    printf("3. Open file berfungsi untuk membuka file");
    gotoxy(20, 11);
    printf("4. Delete file berfungsi untuk menghapus file");
    gotoxy(20, 12);
    printf("5. Rename file berfungsi untuk mengganti nama file");
    gotoxy(20, 13);
    printf("6. Save berfungsi untuk menyimpan file");
    gotoxy(20, 14);
}

// prosedure confirm
void vConfirmExit(){
    for (int i = 9; i < 16; i++)
    {
        // garis vertical
        color(7);
        gotoxy(50, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
    }
    
    // vertical line confirm belakang
    for (int i = 9; i < 16; i++)
    {
        // garis vertical
        color(7);
        gotoxy(79, i);
        if(i == 2){
            printf("%c", 204);
        }else{
            printf("%c", 186);
        }
    }
    
    // horizontal line confirm atas
    for (int i = 50; i < 79; i++)
    {
        gotoxy(i, 9);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // horizontal line confirm bawah
    for (int i = 50; i < 79; i++)
    {
        gotoxy(i, 16);
        if(menuFile && i == 21){ // munculin garis ╤
            printf("%c", 209);
        } else if(menuFile && i == 19){ // munculin garis ╤
            printf("%c", 209);
        } else { 
            printf("%c", 205); 
        }
    }
    
    // garis gabung confirm kiri atas
	for (int i = 0; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 9);
        // garis gabung horizontal dengan garis vertical
        if(i == 50){
            printf("%c", 201);
        }
	}
	
	  // garis gabung confirm kanan atas
	for (int i = 0; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 9);
        // garis gabung horizontal dengan garis vertical
        if(i == 79){
            printf("%c", 187);
        }
	}
	
	 // garis gabung confirm kiri bawah
	for (int i = 0; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 16);
        // garis gabung horizontal dengan garis vertical
        if(i == 50){
            printf("%c", 200);
        }
	}
	
	// garis gabung confirm kanan bawah
	for (int i = 0; i < 129; i++)
    { 
        // garis horizontal
        color(7);
        gotoxy(i, 16);
        // garis gabung horizontal dengan garis vertical
        if(i == 79){
            printf("%c", 188);
        }
	}

    gotoxy(55, 11);
    printf("Do you want to exit");
    gotoxy(55, 13);
    printf("the application?");
    gotoxy(69, 15);
    color(SetMenu3[0]);
    printf("YES");
    color(SetMenu3[1]);
    gotoxy(75, 15);
    printf("NO");
}

void backMenuHome()
{
    printf("Press Enter to return to the home menu ...\n");
    getch();
    system("cls");
    index();
}
