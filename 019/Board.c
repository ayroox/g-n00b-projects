#include <stdbool.h>

#include "Board.h"

typedef struct {
	_Cell grid[SIZE_Y][SIZE_X];
}_Board;

static _Board board;

void createNewBoard() {
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			board.grid[y][x] = Empty;
		}
	}
}

_Bool isFull() {
	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			if (board.grid[y][x] != Empty) {
				return false;
			}
		}
	} 

	return true;
}

_Cell getCellAt(int x, int y) {
	return board.grid[y][x];
}

void setCellAt(int x, int y, _Cell cell) {
	board.grid[y][x] = cell;
}
