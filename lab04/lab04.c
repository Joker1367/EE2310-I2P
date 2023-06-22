// EE2310 lab04 Solving Integer Equation
// 109061217, 林峻霆
// Date: 2020/10/19

// I will explain my algorithm here first because i use a different method.
// I use a theorem called "Sum of two squares". In this theorem, it said that
// n = a^2 + b^2 has solutions if and only if its prime decomposition contains
// no term p^k where p % 4 = 3 and k is odd. According to this theorem , we
// can notice that the solution set of n^3 = a^2 + b^2 is equivalent to
// n = a^2 + b^2.Therefore, we may replace the question with solving
// n = a^2 + b^2, and print n^3 = (an)^2 + (bn)^2 at the end. 

// Dealing with every n <= max, approaching it with modulo is a good way.For
// any integer a, a^2 % 4 = 0 or 1, so n % 4 = 0,1 or 2.Therefore, we dont
// need to test n % 4 = 3 case.Additionally, we may find out that n % 4 = 0
// case can be derived from n % 4 = 1 or 2 cases.To sum up, we just only need 
// to test n % 4 = 1 or 2 case and I also use some properties of odd and even
// while calculating.
 
#include <stdio.h>

#define max 5000 

int main(void)
{
	int n;                                             // n in the equation
	int a;                                             // a in the equation
	int b;                                             // b in the equation
	int i = 1;                                         // scalar i
	int j = 1;                                         // scalar j
	int total = 0;                                     // amount of n
	int n_output;                                      // the output n
	int a_output;                                      // the output a
	int b_output;                                      // the output b

	for (n = 2; n <= max; n++) {					   // initialize a loop
		if (n % 4 == 1) {                              // judge cases
			for (a = 1; a * a <= n / 2; a++) {				  
				for (b = a + 1; b * b + a * a <= n; b = b + 2) {   
					if (n == a * a + b * b) {          // judge cases
						while (n * i <= max){             
							n_output = n * i;          // change n
							a_output = a * n * j;      // change a
							b_output = b * n * j;      // change b
							total += 1;                // calculate amount
							printf("%d: ", total);     // print the result
							printf("%d ^ 3 = ", n_output);
							printf("%d ^ 2 + ", a_output);
							printf("%d ^ 2\n", b_output);
							i = i * 4;                 // increase scalar
							j = j * 8;                 // increase scalar
						}
						i = 1;                         // change back to 1
						j = 1;                         // change back to 1
						b = n;                         // exit the loop
						a = b;                         // exit the loop
					}
				}
			}
		}
		else if (n % 4 ==2){                           // judge cases 
			for (a = 1; a * a <= n/2; a = a + 1){      // initialize loop
				for (b = a; b * b + a * a <= n; b = b + 1) {      
					if (n == a * a + b * b) {          // judge
						while (n * i <= max) {          
							int n_output = n * i;      // the output n
							int a_output = a * n * j;  // the output a
							int b_output = b * n * j;  // the output b
							total += 1;                // caculate total
							printf("%d: ", total);     // print the result
							printf("%d ^ 3 = ", n_output);    
							printf("%d ^ 2 + ", a_output);            
							printf("%d ^ 2\n", b_output);     
							i = i * 4;                 // increse scalar
							j = j * 8;                 // increase scalar
						}
						i = 1;                         // change back to 1
						j = 1;                         // change back to 1
						b = n;                         // exit the loop   
						a = b;                         // exit the loop
					}
				}
			}
		}
	}
	printf("%d solutions found for ", total);          // print the amount
	printf("n <= %d.\n", max);                        /* use ld if max is
	                                                      big*/    
	return 0;                                          // end the program
}

