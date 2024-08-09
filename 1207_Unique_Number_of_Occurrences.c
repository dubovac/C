/**
 * 1207. Unique Number of Occurrences
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
 *
 *
 *
 * Example 1:
 *
 *	Input: arr = [1,2,2,1,1,3]
 *	Output: true
 *	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1.
 *	No two values have the same number of occurrences.
 *
 * Example 2:
 *
 *	Input: arr = [1,2]
 *	Output: false
 *
 * Example 3:
 *
 *	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 *	Output: true
 *
 *
 *
 * Constraints:
 *
 *	1 <= arr.length <= 1000
 *	-1000 <= arr[i] <= 1000
 */
#include <stdio.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
	int max = -1001;
	int min = 1001;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	int size = max - min + 1;
	int temp[size];

	for (int i = 0; i < size; i++)
		temp[i] = 0;


	for (int i = 0; i < arrSize; i++)
		temp[arr[i] - min]++;

	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (temp[i] != 0 && temp[j] != 0 && temp[i] == temp[j])
				return false;
	return true;
}

int main(void) {
	int a0[] = {1, 2, 2, 1, 1, 3};
	int aS0 = 6;
	printf("%s\n", uniqueOccurrences(a0,aS0) ? "True" : "False");

	int a1[] = {1, 2};
	int aS1 = 2;
	printf("%s\n", uniqueOccurrences(a1,aS1) ? "True" : "False");

	int a2[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
	int aS2 = 10;
	printf("%s\n", uniqueOccurrences(a2,aS2) ? "True" : "False");
}
