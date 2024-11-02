/**
 * 412. Fizz Buzz
 * Easy
 * Topics
 * Companies
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 *	answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 *	answer[i] == "Fizz" if i is divisible by 3.
 *	answer[i] == "Buzz" if i is divisible by 5.
 *	answer[i] == i (as a string) if none of the above conditions are true.
 *
 *
 *
 * Example 1:
 *
 *	Input: n = 3
 *	Output: ["1","2","Fizz"]
 *
 * Example 2:
 *
 *	Input: n = 5
 *	Output: ["1","2","Fizz","4","Buzz"]
 *
 * Example 3:
 *
 *	Input: n = 15
 *	Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 *
 *
 *
 * Constraints:
 *
 *	1 <= n <= 10^4
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(int i) {
	int n = i;
	int counter = 0;

	while (n > 0) {
		n /= 10;
		counter++;
	}

	char* s = (char *) malloc((counter + 1) * sizeof(char));
	s[counter] = '\0';

	for (int j = counter - 1; j >= 0; j--) {
		int k = i % 10;
		i /= 10;
		s[j] = k + '0';
	}

	return s;
}

char** fizzBuzz(int n, int* returnSize) {
	char** fb = (char **) malloc(n * sizeof(char *));
	int j = 0;

	for (int i = 1; i <= n; i++)
		if (i % 3 == 0 && i % 5 == 0) {
			fb[j] = (char *) malloc(9 * sizeof(char));
			strcpy(fb[j], "FizzBuzz");
			j++;
		}
		else if (i % 3 == 0) {
			fb[j] = (char *) malloc(5 * sizeof(char));
			strcpy(fb[j], "Fizz");
			j++;
		}
		else if (i % 5 == 0) {
			fb[j] = (char *) malloc(5 * sizeof(char));
			strcpy(fb[j], "Buzz");
			j++;
		}
		else {
			char* s = itoa(i);
			fb[j] = (char *) malloc((strlen(s) + 1) * sizeof(char));
			strcpy(fb[j], s);
			j++;
		}

	*returnSize = j;

	return fb;
}

int main(void) {
	int rS = 0;
	int* retSize = &rS;
	int num = 35;

	char** ss = fizzBuzz(num, retSize);

	for (int i = 0; i < *retSize; i++)
		printf("%s\t", ss[i]);

	printf("\n");
}
