// EE2310 lab12. Polynomials
// 109061217, 林峻霆
// Date: 2020/12/22

#include <stdio.h>
#include <stdlib.h>

typedef struct sPoly {   // a struct store a term's degree, coef and next term
	int degree;          // term's degree
	double coef;         // terms coefficient
	struct sPoly *next;  // next term's address
} POLY;

POLY *oneTerm(int degree, double coef); // function: build a one term polynomial
POLY *add(POLY *p1, POLY *p2);         // function: add 2 polynomial together
POLY *sub(POLY *p1, POLY *p2);         // function: subtraction of 2 polynomial
POLY *mply(POLY *p1, POLY *p2);        // function: multiply two polynomial
void print(POLY *p1);                  // function: print the polynomial
void release(POLY *p1);                // function: release polynomial's memory

int main(void)
{
	POLY *X = oneTerm(1, 1);           // X = x
	POLY *ONE = oneTerm(0, 1);         // ONE = 1

	POLY *A = add(X, ONE);             // A = X + ONE
	POLY *A2 = mply(A, A);             // A2 = A * A
	POLY *A3 = mply(A, A2);            // A3 = A2 * A
	POLY *A4 = mply(A, A3);            // A4 = A3 * A
	POLY *A5 = mply(A, A4);            // A5 = A4 * A

	POLY *B = sub(X, ONE);             // B = X - ONE
	POLY *B2 = mply(B, B);             // B2 = B * B
	POLY *B3 = mply(B, B2);            // B3 = B2 * B
	POLY *B4 = mply(B, B3);            // B4 = B3 * B
	POLY *B5 = mply(B, B4);            // B5 = B4 * B

	POLY *C = add(A, B);               // C = A + B
	POLY *C2 = mply(A2, B2);           // C2 = A2 * B2
	POLY *C3 = mply(A3, B3);           // C3 = A3 * B3
	POLY *C4 = mply(A4, B4);           // C4 = A4 * B4
	POLY *C5 = mply(A5, B5);           // C5 = A5 * B5

	printf("A =");                     // print the result
	print(A);
	printf("A2 =");
	print(A2);
	printf("C =");
	print(C);
	printf("C2 =");
	print(C2);
	printf("C3 =");
	print(C3);
	printf("C4 =");
	print(C4);
	printf("C5 =");
	print(C5);
	
	return 0;                          // end the program
}

POLY *oneTerm(int degree, double coef)
	// build a one term polynomial with two inputs: degree, coef and one output
	// 	Inputs:
	// 		degree: term's degree
	// 		coef: term's coefficient
	// 	Outputs:
	// 		new_node: pointer of the new build term
{
	POLY *new_node = malloc(sizeof(POLY)); // assign memory for term

	new_node->degree = degree;             // assign degree
	new_node->coef = coef;                 // assign coefficient
	new_node->next = NULL;                 // pointer to next point to NULL

	return new_node;                       // return the term 
}

