/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- 	Section:
-	NetID:
-	Date:
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED

/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);


/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
double roll(double x_mag);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleRadsForScreen(double rad);
double pitch(double y_mag);
/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                     /* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */
	
	do
	{
		 /* Scan a line of input */
		scanf("%lf, %lf, %lf, %d, %d, %d, %d", &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left);
		
		
	/* Calculate and scale for pitch AND roll AND joystick */
		if(type == 0){
			roll_rad = roll(x);
		}else{
			pitch_rad = pitch(y);
		}

		// switch between roll and pitch(up vs. down button) (DONE)
		if(b_Up == 1){
			type = 0;
		}else if(b_Down == 1){
			type = 1;
		}
		
		// Scale your output value (DONE?)
		if(type == 0){
			scaled_value = scaleRadsForScreen(roll_rad);
		}else{
			scaled_value = scaleRadsForScreen(pitch_rad);
		}
		
		
		graph_line(scaled_value);

		fflush(stdout);
		/* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
	} while (b_Left == 0); // Modify to stop when left button is pressed
	return 0;
}

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C) {
	scanf("%lf %lf %lf %d %d %d %d %d", &g_x, &g_y, &g_z, &time, &Button_T, &Button_X, &Button_S, &Button_C);
	if(Button_C == 0){
		return 0;
	}else{
		return 1;
	}
}

double roll(double x_mag) {
	if(x_mag <= -1){
		x_mag = -1;
	}else if(x_mag >= 1){
		x_mag = 1;
	}
	return asin(x_mag);
}

double pitch(double y_mag) {
	if(y_mag <= -1){
		y_mag = -1;
	}else if(y_mag >= 1){
		y_mag = 1;
	}
	return asin(y_mag);
}

int scaleRadsForScreen(double rad) {
	return (rad * 39) / (PI / 2) ;
}

void print_chars(int num, char use) {
	if(num == 0){
		printf("%40c\n", use);
	}else if(num > 0){
		printf("%40c", use);
		for(int i = 0; i < num - 1; ++i){
			printf("%c", use);
		}
		printf("\n");
	}else{
        if(num == -1){
            printf("%40c", use);
        }else{
			int col = 41 + num;
			printf("%*c", col, use);
            for(int j = col; j < 40; ++j){
				printf("%c", use);
			}
		}
		printf("\n");
	}
}

void graph_line(int number) {
	if(number == 0){
		print_chars(number, '0');
	}else if(number > 0){
		print_chars(number, 'r');
	}else if(number < 0){
		print_chars(number, 'l');
	}
	
}