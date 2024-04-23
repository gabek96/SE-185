/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<stdbool.h>
/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
#define TRUE 6
#define FALSE 8
#define NONE 5
#define TRIANGLE 1
#define SQUARE 2
#define X 3
#define CIRCLE 4

int computerGuess();
int userGuess(int a, int b, int c, int d);
int ButtonPrint(int l);
int StillActive(int tx, int ty);
/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    srand(time(NULL)); /* This will ensure a random game each time. */

int t, b01, b02, b03, b04;
int time, lvl;
lvl = 1;
int comguess;
int x = 0;
int game = TRUE;
int pressed;
int startTime;
int Count [NONE]={0,0,0,0,0};

int timeGiven = 2500;
printf("Press triangle to start the game\n");
scanf(" %d, %d, %d, %d, %d", &t, &b01, &b02, &b03, &b04);
while(userGuess(b01, b02, b03, b04)!=TRIANGLE){
	scanf(" %d, %d, %d, %d, %d", &t, &b01, &b02, &b03, &b04);	
}
while(game==TRUE){
	for(int i = 0; i<NONE; i++){
		Count[i] = 0;
	}
	printf("Level: %d\n", lvl);
	scanf(" %d, %d, %d, %d, %d", &t, &b01, &b02, &b03, &b04);
	comguess = computerGuess();
	ButtonPrint(comguess);
	startTime = t;
	printf("You have %d miliseconds to respond\n", timeGiven);
	while(StillActive(t, timeGiven + startTime)==TRUE){
		scanf(" %d, %d, %d, %d, %d", &t, &b01, &b02, &b03, &b04);
		pressed = userGuess(b01, b02, b03, b04);
		Count[pressed] = Count[pressed] + 1;
		if((Count[pressed] > 1)&&(pressed !=NONE)){
			if(pressed==comguess){
				printf("Good Job\n");
				lvl = lvl + 1;
				timeGiven = timeGiven - 100;
				break;
			}
			else{
				printf("Sorry you pressed the wrong button\n");
				printf("You Lose\n");
				printf("You went through %d rounds", lvl);
				return 0;
			}
		}
    }
	if(StillActive(t, timeGiven + startTime) == FALSE){
		printf("You ran out of time\n");
		printf("You Lose\n");
		printf("You went through %d rounds", lvl);
		return 0;
			}
		}
}
	
	int StillActive (int tx, int ty){
		
		if(ty - tx > 0){
			return TRUE;
		}
	else {
		return FALSE;
	}
	/* Put your functions here, and be sure to put prototypes above. */

	}
	int userGuess(int a, int b, int c, int d){
		if(a==1){
			return TRIANGLE;
		}
		else if(b==1){
			return CIRCLE;
		}
		else if(c==1){
		return X;
		}
		else if(d==1){
			return SQUARE;
		}
		else{
		return NONE;
		}
	}
int ButtonPrint(int l){ 
	if(1==TRIANGLE){
		printf("Press Triangle\n");
	}
	else if(1==CIRCLE){
		printf("Press Circle\n");
	}
	else if (1==X){
		printf("Press X\n");
	}
	else if(1==SQUARE){
		printf("Press Square\n");
	}
	
}

	int computerGuess() {
		if(((rand()%3)+1 )== 1){
			return TRIANGLE;
		}
		else if (((rand()%3)+1) == 2){
			return SQUARE;
		}
		else if (((rand()%3)+1) == 3){
			return X;
		}
		else {
			return CIRCLE;
		}
		return 0;
	}