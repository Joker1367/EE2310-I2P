// EE2310 lab11 The Game of Life
// 109061217, 林峻霆
// Date: 2020/12/18

#include "life.h"

void readGrid(CELL grid[N][N])
	// A function that read data from input file and determine the initial
	// state of each cell
{
	int i, j;                                 // parameter for loop and index
	char c;                                   // input char: . denote dead
                                              //             o denote live
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			c = getchar();                    // read the valid input
			while (c == ' ' || c == '\n') {
				c = getchar();
			}	
			if (c == '.') {                   // check live or dead
				grid[i][j].next = DEAD;       // set the state
				grid[i][j].current = DEAD;
				grid[i][j].age = 0;
				grid[i][j].Nnbr = 0;
			}
			else {
				grid[i][j].next = LIVE;       // set the state
				grid[i][j].current = DEAD;
				grid[i][j].age = 0;
				grid[i][j].Nnbr = 0;
				grid[i][j].color =  GREEN;
			}
		}
	}
}

int stillLife(CELL grid[N][N])
	// A function that check whether the Still pattern occur
	// 		if occur, return 1
	// 		else, return 0
{
	int i, j;                        // parameter for loop and index
	int found = 1;                   // parameter for found still pattern

	for (i = 0; i < N; i++) {        // check whether current = next
		for (j = 0; j < N; j++) {
			if (grid[i][j].current != grid[i][j].next) {
				found = 0;
			}
			grid[i][j].current = grid[i][j].next;	// change to next state
		}
	}

	if (found)                       // Still pattern occur
		return 1;                    // return 1
	else                             // Still pattern not occur
		return 0;                    // return 0
}

void nextGen(CELL grid[N][N]) 
	// A function that determine the next state by calculating the amount of 
	// alive neighbors.
	// It also change the age and color of each cell.
{
	int i, j;                               // parameter for loop and index
	int t, l;                               // parameter for neighbor calculate
	int row, col;                           // parameter for calculate row col

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			grid[i][j].Nnbr = 0;               // reset the amount
			for (t = -1; t <= 1; t++) {        // calculate the amount
				for (l = -1; l <= 1; l++) {
					if (t != 0 || l != 0) { 
						row = (i + t + N) % N; // calculate row
						col = (j + l + N) % N; // calculate col
						if (grid[row][col].current == LIVE) 
							grid[i][j].Nnbr += 1;
					}
				}
			}

			if (grid[i][j].current == DEAD && grid[i][j].Nnbr == 3) {
				grid[i][j].next = LIVE;       // change from dead to alive
			}
			else if (grid[i][j].current == LIVE) {
				if (grid[i][j].Nnbr != 3 && grid[i][j].Nnbr != 2)
					grid[i][j].next = DEAD;   // change from alive to dead
			}

			if (grid[i][j].next == LIVE) {    // increase the age if alive
				grid[i][j].age += 1;
			}   
			else {                            // reset age if dead
				grid[i][j].age = 0;             
			}

			if (grid[i][j].age == 1) {        // color GREEN if 1-year-old
				grid[i][j].color = GREEN;
			}
			else if (grid[i][j].age == 2) {   // color YELLOW if 2-year-old
				grid[i][j].color = YELLOW;
			}
			else if (grid[i][j].age > 2) {    // color RED if > 2-year-old
				grid[i][j].color = RED;
			}
			else {                            // color white if dead
				grid[i][j].color = WHITE;
			}
		}
	}
}
