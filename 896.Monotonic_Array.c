/**
 * 896. Monotonic Array
 * Easy
 * Topics
 * Companies
 *
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 *
 * An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
 * An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 *
 * Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 *
 *
 *
 * Example 1:
 *
 *	Input: nums = [1,2,2,3]
 *	Output: true
 *
 * Example 2:
 *
 *	Input: nums = [6,5,4,4]
 *	Output: true
 *
 * Example 3:
 *
 *	Input: nums = [1,3,2]
 *	Output: false
 *
 *
 * Constraints:
 *
 *	1 <= nums.length <= 10^5
 *	-10^5 <= nums[i] <= 10^5
 */

#include <stdio.h>
#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
	int incr = 0;
	int decr = 0;

	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i + 1] > nums[i])
			incr = 1;
		if (nums[i + 1] < nums [i])
			decr = 1;
		if (incr == 1 && decr == 1)
			return false;
	}

	return true;
}

int main(void) {
	int a[] = {1, 2, 2, 3};
	int aS = 4;
	printf("%s\n", isMonotonic(a, aS) ? "True" : "False");

	int b[] = {6, 5, 4, 4};
	int bS = 4;
	printf("%s\n", isMonotonic(b, bS) ? "True" : "False");

	int c[] = {1, 3, 2};
	int cS = 3;
	printf("%s\n", isMonotonic(c, cS) ? "True" : "False");

	int d[] = {4, 4, 4, 4};
	int dS = 4;
	printf("%s\n", isMonotonic(d, dS) ? "True" : "False");
}
