/**
 * 12. Integer to Roman
 * Medium
 * Topics
 * Companies
 *
 * Seven different symbols represent Roman numerals with the following values:
 *
 *	Symbol	Value
 *	   I	1
 *	   V	5
 *	   X	10
 *	   L	50
 *	   C	100
 *	   D	500
 *	   M	1000
 *
 * Roman numerals are formed by appending the conversions of decimal place values from highest to lowest.
 * Converting a decimal place value into a Roman numeral has the following rules:
 *
 *	If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
 *	If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX.
 *	Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
 *	Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10.
 *	You cannot append 5 (V), 50 (L), or 500 (D) multiple times.
 *	If you need to append a symbol 4 times use the subtractive form.
 *
 * 	Given an integer, convert it to a Roman numeral.
 *
 *
 *
 * Example 1:
 *
 *	Input: num = 3749
 *
 * 	Output: "MMMDCCXLIX"
 *
 * Explanation:
 *
 * 	3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 * 	 700 = DCC as 500 (D) + 100 (C) + 100 (C)
 * 	  40 = XL as 10 (X) less of 50 (L)
 * 	   9 = IX as 1 (I) less of 10 (X)
 * 	Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
 *
 * Example 2:
 *
 *	Input: num = 58
 *
 *	Output: "LVIII"
 *
 * Explanation:
 *
 * 	50 = L
 * 	 8 = VIII
 *
 * Example 3:
 *
 * Input: num = 1994
 *
 * Output: "MCMXCIV"
 *
 * Explanation:
 *
 * 	1000 = M
 * 	 900 = CM
 * 	  90 = XC
 * 	   4 = IV
 *
 *
 *
 * Constraints:
 *
 *	1 <= num <= 3999
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intToRoman(int num) {
	int year = 0;
	int decade = 0;
	int century = 0;
	int millenium = 0;
	int counter = 1;

	while (num) {
		int temp = num % 10;
		num /= 10;

		switch (counter) {
			case 1:
				year = temp;
				break;
			case 2:
				decade = temp;
				break;
			case 3:
				century = temp;
				break;
			case 4:
				millenium = temp;
				break;
		}

		counter++;

	}

	char* result = (char *) malloc(16 * sizeof(char));

	strcpy(result, "");

	if (millenium) {
		switch (millenium) {
			case 1:
				strcat(result, "M");
				break;
			case 2:
				strcat(result, "MM");
				break;
			case 3:
				strcat(result, "MMM");
				break;
		}

		
	}

	if (century) {
		switch (century) {
			case 1:
				strcat(result, "C");
				break;
			case 2:
				strcat(result, "CC");
				break;
			case 3:
				strcat(result, "CCC");
				break;
			case 4:
				strcat(result, "CD");
				break;
			case 5:
				strcat(result, "D");
				break;
			case 6:
				strcat(result, "DC");
				break;
			case 7:
				strcat(result, "DCC");
				break;
			case 8:
				strcat(result, "DCCC");
				break;
			case 9:
				strcat(result, "CM");
				break;
		}
	}

	if (decade) {
		switch (decade) {
			case 1:
				strcat(result, "X");
				break;
			case 2:
				strcat(result, "XX");
				break;
			case 3:
				strcat(result, "XXX");
				break;
			case 4:
				strcat(result, "XL");
				break;
			case 5:
				strcat(result, "L");
				break;
			case 6:
				strcat(result, "LX");
				break;
			case 7:
				strcat(result, "LXX");
				break;
			case 8:
				strcat(result, "LXXX");
				break;
			case 9:
				strcat(result, "XC");
				break;
		}
	}

	if (year) {
		switch (year) {
			case 1:
				strcat(result, "I");
				break;
			case 2:
				strcat(result, "II");
				break;
			case 3:
				strcat(result, "III");
				break;
			case 4:
				strcat(result, "IV");
				break;
			case 5:
				strcat(result, "V");
				break;
			case 6:
				strcat(result, "VI");
				break;
			case 7:
				strcat(result, "VII");
				break;
			case 8:
				strcat(result, "VIII");
				break;
			case 9:
				strcat(result, "IX");
				break;
		}
	}


	return result;
}

int main(void) {
	int year = 3888;

	char* roman = intToRoman(year);

	printf("%d = %s\n", year, roman);
}
