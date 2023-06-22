//EE2310 lab02 Grouping Digits
//109061217 林峻霆
//2020/10/5

# include <stdio.h>

int main(void)
{
    int N;                                                   // input number 
    int thousand;                                            // below thousand
    int million;                                             // below million
    int billion;                                             // below billion  
    int trillion;                                            // below trillion
    
    printf("Input a positive integer N (N < 2000000000): "); // prompt for input
    scanf("%d", &N);					     // input the number

    thousand = N % 1000;				     // compute thousand
    N = N / 1000;                                            // N minus thousand
    million = N % 1000;                                      // compute million
    N = N / 1000;                                            // N minus million
    billion = N % 1000;                                      // compute billion
    N = N / 1000;                                            // N minus billion

    printf("N: ");                                           // print the begin
    if(N != 0)                                               // judge and print
    {
	printf("%d,%.3d,%.3d,%.3d\n", N, billion, million, thousand);
    }
    else if(billion != 0)
    {
        printf("%d,%.3d,%.3d\n", billion, million, thousand);
    }
    else if(million != 0)
    {
        printf("%d,%.3d\n", million, thousand);
    }
    else
    {
	printf("%d\n", thousand);
    }

    return 0;                                                // program end
}	
