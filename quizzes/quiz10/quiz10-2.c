#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function Declartions
int recursivePower(int baseNum, int powerVal, int basePower, int result);

int main(){
	int basePower = 1;
	int powerVal;
	int baseNum;
	int result;

	printf("Write down a number followed by it's exponent: ");
	scanf("%d %d", &baseNum, &powerVal);
	
	result = baseNum;
	result = recursivePower(baseNum, powerVal, basePower, result);
	
	printf("%d to the power of %d = %d", baseNum, powerVal, result);
}

//Functions Defintions 

int recursivePower(int baseNum, int powerVal, int basePower, int result){
	if(basePower == powerVal){
		return result;
	}
	else if(basePower < powerVal){
		basePower++;
		result = result * baseNum;
		recursivePower(baseNum, powerVal, basePower, result);	
	}
}
