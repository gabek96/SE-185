#include<stdio.h>

int main(){
	int N; //Size of the array
	int i; //loop variable
	
	//ask user to enter array size
	printf("Enter array size: ");
	scanf("%d",&N);
	
	int scores[N];//array declaration
	
	//initializing array elements
	for(i=0; i<N; i++){
		printf("Enter number [%d]: ", i );
		scanf("%d", &scores[i]);
	}
	
	//printing array
	printf("\n.....Printing array......\n");
	for(i=0; i<N; i++){
		printf("Element [%d]= %d\n", i, scores[i] );
	}

	//find maximum
	int max=scores[0];
	for(i=0; i<N; i++){
		if(scores[i]>max){
			max=scores[i];
		}
	}
	printf("\nThe maximum value= %d", max);
	
	return 0;
}