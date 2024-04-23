#include <stdio.h>

void main() {
	//variable declaration
	int userNum = 4567;
	double userNum2 = 123.4567;
	char userString[40] = "ZyBook is great!";
	
	//output formatting
	printf("\n(a) %d\n(b) %5d\n(c) %05d",userNum,userNum,userNum);
	printf("\n(d) %6.2lf\n(e) %7.2lf\n(f) %07.2lf",userNum2,userNum2,userNum2);
	printf("\n(g) %s\n(h) %.6s\n(i) %-18s185\n", userString,userString,userString);
	
	//input formatting
	scanf("%2d %lf %3s", &userNum,&userNum2,userString);
	printf("%d %.2lf %s",userNum,userNum2,userString);	
}