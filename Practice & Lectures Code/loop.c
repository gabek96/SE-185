#include <stdio.h>
#include<stdlib.h>

void main () {
	
	int curNum;
	int curSum = 0;
	int numInput = 0; //loop counter variable
	while (numInput < 4) { // exit condition
		printf("\nEnter number %d:", numInput+1);
		scanf("%d", curNum);
		curSum = curSum + curNum;
	
		numInput++;// udpate loop coiunter variable
	}
printf ("\nResult = %d", curSum);	
}