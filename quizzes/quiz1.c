#include <stdio.h>	//add input output header file  
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
@copyright info
Author Name:
Team:
Company:
Date:x
input, functions, outputs
*/

int main (void) {

/* long long int number = 1234567890;
printf("Please enter the 10  digit phone number: \n");
//scanf("%11d", &number);
int area = number/10000000;
printf("The area code is: %d\n", area);

int exchangeCode = number  % 10000000;
exchangeCode = exchangeCode / 10000;
printf("The exchange code is: %d\n" , exchangeCode);

int userNumber = number%1000;
printf("The user number is: %d\n", userNumber);
*/


double mikeE;
double maryE;
double garyE;
double loganE;

mikeE = sqrt (pow((15.55-22.05),2) + (pow((55.15-85.10),2)));
maryE = sqrt (pow((15.55-43.25),2) + (pow((55.15-9.80),2)));
garyE = sqrt (pow((15.55-2.55),2) + (pow((55.15-72.86),2)));
loganE = sqrt (pow((15.55-15.15),2) + (pow((55.15-40.40),2)));
	
printf("The E distance for Mike is: %lf\n", mikeE);
printf("The E distance for Mary is: %lf\n", maryE);
printf("The E distance for Gary is: %lf\n", garyE);
printf("The E distance for Logan is: %lf\n", loganE);

return 0;
}