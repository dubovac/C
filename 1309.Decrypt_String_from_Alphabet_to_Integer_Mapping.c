/**
 * 1309. Decrypt String from Alphabet to Integer Mapping
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * You are given a string s formed by digits and '#'.
 * We want to map s to English lowercase characters as follows:
 *
 *	Characters ('a' to 'i') are represented by ('1' to '9') respectively.
 *	Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
 *
 * Return the string formed after mapping.
 *
 * The test cases are generated so that a unique mapping will always exist.
 *
 *
 *
 * Example 1:
 *
 *	Input: s = "10#11#12"
 *	Output: "jkab"
 *	Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
 *
 * Example 2:
 *
 *	Input: s = "1326#"
 *	Output: "acz"
 *
 *
 *
 * Constraints:
 *
 *	1 <= s.length <= 1000
 *	s consists of digits and the '#' letter.
 *	s will be a valid string such that mapping is always possible.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* freqAlphabets(char* s) {
	if (strlen(s) == 0) {
		char* r = (char *) malloc(sizeof(char));
		r[0] = '\0';
		return r;
	}

	char ss[strlen(s) + 1];
	int k = 0;

	int i = (int) strlen(s) - 1;

	while (i >= 0) {
		int j = 0;

		if (s[i] == '#') {
			if (s[i - 2] == '1')
				j = 10;
			else
				j = 20;
			j += s[i - 1] - '0';
			ss[k++] = j + 'a' - 1;
			
			i -= 3;
		}
		else {
			j = s[i] - '0';
			ss[k++] = j + 'a' - 1;
			
			i--;
		}
	}

	ss[k] = '\0';
	char* r = (char *) malloc((k + 1) * sizeof(char));

	for (int i = 0; i < k; i++)
		r[i] = ss[k - i - 1];

	r[k] = '\0';

	return r;
}

int main(void) {
	char* s0 = "";
	char* r0 = freqAlphabets(s0);
	printf("%s\n", r0);

	char* s1 = "12";
	char* r1 = freqAlphabets(s1);
	printf("%s\n", r1);

	char* s2 = "12#";
	char* r2 = freqAlphabets(s2);
	printf("%s\n", r2);

	char* s3 = "99912#345";
	char* r3 = freqAlphabets(s3);
	printf("%s\n", r3);

	char* s4 = "151112";
	char* r4 = freqAlphabets(s4);
	printf("%s\n", r4);
}
