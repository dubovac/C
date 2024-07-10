/**
 * 258. Add Digits
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
 *
 *
 *
 * Example 1:
 *
 * 	Input: num = 38
 * 	Output: 2
 * 	Explanation: The process is
 * 	38 --> 3 + 8 --> 11
 * 	11 --> 1 + 1 --> 2
 * 	Since 2 has only one digit, return it.
 *
 * Example 2:
 *
 * 	Input: num = 0
 * 	Output: 0
 *
 *
 *
 * Constraints:
 *
 * 	0 <= num <= 231 - 1
 *
 *
 * 
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
 */
#include <stdio.h>

int addDigits(int num) {
	if (num > 9)
		while (num > 9) {
			int sum = 0;
			while (num != 0) {
				sum += num % 10;
				num /= 10;
			}
			num = sum;
		}

	return num;
}

int main(void) {
	int x = 2147483647;

	printf("%d\n", addDigits(x));
}
