#include <stdio.h>
#include<stdlib.h>

void main () {
int curNum;
int curSum = 0;
int i;//loop counter variable
for(i=0; i<4; i++){
	printf("\nEnter your number %d:", i+1);
	scanf("%d",&curNum);
	curSum += curNum;
}
printf("\nResults: %d", &curSum
 );
}