POLY *add(POLY *p1, POLY *p2)
	// add two input polynomial together and return the result
{
	POLY *front;      // pointer to the first term of result polynomial 
	POLY *now;        // pointer to the current term of result polynomial
	POLY *cur1 = p1;  // pointer to the current term of p1 polynomial
	POLY *cur2 = p2;  // pointer to the current term of p2 polynomial

	// check the condition and then compute the first term of result polynomial
	if (cur1->degree > cur2->degree) {       
		front = oneTerm(cur1->degree, cur1->coef);
		cur1 = cur1->next;
	} 
	else if (cur1->degree < cur2->degree) {
		front = oneTerm(cur2->degree, cur2->coef);
		cur2 = cur2->next;
	}
	else {
		front = oneTerm(cur1->degree, cur1->coef + cur2->coef);
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	now = front;      // point now to front

	// check condition and compute the rest of terms(same method as the above)
	while (cur1 && cur2) { 
		if (cur1->degree > cur2->degree) {
			now->next = oneTerm(cur1->degree, cur1->coef);
			cur1 = cur1->next;
			now = now->next;
		}
		else if (cur1->degree < cur2->degree) {
			now->next = oneTerm(cur2->degree, cur2->coef);
			cur2 = cur2->next;
			now = now->next;
		}
		else if (cur1->coef + cur2->coef != 0) {
			now->next = oneTerm(cur1->degree, cur1->coef + cur2->coef);
			cur1 = cur1->next;
			cur2 = cur2->next;
			now = now->next;
		}
		else {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

	// if one polynomial reach its end, add the rest of another to the result
	if (!cur1) {
		now->next = cur2; // link now->next to rest of the polynomial
	}
	else { 
		now->next = cur1; // link now->next to rest of the polynomial
	}

	return front;         // return the pointer of the first term of result
}

POLY *sub(POLY *p1, POLY *p2)
	// compute p1 - p2 and return the result (almost the same as add)
{
	POLY *front;          // pointer to the first term of result polynomial
	POLY *now;            // pointer to the current term of result polynomial
	POLY *cur1 = p1;      // pointer to the current term of p1 polynomial
	POLY *cur2 = p2;      // pointer to the current term of p2 polynomial

	// check conditions and compute the first term of the result polynomial
	if (cur1->degree > cur2->degree) {
		front = oneTerm(cur1->degree, cur1->coef);
		cur1 = cur1->next;
	}
	else if (cur1->degree < cur2->degree) {
		front = oneTerm(cur2->degree, -(cur2->coef));
		cur2 = cur2->next;
	}
	else {
		front = oneTerm(cur1->degree, cur1->coef - cur2->coef);
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	now = front;         // point now to front

	// check conditions and compute rest of terms (same as above)
	while (cur1 && cur2) {
		if (cur1->degree > cur2->degree) {
			now->next = oneTerm(cur1->degree, cur1->coef);
			cur1 = cur1->next;
			now = now->next;
		}
		else if (cur1->degree < cur2->degree) {
			now->next = oneTerm(cur2->degree, cur2->coef);
			cur2 = cur2->next;
			now = now->next;
		}
		else if (cur1->coef - cur2->coef != 0) {
			now->next = oneTerm(cur1->degree, cur1->coef - cur2->coef);
			cur1 = cur1->next;
			cur2 = cur2->next;
			now = now->next;
		}
		else {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

	// while one reach its end, do some transform and add to the result 
	if (!cur1) {
		while (cur2) {
			now->next = oneTerm(cur2->degree, -(cur2->coef));
			cur2 = cur2->next;
			now = now->next;
		}
	}
	else 
		now->next = cur1; // link now->next to rest of polynomial

	return front;         // return the first term addrres of result polynomial
}

POLY *mply(POLY *p1, POLY *p2)
	// use addition to complete multiplication, the below is the description
	// of algorithm
	//		steps 1.: multiply a term from p1 with every term of p2
	//		steps 2.: add the result above to the result polynomial
	//		steps 3.: move term from p1 to next term
	//		steps 4.: continue until reach the end of polynomial
{
	POLY *result = oneTerm(0, 0); // build the initial condition of final result
	POLY *front;                  // pointer to the first term of tmp result
	POLY *now;                    // pointer to the current term of tmp result
	POLY *cur1 = p1;              // pointer to the current term of p1
	POLY *cur2 = p2;              // pointer tom the current term of p2
	int deg_sum;                  // sum of degree
	int coef_mply;                 // multiply of coefficient


	while (cur1) {                // multiply every term in p2 with a term in p1
		front = oneTerm(cur1->degree + cur2->degree, cur1->coef * cur2->coef);
		cur2 = cur2->next;
		now = front;
		while (cur2) {
			deg_sum = cur1->degree + cur2->degree;
			coef_mply = cur1->coef * cur2->coef;
			now->next = oneTerm(deg_sum, coef_mply);
			cur2 = cur2->next;
			now = now->next;
		}
		
		result = add(result, front);  // add tmp result with final result
		release(front);               // release memory of tmp result
		cur2 = p2;                    // point cur2 back to first term of p2
		cur1 = cur1->next;            // point term in cur1 to next term
	}

	return result;                    // return final result polynomial
}

void print(POLY *p1)
	// function that print out the polynomial
{
	POLY *cur = p1;                  // point cur to the first term of p1

	if (cur->coef != 1)              // print the first term
		printf(" %lg x", cur->coef);
	else
		printf(" x");
	if (cur->degree != 1)
		printf("^%d", cur->degree);
	
	cur = cur->next;                 // move cur to next term
	while (cur) {                    // print the rest of terms
		if (cur->coef != 0) {
			if (cur->degree > 1) {
				if (cur->coef < 0)
					printf(" %lg x^%d", cur->coef, cur->degree);
				else if (cur->coef == 1)
					printf(" +x^%d", cur->degree);
				else
					printf(" +%lg x^%d", cur->coef, cur->degree);
			}
			else if (cur-> degree == 1) {
				if (cur->coef < 0)
					printf(" %lg x", cur->coef);
				else if (cur->coef == 1)
					printf(" +x");
				else
					printf(" +%lg x", cur->coef);
			}	
			else {
				if (cur->coef < 0)
					printf(" %lg", cur->coef);
				else
					printf(" +%lg", cur->coef);
			}
		}
		cur = cur->next;            // move cur to next term
	}
	printf("\n");                   // print next line
}

void release(POLY *p1)
	// use "free" command to release memory of un-used polynomial
{
	POLY *cur;                      // a pointer help releasing memory
	while (p1) {                    // do until p1 reach its end (NULL)
		cur = p1->next;             // point cur to p1->next
		free(p1);					// release memory in p1
		p1 = cur;                   // move p1 to cur (p1->next)
	}
}
