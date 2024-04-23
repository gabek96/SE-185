#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void replace_char(char *string, char replace, char new);
	

int main (void)
	{
char s2[50] = "!";
char s1[50]	;
printf("Please enter your password: ", s1);
scanf("%s", s1);

replace_char(s1, 'a', '@');
replace_char(s1, 'a', '@');
replace_char(s1, 'a', '@');
replace_char(s1, 'a', '@');
replace_char(s1, 'a', '@');
replace_char(s1, 'a', '@');
strcat(s1,s2);

printf("Your new password: %s\n ", s1);
return 0;
	}
	
void replace_char(char * string, char replace, char new) {
	
	int slen = strlen(string);
	
	for(int i = 0; i < slen; i++)
		if(string[i] == replace)
			string[i] = new;
}
