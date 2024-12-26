/**
 * 4. Median of Two Sorted Arrays
 * Hard
 * Topics
 * Companies
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 *
 * Example 1:
 *
 *	Input: nums1 = [1,3], nums2 = [2]
 *	Output: 2.00000
 *	Explanation: merged array = [1,2,3] and median is 2.
 *
 * Example 2:
 *
 *	Input: nums1 = [1,2], nums2 = [3,4]
 *	Output: 2.50000
 *	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 *
 * Constraints:
 *
 *	nums1.length == m
 *	nums2.length == n
 *	0 <= m <= 1000
 *	0 <= n <= 1000
 *	1 <= m + n <= 2000
 *	-10^6 <= nums1[i], nums2[i] <= 10^6
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
	return *(int *) a - *(int *) b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int nums[nums1Size + nums2Size];

	memcpy(nums, nums1, nums1Size * sizeof(int));
	memcpy(nums + nums1Size, nums2, nums2Size * sizeof(int));

	qsort(nums, nums1Size + nums2Size, sizeof(int), comp);

	if ((nums1Size + nums2Size) % 2 == 0)
		return (nums[(nums1Size + nums2Size) / 2 - 1] + nums[(nums1Size + nums2Size) / 2]) / 2.;

	return nums[(nums1Size + nums2Size) / 2];
}

int main(void) {
	int n1[] = {1, 3, 5};
	int n2[] = {2, 4, 6};
	int n1S = sizeof(n1) / sizeof(n1[0]);
	int n2S = sizeof(n2) / sizeof(n2[0]);
	printf("%f\n", findMedianSortedArrays(n1, n1S, n2, n2S));

	int n3[] = {1, 3, 5, 7};
	int n4[] = {2, 4, 6};
	int n3S = sizeof(n3) / sizeof(n3[0]);
	int n4S = sizeof(n4) / sizeof(n4[0]);
	printf("%f\n", findMedianSortedArrays(n3, n3S, n4, n4S));

}
