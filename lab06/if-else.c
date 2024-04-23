#include<stdio.h>

// Odd or even program
int main(void) {
	
int userNum; //delcaring vairable 
int reimander; //declaring a variable 

printf("PLease Enter a Number");
scanf("%d", &userNum);

reimander = userNum % 2;

if(reimander == 0){
printf("%d is even\n", userNum);
}

else{
	printf("%d is odd\n", userNum);
} 	

return 0;	
}