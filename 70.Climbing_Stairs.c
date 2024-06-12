/*
 * 70. Climbing Stairs
 * Easy
 * Topics
 * Companies
 * Hint
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 *
 *
 * Example 1:
 *
 * 	Input: n = 2
 * 	Output: 2
 * 	Explanation: There are two ways to climb to the top.
 * 	1. 1 step + 1 step
 * 	2. 2 steps
 *
 * Example 2:
 *
 * 	Input: n = 3
 * 	Output: 3
 * 	Explanation: There are three ways to climb to the top.
 * 	1. 1 step + 1 step + 1 step
 * 	2. 1 step + 2 steps
 * 	3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 * 	1 <= n <= 45
 */
#include <stdio.h>

int climbStairs(int n) {
	int first = 0;
	int second = 1;
	int third = 0;

	for (int i = 0; i < n; i++) {
		third = second + first;
		first = second;
		second = third;
	}
	return third;
}

int main(void) {
	for (int i = 1; i < 46; i++)
		printf("%d:\t%d\n", i, climbStairs(i));
}
