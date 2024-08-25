/**
 * 344. Reverse String
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Write a function that reverses a string.
 * The input string is given as an array of characters s.
 *
 * You must do this by modifying the input array in-place with O(1) extra memory.
 *
 *
 *
 * Example 1:
 *
 * 	Input: s = ["h","e","l","l","o"]
 * 	Output: ["o","l","l","e","h"]
 *
 * Example 2:
 *
 * 	Input: s = ["H","a","n","n","a","h"]
 * 	Output: ["h","a","n","n","a","H"]
 *
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 105
 * 	s[i] is a printable ascii character.
 */

#include <stdio.h>

void reverseString(char* s, int sSize) {
	for (int i = 0, j = sSize - 1; i < j; i++, j--) {
		s[i] ^= s[j];
		s[j] ^= s[i];
		s[i] ^= s[j];
	}
}

int main(void) {
	char s[] = "hello";
	int sSize = 5;

	printf("%s\n", s);

	reverseString(s, sSize);

	printf("%s\n", s);
}
