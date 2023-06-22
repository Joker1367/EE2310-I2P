// EE231002 Lab01 Purchasing Petroleum
// // 109061217, Henry Lin
// // Date:2001.09.21
#include<stdio.h>

int main(void){
    int NT_amount;                                          //NT dollars
    float NT_liters;                                        //liters in NT
    float NT_gallons;                                       //gallons in NT
    float US_liters;                                        //liters in US
    float US_gallons;                                       //gallons in US
	
    printf("Input NT amount:");                             //prompt for amount
    scanf("%d", &NT_amount);                                //input NT_amount

    US_gallons = NT_amount/2.525/29.02;                     //calculate USgallon
    US_liters = NT_amount/2.525/29.02*3.785;                //calculate USliter
    NT_liters = NT_amount/23.5;                             //calculate NTlitter
    NT_gallons = NT_amount/23.5/3.785;                      //calculate NTgallon

    printf("Petroleum bought in Taiwan: %.6f ", NT_liters); //output the NT_data
    printf("liters or %.6f gallons.\n", NT_gallons);
    printf("Petroleum bought in US: %.6f ", US_liters);     //output the US_data
    printf("liters or %.6f gallons.\n", US_gallons);

    return 0;                                               //end the program
}

