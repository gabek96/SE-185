#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool main (void) {
	bool check1 = false;
	bool check2 = false;

	char mainName[100];
	char mainPass[100];
	char name [100];
	char pass[100];
	
	strcpy(mainName, "se185@iastate.edu");
	strcpy(mainPass, "ds4rd");
	printf("Enter your username: ");
	scanf("%s", &name);
	printf("Enter your password: ");
	scanf("%s", &pass);
	
	if (strcmp(name, mainName) == 0) {
		check1 = true;
	}
	
	else{	
		check1 = false;
	}
	
	if(strcmp(pass, mainPass) == 0) {
		check2 = true;
	}	
	
	else {
		check2 = false;
	}
	
	if(check1 == check2) {
		printf("Success!");
	}
	
if(check1 == true && check2 == false) {
	printf("Password is incorrect\n");
	}	
	
	if(check1 == false && check2 == true) {
	printf("Username is incorrect");
	}	
	
	if(check1 == true && check2 == false) {
	printf("Username and Password is incorrect");
	}	

return 0;
}