/**
 * 164. Maximum Gap
 * Medium
 * Topics
 * Companies
 *
 * Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra space.
 *
 *
 *
 * Example 1:
 *
 *	Input: nums = [3,6,9,1]
 *	Output: 3
 *	Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 *
 * Example 2:
 *
 *	Input: nums = [10]
 *	Output: 0
 *	Explanation: The array contains less than 2 elements, therefore return 0.
 *
 *
 *
 * Constraints:
 *
 *	1 <= nums.length <= 10^5
 *	0 <= nums[i] <= 10^9
 */ 



#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

	return (*(int *) a - *(int *) b);
}

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;
    
    int max = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++)
        if(nums[i] - nums[i - 1] > max)
            max = nums[i] - nums[i - 1];
        
    return max;
}

int main(void) {
	int nums0[] = {3, 6, 9, 1};
	int numsSize0 = 4;
	printf("%d\n", maximumGap(nums0, numsSize0));
}
