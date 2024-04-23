#include<stdio.h>
int main (){
char firstname[50];
char lastname[50];
char fullname [50];
int numLetters = 0;

printf("What's your first name?\n");
scanf("%s", firstname);

printf("What is your last name?\n");
scanf("%s", lastname);

printf("First Name:%c\n Last Name:%c\n Full Name:%c\n ", &firstname, &lastname, &fullname);
return (0);
}