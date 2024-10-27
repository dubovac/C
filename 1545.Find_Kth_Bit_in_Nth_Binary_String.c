/**
 * 1545. Find Kth Bit in Nth Binary String
 * Medium
 * Topics
 * Companies
 * Hint
 *
 * Given two positive integers n and k, the binary string Sn is formed as follows:
 *
 *	S1 = "0"
 *	Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
 *
 * Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
 *
 * For example, the first four strings in the above sequence are:
 *
 *	S1 = "0"
 *	S2 = "011"
 *	S3 = "0111001"
 *	S4 = "011100110110001"
 *
 * Return the kth bit in Sn.
 * It is guaranteed that k is valid for the given n.
 *
 *
 *
 * Example 1:
 *
 *	Input: n = 3, k = 1
 *	Output: "0"
 *	Explanation: S3 is "0111001".
 *	The 1st bit is "0".
 *
 * Example 2:
 *
 *	Input: n = 4, k = 11
 *	Output: "1"
 *	Explanation: S4 is "011100110110001".
 *	The 11th bit is "1".
 * 
 *
 * Constraints:
 *
 *	1 <= n <= 20
 *	1 <= k <= 2^n - 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findKthBit(int n, int k) {
	if (n == 1)
		return '0';
	
	int p = 1;

	char** stringArray = (char **) malloc(n * sizeof(char *));

	stringArray[0] = (char *) malloc((p + 1) * sizeof(char));
	stringArray[0][0] = '0';
	stringArray[0][1] = '\0';

	for (int i = 1; i < n; i++) {
		int t = p;
		p = 2 * p + 1;

		stringArray[i] = (char *) malloc((p + 1) * sizeof(char));

		for (int j = 0; stringArray[i - 1][j] != '\0'; j++)
			stringArray[i][j] = stringArray[i - 1][j];

		stringArray[i][t] = '1';

		for (int j = 0; j < t; j++)
			if (stringArray[i - 1][j] == '0')
				stringArray[i - 1][j] = '1';
			else
				stringArray[i - 1][j] = '0';

		for (int j = 0, m = t - 1; j < m; j++, m--) {
			char temp = stringArray[i - 1][j];
			stringArray[i - 1][j] = stringArray[i - 1][m];
			stringArray[i - 1][m] = temp;
		}

		for (int l = t + 1, o = 0; l < p; l++, o++)
			stringArray[i][l] = stringArray[i - 1][o];
            
		stringArray[i][p] = '\0';

		free(stringArray[i - 1]);
	}

	char result = stringArray[n - 1][k - 1];
	
	free(stringArray[n - 1]);

	free(stringArray);

	return result;
}

int main(void) {
	int n = 3;
	int k = 1;
	printf("n = %d\tk = %d\t\tfindKthBit(%d, %d) = %c\n\n", n, k, n, k, findKthBit(n, k));

	n = 4;
	k = 11;
	printf("n = %d\tk = %d\t\tfindKthBit(%d, %d) = %c\n\n", n, k, n, k, findKthBit(n, k));

	n = 18;
	k = 262100;
	printf("n = %d\tk = %d\t\tfindKthBit(%d, %d) = %c\n\n", n, k, n, k, findKthBit(n, k));

	n = 1;
	k = 1;
	printf("n = %d\tk = %d\t\tfindKthBit(%d, %d) = %c\n\n", n, k, n, k, findKthBit(n, k));

	n = 20;
	k = 1000000;
	printf("n = %d\tk = %d\t\tfindKthBit(%d, %d) = %c\n\n", n, k, n, k, findKthBit(n, k));
}
