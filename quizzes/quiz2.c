#include <stdio.h>


int main() {

char firstname[10];
printf("Enter your first name\n");
scanf(" %s", &firstname);

char lastname[10];
printf("Enter your last name\n");
scanf(" %s", &lastname);

char major[10]; 
printf("Enter your major\n");
scanf(" %s", &major);

char year[10];
printf("Enter year in college\n");
scanf(" %s", &year);

char grad[10];
printf("Enter your graduation year\n");
scanf(" %s", &grad);

printf("Name (last, first): Name (%s, %s) \n", lastname, firstname);
printf("%s\n", major);
printf("%s\n", year);
printf("%s\n", grad);

return 0;
}