/*
 * 27. Remove Element
 *
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 *
 * Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 *
 * 	Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 * 	Return k.
 *
 * Custom Judge:
 *
 * The judge will test your solution with the following code:
 *
 * 	int[] nums = [...];			// Input array
 * 	int val = ...;				// Value to remove
 * 	int[] expectedNums = [...];		// The expected answer with correct length.
 * 						// It is sorted with no values equaling val.
 *
 * 	int k = removeElement(nums, val);	// Calls your implementation
 *
 * 	assert k == expectedNums.length;
 * 	sort(nums, 0, k);			// Sort the first k elements of nums
 * 	for (int i = 0; i < actualLength; i++) {
 * 		assert nums[i] == expectedNums[i];
 * 	}
 * 
 * If all assertions pass, then your solution will be accepted.
 *
 *
 *
 * Example 1:
 *
 * 	Input: nums = [3,2,2,3], val = 3
 * 	Output: 2, nums = [2,2,_,_]
 * 	Explanation: Your function should return k = 2, with the first two elements of nums being 2.
 * 	It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * Example 2:
 *
 * 	Input: nums = [0,1,2,2,3,0,4,2], val = 2
 * 	Output: 5, nums = [0,1,4,0,3,_,_,_]
 * 	Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
 * 	Note that the five elements can be returned in any order.
 * 	It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 *
 *
 * Constraints:
 *
 * 	0 <= nums.length <= 100
 * 	0 <= nums[i] <= 50
 * 	0 <= val <= 100
 */





#include <stdio.h>

int removeElement(int* nums, int numSize, int val) {
	if (numSize == 0) //|| (numSize == 1 && nums[0] == val))
		return 0;

//	if (numSize == 1)
//        	return 1;

	
	for (int i = 0; i < numSize - 1; i++)
		if (nums[i] == val) {
			for (int j = 0; i + j < numSize - 1; j++)
				nums[i + j] = nums[i + j + 1];
			numSize--;
			i--;
		}

	if (nums[numSize -1] == val)
        numSize--;

	return numSize;
}

int main(void) {
	int nums[] = {3, 2, 2, 3};
	int val = 3;
	int numSize = 4;
	int counter = removeElement(nums, numSize, val);
	printf("counter = %d\n", counter);
	for (int i = 0; i < counter; i++)
		printf("nums[%d] = %d\t", i, nums[i]);
	puts("");


	int nums1[] = {0, 1, 2, 2, 3, 0, 4, 2, 2, 2};
	int val1 = 2;
	int numSize1 = 10;
	int counter1 = removeElement(nums1, numSize1, val1);
	printf("counter1 = %d\n", counter1);
	for (int i = 0; i < counter1; i++)
		printf("nums1[%d] = %d\t", i, nums1[i]);
	puts("");

	int nums2[] = {};
	int val2 = 0;
	int numSize2 = 0;
	int counter2 = removeElement(nums2, numSize2, val2);
	printf("counter2 = %d\n", counter2);
	for (int i = 0; i < counter2; i++)
		printf("nums2[%d] = %d\t", i, nums2[i]);
	puts("");

	int nums3[] = {1};
	int val3 = 1;
	int numSize3 = 1;
	int counter3 = removeElement(nums3, numSize3, val3);
	printf("counter3 = %d\n", counter3);
	for (int i = 0; i < counter3; i++)
		printf("nums3[%d] = %d\t", i, nums3[i]);
	puts("");

	int nums4[] = {2};
	int val4 = 3;
	int numSize4 = 1;
	int counter4 = removeElement(nums4, numSize4, val4);
	printf("counter4 = %d\n", counter4);
	for (int i = 0; i < counter4; i++)
		printf("nums4[%d] = %d\t", i, nums4[i]);
	puts("");

	int nums5[] = {3, 3, 3, 3, 3};
	int val5 = 3;
	int numSize5 = 5;
	int counter5 = removeElement(nums5, numSize5, val5);
	printf("counter5 = %d\n", counter5);
	for (int i = 0; i < counter5; i++)
		printf("nums5[%d] = %d\t", i, nums5[i]);
	puts("");

	int nums6[] = {4, 5};
	int val6 = 4;
	int numSize6 = 2;
	int counter6 = removeElement(nums6, numSize6, val6);
	printf("counter6 = %d\n", counter6);
	for (int i = 0; i < counter6; i++)
		printf("nums6[%d] = %d\t", i, nums6[i]);
	puts("");

	int nums7[] = {4, 5};
	int val7 = 5;
	int numSize7 = 2;
	int counter7 = removeElement(nums7, numSize7, val7);
	printf("counter7 = %d\n", counter7);
	for (int i = 0; i < counter7; i++)
		printf("nums7[%d] = %d\t", i, nums7[i]);
	puts("");

}
