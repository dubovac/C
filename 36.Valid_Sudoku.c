#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
	char compare[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // '0' is in array to compare index numbers according to array elements

	for (int i = 0; i < boardSize; i++) {
		int result[10] = {0};
		for (int j = 0; j < *boardColSize; j++)
			for (int k = 1; k < 10; k++)
				if (board[i][j] == compare[k])
					if (++result[k] > 1)
						return false;

	}


	for (int j = 0; j < boardSize; j++) {
		int result[10] = {0};
		for (int i = 0; i < *boardColSize; i++)
			for (int k = 1; k < 10; k++)
				if (board[i][j] == compare[k])
					if (++result[k] > 1)
						return false;

	}

	for (int n = 0; n < 9; n += 3)
		for (int m = 0; m < 9; m += 3) {
			int result[10] = {0};
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					for (int k = 1; k < 10; k++)
						if (board[n + i][m + j] == compare[k])
							if (++result[k] > 1)
								return false;
		}

	return true;
}

int main(void) {
	int bS = 9;
	int* bCS = &bS;
	char** b = (char **) malloc(bS * sizeof(char *));

	for (int i = 0; i < bS; i++)
		b[i] = (char *) malloc(*bCS * sizeof(char));
  	char* temp[] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};

	for (int i = 0; i < bS; i++) {
		for (int j = 0; j < *bCS; j++) {
			b[i][j] = temp[i][j];
			printf("%c\t", b[i][j]);
		}
		puts("");
	}

	printf("%s\n", isValidSudoku(b, bS, bCS) ? "True" : "False");

	for (int i = 0; i < bS; i++)
		free(b[i]);

	free(b);
}
