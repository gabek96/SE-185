#include<stdio.h>
#include<stdlib.h>

typedef struct time {
	int hour;
	int min;
	int sec;
}time;

void convertTime(int num);
void printTime(int num);

void main() {
	time *mileTime;
	mileTime = (int*)malloc(5 * sizeof(int));
	
	int seconds;
	printf("Total seconds: ");
	scanf("%d", &seconds);
	
	convertTime(seconds);
	printTime(seconds);
}

void convertTime(int num){
int hour = 0;
int min = 0;
 int sec = 0;

hour = hour + num / 3600;
min = min + num / 60;
min = min - 60;
sec = sec + num % 60;	
}

void printTime(int num){
int hour = 0;
int min = 0;
 int sec = 0;

hour = hour + num / 3600;
min = min + num / 60;
min = min - 60;
sec = sec + num % 60;	

printf("hour %d ", hour);
printf("min %d ", min);
printf("sec %d ", sec);
}

