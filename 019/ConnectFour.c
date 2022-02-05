#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Board.h"

#ifdef _WIN32
	#define CLEAR_CMD "cls"
#else
	#define CLEAR_CMD "clear"
#endif

#define P_ONE_FILL "🟥"
#define P_TWO_FILL "🟨"
#define EMPTY_FILL "⬛"

void printBoard();
void printFooter();
void printScreen();
_Bool dropCell(int column, _Cell player);
_Cell getCurrentPlayer();
_Bool isTie();
_Bool isWin();
void initGame();

int turns = 0;

int main() {
	createNewBoard();
	initGame(); 

	return 0;
}	

void printScreen() {
	system(CLEAR_CMD);
	printBoard();
	printFooter();
}

void printBoard() {
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			switch (getCellAt(x, y)) {
				case Empty:
					printf("%s", EMPTY_FILL);
					break;
				case PlayerOne:
					printf("%s", P_ONE_FILL);
					break;
				case PlayerTwo:
					printf("%s", P_TWO_FILL);
					break;
			}	
		}
		printf("\n");
	}	
}

void printFooter() {
	for (int x = 1; x < SIZE_X + 1; x++) {
		switch (x) {
			case 1:
				printf("1️⃣");
				break;
			case 2:
				printf("2️⃣");
				break;
			case 3:
				printf("3️⃣");
				break;
			case 4:
				printf("4️⃣");
				break;
			case 5:
				printf("5️⃣");
				break;
			case 6:
				printf("6️⃣");
				break;
			case 7:
				printf("7️⃣");
				break;
			case 8:
				printf("8️⃣");
				break;
			case 9:
				printf("9️⃣");
				break;
			default:
				if (x % 2 == 0) {
					printf("*️⃣");
					break;
				}

				printf("#️⃣");
				break;
		}
		printf(" ");
	}
	printf("\n");
	if (getCurrentPlayer() == PlayerOne) {
		printf("It's %s's turn\n", P_ONE_FILL);
	} else {
		printf("It's %s's turn\n", P_TWO_FILL);
	}
}

_Bool dropCell(int column, _Cell player) {
	for (int y = SIZE_Y - 1; y >= 0; y--) {
		if (getCellAt(column, y) == Empty) {
			setCellAt(column, y, player);
			return true;
		}
	}

	return false;
}

_Cell getCurrentPlayer() {
	if (turns % 2 == 0) {
		return PlayerTwo;
	}

	return PlayerOne;
}

_Bool isWin() {
	int count = 0;

	//Horizontal Check
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			count++;

			if (getCellAt(x, y) != getCurrentPlayer()) {
				count = 0;
			}

			if (count == 4) {
				return true;
			}
		}
	} count = 0;

	//Vertical Check
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			count++;

			if (getCellAt(y, x) != getCurrentPlayer()) {
				count = 0;
			}

			if (count == 4) {
				return true;
			}
		}
	} count = 0;
	
	//Mid Left To Right Diagonal Check
	for (int x = 0; x < SIZE_X; x++) {
		count++;
		
		if (getCellAt(x, x) != getCurrentPlayer()) {
			count = 0;
		}

		if (count == 4) {
			return true;
		}
	} count = 0;

	//Left To Right Diagonal Check
	for (int x = 0; x < SIZE_X; x++) {
		for (int p = 0; p < SIZE_X; p++) {
			count++;
			if (getCellAt(p + x + 1, p) != getCurrentPlayer()) {
				count = 0;
			}

			if (count == 4) {
				return true;
			}
		} count = 0;
	} count = 0;

	// Top Left To Right Diagonal Check 
	for (int x = SIZE_X - 1; x >= 0; x--) {
		for (int p = 0; p < SIZE_X - 1; p++) {
			if (x - p < 0) {
				continue;
			} count++;

			if (getCellAt(x - p, p) != getCurrentPlayer()) {
				count = 0;
			}

			if (count == 4) {
				return true;
			}
		} count = 0;
	}

	// Bottom Left To Right Diagonal Check
	for (int x = SIZE_X - 2; x >= 1; x--) {
		int counter = SIZE_X - 2;
		for (int y = SIZE_X - x; y < SIZE_X; y++) {
			count++;

			if (getCellAt(y, counter) != getCurrentPlayer()) {
				count = 0;
			}

			if (count == 4) {
				return true;
			}
			counter--; 
		}
	} count = 0;

	return false;
}

_Bool isTie() {
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			if (getCellAt(x, y) == Empty) {
				return false;
			}
		}
	}

	return true;
}

void initGame() {
	int column;
	printScreen();
	scanf("%d", &column);

	if (column > SIZE_X || column < 1) {
		initGame();
	}

	if (!dropCell(column - 1, getCurrentPlayer())) {
		initGame();
	}
	
	if (isTie()) {
		printScreen();
		printf("TIE in %d turns\nNo one wins!\n", turns);
		return;
	}

	if (isWin()) {
		printScreen();
		printf("WIN in %d turns congrats ", turns);
		getCurrentPlayer() == PlayerOne ? printf("Player One!\n") : printf("Player Two!\n");
		return;
	}

	turns++;
	initGame();
}
