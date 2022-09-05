/*
 * 9. Palindrome Number
 * Easy
 *
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 *
 *	For example, 121 is a palindrome while 123 is not.
 *
 * Example 1:
 *
 *	Input: x = 121
 *	Output: true
 *	Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 *
 *	Input: x = -121
 *	Output: false
 *	Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 *
 *	Input: x = 10
 *	Output: false
 *	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 *
 * Constraints:
 *
 *	-2^31 <= x <= 2^31 - 1
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(void) {
	int n = 54;
	printf("Number %d is palindrome? %s\n", n, isPalindrome(n) ? "True" : "False");

	n = 123454321;
	printf("Number %d is palindrome? %s\n", n, isPalindrome(n) ? "True" : "False");

	n = -454;
	printf("Number %d is palindrome? %s\n", n, isPalindrome(n) ? "True" : "False");

	n = 0;
	printf("Number %d is palindrome? %s\n", n, isPalindrome(n) ? "True" : "False");
	return 0;
}

bool isPalindrome(int x) {
	if (x < 0)
		return 0;

	if (x == 0)
		return 1;

	int y = x;
	int i = 0;

	while (y > 0) {
		y /= 10;
		++i;
	}

	int j = i - 1;

	int s[i];

	for (; i > 0; --i) {
		s[i - 1] = x % 10;
		x /= 10;
	}

	for (; i < j; ++i, --j)
		if (s[i] != s[j])
			return 0;

	return 1;
}
