/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int close_to(double tolerance, double point, double  value);
double magnitude(double x, double y, double z);
void direction(double gx, double gy, double gz);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle = 0, circle, x_button, square, t;
    double ax, ay, az, gx, gy, gz;
	int print = 0;



    while (triangle == 0)
    {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t,
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
			  if ( close_to(.25, 0, magnitude(ax,ay,az))) {
				  direction(gx,gy,gz);
			  }
		
/*		if (print == 0 && magnitude(ax,ay,az) <.5){
		
			direction(gx, gy, gz);
			print = 1;
			
			
		}
		else if (magnitude(ax, ay, az) > .5){
			print = 0;
		}
		*/
    }

    return 0;
}
/* Put your functions here, and be sure to put prototypes above. */

double magnitude(double x, double y, double z){
	return sqrt(pow(x,2) + pow(y, 2) + pow(z, 2)); 
}

int close_to(double tolerance, double point, double  value){
		if (fabs(value - point)<= tolerance){
			return 1;
		}
		else{
			return 0;
		}
}

void direction(double x, double y, double z){
//fflush(stdout);
	//printf("test");
	if(close_to(.3, 1, x)==1){
		printf("left\n");
		fflush(stdout);
		
	}
	
	else if(close_to(.3, -1, x)==1){// tracks alignment for controller
		printf("right\n");
		fflush(stdout);
	}
	
	else if(close_to(.3, 1, y)==1){// tracks alignment for controller
		printf("top\n");
		fflush(stdout);
	}
	
	else if(close_to(.3, -1, y)==1){// tracks alignment for controller
		printf("bottom\n");
		fflush(stdout);
	}
	
	else if(close_to(.3, 1, z)==1){// tracks alignment for controller
		printf("front\n");
		fflush(stdout);
	}
	
	else if(close_to(.3, -1, z)==1){// tracks alignment for controller
		printf("back\n");
		fflush(stdout);
	}
}