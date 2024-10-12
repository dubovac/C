/**
 * 383. Ransom Note
 * Easy
 * Topics
 * Companies
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 *
 * Example 1:
 *
 *	Input: ransomNote = "a", magazine = "b"
 *	Output: false
 *
 * Example 2:
 *
 *	Input: ransomNote = "aa", magazine = "ab"
 *	Output: false
 *
 * Example 3:
 *
 *	Input: ransomNote = "aa", magazine = "aab"
 *	Output: true
 *
 *
 *
 * Constraints:
 *
 *	1 <= ransomNote.length, magazine.length <= 10^5
 *	ransomNote and magazine consist of lowercase English letters.
 */

#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
	int rN[26] = {0};
	int m[26] = {0};

	for (int i = 0; ransomNote[i] != '\0'; i++)
		rN[ransomNote[i] - 'a']++;


	for (int i = 0; magazine[i] != '\0'; i++)
		m[magazine[i] - 'a']++;



	for (int i = 0; i < 26; i++)
		if (rN[i] != 0 && rN[i] > m[i])
			return false;
	
	return true;
}

int main(void) {
	char ransomNote0[] = "a";
	char magazine0[] = "b";
	printf("%s\n", canConstruct(ransomNote0, magazine0) ? "True" : "False");

	char ransomNote1[] = "aa";
	char magazine1[] = "ab";
	printf("%s\n", canConstruct(ransomNote1, magazine1) ? "True" : "False");

	char ransomNote2[] = "aa";
	char magazine2[] = "aab";
	printf("%s\n", canConstruct(ransomNote2, magazine2) ? "True" : "False");

	char ransomNote3[] = "bg";
	char magazine3[] = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"; 
	printf("%s\n", canConstruct(ransomNote3, magazine3) ? "True" : "False");
}
