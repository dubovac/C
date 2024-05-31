/*
 * 35. Search Insert Position
 * Easy
 * Topics
 * Companies
 *
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 *
 * Example 1:
 *
 * 	Input: nums = [1,3,5,6], target = 5
 * 	Output: 2
 *
 * Example 2:
 *
 * 	Input: nums = [1,3,5,6], target = 2
 * 	Output: 1
 *
 * Example 3:
 *
 * 	Input: nums = [1,3,5,6], target = 7
 * 	Output: 4
 *
 *
 *
 * Constraints:
 *
 * 	1 <= nums.length <= 104
 * 	-104 <= nums[i] <= 104
 * 	nums contains distinct values sorted in ascending order.
 * 	-104 <= target <= 104
 */
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	int i = numsSize / 2;
	int min = 0;
	int max = numsSize;

	if (target <= nums[0])
		return 0;

	if (target > nums[numsSize - 1])
		return numsSize;

	while (nums[i] != target) {
		if (target < nums[i]) {
			max = i;
			i = (min + max) / 2;
			if (i == max)
				return i;
		}
		else if (target > nums[i]) {
			min = i;
			i = (min + max) / 2;
			if (i == min)
				return i + 1;
		}
	}

	return i;
}

int main(void) {
	int nums0[] = {1, 3, 5, 6};
	int numsSize0 = 4;
	int target0 = 5;
	printf("Index 0 = %d\n", searchInsert(nums0, numsSize0, target0));

	int nums1[] = {1, 3, 5, 6};
	int numsSize1 = 4;
	int target1 = 2;
	printf("Index 1 = %d\n", searchInsert(nums1, numsSize1, target1));

	int nums2[] = {1, 3, 5, 7};
	int numsSize2 = 4;
	int target2 = 6;
	printf("Index 2 = %d\n", searchInsert(nums2, numsSize2, target2));

}
