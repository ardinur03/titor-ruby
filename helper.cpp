/* Deskripsi  		 : modul modul yang nanti di gunakan secara reusable atau di gunakan kembali
/* Source 			 : tidak ada
/* Dimodifikasi oleh : Muhamad Ardi Nur Insan 211511022 */

#include "helper.h"

// validasi jangan input karakter \ / : * ? " < > |
int validateChar(char ektensiFileTemp)
{
	if (ektensiFileTemp == '\\' || ektensiFileTemp == '/' || ektensiFileTemp == ':' || ektensiFileTemp == '*' || ektensiFileTemp == '?' || ektensiFileTemp == '"' || ektensiFileTemp == '<' || ektensiFileTemp == '>' || ektensiFileTemp == '|')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE); /*Obtain a handle to the consle screen*/
	COORD pos = {(SHORT)x, (SHORT)y};
	SetConsoleCursorPosition(output, pos);
}

void gotoxy(int X, int y)
{
	COORD coord; // struct yang berisikan dua variabel bertipe SHORT, yaitu X dan Y
	coord.X = X;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Menetapkan posisi cursor di layar.
}

void loading_screen()
{
	int i;
	gotoxy(40, 10);
	printf("Loading...");
	gotoxy(40, 12);
	for (i = 0; i <= 17; i++)
	{
		Sleep(90);
		printf("%c", 177);
	}
	printf("\n\n");
	// system("pause");
	system("cls");
}

/**
 * @details description : modul untuk ascii full down text editor titor apps
*/
void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/** @param color : warna yang akan di set  */

void hideCursor(){
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
/** awmbunyikan Cursor di dalam console */

void showCursor(){
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
/** menampilkan Cursor di dalam console */
