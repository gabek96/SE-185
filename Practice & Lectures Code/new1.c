#include <stdio.h>
#include<stdlib.h>

void main () {
	
int i, num, sum;
int *ptr;
printf("\n Enter number of elements: ");
scanf("%d", &num); //get the array size 
//allocate dynamic theory	
ptr = (int*)malloc(num, sizeof(int));

if(ptr==NULL){
	printf("\nError!!!!!");
	exit(0);
	
} 

	for(i=0, i<num; i++) {
	printf("\nElement[0]:", *(ptr+i));
	}

	free(ptr); //free memory
}