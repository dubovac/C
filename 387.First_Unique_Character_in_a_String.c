/**
 * 387. First Unique Character in a String
 * Easy
 * Topics
 * Companies
 *
 * Given a string s, find the first non-repeating character in it and return its index.
 * If it does not exist, return -1.
 *
 *
 *
 * Example 1:
 *
 *	Input: s = "leetcode"
 *	Output: 0
 *	Explanation:
 *	The character 'l' at index 0 is the first character that does not occur at any other index.
 *
 * Example 2:
 *
 *	Input: s = "loveleetcode"
 *	Output: 2
 *
 * Example 3:
 *
 *	Input: s = "aabb"
 *	Output: -1
 *
 *
 *
 * Constraints:
 *
 *	1 <= s.length <= 10^5
 *	s consists of only lowercase English letters.
 */

#include <stdio.h>

int firstUniqChar(char* s) {
	int t[26] = {0};

	for (int i = 0; s[i] != '\0'; i++)
		t[s[i] - 'a']++;

	for (int i = 0; s[i] != '\0'; i++)
		if (t[s[i] - 'a'] == 1)
			return i;

	return -1;
}

int main(void) {
	char* s0 = "leetcode";
	printf("%d\n", firstUniqChar(s0));

	char* s1 = "loveleetcode";
	printf("%d\n", firstUniqChar(s1));

	char* s2 = "aabb";
	printf("%d\n", firstUniqChar(s2));
}
