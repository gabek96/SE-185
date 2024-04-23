#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdio.h>
int main (){
	int studs[4][2];
	int  i; 
	int  j;
	double avg, avg2;
	char stdgrade1, stdgrade2;
	double grades[4][2];
	
	for( i = 1; i < 3; i++){
		for( j = 1; j < 5; j++){
		printf("Student - %d Asssignment- %d grades ", i, j);
		scanf("%d", &stdgrade1);
		
		if (i == 1){
			avg += grades[i][j];	
		}
		else if(i == 1){
			avg += grades[i][j];
		}
	}
	
}
	
	avg /= 4;
	avg2 /= 4;
	
	if(avg >= 85){
		stdgrade1 = 'A';
	}
	
	else if(avg >= 75){
		stdgrade1 = 'B';
	}
	else if (avg >= 60){
		stdgrade1 = 'C';
	}
	
	else if(avg >= 60){
		stdgrade1 = 'C';
	}
	
	else{
		stdgrade1 = 'F';
	}
	
	if(avg2 >= 85){
		stdgrade2 = 'A';
	}
	
	else if(avg2 >= 75){
		stdgrade2 = 'B';
	}
	else if (avg2 >= 60){
		stdgrade2 = 'C';
	}
	
	else if(avg2 >= 60){
		stdgrade2 = 'C';
	}
	
	else{
		stdgrade2 = 'F';
	}
	
	printf("\nStudent 1 Avg = %.2lf\n", avg);
	printf("\nStudent 1 Grade = %c\n", stdgrade1);
	printf("\nStudent 2 Avg = %.2lf\n", avg2);
	printf("\nStudent 2 Grade = %c\n", stdgrade2);
	
	return 0;
}