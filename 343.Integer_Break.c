/**
 * 343. Integer Break
 * Medium
 * Topics
 * Companies
 * Hint
 *
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 *
 * Example 1:
 *
 *	Input: n = 2
 *	Output: 1
 *	Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 * Example 2:
 *
 * 	Input: n = 10
 * 	Output: 36
 * 	Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *	2 <= n <= 58
 */
#include <stdio.h>

int integerBreak(int n) {
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	if (n == 4)
		return 4;

	int max = 1;

	while (n > 4) {
		max *= 3;
		n -= 3;
	}
	
	if (n == 2)
		max *= 2;

	if (n == 3)
		max *= 3;

	if (n == 4)
		max *= 4;

	return max;
}
int main(void) {
	for (int i = 2; i <= 58; i++)
		printf("%d:\t%d\n", i, integerBreak(i));
}
