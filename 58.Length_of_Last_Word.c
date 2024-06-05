/*
 * 58. Length of Last Word
 * Solved
 * Easy
 * Topics
 * Companies
 *
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 *
 * Example 1:
 *
 * 	Input: s = "Hello World"
 * 	Output: 5
 * 	Explanation: The last word is "World" with length 5.
 *
 * Example 2:
 *
 * 	Input: s = "   fly me   to   the moon  "
 * 	Output: 4
 * 	Explanation: The last word is "moon" with length 4.
 *
 * Example 3:
 *
 * 	Input: s = "luffy is still joyboy"
 * 	Output: 6
 * 	Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 104
 * 	s consists of only English letters and spaces ' '.
 * 	There will be at least one word in s.
 */

#include <stdio.h>

int lengthOfLastWord(char* s) {
	if (s == NULL)
		return 0;

	if (s[0] == '\0')
		return 0;

	int start = 0;
	int stop = 0;
	int in_word = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ' && in_word == 0) {
			start = i;
			in_word = 1;
		}

		if (s[i] == ' ' && in_word == 1) {
			stop = i;
			in_word = 0;
		}

		if (s[i + 1] == '\0' && in_word == 1)
			stop = i + 1;
	}

	return stop - start;
}

int main(void) {
	char* s = "Hello World";
	printf("%d\n", lengthOfLastWord(s));

	char* ss = NULL;
	printf("%d\n", lengthOfLastWord(ss));

	char* sss = "";
	printf("%d\n", lengthOfLastWord(sss));

	char* ssss = "   fly me   to   the moon  ";
	printf("%d\n", lengthOfLastWord(ssss));
	
	char* sssss = "luffy is still joyboy";
	printf("%d\n", lengthOfLastWord(sssss));
}
