/**
 * 766. Toeplitz Matrix
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Given an m x n matrix, return true if the matrix is Toeplitz.
 * Otherwise, return false.
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
 *
 *
 *
 * Example 1:
 *
 * 	1	2	3	4
 *
 * 	5	1	2	3
 *
 * 	9	5	1	2
 *
 *	Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 *	Output: true
 *	Explanation:
 *	In the above grid, the diagonals are:
 *	"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 *	In each diagonal all elements are the same, so the answer is True.
 *
 * Example 2:
 *
 * 	1	2
 *
 * 	2	2
 *
 *	Input: matrix = [[1,2],[2,2]]
 *	Output: false
 *	Explanation:
 *	The diagonal "[1, 2]" has different elements.
 *
 *
 *
 * Constraints:
 *
 *	m == matrix.length
 *	n == matrix[i].length
 *	1 <= m, n <= 20
 *	0 <= matrix[i][j] <= 99
 *
 *
 *
 * Follow up:
 *
 *	What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
 *	What if the matrix is so large that you can only load up a partial row into the memory at once?
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
	if (matrixSize == 1 || *matrixColSize == 1)
		return true;

	for (int i = 0; i < *matrixColSize - 1; i++) {
		int j = 1;

		while (j < matrixSize && i + j < *matrixColSize) {
			if (matrix[j][i + j] != matrix[j - 1][i + j - 1])
				return false;
			j++;
		}
	}

	for (int k = 1; k < matrixSize - 1; k++) {
		int l = 1;

		while (k + l < matrixSize && l < *matrixColSize) {
			if (matrix[k + l][l] != matrix[k + l - 1][l - 1])
				return false;
			l++;
		}
	}

	return true;
}

int main(void) {
	int** m = (int **) malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++)
		m[i] = (int *) malloc(4 * sizeof(int));

	int mS = 3;
	int matrixCS = 4;
	int *mCS = &matrixCS;

	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[0][3] = 4;

	m[1][0] = 5;
	m[1][1] = 1;
	m[1][2] = 2;
	m[1][3] = 3;

	m[2][0] = 9;
	m[2][1] = 5;
	m[2][2] = 1;
	m[2][3] = 2;

	printf("%s\n", isToeplitzMatrix(m, mS, mCS) ? "True" : "False");
}
