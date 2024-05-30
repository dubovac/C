/*
 * 28. Find the Index of the First Occurrence in a String
 * Easy
 * Topics
 * Companies
 *
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 *
 *
 * Example 1:
 *
 * 	Input: haystack = "sadbutsad", needle = "sad"
 * 	Output: 0
 * 	Explanation: "sad" occurs at index 0 and 6.
 * 	The first occurrence is at index 0, so we return 0.
 *
 * Example 2:
 *
 * 	Input: haystack = "leetcode", needle = "leeto"
 * 	Output: -1
 * 	Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 *
 *
 * Constraints:
 *
 * 	1 <= haystack.length, needle.length <= 104
 * 	haystack and needle consist of only lowercase English characters.
 */
#include <stdio.h>

int strStr(char* haystack, char* needle) {
	for (int i = 0; haystack[i] != '\0'; i++) {
		int j = 0;
		int check = 1;
		while (needle[j] != '\0' && haystack[i + j] != '\0') {
			if (needle[j] != haystack[i + j]) {
				check = 0;
				break;
			}
			j++;

		}
		if (check && haystack[i + j] == '\0' && needle[j] == '\0')
			return i;
		if (check && haystack[i + j] != '\0')
			return i;
		if (haystack[i + j] == '\0')
			return -1;
	}
	return -1;
}

int main(void) {
	char* haystack_1 = "sadbutsad";
	char* needle_1 = "sad";
	printf("Haystack 1 = %s\nNeedle 1 = %s\n", haystack_1, needle_1);
	int index_1 = strStr(haystack_1, needle_1);
	printf("Index 1 = %d\n\n", index_1);

	char* haystack_2 = "leetcode";
	char* needle_2 = "leeto";
	printf("Haystack 2 = %s\nNeedle 2 = %s\n", haystack_2, needle_2);
	int index_2 = strStr(haystack_2, needle_2);
	printf("Index 2 = %d\n\n", index_2);

	char* haystack_3 = "aaa";
	char* needle_3 = "aaaa";
	printf("Haystack 3 = %s\nNeedle 3 = %s\n", haystack_3, needle_3);
	int index_3 = strStr(haystack_3, needle_3);
	printf("Index 3 = %d\n\n", index_3);

	char* haystack_4 = "a";
	char* needle_4 = "a";
	printf("Haystack 4 = %s\nNeedle 4 = %s\n", haystack_4, needle_4);
	int index_4 = strStr(haystack_4, needle_4);
	printf("Index 4 = %d\n", index_4);

}
