//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Nathan Voung" | "70"
Team member 2 "Gabe" | "30"
Team member 3 "Name" | "Percentage of Contribution to The Project"
Team member 4 "Name" | "Percentage of Contribution to The Project"
*/

////////////////////
#include<stdio.h>//
//add more here////
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//////////////////////
//Struct Definition//
////////////////////
typedef struct scoretable{
	char name[3];
	int score;
	int rank;
} scores;

/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

//void printScoreboard();

void printTriangle();

void printSquare();

void printCircle();

void printX();


int main(){
	
srand(time(NULL));
char startB;
int shapeSelector[4];
int roundNum = 1;
char userInput;
int x;
int i, endGame, turn, tempScore;
char Ans[4];
char Wrong; 
scores high[11];
FILE *fp = NULL;
int min = 99;
int scoreU;
char tempName[3];


//Intro Stuff
fp = fopen("scoreboard.txt", "r");
	for(int i = 0; i<10; i++){
	fscanf(fp,"%d %d %s \n", &high[i].rank, &high[i].score, high[i].name);
	}
		for(int i = 0; i<10; i++){
	printf("%d %d %s \n", i+1, high[i].score, high[i].name );
		}
printf("press g to start the game");
scanf("%c", &startB);

//Game Start

if( startB == 'g'){
	scoreU = 0; 
	turn = 1;
	printf("3...\n");
	printf("2....\n");
	printf("1....\n");
	do{
		for(int i = 0; i< roundNum; i++){
			sleep(3);
			shapeSelector[i] = rand()%4;
			if(shapeSelector[i] == 0){ //This just prints out the shape if the randome number is 0
				Ans[i] = 'w';
				printTriangle();
			}
			
			if(shapeSelector[i] == 1){ // same as the comment above
				Ans[i] = 'a';
				printSquare();
			}
			
			if(shapeSelector[i] == 2){// same as the comment above
				Ans[i] = 'd';
				printCircle();
			}
			
			if(shapeSelector[i] == 3){// same as the comment above
				Ans[i] = 's';
				printX();
			}
					sleep(3); 
		}
		system("clear");
		printf("turn: %d\n", turn);
		printf("score: %d\n", high[11].score);
		printf("Okay what was the order?(Use w,a,s,d)\n");
		
		if(1){
			for(int i = 0; i<roundNum; i++){
			printf("\n%d time:", i+1);
			scanf("%c", &userInput);
			scanf("%c", &userInput);


			if( userInput == 'w'){
				x = 0;
			}
			if( userInput == 'a'){
				x = 1;
			}
			if( userInput == 's'){
				x = 3;
			}
			if( userInput == 'd'){
				x = 2;
			}
			if( x == shapeSelector[i]){
				scoreU = scoreU + 1;
			}
			printf("score: %d\n", scoreU); //score goes here so it updates and then print

			if( x != shapeSelector[i]){
				endGame = 1;
				printf("Incorrect, the correct answer is %c\n", Ans[i]);
				break;
			}
		
		}
		}
	roundNum++;
	turn++;
	}while(endGame != 1);
}
	if(endGame == 1)
		high[11].score = scoreU;
	
	for(int i = 0; i<10; i++){
			if(min > high[i].score){
				min = high[i].score;
			}
		}
	
	printf("%d", min);
		if(high[11].score > min){
			printf("sorry you lose, you got to round %d\nYour final score was %d. Try again and get even higher!", roundNum, scoreU); 
			printf("You Made it on the High Score table.\nEnter User Name(3-Words, All CAPS): ");
			scanf("%s", high[11].name);
	for(i = 0; i<10; i++){
		if(high[11].score > high[i].score){
			tempScore = high[i].score;
			strcpy(tempName,high[i].name);
			high[i].score = high[11].score;
			strcpy(high[i].name, high[11].name);
			high[11].score = tempScore;
			strcpy(high[11].name,tempName);
		}
	}
	
	fp = fopen("scoreboard.txt", "w");
	for(int i = 0; i<10; i++){
		fprintf(fp,"%d %d %s\n", i+1 ,high[i].score, high[i].name);
		}
	fclose(fp);
	
	fp = fopen("scoreboard.txt", "r");
	for(int i = 0; i<10; i++){
	fscanf(fp,"%d %d %s \n", &high[i].rank, &high[i].score, high[i].name);
	}
		for(int i = 0; i<10; i++){
	fscanf(fp,"%d %d %s \n", &high[i].rank, &high[i].score, high[i].name);
	}
	
	for(int i = 0; i<10; i++){
	printf("%d %d %s \n", i+1, high[i].score, high[i].name );
		}
	fclose(fp);
		}
		else{
			printf("sorry you lose, you got to round %d\nYour final score was %d. Try again and get even higher!", roundNum-1, scoreU); 
	}
	
	
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////

void printTriangle(){
	printf("                        * * * * * * * * *                   \n"//Triangle

        "                        *       ^       *                   \n"

        "                        *      ^^^      *                   \n"

        "                        *     ^^^^^     *                   \n"

        "                        *    ^^^^^^^    *                   \n"

        "                        *   ^^^^^^^^^   *                   \n"

        "                        * * * * * * * * *                   \n"

        "                                                            \n"

        "              HHHHHHH                        OO             \n"

        "              H     H                       O  O            \n"

        "              H     H                      O    O           \n"

        "              H     H                     O      O          \n"

        "              H     H                     O      O          \n"

        "              H     H                      O    O           \n"

        "              HHHHHHH                       O  O            \n"

        "                                             OO             \n"

        "                                                            \n"

        "                                                            \n"

        "                            X     X                         \n"

        "                             X   X                          \n"

        "                              X X                           \n"

        "                               X                            \n"

        "                              X X                           \n"

        "                             X   X                          \n"

        "                            X     X                         \n\n\n\n\n\n\n\n");
}

void printSquare(){
	 printf("                               ^                        \n"//Square

            "                              ^^^                       \n"

            "                             ^^^^^                      \n"

            "                            ^^^^^^^                     \n"

            "                           ^^^^^^^^^                    \n"

            "                                                        \n"

            "           * * * * * * * *                                      \n"

            "           *             *                                \n"

            "           *   HHHHHHH   *                     OO         \n"

            "           *   H     H   *                    O  O        \n"

            "           *   H     H   *                   O    O       \n"

            "           *   H     H   *                  O      O      \n"

            "           *   H     H   *                  O      O      \n"

            "           *   H     H   *                   O    O       \n"

            "           *   HHHHHHH   *                    O  O        \n"

            "           *             *                     OO         \n"

            "           * * * * * * * *                                             \n"

            "                                                        \n"

            "                            X     X                     \n"

            "                             X   X                      \n"

            "                              X X                       \n"

            "                               X                        \n"

            "                              X X                       \n"

            "                             X   X                      \n"

            "                            X     X                     \n\n\n\n\n\n\n\n");
}

void printCircle(){
	printf("                               ^                        \n"//Circle

        "                              ^^^                       \n"

        "                             ^^^^^                      \n"

        "                            ^^^^^^^                     \n"

        "                           ^^^^^^^^^                    \n"

        "                                                        \n"

        "                                          * * * * * *           \n"

        "              HHHHHHH                   *     OO     *    \n"

        "              H     H                   *    O  O    *    \n"

        "              H     H                   *   O    O   *    \n"

        "              H     H                   *  O      O  *    \n"

        "              H     H                   *  O      O  *    \n"

        "              H     H                   *   O    O   *    \n"

        "              HHHHHHH                   *    O  O    *    \n"

        "                                        *     OO     *    \n"

        "                                          * * * * * *     \n"

        "                                                        \n"

        "                            X     X                     \n"

        "                             X   X                      \n"

        "                              X X                       \n"

        "                               X                        \n"

        "                              X X                       \n"

        "                             X   X                      \n"

        "                            X     X                     \n\n\n\n\n\n\n\n");
}

void printX(){
	printf("                               ^                        \n"//X_Button

        "                              ^^^                       \n"

        "                             ^^^^^                      \n"

        "                            ^^^^^^^                     \n"

        "                           ^^^^^^^^^                    \n"

        "                                                        \n"

        "                                                        \n"

        "              HHHHHHH                        OO         \n"

        "              H     H                       O  O        \n"

        "              H     H                      O    O       \n"

        "              H     H                     O      O      \n"

        "              H     H                     O      O      \n"

        "              H     H                      O    O       \n"

        "              HHHHHHH                       O  O        \n"

        "                                             OO         \n"

        "                                                        \n"

        "                        * * * * * * * * *                               \n"

        "                        *    X     X    *                  \n"

        "                        *     X   X     *                  \n"

        "                        *      X X      *                  \n"

        "                        *       X       *                  \n"

        "                        *      X X      *                  \n"

        "                        *     X   X     *                  \n"

        "                        *    X     X    *                  \n"

        "                        * * * * * * * * *                  \n\n\n\n\n\n\n\n");
}