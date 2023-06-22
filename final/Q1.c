// Q1 109061217 林峻霆
// Given an integer NxN matrix A, please write a function to find
// the smallest element of A using one for-loop.
//
// For example, if N = 3
//
// int A[N][N] = { {7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
//
// then the function returns 1.
//
#include <stdio.h>

#define N 3

int min(int A[N][N])
	// a function that find out the smallest element in an N * N matrix
	// and return it
{
	int total;     // total amount of element in matrix
	int min;       // the smallest element
	int i;         // parameter for loop

	min = A[0][0];                   // assign min
	total = N * N;                   // calculate total
	for (i = 0; i < total; i++) {    // travel the matrix
		if (*(A[0] + i) < min)       // comparing
			min = *(A[0] + i);       // if smaller, swap
	}

	return min;                      // return the result
}

int main(void)
{
	int A[3][3] = {{7,8,9}, {2,1,3},{4,5,6}};

	int i;
	int (*p)[3];

	for (p = A;p < A + 3; p++){
		for(i = 0 ; i < 3; i++) {
			printf("%d ", (*p)[i]);
		}
		printf("\n");
	}

	return 0;
}



