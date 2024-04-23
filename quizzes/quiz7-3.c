#include<stdio.h>

void examStat (int grade[], int result[], int class, int class2);

int main(){
int midterm1Score [30];
int result[4];
 for(int i = 0; i<30; i++){
printf("enter score for student %d: ", i+1); 
scanf("%d", &midterm1Score[i]);
 }

examStat (midterm1Score, result, 30, 4);
 printf("the average is: %d\n", result[0]);
printf("the max score is: %d\n", result[1]);
printf("the min score is: %d\n", result[2]);
printf("the number of students who failed is: %d\n", result[3]);
printf("the number of students who got an A is: %d\n", result[4]);

return 0;
}
 
void examStat (int grade[], int result[], int class, int class2){
int avg = 0; 
 int min grade[0];
 int max = grade[0]; 
 int fail = 0;
 int A = 0; 
 
 for(int i = 0; i<class; i++){
avg+= grade[i]; 
if(max<grade[i]){
 max= grade[i]; 
}

if(min > grade[i]){
min = grade[i];
}

 if(grade[i]<60){
fail++;
 }
 
 if(grade[i]>93){
A++;
}

avg /= class;
result[0]= avg; 
result[1] = max;
result[2] = min; 
result[3] = fail;
result[4] = A;
 
 }