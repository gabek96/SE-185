#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main () {

int num = -2;
int go = 3;

while(go != 0) {

if(num >= 0)
{
	
	num += 3;
	break;
	
}

else{
	if (num % 2 == 0){
		num *= -1;
}
	
	else{
		
		num++;
	}
}
go--;
}
return 0;
}