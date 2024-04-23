#include <stdio.h>

//C code to implement Tower of Hanoi 
int linearSearch(int n[], int X){
	for(int i = 0, i < 7; i++){
		if(n[i] ==X){
			return i;
		}
	}
	return -1;
}
void main(){
	int a[7] = {38, 20, 16, 7, 37, 4, 42}
	int x;
	printf("\n Enter a number to search:");
	scanf("%d",&x);
	int result = linearSearch(a,x);
	if(result == -1)
		printf(\nTHe number not found!!!!");
	else 
		printf("\nFound the Number. a[%d] = %d", result, a[result]);
}

/*void TOH(int n, char a, char c, char b){
		//base case ti move disk n-1 from A->C
		if(n==1){
			printf("\nMove disk 1 from rod %c to rod %c", a, c);
			return;
		}
	//recursive case
	// move n-1 disk A-> B
	TOH(n-1,a,b,c);
	printf("\n Move disk 1 ftom rod %c to rod %c", b, c);
	//move n-1 disk B -> C
	TOH(n-1,b,c,a);
}
void main(){
  int N = 3; // number of disk
  TOH(N,'A','C','B');
}
*/