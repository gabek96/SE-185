#include <stdio.h>	//add input output header file  
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
@copyright info
Author Name:
Team:
Company:
Date:x
input, functions, outputs
*/

// function delcaration
int (int x);

void main () {
	
	int a;
	printf("Enter an integer value");
	scanf("%d", &a);
	int b = sqr(a); //function call 
	printf("Result = %d", b);

return 0;
}
// function definition
int sqr(int x) {
	
	int n = x * x;
	return n;
}