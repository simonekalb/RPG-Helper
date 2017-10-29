// RPGHelper.cpp: definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"

void showTitle();
void showHeader();
void showMenu();
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

	} while (selection != '4');

	return 0;
}

void showTitle() {

	printf("-------------- RPG Generator --------------\n");
}

void showHeader() {

	printf("Copyleft 2017 (C) - NoDelay Software\n");
	printf("\n");

}

void showMenu() {

	printf("Main Menu\n");
	printf("-------------------------\n");
	printf("Please make your choice:\n\n");

	printf("1. Create Character \n");
	printf("2. Print Characters \n");
	printf("3. Roll a dice\n");
	printf("4. Quit\n");
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

	printf("[$]: ");
	fflush(stdout);
	return getchar();
}