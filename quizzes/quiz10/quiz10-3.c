#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function Declations

int recusiveStrLength(int string, char* userString, int i);
int main(){

int string = 0;
char userString[70];
int i = 0;

printf("Enter a string: ");
scanf("%s", userString);
string =  recusiveStrLength(string, userString, i);
printf("The length of %s = %d", userString, string);
}

//Function Defintions

int recusiveStrLength(int string, char* userString, int i){
if(userString[i] =='\0'){
return string;	
}
else{
	
	string++;
	i++;
 recusiveStrLength(string, userString, i);
}
	
	
}