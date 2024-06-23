/**
 * 119. Pascal's Triangle II
 * Easy
 * Topics
 * Companies
 *
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
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
 * 	Input: rowIndex = 3
 * 	Output: [1,3,3,1]
 *
 * Example 2:
 *
 * 	Input: rowIndex = 0
 * 	Output: [1]
 *
 * Example 3:
 *
 * 	Input: rowIndex = 1
 * 	Output: [1,1]
 *
 *
 *
 * Constraints:
 *
 * 	0 <= rowIndex <= 33
 *
 *
 *
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
	*returnSize = rowIndex + 1;

	if (rowIndex == 0) {
		int* first = (int *) malloc(sizeof(int));
		*first = 1;
		return first;
	}

	int* current = (int *) malloc(2 * sizeof(int));
	current[0] = 1;
	current[1] = 1;

	if (rowIndex == 1)
		return current;

	for (int i = 2; i < rowIndex + 1; i++) {
		int* next = (int *) malloc((i + 1) * sizeof(int));

		for (int j = 0; j <= i; j++)
			if (j == 0 || j == i)
				next[j] = 1;
			else
				next[j] = current[j - 1] + current[j];
		

		int* temp = current;
		current = next;
		free(temp);
	}

	return current;
}

int main(void) {
	for (int j = 0; j < 34; j++) {
		int rS = 0;
		int rI = j;
		int* rSPtr = &rS;

		int* result = getRow(rI, rSPtr);

		for (int i = 0; i < *rSPtr; i++) {
			printf("%d ", result[i]);
		}
		puts("");
	}

}
