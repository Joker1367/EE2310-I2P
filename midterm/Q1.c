// Q1 109061217 林峻霆
// Given an integer array A of N elements, A[j], 0 <= j < N,
// please write a program to find the index j such that A[j] - A[j + 1]
// is the largest, 0 <= j < N - 1.
//
// For example, if
//
// int A[10] = {25, 7, 29, 17, 19,
//              29, 25, 21, 23, 17};
//
// then the program executes to get
// $ ./a.out
// Max(A[j] - A[j + 1]) is 18 when j = 0
//

#include <stdio.h>

#define N 10

int A[N] = {25, 7, 29, 17, 19,                                              
            29, 25, 21, 23, 17};                      // a array

int main(void)
{
	int i;                                            // parameter in loop
	int distance;                                     // A[j] - A[j + 1]
	int max = A[0] - A[1];                            // the max distance
	int index = 0;                                    // index of max

	for (i = 1; i < N - 1; i++) {
		distance = A[i] - A[i + 1];                   // calculate distance
		if (distance > max) {                         // if bigger, swap
			max = distance;
			index = i;
		}
	}

	printf("Max(A[j] - A[j + 1]) is %d when ", max);  // print the result
	printf("j = %d\n", index);

	return 0;                                         // end the program
}

