// Q2 109061217 林峻霆
// Given an integer array A of N elements, A[j], 0 <= j < N,
// N is an even number, please write a program to swap even and odd
// elements of A array.
//
// For example, if
//
// int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
// then the program executes to get
// $ ./a.out
// A = 1 0 3 2 5 4 7 6 9 8
//
// Note that the memory content of A must be changed.

#include <stdio.h>

#define N 10

int A[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};    // a array

int main(void)
{
	int tmp;                                  // a variable to swap
	int i;                                    // parameter for loop, index

	for (i = 0; i < N - 1; i = i + 2) {       // swapping
		tmp = A[i];
		A[i] = A[i + 1];
		A[i + 1] = tmp;
	}

	printf("A =");                            // print the result
	for (i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");

	return 0;                                 // end the program
}


