/**
 * 125. Valid Palindrome
 * Easy
 * Topics
 * Companies
 *
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
 * Alphanumeric characters include letters and numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 *
 * Example 1:
 *
 * 	Input: s = "A man, a plan, a canal: Panama"
 * 	Output: true
 * 	Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 * Example 2:
 *
 * 	Input: s = "race a car"
 * 	Output: false
 * 	Explanation: "raceacar" is not a palindrome.
 *
 * Example 3:
 *
 * 	Input: s = " "
 * 	Output: true
 * 	Explanation: s is an empty string "" after removing non-alphanumeric characters.
 * 	Since an empty string reads the same forward and backward, it is a palindrome.
 *
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 2 * 105
 * 	s consists only of printable ASCII characters.
 */


#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int counter = 0;
    bool check = true;

    for (int i = 0; s[i] != '\0'; i++)
	    if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
		    counter++;

    if (counter <= 1)
	    return check;
    
    int s_array[counter];
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++)
	    if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9')) {
		    if ('A' <= s[i] && s[i] <= 'Z')
			    s_array[j++] = s[i] - 'A' + 'a';
		    else
			    s_array[j++] = s[i];
	    }


    for (int i = 0; i <= counter - 1 - i; i++)
	    if (s_array[i] != s_array[counter - 1 - i]) {
		    check = false;
		    break;
	    }

    return check;
}

int main(void) {
	char* s = "A man, a plan, a canal: Panama";

	printf("%s\n", isPalindrome(s) ? "True" : "False");

	char* ss = "race a car";

	printf("%s\n", isPalindrome(ss) ? "True" : "False");

	char* sss = "";

	printf("%s\n", isPalindrome(sss) ? "True" : "False");

	char* ssss = "p0";

	printf("%s\n", isPalindrome(ssss) ? "True" : "False");
}
