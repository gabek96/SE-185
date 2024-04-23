#include<stdio.h>
#include<ctype.h>
int main() {
	
	char letter = 'a';
	
	while(letter <= 'z'){
		printf("%c\n", toupper(letter));
		letter++;
		
		
	} 
	return 0;
}