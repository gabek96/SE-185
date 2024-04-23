#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
int main(){
	FILE *file = NULL;
	file = fopen("student_data","w");
	char names[4][50];
	double score1[3];
	double score2[3];
 	double score3[3];
	double score4[3];
	
	double average1;
	double average2;
	double average3;
	double average4;
	double sum1, sum2, sum3;
	
	printf("Enter student1 name and three exam scores: ");
	scanf("%s %lf %lf %lf", &names[0], &score1[0], &score1[1], &score1[2]);
	printf("Enter student2 name and three exam scores: ");
	scanf("%s %lf %lf %lf", &names[1], &score2[0], &score2[1], &score2[2]);
	printf("Enter student3 name and three exam scores: ");
	scanf("%s %lf %lf %lf", &names[2], &score3[0], &score3[1], &score3[2]);
	printf("Enter student4 name and three exam scores: ");
	scanf("%s %lf %lf %lf", &names[3], &score4[0], &score4[1], &score4[2]);
	
	fprintf(file, "%s %.2lf %.2lf %.2lf\n", names[0], score1[0], score1[1], score1[2]);
	fprintf(file, "%s %.2lf %.2lf %.2lf\n", names[1], score2[0], score2[1], score2[2]);
	fprintf(file, "%s %.2lf %.2lf %.2lf\n", names[2], score3[0], score3[1], score3[2]);
	fprintf(file, "%s %.2lf %.2lf %.2lf\n", names[3], score4[0], score4[1], score4[2]);
	
	printf("%s exam scores = %.2lf, %.2lf, %.2lf\n", names[0], score1[0], score1[1], score1[2]);
	printf("%s exam scores = %.2lf, %.2lf, %.2lf\n", names[1], score2[0], score2[1], score2[2]);
	printf("%s exam scores = %.2lf, %.2lf, %.2lf\n", names[2], score3[0], score3[1], score3[2]);
	printf("%s exam scores = %.2lf, %.2lf, %.2lf\n", names[3], score4[0], score4[1], score4[2]);
	file = fopen("student_data","r");
	fscanf(file, "%s %lf %lf %lf", &names[0], &sum1, &sum2, &sum3);
	average1 = (sum1 + sum2 + sum3)/3;
	printf("\n%lf\n", average1);
	
	fclose(file);
	return 0;
}