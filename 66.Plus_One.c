/*
 * 66. Plus One
 * Easy
 * Topics
 * Companies
 *
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order.
 * The large integer does not contain any leading 0's.
 *
 * Increment the large integer by one and return the resulting array of digits.
 *
 *
 *
 * Example 1:
 * 
 * 	Input: digits = [1,2,3]
 * 	Output: [1,2,4]
 * 	Explanation: The array represents the integer 123.
 * 	Incrementing by one gives 123 + 1 = 124.
 * 	Thus, the result should be [1,2,4].
 *
 * Example 2:
 *
 * 	Input: digits = [4,3,2,1]
 * 	Output: [4,3,2,2]
 * 	Explanation: The array represents the integer 4321.
 * 	Incrementing by one gives 4321 + 1 = 4322.
 * 	Thus, the result should be [4,3,2,2].
 *
 * Example 3:
 *
 * 	Input: digits = [9]
 * 	Output: [1,0]
 * 	Explanation: The array represents the integer 9.
 * 	Incrementing by one gives 9 + 1 = 10.
 * 	Thus, the result should be [1,0].
 *
 *
 *
 * Constraints:
 *
 * 	1 <= digits.length <= 100
 * 	0 <= digits[i] <= 9
 * 	digits does not contain any leading 0's.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int add = 1;
	for (int i = digitsSize - 1; i >= 0; i--) {
		digits[i] += add;
		if (digits[i] >= 10)
			digits[i] -= 10;
		else {
			add = 0;
			break;
		}
	}
	*returnSize = digitsSize + add;

	int* returnDigits = (int *) malloc(*returnSize * sizeof(int));

	if (*returnSize == digitsSize)			// add is 0
		for (int i = 0; i < *returnSize; i++)
			returnDigits[i] = digits[i];
	else {						// add is 1
		returnDigits[0] = add;
		for (int i = 1; i < *returnSize; i++)
			returnDigits[i] = digits[i - 1];
	}

	return returnDigits;
}

int main(void) {
	int digits[] = {9, 9, 9, 9, 9};
	int digitsSize = 5;
	int zero = 0;
	int* returnSize = &zero;

	int* returnDigits = plusOne(digits, digitsSize, returnSize);

	for (int i = 0; i < *returnSize; i++)
		printf("returnDigits[%d] = %d\n", i, returnDigits[i]);
}
