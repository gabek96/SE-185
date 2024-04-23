#include <stdio.h>	//add input output header file  
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
@copyright info
Author Name:
Team:
Company:
Date:
input, functions, outputs
*/

int main (void) {

long long int number;
printf("Please enter the 10  digit phone number: ");
scanf("%11d", &number);
int area = number/100000000;
printf("The area code is: %d", area);

int exchangeCode = exchangeCode  / 1000;
printf("The exchange code is: %d" , exchangeCode);

int userNumber = number%1000;
printf("The user number is: &d", userNumber);
/*
double mikeE;
double maryE;
double garyE;
double loganE;

mikeE = sqrt (pow((15.55-22.05),2) + (pow((15.55-85.10),2);
maryE = sqrt (pow((15.55-43.25),2) + (pow((15.55-9.80),2);
garyE = sqrt (pow((15.55-2.55),2) + (pow((15.55-72.86),2);
loganE = sqrt (pow((15.55-15.15),2) + (pow((15.55-40.40),2);
*/

	
	
	return 0;
}
