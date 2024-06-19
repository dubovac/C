/*
 *
 * 118. Pascal's Triangle
 * Easy
 * Topics
 * Companies
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *
 *			      1
 *		      1   1
 *		    1   2   1
 *		  1   3   3   1
 *		1   4   6   4   1
 *
 * Example 1:
 *
 * 	Input: numRows = 5
 * 	Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *
 * Example 2:
 *
 * 	Input: numRows = 1
 * 	Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 * 	1 <= numRows <= 30
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	*returnSize = numRows;

    *returnColumnSizes = (int *) malloc(numRows * sizeof(int));  
	int** array = (int **) malloc(numRows * sizeof(int *));
	
	for (int i = 0; i < numRows; i++) {
		*returnColumnSizes[i] = i + 1;	// LEETCODE LINE IS: (*returnColumnSizes)[i] = i + 1;

		array[i] = (int *) malloc((i + 1) * sizeof(int));

		for (int j = 0; j <= i; j++)
			if (j == 0 || j == i)
				array[i][j] = 1;
			else
				array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
	}

	return array;   
}

int main(void) {
	int r = 5;
	int* rS = &r;

	int r0 = 0;
	int* rp0 = &r0;
	int r1 = 0;
	int* rp1 = &r1;
	int r2 = 0;
	int* rp2 = &r2;
	int r3 = 0;
	int* rp3 = &r3;
	int r4 = 0;
	int* rp4 = &r4;
	int* rCS[] = {rp0, rp1, rp2, rp3, rp4};

	for (int i = 0; i < *rS; i++)
		printf("*rCS = %d\n", *rCS[i]);

	int** returnCS = generate(r, rS, rCS);
	printf("*rS = %d\n", *rS);
	for (int i = 0; i < *rS; i++)
		printf("*rCS = %d\n", *rCS[i]);

	for (int i = 0; i < *rS; i++) {
		for (int j = 0; j < *rCS[i]; j++)
			printf("%d\t", returnCS[i][j]);
		puts("");
	}

}
