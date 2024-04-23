/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Gabe Kiveu
- 	Section: 1
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

/* NO GLOBAL VARIABLES ALLOWED */

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
int read_input(int *time, double *g_x, double *g_y, double *g_z, int *button_T, int *button_C, int *button_X, int *button_S, int *l_joy_x, int *l_joy_y, int *r_joy_x, int *r_joy_y);

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                    /* Values of x, y, and z axis*/
    int t;                             /* Variable to hold the time value */
    int Up, Down, Left, Right; /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;        /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll;     /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                    /* Value of joystick adjusted to fit screen display */
	int p;
    /* Put pre-loop preparation code here */
    int number;
    do
    {
        read_input(&t, &x, &y, &z, &Up, &Right, &Down, &Left, &j_LX, &j_LY, &j_RX, &j_RY);
        /* Scan a line of input */
        scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &Up, &Right, &Down, &Left, &j_LX, &j_LY, &j_RX, &j_RY);
        /* Calculate and scale for pitch AND roll AND joystick */
        if (Up == 1)
        {
            p = 1;
        }
        if (Right == 1)
        {
            p = 2;
        }
        if (Down == 1)
        {
            p = 3;
        }
        if (Left == 1)
        {
            p = 4;
        }
        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
        if (p == 1)
        {
            number = scaleMagForScreen(x);
        }
        if (p == 2)
        {
            number = scaleMagForScreen(y);
        }
        if (p == 3)
        {
            number = scaleMagForScreen(z);
        }
        if (p == 4)
        {
            number = scaleJoyForScreen(j_LX);
        }
        /* Output your graph line */
        graph_line(number);
        fflush(stdout);

    } while (!Down); /* Modify to stop when left button is pressed */
    while (Up == 0)
    {
        scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &Up, &Right, &Down, &Left, &j_LX, &j_LY, &j_RX, &j_RY);
    }
    return 0;
}
int read_input(int *time, double *g_x, double *g_y, double *g_z, int *button_T, int *button_C, int *button_X, int *button_S, int *l_joy_x, int *l_joy_y, int *r_joy_x, int *r_joy_y)
{	int j_LX;
    int buttonPress;
    scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &time, &g_x, &g_y, &g_z, &button_T, &button_C, &button_X, &button_S, &l_joy_x, &l_joy_y, &r_joy_x, &r_joy_y);

    if ( j_LX == 1)
    {
        buttonPress = 1;
    }
    else
    {
        buttonPress = 0;
    }
    return buttonPress;
}
int scaleMagForScreen(double rad)
{
    if (rad < -1)
    {
        rad = -1;
        return rad;
    }
    else if (rad > 1)
    {
        rad = 1;
        return rad;
    }

    return rad * 39;
}
int scaleJoyForScreen(int rad)
{
    /*int joyScale;
    if ((rad >= -128) && (rad <= 127))
    {
        joyScale = rad;
    }
    else if (rad < -128)
    {
        rad = (-39 / -128);
        joyScale = rad;
    }
    else if (rad > 128)
    {
        rad = (39 / 128);
        joyScale = 39;
    }
    return joyScale; */

	return rad * (39.0 / 128.0);
}
void print_chars(int num, char use)
{
    int i;
    for (i = 0; i < num; ++i)
    {
        printf("%c", use);
    }
}
void graph_line(int number)
{
    if (number > 0)
    {
        print_chars(39, ' ');
        print_chars(number, 'r');
        print_chars(1, '\n');
    }
    else if (number < 0)
    {
        print_chars(39 + number, ' ');
        print_chars(number * -1, 'l');
        print_chars(1, '\n');
    }
    else if (number == 0)
    {
        print_chars(39, ' ');
        print_chars(1, '0');
        print_chars(1, '\n');
    }
}
