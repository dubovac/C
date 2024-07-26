/*
 * 205. Isomorphic Strings
 * Easy
 * Topics
 * Companies
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters.
 * No two characters may map to the same character, but a character may map to itself.
 *
 *
 *
 * Example 1:
 *
 * 	Input: s = "egg", t = "add"
 * 	Output: true
 *
 * Example 2:
 *
 * 	Input: s = "foo", t = "bar"
 * 	Output: false
 *
 * Example 3:
 *
 * 	Input: s = "paper", t = "title"
 * 	Output: true
 *
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 5 * 104
 * 	t.length == s.length
 * 	s and t consist of any valid ascii character.
 */
#include <stdbool.h>
#include <stdio.h>

bool isIsomorphic(char* s, char* t) {
	int length = 0;

	for (int i = 0; s[i] != '\0'; i++)
		length++;

	int s_array[length], t_array[length];

	for (int i = 0; i < length; i++) {
		s_array[i] = 0;
		t_array[i] = 0;
	}

	int s_counter = 0;
	int t_counter = 0;
	bool return_bool = true;

	for (int i = 1; i < length; i++) {
		bool s_check = true;
		bool t_check = true;

		for (int j = 0; j < i; j++)
			if (s[i] == s[j]) {
				s_array[i] = s_array[j];
				s_check = false;
				break;
			}

		for (int j = 0; j < i; j++)
			if (t[i] == t[j]) {
				t_array[i] = t_array[j];
				t_check = false;
				break;
			}

		if (s_check)
			s_array[i] = ++s_counter;

		if (t_check)
			t_array[i] = ++t_counter;

		if (s_array[i] != t_array[i]) {
			return_bool = false;
			break;
		}
	}

	return return_bool;
}

int main(void) {
	char* s0 = "egg";
	char* t0 = "add";

	if(isIsomorphic(s0, t0))
		printf("True\n");
	else
		printf("False\n");

	char* s1 = "foo";
	char* t1 = "bar";

	if(isIsomorphic(s1, t1))
		printf("True\n");
	else
		printf("False\n");

	char* s2 = "paper";
	char* t2 = "title";

	if(isIsomorphic(s2, t2))
		printf("True\n");
	else
		printf("False\n");

}
