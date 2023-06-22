// EE2310 lab03 Day of the Year
// 109061217, 林峻霆
// Date: 2020/10/5

#include <stdio.h>

int main(void)
{
    int month;                                         // input month
    int day;                                           // input day
    int total_day;                                     // total day
    int week;                                          // week
    int weekday;                                       // on which weekday

    printf("Input a date (m/d): ");                    // prompt for input
    scanf("%d/%d", &month, &day);                      // input month, day

    switch (month) {                                   // judge and calculate
		case 1:
	   		total_day = day;
	   		break;
		case 2:
	   		total_day = day + 31;
	   		break;
        case 3:
	    	total_day = day + 60;
	    	break;
		case 4:
	    	total_day = day + 91;
 	    	break;
		case 5:
	    	total_day = day + 121;
	    	break;
		case 6:
	    	total_day = day + 152;
	    	break;
		case 7:
		    total_day = day + 182;
	    	break;
		case 8:
	    	total_day = day + 213;
	    	break;
		case 9:
	    	total_day = day + 244;
	    	break;
		case 10:
	    	total_day = day + 274;
	    	break;
		case 11:
	    	total_day = day + 305;
	    	break;
		case 12:
	    	total_day = day + 335;
    }
    
    week = (total_day + 9) / 7;                       // calculate the week
    weekday = (total_day + 3) % 7;                    // calculate the weekday

    printf("It is day %d of the year,\n", total_day); // print total day
    printf("in the week %d of the year,\n", week);    // print week
    
    switch (weekday) {                                // judge and print
		case 0:
	   		printf("and it is Saturday.");
	   		break;
		case 1:
	   		printf("and it is Sunday.");
  	   		break;
		case 2:
	   		printf("and it is Monday.");
	   		break;
		case 3:
	   		printf("and it is Tuesday.");
	   		break;
		case 4:
	   		printf("and it is Wednesday.");
	   		break;
		case 5:
	   		printf("and it is Thursday.");
	   		break;
		case 6:
	   		printf("and it is Friday.");
    }
    printf("\n");                                     // new line

    return 0;                                         // end the program
}
