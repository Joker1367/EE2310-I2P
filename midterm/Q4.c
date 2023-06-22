// Q4 109061217 林峻霆
// A large integer can be made easier to read if the digits are grouped
// together with ',' inserted between groups. For example, the number
//
// 12,3456,7890 
//
// is much easier to read.
// Please write a program that uses loops (for, while or do) to group
// the digits for large integers. For example, if
//
// long N = 1122334455667788990;
//
// then the program executes to get
// $ ./a.out
// 112,2334,4556,6778,8990
//

#include <stdio.h>

long N = 1;                 // a long integer

int main(void)
{
    long number[5];                           // a array to store     
	int i = 0;                                // parameter for loop, array

	while (N > 0) {
		number[i] = N % 10000;                // calculate and store
		N = N / 10000;
		i = i + 1;
	}

	i = i - 1;                                // change i to i - 1
	printf("%ld", number[i]);                 // print the result
	while (i--) {
		printf(",%.4ld", number[i]);
	}
	printf("\n");

	return 0;                                 // end the program
}


