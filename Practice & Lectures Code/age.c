#include <stdio.h>
#include<stdlib.h>

void main () {
	
	int userAge;
	int validAge = 0;//loop counter variable
	int numTry = 0;
	
	while(validAge==0){//exit condition
	if(numTry==3){
		printf("\nError!!! Try again");
		//break
		exit (0);
	}
	numTry++;
	printf("\n Enter your age: ");
scanf("%d", &userAge);

if(userAge >0 && userAge <= 130){
	printf("\nThanks for entering your age." );
	validAge =1;
	//break
	exit(0);
}	
	else{
	printf("\nInvalid Input. Try Again");	
		
	}	
	}
}