/*
 * 1. Two Sum
 * Easy
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *	Input: nums = [2,7,11,15], target = 9
 *	Output: [0,1]
 *	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 *
 *	Input: nums = [3,2,4], target = 6
 *	Output: [1,2]
 *
 * Example 3:
 *	Input: nums = [3,3], target = 6
 *	Output: [0,1]
 *
 * Constraints:
 *
 *	2 <= nums.length <= 104
 *	-109 <= nums[i] <= 109
 *	-109 <= target <= 109
 *	Only one valid answer exists.
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize){
	int *array = (int *) malloc(2 * sizeof(int));

	int t = 0;

	for (int i = 0; i < numsSize - 1; ++i) {
		for (int j = i + 1; j < numsSize; ++j)
			if (target == nums[i] + nums[j]) {
				array[0] = i;
				array[1] = j;
				*returnSize = 2;	// this line for leetcode to work
				t = 1;
				break;			// not necessary but ok
			}
		if (t)
			break;
	}

	return array;
}

int main(void) {
	int nums[] = {3, 2, 5, 5, 4};

	int numsSize = 5;

	int target = 9;

	int returnSize[] = {};

	int *answer = twoSum(nums, numsSize, target, returnSize);

	printf("answer[%d] = %d\nanswer[%d] = %d\n", 0, answer[0], 1, answer[1]);

	return 0;
}
