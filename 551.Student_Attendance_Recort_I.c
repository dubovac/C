/**
 * 551. Student Attendance Record I
 * Easy
 * Topics
 * Companies
 *
 * You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day.
 * The record only contains the following three characters:
 *
 *	'A': Absent.
 *	'L': Late.
 *	'P': Present.
 *
 * The student is eligible for an attendance award if they meet both of the following criteria:
 *
 *	The student was absent ('A') for strictly fewer than 2 days total.
 *	The student was never late ('L') for 3 or more consecutive days.
 *
 * Return true if the student is eligible for an attendance award, or false otherwise.
 *
 *
 *
 * Example 1:
 *
 *	Input: s = "PPALLP"
 *	Output: true
 *	Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
 *
 * Example 2:
 *
 *	Input: s = "PPALLL"
 *	Output: false
 *	Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
 *
 *
 *
 * Constraints:
 *
 *	1 <= s.length <= 1000
 *	s[i] is either 'A', 'L', or 'P'.
 */

#include <stdio.h>
#include <stdbool.h>

bool checkRecord(char* s) {
	int a = 0;
	int l = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'A') {
			a++;
			if (a >= 2)
				return false;
		}

		if (s[i] == 'L') {
			l++;
			if (l == 3)
				return false;
		}
		else
			l = 0;
	}

	return true;
}

int main(void) {
	char* s0 = "PPALLP";
	printf("%s\n", checkRecord(s0) ? "true" : "false");

	char* s1 = "PPALLL";
	printf("%s\n", checkRecord(s1) ? "true" : "false");

	char* s2 = "PPAALP";
	printf("%s\n", checkRecord(s2) ? "true" : "false");
}
