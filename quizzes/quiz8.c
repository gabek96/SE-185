#include<stdio.h>

int add( int num1, int num2, int num3, int num4);
int sub (int num1, int num2, int num3, int num4);
int mult(int num1, int num2, int num3, int num4);
int user1;
int user2;
int user3;
int user4;


int main(){	
//struct 

typedef struct math{
	
	int add; 
	int sub;
	int mult;
	
}math;


int ptr1;
int ptr2;

printf(" Enter a real and imaginary number 1: ");
scanf("%d %d", &user1, &user2);
printf(" Enter a real and imaginary number 2: ");
scanf("%d %d", &user3, &user4);

//function call

add(user1, user2, user3, user4);
sub(user1, user2, user3, user4);
mult(user1, user2, user3, user4);
	
return 0;
	
}

//Function Definition

//Addition
int add( int num1, int num2, int num3, int num4){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
a = a + user1 + user3;
b = b + user2 + user4;
printf("ADD = %d+%di\n",a,b);
}

//Subtraction
int sub( int num1, int num2, int num3, int num4){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
a = a + user1 - user3;
b = b + user2 - user4;
printf("SUB = %d+%di\n",a,b);
}

//Multiplication
int mult( int num1, int num2, int num3, int num4){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
a = a + user1 * user4 *-1;
b = b + user2 * user4;
printf("MULT = %d+%di\n",a,b);
}