/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i, j;
	int sum = i + j;

    printf("Enter an integer: "); //missing semicolon
    scanf("%d", &i);

    printf("Enter another integer:"); //missing quotation mark
    scanf("%d", &j); // missing semicolon

    if (j % i == 0) {
        printf("%d divides %d\n", i, j);
		printf("Answer: %d", sum);
    } 	
	
	else{

        printf("%d does not divide %d\n", i, j); // forgot n printf statement
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}
