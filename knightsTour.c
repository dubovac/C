/*
 * (Knight's Tour)
 * One of the more interesting puzzles for chess buffs is the Knight's Tour problem, originally proposed by the mathematician Euler.
 * The question is this: Can the chess piece called the knight move around an empty chessboard and touch each of the 64 squares once and only once?
 * We study this intriguing problem in-depth here.
 *
 * The knight makes L-shaped moves (two in one direction and then one in perpendicular direction).
 * Thus, from a square in the middle of an empty chessboard, the knight can make eight different moves (number 0 through 7), as shown in the following diagram:
 *
 * 	    0   1   2   3   4   5   6   7
 * 	  ---------------------------------
 * 	0 |   |   |   |   |   |   |   |   |
 * 	  ---------------------------------
 * 	1 |   |   |   | 2 |   | 1 |   |   |
 * 	  ---------------------------------
 * 	2 |   |   | 3 |   |   |   | 0 |   |
 * 	  ---------------------------------
 * 	3 |   |   |   |   | K |   |   |   |
 * 	  ---------------------------------
 * 	4 |   |   | 4 |   |   |   | 7 |   |
 * 	  ---------------------------------
 * 	5 |   |   |   | 5 |   | 6 |   |   |
 * 	  ---------------------------------
 * 	6 |   |   |   |   |   |   |   |   |
 * 	  ---------------------------------
 * 	7 |   |   |   |   |   |   |   |   |
 * 	  ---------------------------------
 *
 *
 * 	a) Draw 8-by-8 chessboard on a sheet of paper and attempt a Knight's Tour by hand.
 * 	   Put a 1 in the first square you move to, a 2 in the second square, a 3 in the third, and so on.
 * 	   Before starting the tour, estimate how far you think you'll get, remembering that a full tour consists of 64 moves.
 * 	   How far did you get?
 * 	   Were you close to the estimate?
 * 
 * 	b) Now let's develop a program that will move the knight around a chessboard.
 * 	   The board itself is represented by an 8-by-8 two-dimensional array board.
 * 	   Each square is initialized to zero.
 * 	   We describe each of the eight possible moves in terms of both its horizontal and vertical components.
 * 	   For example, a move of type 0, as shown in the preceding diagram, consists of moving two squares horizontally to the right and one square vertically upward.
 * 	   Move 2 consists of moving one square horizontally to the left and two squares vertically upward.
 * 	   Horizontal moves to the left and vertical moves upward are indicated with negative numbers.
 * 	   The eight moves may be described by two one-dimensional arrays, horizontal and vertical, as follows:
 *
 * 	   	horizontal[0] =  2	vertical[0] = -1
 * 	   	horizontal[1] =  1	vertical[0] = -2
 * 	   	horizontal[2] = -1	vertical[0] = -2
 * 	   	horizontal[3] = -2	vertical[0] = -1
 * 	   	horizontal[4] = -2	vertical[0] = 1
 * 	   	horizontal[5] = -1	vertical[0] = 2
 * 	   	horizontal[6] =  1	vertical[0] = 2
 * 	   	horizontal[7] =  2	vertical[0] = 1
 *
 * 	   The variables currentRow and currentColumn indicate the row and column of the knight's current position.
 * 	   To make a move of type moveNumber, where moveNumber is between 0 and 7, your program uses the statements
 * 	   
 * 	   	currentRow += vertical[moveNumber];
 * 	   	currentColumn += horizontal[moveNumber];
 *
 * 	   Keep a counter that varies from 1 to 64.
 * 	   Record the latest count in each square the knight moves to.
 * 	   Remember to test each potential move to see if the knight has already visited that square.
 * 	   And, of course, test every potential move to make sure that the knight does not land off the chessboard.
 * 	   Now write a program to move the knight around the chessboard.
 * 	   Run the program.
 * 	   How many moves did the knight make?
 *
 * 	c) After attempting to write and run a Knight's Tour program, you have probably developed some valuable insights.
 * 	   We'll use these to develop a heuristic (or strategy) for moving the knight.
 * 	   Heuristics do not guarantee success, but a carefully developed heuristic greatly improves the chance of success.
 * 	   You may have observed that the outer squares are in some sense more troublesome than the squares nearer to the center of the board.
 * 	   In fact, the most troublesome, or inaccessible, squares are the four corners.
 *
 * 	   Intuition may suggest that you should attempt to move the knight to the most troublesome squares first and leave open those that are easiest to get to,
 *	   so that when the board gets congested near the end of the tour, there will be a greater chance of success.
 *
 *	   We develop an "accessibility heuristic" by classifying each square according to how accessible it is and always moving the knight to the square
 *	   (within the knight's L-shaped moves, of course) that's most inaccessible.
 *	   We label a two-dimensional array accessibility with numbers indicating from how many squares each particular square is accessible.
 *	   On a blank chessboard, the center squares are therefore rated as 8s, the corner squares are rated as 2s,
 *	   and the other squares have accessibility numbers of 3, 4, or 6 as follows:
 *
 *	   	2  3  4  4  4  4  3  2
 * 		  3  4  6  6  6  6  4  3
 * 		  4  6  8  8  8  8  6  4
 * 		  4  6  8  8  8  8  6  4
 * 		  4  6  8  8  8  8  6  4
 * 		  4  6  8  8  8  8  6  4
 * 		  3  4  6  6  6  6  4  3
 *	   	2  3  4  4  4  4  3  2
 *
 * 	   Now write a version of the Knight's Tour program using the accessibility heuristic.
 * 	   At any time the knight should move to the square with the lowest accesibility number.
 * 	   In case of a tie, the knight may move to any of the tied squares.
 * 	   Therefore, the tour may begin in any of the four corners.
 * 	   [Note: As the knight moves around the chessboard, your program should reduce the accessibility numbers as more and more squares become occupied.
 * 	   In this way, at any given time during the tour, each available square's accessibility number will remain equal to precisely the number of squares
 * 	   from which that square may be reached.]
 * 	   Run this version of your program.
 * 	   Did you get a full tour?
 * 	   (Optional: Modify the program to run 64 tours, one from each square of the chessboard.
 *	   How many full tours did you get?)
 * 
 * 	d) Write a version of the Knight's Tour program which, when encountering a tie between two or more squares,
 * 	   decides what square to choose by looking ahead to those squares reachable from the "tied" squares.
 * 	   Your program should move the square for which the next move would arrive at a square with the lowest accessibility number.
 */

