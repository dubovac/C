#include <stdio.h>

void towersOfHanoi(int n);
void towersOfHanoiToThird(int n);
void towersOfHanoiToFirst(int n);

int main(void) {
	int number;

	printf("Enter positive integer: ");
	scanf("%d", &number);

	towersOfHanoi(number);

	return 0;
}

void towersOfHanoiToThird(int n) {
	if (n == 3) {
		puts("1 -> 3");
		puts("1 -> 2");
		puts("3 -> 2");
		puts("1 -> 3");
		puts("2 -> 1");
		puts("2 -> 3");
		puts("1 -> 3");
	} else {
		towersOfHanoiToThird(n - 1);
		puts("1 -> 2");
		towersOfHanoiToFirst(n - 1);
		puts("2 -> 3");
		towersOfHanoiToThird(n - 1);
	}
}

void towersOfHanoiToFirst(int n) {
	if (n == 3) {
		puts("3 -> 1");
		puts("3 -> 2");
		puts("1 -> 2");
		puts("3 -> 1");
		puts("2 -> 3");
		puts("2 -> 1");
		puts("3 -> 1");
	} else {
		towersOfHanoiToFirst(n - 1);
		puts("3 -> 2");
		towersOfHanoiToThird(n - 1);
		puts("2 -> 1");
		towersOfHanoiToFirst(n - 1);
	}
}


void towersOfHanoi(int n) {
	if (n == 1)
		puts("1 -> 3");
	else if (n == 2) {
		puts("1 -> 2");
		puts("1 -> 3");
		puts("2 -> 3");
	}
	else
		towersOfHanoiToThird(n);
}
