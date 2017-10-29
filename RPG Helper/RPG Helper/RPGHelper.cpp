// RPGHelper.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

const int defaultColumnWidth = 80;
const int defaultColumnHeight = 40;

#ifdef _WIN32
#include <Windows.h>

void clrscr()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hStdout, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hStdout,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hStdout,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hStdout, coordScreen);
}

int getColumnWidth() {

	CONSOLE_SCREEN_BUFFER_INFO info;
	HANDLE out;
	if (!(out = GetStdHandle(STD_OUTPUT_HANDLE)) || !GetConsoleScreenBufferInfo(out, &info))
		return defaultColumnWidth;
	return info.dwSize.X;
}

#else

#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")

int getColumnWidth() {
	return defaultColumnWidth;
}
#endif

void printCenteredString(const char *stringToCenter);
void showTitle();
void showHeader();
void showMenu();
void generateCharacter();
void showCharacters();
void rollDice();
void menuSelector(int selection);
void flush(FILE *in);
int input();

int main() {

	int selection;

	showTitle();
	showHeader();
	showMenu();

	do {
		selection = input();
		flush(stdin);
		menuSelector(selection);

	} while (selection != '4');

	return 0;
}

void showTitle() {

	printCenteredString("-------------- RPG Generator --------------\n");
}

void showHeader() {

	printCenteredString("Copyleft 2017 (C) - NoDelay Software\n");
	printf("\n");

}

void showMenu() {

	printCenteredString("Main Menu\n");
	printCenteredString("-----------------------------------------\n");
	printf("\tPlease make your choice:\n\n");

	printf("\t1. Create Character \n");
	printf("\t2. Print Characters \n");
	printf("\t3. Roll a dice\n");
	printf("\t4. Quit\n");
	printf("\n");
}

void flush(FILE *in) {

	int character;

	do {
		character = fgetc(in);
	} while (character != EOF && character != '\n');

	clearerr(in);
}

int input() {

	printf("\t[$]: ");
	fflush(stdout);
	return getchar();
}

void printCenteredString(const char *stringToCenter) {

	const int screenWidth = getColumnWidth();
	const int stringLenght = strlen(stringToCenter);
	const int fieldWidth = (screenWidth - stringLenght) / 2 + stringLenght;
	printf("%*s", fieldWidth, stringToCenter);
}

void menuSelector(int selection) {
	switch (selection)
	{
	case 49:
		generateCharacter();
		break;

	case 50:
		showCharacters();
		break;

	case 51:
		rollDice();
		break;

	default:
		break;
	}

}


void generateCharacter() {
	clrscr();
}
void showCharacters() {
	clrscr();

}
void rollDice() {}