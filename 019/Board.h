#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#define SIZE_X 7
#define SIZE_Y 6

typedef enum {
	Empty,
	PlayerOne,
	PlayerTwo
}_Cell;

void createNewBoard();
_Bool isFull();
_Cell getCellAt(int x, int y);
void setCellAt(int x, int y, _Cell cell);

#endif
