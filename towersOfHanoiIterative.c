#include <stdio.h>
#include <math.h>

void towersOfHanoi(int n);
int moves(int n);
int oneTwoThree(int n, int i);
void threeTwoOne(int n, int i);

int main(void) {
	int number;

	printf("Enter positive integer: ");
	scanf("%d", &number);

	towersOfHanoi(number);

	return 0;
}

void towersOfHanoi(int n) {
	int t = 1;

	if (n == 1)
		puts("1 -> 3");
	else if (n == 2) {
		puts("1 -> 2");
		puts("1 -> 3");
		puts("2 -> 3");
	}
	else if (n == 3) {
		puts("1 -> 3");
        	puts("1 -> 2");
        	puts("3 -> 2");
                puts("1 -> 3");
                puts("2 -> 1");
                puts("2 -> 3");
                puts("1 -> 3");
	} else
		for (int i = 1; i < 2 * pow(3, n - 3); i++)
			if (i % 2 == 1)
				if (t % 2 == 1) {
					puts("1 -> 3");
                			puts("1 -> 2");
					puts("3 -> 2");
      					puts("1 -> 3");
			        	puts("2 -> 1");
                			puts("2 -> 3");
                			puts("1 -> 3");
					t++;
				} else {
					puts("3 -> 1");
		 			puts("3 -> 2");
					puts("1 -> 2");
					puts("3 -> 1");
					puts("2 -> 3");
					puts("2 -> 1");
					puts("3 -> 1");
					t++;
				}
			else if (oneTwoThree(n, i)) 
				;
			else
				threeTwoOne(n, i);
}

int oneTwoThree(int n, int i) {
	int t = 0;
	int m = 0;
	int result = 0;
	int s = 0;

	while (n - 3 - t > 0) {
		m = moves(n - t) + 1;

		for (int j = 0; j < m; j++)
			if (i == 2 * (int) pow(3, t) * (j * 6 + 1)) {
				puts("1 -> 2");
				result = 1;
			} else if (i == 4 * (int) pow(3, t) * (j * 3 + 1)) {
				puts("2 -> 3");
				result = 1;
			}
		t++;
	}

	return result;
}

void threeTwoOne(int n, int i) {
	int t = 0;
	int m = 0;
	int result = 0;
	int s = 0;

	while (n - 3 - t > 0) {
		m = moves(n - t);

		for (int j = 0; j < m; j++)
			if (i == 4 * (int) pow(3, t) * (j * 3 + 2))
				puts("3 -> 2");
			else if (i == 2 * (int) pow(3, t) * (j * 6 + 5))
				puts("2 -> 1");
		t++;
	}
}

int moves(int n) {
	int result = 0;

	if (n == 4)
		return 0;
	else
		for (int i = 0; i < n - 4; i++)
			result = 3 * result + 1;

	return result;
}
