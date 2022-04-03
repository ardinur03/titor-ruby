#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "ansiEscapes.h"

static HANDLE stdoutHandle;
static DWORD outModeInit;

void setupConsole(){
	DWORD outMode = 0;
	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(stdoutHandle == INVALID_HANDLE_VALUE){
		exit(GetLastError());
	}
	
	if(!GetConsoleMode(stdoutHandle, &outMode)){
		exit(GetLastError());
	}
	
	outModeInit = outMode;
	
	/* Enable ANSI escape codes for windows*/
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	
	if(!SetConsoleMode(stdoutHandle, outMode)){
		exit(GetLastError());
	}
}

void restoreConsole(){
	//reset console mode
	if(!SetConsoleMode(stdoutHandle, outModeInit)) {
		exit(GetLastError());
	}
}