#include <stdio.h>

int knight(int currentRow[], int currentColumn[], int board[][8], int counter, int accessibility[][8]);
int minAccessibilityNum(int currentRow[], int currentColumn[], int board[][8], int accessibility[][8], int aroundKnight[]);
size_t position(int result, int aroundKnight[]);
int minimumArrayElementGreaterThanZero(int aroundKnight[]);
int horizontal[] = {2, 1, -1, -2, -2, -1, 1, 2};
int vertical[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void) {
	for (size_t row = 0; row < 8; ++row)
		for (size_t column = 0; column < 8; ++column) {
			int board[8][8] = {};
			int currentRow[1] = {};
			int currentColumn[1] = {};
			int moves;
			int accessibility[][8] = {{2, 3, 4, 4, 4, 4, 3, 2},
						                    {3, 4, 6, 6, 6, 6, 4, 3},
						                    {4, 6, 8, 8, 8, 8, 6, 4},
						                    {4, 6, 8, 8, 8, 8, 6, 4},
						                    {4, 6, 8, 8, 8, 8, 6, 4},
						                    {4, 6, 8, 8, 8, 8, 6, 4},
						                    {3, 4, 6, 6, 6, 6, 4, 3},
						                    {2, 3, 4, 4, 4, 4, 3, 2}};

			currentRow[0] = row;
			currentColumn[0] = column;
			board[currentRow[0]][currentColumn[0]] = 100;		// assigning 100 to starting position


			for (size_t i = 0; i < 64; ++i)
				if (!knight(currentRow, currentColumn, board, i + 1, accessibility)) {
					moves = i;
					break;
				}
			
			if (moves == 63) {
				printf("Moves = %d\t\tStarting point: 100\n", moves);
				for (size_t r = 0; r < 8; ++r) {
					for (size_t c = 0; c < 8; ++c)
						printf("%d\t", board[r][c]);
					printf("%s", "\n\n\n\n");
				}
			}
		}

	return 0;
}
		
int knight(int currentRow[], int currentColumn[], int board[][8], int counter, int accessibility[][8]) {
	int aroundKnight[8] = {};

	int result = minAccessibilityNum(currentRow, currentColumn, board, accessibility, aroundKnight);

	if (result) {
		size_t moveNumber = position(result, aroundKnight);

		--accessibility[currentRow[0]][currentColumn[0]];

		currentRow[0] += vertical[moveNumber];	
		currentColumn[0] += horizontal[moveNumber];

		board[currentRow[0]][currentColumn[0]] = counter;
		
		return result;
	}
	else
		return result;
}

int minAccessibilityNum(int currentRow[], int currentColumn[], int board[][8], int accessibility[][8], int aroundKnight[]) {
	for (size_t j = 0; j < 8; ++j) {
        	int nextRow = currentRow[0] + vertical[j];
        	int nextColumn = currentColumn[0] + horizontal[j];
                                                                                                                             
        	if (nextRow >= 0 && nextRow < 8 && nextColumn >= 0 && nextColumn < 8 && board[nextRow][nextColumn] == 0)
                	aroundKnight[j] = accessibility[nextRow][nextColumn];
	}
          
	return minimumArrayElementGreaterThanZero(aroundKnight);
}

size_t position(int result, int aroundKnight[]) {
	for (size_t pos = 0; pos < 8; ++pos)
		if (result == aroundKnight[pos])
			return pos;
}

int minimumArrayElementGreaterThanZero(int aroundKnight[]) {
	int temp = aroundKnight[0];
                                      
	for (size_t i = 1; i < 8; ++i)
		if (aroundKnight[i] > temp)    
			temp = aroundKnight[i];

	for (size_t k = 0; k < 8; ++k)
		if (aroundKnight[k] != 0 && aroundKnight[k] < temp)
			temp = aroundKnight[k];

	return temp;
}
