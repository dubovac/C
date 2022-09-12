/*
 * 20. Valid Parentheses
 * Easy
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *	Open brackets must be closed by the same type of brackets.
 *	Open brackets must be closed in the correct order.
 *	Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 *
 *	Input: s = "()"
 *	Output: true
 *
 * Example 2:
 *
 *	Input: s = "()[]{}"
 *	Output: true
 *
 * Example 3:
 *
 *	Input: s = "(]"
 *	Output: false
 *
 * Constraints:
 *
 *	1 <= s.length <= 10^4
 *	s consists of parentheses only '()[]{}'.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char *s);
char *shift(char *s, int p);

int main(void) {
	char *str = "((){}{}[][]()()([{}[{{{}([])(){}}}]]))";
	printf("String is correct? %s\n", isValid(str) ? "Yes" : "No");

	char *str1 = "((){}{}[][]()()([{}[{{{}([])(){}}}]]))(";
	printf("String is correct? %s\n", isValid(str1) ? "Yes" : "No");

	char *str2 = "((";
	printf("String is correct? %s\n", isValid(str2) ? "Yes" : "No");

	char *str3 = "){";
	printf("String is correct? %s\n", isValid(str3) ? "Yes" : "No");

	char *str4 = "(){}}{";
	printf("String is correct? %s\n", isValid(str4) ? "Yes" : "No");

	return 0;
}

bool isValid(char *s) {
	if (strlen(s) % 2 != 0)
		return false;
	
	while (s[0] != '\0') {
            if (s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        
		for (int i = 0; s[i] != '\0'; ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				if (s[i + 1] == '\0')
					return false;
				else
					continue;
			else if (s[i] == ')')
				if (s[i - 1] != '(')
					return false;
				else {
					s = shift(s, i - 1);
					break;
				}
			else if (s[i] == ']')
				if (s[i - 1] != '[')
					return false;
				else {
					s = shift(s, i - 1);
					break;
				}
			else if (s[i] == '}')
				if (s[i - 1] != '{')
					return false;
				else {
					s = shift(s, i - 1);
					break;
				}
		}
	}

	return true;
}

char *shift(char *s, int p) {
	int k = strlen(s) - 2;
	char *ss = malloc((k + 1) * sizeof(char));

	for (size_t i = 0; i < k; i++) {
		if (i < p)		
			ss[i] = s[i];
		if (i >= p)
			ss[i] = s[i + 2];
	}

	ss[k] = '\0';

	return ss;
}
