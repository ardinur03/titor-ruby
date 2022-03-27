#ifndef ANSI_ESCAPES_H
#define ANSI_ESCAPES_H

enum clearScreenCodes{
	CLEAR_FROM_CURSOR_TO_END,
	CLEAR_FROM_CURSOR_TO_BEGIN,
	CLEAR_ALL
};

void setupConsole();
void restoreConsole();

static inline void clearScreen(){
	printf("\x1b[%dJ", CLEAR_ALL);
}

static inline void clearScreenToBottom(){
	printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearScreenToTop(){
	printf("\x1b[%dJ", CLEAR_FROM_CURSOR_TO_BEGIN);
}

static inline void clearLine(void) {
    printf("\x1b[%dK", CLEAR_ALL);
}

static inline void clearLineToRight(){
	printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_END);
}

static inline void clearLineToLeft(){
	printf("\x1b[%dK", CLEAR_FROM_CURSOR_TO_BEGIN);
}

static inline void clrToEOL(){
	printf("\x1b[1J");
}

static inline void moveUp(int pos){
	printf("\x1b[%dA", pos);
}

static inline void moveDown(int pos){
	printf("\x1b[%dB", pos);
}

static inline void moveRight(int pos){
	printf("\x1b[%dC", pos);
}

static inline void moveLeft(int pos){
	printf("\x1b[%dD", pos);
}

static inline void moveTo(int row, int col){
	row++;
	col++;
	printf("\x1b[%d;%dH", row, col);
}

static inline void resetCursor(){
	printf("\x1b[H");
}


#endif