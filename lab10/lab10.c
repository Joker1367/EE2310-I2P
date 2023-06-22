// EE2310 lab10 Academic Competition
// 109061217, 林峻霆
// Date: 2020/12/7

#include <stdio.h>
#include <stdlib.h>

struct STU {                             // struct store student informaition
	char fname[15];                      // student's first name
	char lname[15];                      // student's last name
	double math, sci, lit;               // score of subject
	double min;                          // lowest score
	double total_score;                  // total score
	int winGra;                          // qualify for Grand Prize
	int winSub;                          // qualify for Subject Prize
};

struct STU list[100];                    // a list to store every students

int main(void)
{
	int i, j;                            // parameter for loop and index
	int total = 0;                       // total amount of prize
	char tmp[20];                        // tmp to store input string
	struct STU swp;                      // swp for swapping two struct

	for (i = 0; i < 5; i++)              // filter non-important input
		scanf("%s", tmp);

	for (i = 0; i < 100; i++) {          // input every students' information
		scanf("%s", list[i].fname);
		scanf("%s", list[i].lname);
		scanf("%s", tmp);
		list[i].math = atof(tmp);
		scanf("%s", tmp);
		list[i].sci = atof(tmp);
		scanf("%s", tmp);
		list[i].lit = atof(tmp);
		list[i].total_score = list[i].math + list[i].sci + list[i].lit;

		list[i].min = list[i].math;      // find the lowest-score subject  
		if (list[i].min > list[i].sci) {
			list[i].min = list[i].sci;
			if (list[i].min > list[i].lit)
				list[i].min = list[i].lit;
		}
		else if (list[i].min > list[i].lit)
			list[i].min = list[i].lit;	

		if (list[i].min >= 82)          // check the qualification
			list[i].winGra = 1;
		else
			list[i].winGra = 0;

		if (list[i].min >= 60)
			list[i].winSub = 1;
		else
			list[i].winSub = 0;
	}

	printf("Grand Prize:\n");          // print the first line 
	for (i = 0; i < 100; i++) {        // put top ten to front
		if (list[i].winGra) {
			for (j = i + 1; j < 100; j++) {
				if(list[j].winGra && list[j].total_score > list[i].total_score)
				{
					swp = list[j];
					list[j] = list[i];
					list[i] = swp;
				}
			}
		}
	}
									   // print the name list of Grand Prize
	for(i = 0; i < 100 && total < 10; i++) {
		if(list[i].winGra) {
			total += 1;
			printf("%3d: %s %s ", total, list[i].fname, list[i].lname);
			printf("%.1lf\n", list[i].total_score);
		}
	}

	total = 0;                          // set amount of prize to 0
	printf("Math Prize:\n");            // print the first line
	for (i = 0; i < 100; i++) {         // put top ten to front
		if (!list[i].winGra  && list[i].winSub) {
			for (j = i + 1; j < 100; j++) {
				if (list[j].winSub && list[j].math > list[i].math) {
					swp = list[j];
					list[j] = list[i];
					list[i] = swp;
				}
			}
		}
	}
										// print the name list of Math Prize
	for (i = 0; i < 100 && total < 10; i++) {
		if (!list[i].winGra && list[i].winSub) {
			total += 1;
			printf("%3d: %s %s ", total, list[i].fname, list[i].lname);
			printf("%.1lf\n", list[i].math);
		}
	}

	total = 0;                          // reset the amount of prize
	printf("Science Prize:\n");         // print the first line
	for (i = 0; i < 100; i++) {         // put top ten to front
		if (!list[i].winGra && list[i].winSub) {
			for (j = i + 1; j < 100; j++) {
				if (list[j].winSub && list[j].sci > list[i].sci) {
					swp = list[j];
					list[j] = list[i];
					list[i] = swp;
				}
			}
		}
	}
										// print name list of Science Prize
	for (i = 0; i < 100 && total < 10; i++) {
		if (!list[i].winGra && list[i].winSub) {
			total += 1;
			printf("%3d: %s %s ", total, list[i].fname, list[i].lname);
			printf("%.1lf\n", list[i].sci);
		}
	}

	total = 0;                         // reset the amount of prize
	printf("Literature Prize:\n");     // print the first line
	for (i = 0; i < 100; i++) {        // put top ten to front
		if (!list[i].winGra && list[i].winSub) {
			for (j = i + 1; j < 100; j++) {
				if (list[j].winSub && list[j].lit > list[i].lit) {
					swp = list[j];
					list[j] = list[i];
					list[i] = swp;
				}
			}
		}
	}
									   // print name list of Literature Prize
	for (i = 0; i < 100 && total < 10; i++) {
		if (!list[i].winGra && list[i].winSub) {
			total += 1;
			printf("%3d: %s %s ", total, list[i].fname, list[i].lname);
			printf("%.1lf\n", list[i].lit);
		}
	}

	return 0;                          // end the program
}
