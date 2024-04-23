#include<stdio.h>

int main() {
 int num= 5;


int *myptr = &num;

//printf("%d\n", myptr); 9 printf("num is stored at: %p\n",myptr);

//1
printf("myptr is stored at: %p\n",&myptr); 
printf("num holds this value: %d\n", num);
 
printf("myptr holds this value: %d\n", *myptr);

printf("myptr points to this value %d\n", *myptr); return 0;
}