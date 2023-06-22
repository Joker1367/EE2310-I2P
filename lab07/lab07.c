// EE2310 lab07 Matrix Determinants
// 109061217 林峻霆
// Date: 2020/11/16
#include <stdio.h>

#if !defined(N)
#define N 3
#endif

int Pandita(int P[N]);                            // declare Pandita function

int main(void)
{
	int A[N][N];                                  // a matrix for input
	int i, j;                                     // parameter for loop
	int det = 0;                                  // the determinant
	int factor = 1;                               // constant for multiply
	int sgn = 1;                                  // set initial sign value 1    
	int P[N];                                     // permutation array

	for (i = 0; i < N; i++) {                     // setup permutation array
		P[i] = i;
	}
	for (i = 0; i < N; i++) {                     // input the matrix
		for (j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("Matrix A is\n");                      // print the matrix
	for (i = 0; i < N; i++) {
		printf("  ");
		for (j = 0; j < N; j++) {
			printf(" %d", A[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < N ; i++) {                    // calculate result of
		factor = factor * A[i][P[i]];             // first permutation
	}
	det += factor;                                // add result to determinant
	
	sgn = sgn * Pandita(P);                       // sign of next permutation 
	while (sgn != 0) {                            // detect whether end loop
		factor = 1;                               // reset factor
		for (i = 0; i < N ; i++) {
			factor = factor * A[i][P[i]];         // calculate result of
		}                                         // permutation
		det += factor * sgn;                      // add reult to determinant
		sgn = sgn * Pandita(P);                   // sign of next permutation
	}

	printf("det(A) = %d\n", det);                 // print the result
	return 0;                                     // end the program
}

int Pandita(int P[N])
// The Pandita function input an array. There is a variable "total" in it,
// which is used to record the amount of swap between this and last permutation
// Due to "The property of Odd and Even number", if total != 0 && total is even
// then the sign of permutation will be equal to the last permutation.
//
// To sum up, this function does the things below:
// 1. return 0 if total = 0
// 2. return 1 if total != 0 && total is even
// 3. return -1 if total != 0 && total is odd
{
	int total = 0;                                // amount of swap
	int i ,j, k;                                  // parameter for loop
	int tmp;                                      // parameter for swap
	int find = 1;                                 // parameter for break

	i = N - 2;                                    // start from N-2 th index
	while (i >=0 && find) {
		if (P[i] < P[i + 1]) {                    // find corresponded index
			j = i + 1;
			total += 1;                           // renew the amount of swap
			for ( ; j < N; j++) {                 // swap two index
				if (P[i] > P[j]) {
					tmp = P[i];
					P[i] = P[j - 1];
					P[j - 1] = tmp;
					j = N;
				}
				else if (j == N - 1) {
					tmp = P[i];
					P[i] = P[j];
					P[j] = tmp;
				}
			}
			j = i + 1;                            // reverse from i+1 th index
			for (k = 0; j + k < N - 1 - k; k++) {
				total += 1;                       // renew amount of swap
				tmp = P[j + k];
				P[j + k] = P[N - 1 - k];
				P[N - 1 - k] = tmp;
			}
			find = 0;                             // jump out the loop
		}
		else                                      // if not found go to 
			i = i - 1;                            // next index
	}
	if (total == 0)                               // check if total = 0
		return 0;                    
	else if (total % 2 == 0)                      // check if total is even
		return 1;
	else                                          
		return -1;
}
