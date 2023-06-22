// Q2 109061217 林峻霆
// Given three strings str1, str2 and str3, please write a function to
// return a NEW string which is a concatenation of str1, str2 and str3.
//
// For example, if str1 points to "this is "
//                 str2 points to "a good day "
//             and str3 points to "for final exam."
//   then the function returns a pointer pointing to the memory location
//   that contains the string "this is a good day for final exam."
//
char *STRcat(char *str1, char *str2, char *str3)
	// a function that concatenate three string together and return a new
	// string
{
	int i = 0;                   // parameter for loop
	int j = 0;                   // parameter for loop and index
	int l1 = 0;                  // length of str1
	int l2 = 0;                  // length of str2
	int l3 = 0;                  // length of str3
	char *new;                   // new string

	while (str1[l1] != '\0')     // calculate l1
		l1++;
	while (str2[l2] != '\0')     // calculate l2
		l2++;
	while (str3[l3] != '\0')     // calculate l3
		l3++;

	new = malloc(sizeof(l1 + l2 + l3));  // allocate memory for new string

	for (i = 0 ; i < l1; i++)            // copy str1 to new
		new[i] = str1[i];
	
	j = j + i;

	for (i = 0; i < l2; i++)             // copy str2 to new
		new[j + i] = str2[i];

	j = j + i;

	for (i = 0; i < l3; i++)             // copy str3 to new
		new[j + i] = str3[i];

	return new;                          // return the new string
}
