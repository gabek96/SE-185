#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main () {
	char pass1[30];
	char pass2[30];
	
	printf("\n Enter a password (at least 4 digits)")
	scanf("%s",pass1);
	if(strleb(pass1)<4){
	printf("\n Success!");
	exit(0):
	}
}

else {
	printf("Username or password is incorrect");
	scanf("%s", pass2);
	if strcmp(pass1, pass2);
	printf("\nSucess");
	
	exit(0);
}