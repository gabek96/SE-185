#include <stdio.h>

double DrivingCost ( double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
	
	double dollarCost = drivenMiles/milesPerGallon*dollarsPerGallon;
	
	return dollarCost;	
}


int main() {
	
double milesPerGallon = 22.3, dollarsPerGallon = 3.1599;

double cost = DrivingCost (10,milesPerGallon,dollarsPerGallon);	
printf(" Enter driven Miles: %0.2lf\n", cost);

cost = DrivingCost(50, milesPerGallon, dollarsPerGallon);
printf(" Enter Miles per Gallon: %0.2lf\n", cost);

cost = DrivingCost(400, milesPerGallon,dollarsPerGallon);
printf(" Drivng cost: %0.2lf\n", cost);

return 0;
}