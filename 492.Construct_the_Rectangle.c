/**
 * 492. Construct the Rectangle
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * A web developer needs to know how to design a web page's size.
 * So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
 *
 * 	The area of the rectangular web page you designed must equal to the given target area.
 * 	The width W should not be larger than the length L, which means L >= W.
 * 	The difference between length L and width W should be as small as possible.
 *
 * Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.
 *
 *
 *
 * Example 1:
 *
 * 	Input: area = 4
 * 	Output: [2,2]
 * 	Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1].
 * 	But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2].
 * 	So the length L is 2, and the width W is 2.
 *
 * Example 2:
 *
 * 	Input: area = 37
 * 	Output: [37,1]
 *
 * Example 3:
 *
 * 	Input: area = 122122
 * 	Output: [427,286]
 *
 *
 *
 * Constraints:
 *
 * 	1 <= area <= 107
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* constructRectangle(int area, int* returnSize) {
	*returnSize = 2;

	int* result = (int *) malloc(2 * sizeof(int));

	int length = area;
	int width = 1;
	int l = area;
	
	while (l > width) {
		if (area % l == 0) {
			width = area / l;
			length = l;
		}
		l--;
	}
	result[0] = length;
	result[1] = width;

	return result;
}

int main(void) {
	int rs = 0;
	int* rsPtr = &rs;

	int a0 = 4;
	int* r0 = constructRectangle(a0, rsPtr);
	printf("area[%d] = %d\n", 0, a0);
	printf("length[%d] = %d\twidth[%d] = %d\n\n", 0, r0[0], 0, r0[1]);

	int a1 = 37;
	int* r1 = constructRectangle(a1, rsPtr);
	printf("area[%d] = %d\n", 1, a1);
	printf("length[%d] = %d\twidth[%d] = %d\n\n", 1, r1[0], 1, r1[1]);

	int a2 = 122122;
	int* r2 = constructRectangle(a2, rsPtr);
	printf("area[%d] = %d\n", 2, a2);
	printf("length[%d] = %d\twidth[%d] = %d\n\n", 2, r2[0], 2, r2[1]);

	int a3 = 40000;
	int* r3 = constructRectangle(a3, rsPtr);
	printf("area[%d] = %d\n", 3, a3);
	printf("length[%d] = %d\twidth[%d] = %d\n\n", 3, r3[0], 3, r3[1]);
}
