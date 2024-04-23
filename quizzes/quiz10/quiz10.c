#include <stdio.h>
#include<stdlib.h>
int main() {
	
int rawArray[8] = {12, 7,3,0,28,74,37,299};
int evenArrays[8];	
	
	FILE* wordlist = fopen("numbers.txt", "w");
	
	for(int i = 0; i < 8; i++){
		
	fprintf(wordlist, "%d \n", rawArray[i]);	
			
	}
	
	fclose(wordlist);
	wordlist = fopen("numbers.txt", "r");
	
	for(int i = 0; i < 8; i++){
		fscanf(wordlist,"%d", &evenArrays[i]);
	}
	
	for(int i = 0; i < 8; i++){
		if(evenArrays[i] % 2 == 0){
			printf("%d ", evenArrays[i]);
		}
	}
} 