// Q3 109061217 林峻霆
// Suppose a polynomial, p1, has been constructed using the structure below,
// please write a function to constructed the polynomial p2 which is
// derivative of p1. Note that p1 is assumed to not NULL.
//
// For example, if p1 = x^3 + x^2 + x + 1
//             then the function returns a pointer pointing to
//                      3 x^2 + 2 x + 1
//
typedef struct sPoly {
    int degree;                         // the degree of the node
    double coef;                        // the coefficient of the node
    struct sPoly *next;                 // pointer to the next node
} POLY;

POLY *diff(POLY *p1)
	// a function that differentiate a polynomial and return a new 
	// polynomial of it
{
	POLY *cur;           // current term in p1
	POLY *new;           // new polynomial
	POLY *new_cur;       // current term in new polynomial
	POLY *term;          // a new construct term

	new = malloc(sizeof(POLY));          // allocate memory for first term
	new->degree = p1->degree - 1;        // calculate degree and coef
	new->coef = p1->coef * p1->degree;
	new_cur = new;                       // point new_cur to new
	cur = p1->next;                      // point cur to p1->next

	while (cur && cur->degree > 0) {     // check if is constant term
		term = malloc(sizeof(POLY));     // allocate memory for new term
		new_cur->next = term;            // point new_cur-> to new term
		new_cur = new_cur->next;         // change new_cur to new term;
		new_cur->coef = cur->coef * cur->degree; // calculate coef, degree
		new_cur->degree = cur->degree - 1;      
		cur = cur->next;                 // move cur to cur->next
	}

	return new;                          // return the new polynomial
}
