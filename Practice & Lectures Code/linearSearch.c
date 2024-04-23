#include <stdio.h>

//C code to implement linear search 

//Linear search with iterative function
int bianarySearch(int ptr[], int i, int x){
	//base case
if(H<L)
	return -1;
	int mid = (L+H)/2
	
if(n[mid] == X)
	return mid;

else if(n[mid] < X)
	return bianarySearch(n,mid+1,H,X);

else 
	return bianarySearch(n, 0, mid-1,X);
}
void main(){
	int a[7]= [7]= {38, 20, 16, 7, 37, 4, 43}; //sprted array 
	int x; 
	printf("Enter a number to search:");
	scanf("%d",&x);
	
	int result = bianarySearch(a,0,6,x);
	
	if(sResult == -1)
		printf("Element is not present in the array\n");	
	else 
		printf("Element found in the array: arr[%d]= %d\n", sResult, arr[sResult]);
}
