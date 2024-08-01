/**
 * 709. To Lower Case
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
 *
 *
 *
 * Example 1:
 *
 * 	Input: s = "Hello"
 * 	Output: "hello"
 *
 * Example 2:
 *
 * 	Input: s = "here"
 * 	Output: "here"
 *
 * Example 3:
 *
 * 	Input: s = "LOVELY"
 * 	Output: "lovely"
 *
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 100
 * 	s consists of printable ASCII characters.
 */
#include <stdio.h>
#include <stdlib.h>

char* toLowerCase(char* s) {
	int counter = 0;

	while (s[counter++] != '\0');

	char* ss = (char *) malloc((counter + 1) * sizeof(char));

	for (int i = 0; i < counter; i++)
		if ('A' <= s[i] && s[i] <= 'Z')
			ss[i] = s[i] - 'A' + 'a';
		else
			ss[i] = s[i];

	ss[counter] = '\0';

	return ss;
}

int main(void) {
	char* s = "Hello World!";

	printf("%s\n", toLowerCase(s));
}
