// Q3 109061217 林峻霆
// Given a positive integer N, N may or may not be expressed as
// a sum of two prime numbers.
//
//   N = P1 + P2
//
// Please write a program to find all integer N, 4 <= N <= 100,
// which cannot be expressed as a sum of two prime numbers.
//
// In your program, M should be defined as a macro as the following:
//
// #define M 100
//
// and the program executes to get the following output format.
//
// $ ./a.out
//   1: n1
//   2: n2
//   ...
//   k: nk
// k integers found.
//
// In the above, n1, n2, ..., nk, and k are numbers.
//

#include <stdio.h>

#define M 100

int main(void)
{
	int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19,
				     23, 29, 31, 37, 41, 43, 47,
					 53, 59, 61, 67, 71, 73, 79,
					 83, 89, 97};                    // a prime array
	int not[100] = {0};                              // number not wrong
	int i = 1;                                       // number of correct
	int n = 4;                                       // n start from 4
	int j, k;                                        // parameter for prime
	int h = 0;                                       // parameter for not[]
	int found = 0;                                   // break parameter
   	
	while (n <= M) {                                 // searching
		for (j = 0; prime[j] < n && j < 25; j++);
		j = j - 1;
		for ( ; prime[j] >= n / 2 && found; j--) {
			for (k = 0; k <= j && found; k++) {
				if (n == prime[k] + prime[j]) {      // put wrong in not[]
					not[h] = n;
					found = 0;                       // leave the loop
					h = h + 1;
				}
			}
		}
		found  = 1;
		n = n + 1;
	}
	
	
	h = 0;                                           // index for wrong
	i = 1;                                           // index for correct
	for (n = 5; n <= M; n++) {                       // print the result
		if (n != not[h]) {
			printf("  %d: %d\n", i, n);
			i = i + 1;
		}
		else
			h = h + 1;
	}
	i = i - 1;
	printf("%d integers found.\n", i);

	return 0;                                        // end the program
}

