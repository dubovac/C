/*
 * 1108. Defanging an IP Address
 * Easy
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 *
 * A defanged IP address replaces every period "." with "[.]".
 *
 * Example 1:
 *
 *	Input: address = "1.1.1.1"
 *	Output: "1[.]1[.]1[.]1"
 *
 * Example 2:
 *	Input: address = "255.100.50.0"
 *	Output: "255[.]100[.]50[.]0"
 *
 *
 *
 * Constraints:
 *
 * 	The given address is a valid IPv4 address.
*/
#include <stdio.h>
#include <stdlib.h>

char * defangIPaddr(char * address){
	int dots = 0;
	int length = 0;

	for (int i = 0; address[i] != '\0'; ++i) {
		++length;
		if (address[i] == '.')
			++dots;
	}

	char *result = (char *) malloc((length + 2 * dots + 1) * sizeof(char));	// for leetcode use (length + 2 * dots + 2) ???????

	do {
		if (*address == '.') {
			*result++ = '[';
			*result++ = '.';
			*result++ = ']';
		}
		else 
			*result++ = *address;
		
	} while (*address++);		// while (*address != '\0')

	*result = '\0';

	return result - length - 2 * dots - 1;
}

int main(void) {
	char *address = "255.100.50.0";

	printf("%s\n", defangIPaddr(address));

	return 0;
}
