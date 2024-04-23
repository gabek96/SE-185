/*-----------------------------------------------------------------------------
- SE 185 Lab 08
- Developed for 185
- Name: Gabriel Kiveu
- Section:1
- NetID: 
- Date: 
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
- Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
/*-----------------------------------------------------------------------------
- Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159
/* Screen geometry
 Use ROWS and COLUMNS for the screen height and width (set by system)
 MAXIMUMS */
#define COLUMNS 100
#define ROWS 80
/* Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '
/* Number of samples taken to form an moving average for the gyroscope data
 Feel free to tweak this. */
#define NUM_SAMPLES 1
/*-----------------------------------------------------------------------------
- Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];
/*-----------------------------------------------------------------------------
- Prototypes
-----------------------------------------------------------------------------*/
/* POST: Generates a random maze structure into MAZE[][]
 You will want to use the rand() function and maybe use the output %100.
 You will have to use the argument to the command line to determine how
 difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);
/* PRE: MAZE[][] has been initialized by generate_maze()
 POST: Draws the maze to the screen */
void draw_maze(void);
/* PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
 POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);
/* PRE: -1.0 < mag < 1.0
 POST: Returns tilt magnitude scaled to -1.0 -> 1.0
 You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);
/* Updates the buffer with the new_item and returns the computed
 moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);
/*-----------------------------------------------------------------------------
- Implementation
-----------------------------------------------------------------------------*/
/* Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
 srand(time(NULL));
 
 if (argc != 2 )
 {
 printw("Enter a number between 1-100 on the command line: ");
 refresh();
 return;
 }
 else{
	 
 }
 /* Setup screen for Ncurses
 The initscr functionis used to setup the Ncurses environment
 The refreash function needs to be called to refresh the outputs
 to the screen */
 initscr();
 refresh();
 /* WEEK 2 Generate the Maze */
 int sep;
 sep = atoi(argv[1]);
 generate_maze(sep);
 draw_maze();
 
 /*Read gyroscope data and fill the buffer before continuing */
 int t, a , b, c, d; 
 double x, y, z;
 int max = 700; 
 int temp = 700; 
 int yp = 0; 
 int xp = 50; 
 double mavg = 0; 
 double array[NUM_SAMPLES]; 
 int stop = 0; 
 int ypast =0; 
 int xpast = 50; 
 int win = 0;
 int lose = 0; 
 for (int i = 0; i< NUM_SAMPLES; i++){
 scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &x, &y, &z, &a, &b, &c, &d);
 array[i] = x;
 }
 /*Event Loop*/
 do{
 /* Reading and Updating */
 scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &x, &y, &z, &a, &b, &c, &d);
 lose = t;
 mavg = m_avg(array, NUM_SAMPLES, x);
 if (mavg > .2){
 stop++;
	 if (stop ==10){
	 draw_character(xp, yp, EMPTY_SPACE);
	 xp--;
		 if (MAZE[xp][yp] == WALL){
		 xp = xpast;
		 }
	 xpast = xp;
	 stop = 0;
	}
 }
 if (mavg < -.2){
	stop++;
	 if (stop ==10){
	 draw_character(xp, yp, EMPTY_SPACE);
	 xp++;
		 if (MAZE[xp][yp] == WALL){
		 xp = xpast;
		 }
	 xpast = xp;
	 stop = 0;
	 }
}
 draw_character(xp, yp, AVATAR);
 /* Is it time to move? if so, then move avatar */
 while(1);//Change this to end the game 
 if (t >= temp + max){
	 draw_character(xp, yp, EMPTY_SPACE);
	 yp++;
		 if (MAZE[xp][yp] == WALL){
		 yp = ypast;
		 }
	 temp = t;
	 ypast = yp;
 }
 if (MAZE[xp + 1][yp] == WALL && MAZE[xp - 1][yp] == WALL &&MAZE[xp][yp + 1] == WALL){
	win = 1;
	while (t< lose + 1000){
	scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &x, &y, &z, &a, &b,&c, &d);
	draw_character(xp, yp, AVATAR);
	}
	break;
 }
 
 } while(yp < ROWS); 
 
 /* This function is used to cleanup the Ncurses environment.
 Without it, the characters printed to the screen will persist
 even after the progam terminates */
 endwin();
 if(win == 0){
 printf("You win!\n");
 }
	 else{
	 printf("You lose");
	 }
 }

void draw_maze(void){
 for(int i = 0; i < ROWS; i++){
 for (int j = 0; j < COLUMNS; j++){
 draw_character(j , i, MAZE[j][i]);
 }
 }
}

double m_avg(double buffer[], int avg_size, double new_item){
	 for (int i = avg_size; i > 0; i--){
		buffer[i] = buffer[i-1];
	 }
	 buffer[0] = new_item;
	 double sum = 0;
	 for (int i = 0; i < avg_size; i++){
		sum += buffer[i];
	 }	
 return sum / avg_size;
}
/* PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
 POST: Draws character use to the screen and position x,y
 THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
 DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use){
 mvaddch(y,x,use);
 refresh();
}
void generate_maze(int difficulty){
	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++){
		 int random = rand()%100;
				if (random < difficulty){
					MAZE[j][i] = WALL;
				}
			 
			else{
			 MAZE[j][i] = EMPTY_SPACE;
			}
		}
	}
}

