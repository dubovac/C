/**
 * 54. Spiral Matrix
 * Medium
 * Topics
 * Companies
 * Hint
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 *
 * Example 1:
 *
 *	1 → 2 → 3
 *		↓
 *	4 → 5   6
 *	↑	↓
 *	7 ← 8 ← 9
 *
 *	Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *	Output: [1,2,3,6,9,8,7,4,5]
 *
 * Example 2:
 *
 *	1 →  2 →  3 →  4
 *		       ↓
 *	5 →  6 →  7    8
 *	↑	       ↓
 *	9 ← 10 ← 11 ← 12
 *
 *	Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 *	Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *	m == matrix.length
 *	n == matrix[i].length
 *	1 <= m, n <= 10
 *	-100 <= matrix[i][j] <= 100
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	*returnSize = matrixSize * *matrixColSize;
	int* result = (int *) malloc(*returnSize * sizeof(int));

	int left = 0;
	int right = *matrixColSize;
	int top = 0;
	int bottom = matrixSize;

	int k = 0;

	while(1) {
		for (int j = left; j < right; j++) {
			result[k++] = matrix[top][j];
			if (k == *returnSize)
				break;
		}

		if (k == *returnSize)
			break;

		for (int i = top + 1; i < bottom; i++) {
			result[k++] = matrix[i][right - 1];
			if (k == *returnSize)
				break;
		}

		if (k == *returnSize)
			break;

		for (int j = right - 2; j >= left; j--) {
			result[k++] = matrix[bottom - 1][j];
			if (k == *returnSize)
				break;
		}

		if (k == *returnSize)
			break;

		for (int i = bottom - 2; i > top; i--) {
			result[k++] = matrix[i][left];
			if (k == *returnSize)
				break;
		}

		if (k == *returnSize)
			break;

		left++;
		right--;
		top++;
		bottom--;
	}

	return result;
		
}
int main(void) {

	int mS0 = 3;				// matrix size
	int mCS0 = 3;				// matrix column size
	int* mCSPtr0 = &mCS0;			// matrix column size pointer
	int rS0 = 0;				// return size
	int* rSPtr0 = &rS0;			// return size pointer
	int** matrix0 = (int **) malloc(mS0 * sizeof(int *));
	for (int i = 0; i < mS0; i++)
		matrix0[i] = (int *) malloc(mCS0 * sizeof(int));
	
	int k = 1;
	for (int i = 0; i < mS0; i++) {
		for (int j = 0; j < mCS0; j++) {
			matrix0[i][j] = k++;
			printf("%d\t", matrix0[i][j]);
		}
		puts("");
	}
	puts("");

	int* r0 = spiralOrder(matrix0, mS0, mCSPtr0, rSPtr0);

	for (int i = 0; i < mS0 * mCS0; i++)
		printf("%d ", r0[i]);
	puts("\n\n");

//-----------------------------------------------------------------------------------

	int mS1 = 3;				// matrix size
	int mCS1 = 4;				// matrix column size
	int* mCSPtr1 = &mCS1;			// matrix column size pointer
	int rS1 = 0;				// return size
	int* rSPtr1 = &rS1;			// return size pointer
	int** matrix1 = (int **) malloc(mS1 * sizeof(int *));
	for (int i = 0; i < mS1; i++)
		matrix1[i] = (int *) malloc(mCS1 * sizeof(int));
	
	k = 1;
	for (int i = 0; i < mS1; i++) {
		for (int j = 0; j < mCS1; j++) {
			matrix1[i][j] = k++;
			printf("%d\t", matrix1[i][j]);
		}
		puts("");
	}
	puts("");

	int* r1 = spiralOrder(matrix1, mS1, mCSPtr1, rSPtr1);

	for (int i = 0; i < mS1 * mCS1; i++)
		printf("%d ", r1[i]);
	puts("\n\n");

//-----------------------------------------------------------------------------------

	int mS2 = 5;				// matrix size
	int mCS2 = 8;				// matrix column size
	int* mCSPtr2 = &mCS2;			// matrix column size pointer
	int rS2 = 0;				// return size
	int* rSPtr2 = &rS2;			// return size pointer
	int** matrix2 = (int **) malloc(mS2 * sizeof(int *));
	for (int i = 0; i < mS2; i++)
		matrix2[i] = (int *) malloc(mCS2 * sizeof(int));
	
	k = 1;
	for (int i = 0; i < mS2; i++) {
		for (int j = 0; j < mCS2; j++) {
			matrix2[i][j] = k++;
			printf("%d\t", matrix2[i][j]);
		}
		puts("");
	}
	puts("");

	int* r2 = spiralOrder(matrix2, mS2, mCSPtr2, rSPtr2);

	for (int i = 0; i < mS2 * mCS2; i++)
		printf("%d ", r2[i]);
	puts("\n");

}
