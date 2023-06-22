// Q4 109061217 林峻霆
// A group of N students are participating in a academic competition.
// Three tests were taken by each students: mathematics, science and
// literature. The scores of these students have been organized into
// an array of structures, together with their names. Given that array
// the average of the math scores, the science scores, and the literature
// scores can all be calculated. Please write a function to find the
// maximum of these three averages.

#define N 100

struct STU {                // structure definition for each students
    char fName[15];         // first name
    char lName[15];         // last name
    double math, sci, lit;  // test scores
};

struct STU list[N];       // all students' results as an array of struct

double MaxAverage(struct STU list[N])
	// a function that compares average of math, science, literature and 
	// return the maximum of them 
{
	double max;                               // the maximum
	double avg_math = 0;                      // average of math
	double avg_sci = 0;                       // average of science
	double avg_lit = 0;                       // average of literature
	int i;                                    // parameter for loop, index

	for (i = 0; i < N; i++)                   // calculate avg_math
		avg_math += list[i].math;
	avg_math = avg_math / N;

	for (i = 0; i < N; i++)                   // calculate avg_sci
		avg_sci += list[i].sci;
	avg_sci = avg_sci / N;

	for (i = 0; i < N; i++)                   // calculate avg_lit
		avg_lit += list[i].lit;
	avg_lit = avg_lit / N;

	max = avg_math;                           // comparing
	if (max < avg_lit)
		max = avg_lit;
	if (max < avg_sci)
		max = avg_sci;

	return max;                               // return the result
}
