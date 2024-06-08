/*
 * 67. Add Binary
 * Easy
 * Topics
 * Companies
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 *
 * Example 1:
 *
 * 	Input: a = "11", b = "1"
 * 	Output: "100"
 *
 * Example 2:
 *
 * 	Input: a = "1010", b = "1011"
 * 	Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


 *
 */

#include <stdio.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
	int a_length = 0;
	int b_length = 0;

	for (int i = 0; a[i] != '\0'; i++)
		a_length++;

	for (int j = 0; b[j] != '\0'; j++)
		b_length++;

	int a_array[a_length];
	int b_array[b_length];

	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] == '1')
			a_array[i] = 1;
		else
			a_array[i] = 0;

	for (int j = 0; b[j] != '\0'; j++)
		if (b[j] == '1')
			b_array[j] = 1;
		else
			b_array[j] = 0;
	
	int r;

	if (a_length >= b_length)
		r = a_length + 1;
	else
		r = b_length + 1;

	int sum_array[r];

	int al = a_length - 1;
	int bl = b_length - 1;
	int rl = r - 1;
	int next = 0;
	int bin = 0;

	while (al >= 0 || bl >= 0) {


		int d = (al < 0 ? 0 : a_array[al]) + (bl < 0 ? 0 : b_array[bl]) + next;

		switch (d) {
			case 0:
				bin = 0;
				next = 0;
				break;
			case 1:
				bin = 1;
				next = 0;
				break;
			case 2:
				bin = 0;
				next = 1;
				break;
			case 3:
				bin = 1;
				next = 1;
		}

		sum_array[rl] = bin;

		al--;
		bl--;
		rl--;
	}

	if (next)
		sum_array[rl] = next;

	char* s = (char *) malloc((r + 1) * sizeof(char));

	if (next) {
		for (int i = 0; i < r; i++)
			if (sum_array[i] == 1)
				s[i] = '1';
			else
				s[i] = '0';
		s[r] = '\0';
	}
	else {
		for (int i = 0; i < r - 1; i++)
			if (sum_array[i + 1] == 1)
				s[i] = '1';
			else
				s[i] = '0';
		s[r - 1] = '\0';
	}		

	return s;
}

int main(void) {
	char* a0 = "1011010";
	char* b0 = "111";
	char* s0 = addBinary(a0, b0);
	printf("a0 = \"%20s\"\n", a0);
	printf("b0 = \"%20s\"\n", b0);
	printf("s0 = \"%20s\"\n\n", s0);

	char* a1 = "111";
	char* b1 = "111";
	char* s1 = addBinary(a1, b1);
	printf("a1 = \"%20s\"\n", a1);
	printf("b1 = \"%20s\"\n", b1);
	printf("s1 = \"%20s\"\n\n", s1);

	char* a2 = "111";
	char* b2 = "1";
	char* s2 = addBinary(a2, b2);
	printf("a2 = \"%20s\"\n", a2);
	printf("b2 = \"%20s\"\n", b2);
	printf("s2 = \"%20s\"\n\n", s2);

	char* a3 = "101001000100001";
	char* b3 = "101010101010101";
	char* s3 = addBinary(a3, b3);
	printf("a3 = \"%20s\"\n", a3);
	printf("b3 = \"%20s\"\n", b3);
	printf("s3 = \"%20s\"\n\n", s3);

	char* a4 = "11";
	char* b4 = "1";
	char* s4 = addBinary(a4, b4);
	printf("a4 = \"%20s\"\n", a4);
	printf("b4 = \"%20s\"\n", b4);
	printf("s4 = \"%20s\"\n\n", s4);

	char* a5 = "0";
	char* b5 = "101010101010101";
	char* s5 = addBinary(a5, b5);
	printf("a5 = \"%20s\"\n", a5);
	printf("b5 = \"%20s\"\n", b5);
	printf("s5 = \"%20s\"\n\n", s5);

}
