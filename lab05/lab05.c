// EE2310 lab05 Permutations
// 109061217 林峻霆
// Date: 2020/10/26

#include <stdio.h>

#define N 7

int main(void)
{
	int j;                                        // a parameter in loop
	int k;                                        // a parameter in loop
	int i = 0;                                    // a parameter in loop
	int tmp;                                      // a variable for swapping
	int A[N];                                     // array to store data
    int total = 1;                                // number of permutation

	for (; i < N; i++) {                          // input data in array
		A[i] = i + 1;
	}
	printf("permutation #%d: ", total);
	for(i = 0; i < N; i++) {                      // the first permutation
		printf("%d ", A[i]);
	}
	printf("\n");
	
	i = N - 2;                                    // change i to N - 2
	while (i >= 0) {		  		    		  // initialize a loop
		if (A[i] < A[i + 1]) {                    // compare the data
			j = i + 1;                            // change j to i + 1
			total = total + 1;
			for (; j < N ; j++) {                 // swap two data
				if (A[i] > A[j]) {
					tmp = A[i];
					A[i] = A [j - 1];
					A[j - 1] = tmp;
					j = N;                        // jump out the loop
				}
				else if (j == N - 1) {            // the final-element case 
					tmp = A[i];                  
					A[i] = A[j];
					A[j] = tmp;
				}
			}
			j = i + 1;                            // change j to i + 1
			for (k = 0; j + k < N - 1 - k; k++) { // reverse part of the array
				tmp = A[j + k];
				A[j + k] = A[N - 1 - k];
				A[N - 1 - k] = tmp;
			}
			printf("permutation #%d: ", total);   
			for (k = 0; k < N; k++) {             // print the permutation
				printf("%d ", A[k]);
			}
			printf("\n");
			i = N - 2;	                          // change i back to N - 2
		}
		else
			i = i - 1;                            // see next element in array
	}
	printf("  Total number of permutations");     // print the total amount
	printf(" is %d\n", total); 
	
	return 0;                                     // end the program
}
