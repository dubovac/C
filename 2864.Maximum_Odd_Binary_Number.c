/**
 * 2864. Maximum Odd Binary Number
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * You are given a binary string s that contains at least one '1'.
 *
 * You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
 *
 * Return a string representing the maximum odd binary number that can be created from the given combination.
 *
 * Note that the resulting string can have leading zeros.
 *
 *
 *
 * Example 1:
 *
 *	Input: s = "010"
 *	Output: "001"
 *	Explanation: Because there is just one '1', it must be in the last position.
 *	So the answer is "001".
 *
 * Example 2:
 *
 *	Input: s = "0101"
 *	Output: "1001"
 *	Explanation: One of the '1's must be in the last position.
 *	The maximum number that can be made with the remaining digits is "100".
 *	So the answer is "1001".
 *
 *
 *
 * Constraints:
 *
 *	1 <= s.length <= 100
 *	s consists only of '0' and '1'.
 *	s contains at least one '1'.
 */

#include <stdio.h>
#include <stdlib.h>

char* maximumOddBinaryNumber(char* s){
	int ones = 0;
	int length = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '1')
			ones++;
		length++;
	}

	char* r = (char *) malloc((length + 1) * sizeof(char));

	r[length] = '\0';
	r[length - 1] = '1';

	for (int i = 0; i < length - 1; i++) {
		if (i < ones - 1)
			r[i] = '1';
		else
			r[i] = '0';
	}

	return r;
}

int main(void) {
	char* s0 = "010";
	char* r0 = maximumOddBinaryNumber(s0);
	printf("s0 = %s\n", s0);
	printf("r0 = %s\n", r0);

	char* s1 = "0101";
	char* r1 = maximumOddBinaryNumber(s1);
	printf("\ns1 = %s\n", s1);
	printf("r1 = %s\n", r1);
}
