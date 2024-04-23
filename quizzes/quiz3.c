#include <stdio.h>	
#include<math.h>
#include<string.h>
#include <stdlib.h>
int main (){
	
	int b = 0;
	int lim;
	int a = 100;
	int c = 93;
	int d = 90;
	int e = 87;			
	int f = 83;
	int g = 80;
	int h = 77;
	int j = 73;
	int k = 70;
	int l = 67;
	int z = 63;
	int x = 60;
	
printf("\n Please enter your Grade Percentage");
scanf("%d", &lim);

	
if (lim < b){
printf("Please enter your grade has to be between 0 percent and 100 percent inclusively\n");	
scanf("%d", &lim);
	}
	
else if (lim >= c) {
printf("A");
exit(0);
	}	
		
else if (lim >= d) {
printf("A-");
exit(0);
	}			

else if (lim >= e) {
printf("B+");
exit(0);
	}	

else if (lim >= f) {
printf("B");
exit(0);
	}

else if (lim >= g) {
printf("B-");
exit(0);
	}
	
else if (lim >= h) {
printf("C+");
exit(0);
	}
	
else if (lim >= j) {
printf("C");
exit(0);
	}

else if (lim >= k) {
printf("D+");
exit(0);
	}
	
else if (lim >= l) {
printf("D");
exit(0);
	}
		
else if (lim >= z) {
printf("D-");
exit(0);
	}

else if (lim >= x) {
printf("F");
exit(0);
	}
	
	return 0;
}
			