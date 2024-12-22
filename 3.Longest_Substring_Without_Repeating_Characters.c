/**
 * 3. Longest Substring Without Repeating Characters
 * Medium
 * Topics
 * Companies
 * Hint
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 *
 *
 * Example 1:
 *
 *	Input: s = "abcabcbb"
 *	Output: 3
 *	Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 *
 *	Input: s = "bbbbb"
 *	Output: 1
 *	Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 *
 *	Input: s = "pwwkew"
 *	Output: 3
 *	Explanation: The answer is "wke", with the length of 3.
 *	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 *
 * Constraints:
 *
 *	0 <= s.length <= 5 * 10^4
 *	s consists of English letters, digits, symbols and spaces.
 */

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
	int max = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		int ascii[128] = {0};
		int len = 0;

		for (int j = i; s[j] != '\0'; j++) {
			if (ascii[(int) s[j]] == 0) {
				len++;
				ascii[(int) s[j]]++;
			}
			else
				break;			
		}
		
		if (len > max)
			max = len;
	}

	return max;
}

int main(void) {
	char* s0 = "abcabcbb";
	printf("%d\n", lengthOfLongestSubstring(s0));

	char* s1 = "bbbbb";
	printf("%d\n", lengthOfLongestSubstring(s1));

	char* s2 = "pwwkew";
	printf("%d\n", lengthOfLongestSubstring(s2));
}
