// EE2310 Lab13. Text Decoding
// 10906127, 林峻霆
// Date: 2020/12/28

#include <stdio.h>

int main(void)
{
	char amt;                              // the first char in each line
	char tmp;                              // a char for decoding
	char code[5];                          // char read from the encoded text
	char result[4];                        // the result after decoding
	int i, j;                              // parameter for loop

	amt = getchar();                       // read the first char in each line
	amt = amt - '0';                       // transfer to amount
	while (amt != 0) {                     // check if reach the end
		for (i = 0; i < amt / 3; i++) {    // read the encoded text
			for (j = 0; j < 4; j++) {       
				code[j] = getchar();
				code[j] -= ' ';            // decode (minus ' ')
			}
			result[0] = code[0] << 2;      // decode first char
			tmp = code[1] >> 4;
			result[0] |= tmp;

			result[1] = code[1] << 4;      // decode second char
			tmp = code[2] >> 2;
			result[1] |= tmp;

			result[2] = code[3];           // decode third char
			tmp = code[2] << 6;
			result[2] |= tmp;

			printf("%s", result);          // print the result
		}

		if (amt % 3 == 1) {                // check whether remaining any char
			for (j = 0; j < 4; j++) {      // read the encoded text
				code[j] = getchar();       
				code[j] -= ' ';            // decode (minus' ')
			}
			result[0] = code[0] << 2;      // decode the first char
			tmp = code[1] >> 4;
			result[0] |= tmp;

			printf("%c", result[0]);       // print the decoded char
		}
		else if (amt % 3 == 2) {           // check whether remaining char
			for (j = 0; j < 4; j++) {      // read the encoded text
				code[j] = getchar();
				code[j] -= ' ';            // decode (minus ' ')
			}
			result[0] = code[0] << 2;      // decode first char
			tmp = code[1] >> 4;
			result[0] |= tmp;

			result[1] = code[1] << 4;      // decode second char
			tmp = code[2] >> 2;
			result[1] |= tmp;

			printf("%c%c", result[0], result[1]); // print the result
		}

		amt = getchar();                   // skip the "next line"
		amt = getchar();                   // read first char in each line
		amt = amt - '0';                   // transfer to amount
	}
	return 0;                              // end the program
}

