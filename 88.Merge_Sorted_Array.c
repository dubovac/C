/*
 *
 * 88. Merge Sorted Array
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
 * To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 *
 *
 *
 *
 * Example 1:
 *
 * 	Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 	Output: [1,2,2,3,5,6]
 * 	Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * 	The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 *
 * Example 2:
 *
 * 	Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * 	Output: [1]
 * 	Explanation: The arrays we are merging are [1] and [].
 * 	The result of the merge is [1].
 *
 * Example 3:
 *
 * 	Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * 	Output: [1]
 * 	Explanation: The arrays we are merging are [] and [1].
 * 	The result of the merge is [1].
 * 	Note that because m = 0, there are no elements in nums1.
 * 	The 0 is only there to ensure the merge result can fit in nums1.
 *
 *
 *
 * Constraints:
 *
 * 	nums1.length == m + n
 * 	nums2.length == n
 * 	0 <= m, n <= 200
 * 	1 <= m + n <= 200
 * 	-109 <= nums1[i], nums2[j] <= 109
 *
 *
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
 */
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int temp[nums1Size];
	nums2Size = nums2Size;

	int j = 0;
	int k = 0;

	if (n > 0) {
		for (int i = 0; i < nums1Size; i++) {
			if (m > 0 && n > 0) {
				if (nums1[j] <= nums2[k]) {
					temp[i] = nums1[j++];
					m--;
				}
				else {
					temp[i] = nums2[k++];
					n--;
				}
			}
			else if (m == 0 && n > 0) {
				temp[i] = nums2[k++];
				n--;
			}
			else if (m > 0 && n == 0) {
				temp[i] = nums1[j++];
				m--;
			}
		}

		for (int i = 0; i < nums1Size; i++)
			nums1[i] = temp[i];
	}
}

int main(void) {
	int nums11[] = {1, 2, 3, 0, 0, 0};
	int nums21[] = {2, 5, 6};
	int m1 = 3;
	int n1 = 3;
	int nums1Size1 = 6;
	int nums2Size1 = 3;
	merge(nums11, nums1Size1, m1, nums21, nums2Size1, n1);

	for (int i = 0; i < nums1Size1; i++)
		printf("%d ", nums11[i]);
	puts("\n");

	int nums12[] = {1};
	int nums22[] = {};
	int m2 = 1;
	int n2 = 0;
	int nums1Size2 = 1;
	int nums2Size2 = 0;
	merge(nums12, nums1Size2, m2, nums22, nums2Size2, n2);

	for (int i = 0; i < nums1Size2; i++)
		printf("%d ", nums12[i]);
	puts("\n");

	int nums13[] = {0};
	int nums23[] = {1};
	int m3 = 0;
	int n3 = 1;
	int nums1Size3 = 1;
	int nums2Size3 = 1;
	merge(nums13, nums1Size3, m3, nums23, nums2Size3, n3);

	for (int i = 0; i < nums1Size3; i++)
		printf("%d ", nums13[i]);
	puts("\n");

	int nums14[] = {2, 0};
	int nums24[] = {1};
	int m4 = 1;
	int n4 = 1;
	int nums1Size4 = 2;
	int nums2Size4 = 1;
	merge(nums14, nums1Size4, m4, nums24, nums2Size4, n4);

	for (int i = 0; i < nums1Size4; i++)
		printf("%d ", nums14[i]);
	puts("\n");

	int nums15[] = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
	int nums25[] = {1, 2, 2};
	int m5 = 6;
	int n5 = 3;
	int nums1Size5 = 9;
	int nums2Size5 = 3;
	merge(nums15, nums1Size5, m5, nums25, nums2Size5, n5);

	for (int i = 0; i < nums1Size5; i++)
		printf("%d ", nums15[i]);
	puts("\n");

	int nums16[] = {4, 0, 0, 0, 0, 0};
	int nums26[] = {1, 2, 3, 5, 6};
	int m6 = 1;
	int n6 = 5;
	int nums1Size6 = 6;
	int nums2Size6 = 5;
	merge(nums16, nums1Size6, m6, nums26, nums2Size6, n6);

	for (int i = 0; i < nums1Size6; i++)
		printf("%d ", nums16[i]);
	puts("\n");

	int nums17[] = {-1, 3, 0, 0, 0, 0, 0};
	int nums27[] = {0, 0, 1, 2, 3};
	int m7 = 2;
	int n7 = 5;
	int nums1Size7 = 7;
	int nums2Size7 = 5;
	merge(nums17, nums1Size7, m7, nums27, nums2Size7, n7);

	for (int i = 0; i < nums1Size7; i++)
		printf("%d ", nums17[i]);
	puts("\n");
}
