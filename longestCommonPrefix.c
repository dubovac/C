/*
 * 14. Longest Common Prefix
 * Easy
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *	Input: strs = ["flower","flow","flight"]
 *	Output: "fl"
 *
 * Example 2:
 *
 *	Input: strs = ["dog","racecar","car"]
 *	Output: ""
 *	Explanation: There is no common prefix among the input strings.
 *
 *
 * Constraints:
 *
 *	1 <= strs.length <= 200
 *	0 <= strs[i].length <= 200
 *	strs[i] consists of only lowercase English letters.
 */
#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize);

int main(void) {
	char *strs[] = {"flower", "flow", "flight"};
	printf("%s\n", longestCommonPrefix(strs, 3));

	char *strs1[] = {"flower", "flower", "flower"};
	printf("%s\n", longestCommonPrefix(strs1, 3));


	char *strs2[] = {"", "flower", ""};
	printf("%s\n", longestCommonPrefix(strs2, 3));

	char *strs3[] = {"", "", ""};
	printf("%s\n", longestCommonPrefix(strs3, 3));

	return 0;
}

char *longestCommonPrefix(char **strs, int strsSize) {
	if (strsSize <= 1)
		return strs[0];
	
	int n = 0, m;

	for (int i = 0; strs[0][i] != '\0'; ++i)
		++n;

	for (int j = 1; j < strsSize; ++j) {
		m = 0;

		for (int k = 0; strs[j][k] != '\0'; ++k)
			++m;

		if (m < n)
			n = m;
	}

	char *resultStr = (char *)malloc((n + 1) * sizeof(char));

	int t = 1;
	int z = 0;
	
	for (int p = 0; t != 0; ++p) {
		for (int l = 1; l < strsSize && t != 0; ++l)
			if (strs[0][p] != strs[l][p]) 
				t = 0;

		if (t && strs[0][p] != '\0')
			resultStr[z++] = strs[0][p];
		else {
			resultStr[z] = '\0';
			return  resultStr;
		}
	}

	return 0;
}
