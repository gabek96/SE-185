// Lab 09 DS4Talker Skeleton Code       
#include <curses.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 0   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);
void draw_character(int x, int y, char use);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];

	int wordcount;
	int up, down, left, right, xbutton, triangle, circle, square; //controlller functions
	*x = right;
	*y = left;
	int i = 0; int row = 1; int col = 1;
	wordcount = read_words(wordlist, argv[1]); //words from the text file 
	
	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
		
	}
	initscr();
	do{
		for( int i = 0; i < wordcount; i++){
		mvprintw( row + 1, col + 1, "%s", wordlist[i]);
			col += 8;
			if (i % 10 == 0){
				
			row += 5;
			col = 0;
			}
			
			refresh();
		}

		scanf("%d, %d, %d, %d, %d, %d, %d, %d,", &up, &down, &left, &right, &xbutton, &triangle, &circle, &square);
		draw_character(x, y, '>');
		
		//want this conditionals to allow me to move around the list 
		if(up > 100){
		draw_character(x,y,'_');
		y++;
		draw_character(x,y,'>');		
		}
		
		else if(down > -90){
		draw_character(x,y,'_');
		x++;
		draw_character(x,y,'>');		
		}
		
		else if(left > -100){
		draw_character(x,y,'_');
		x++;
		draw_character(x,y,'>');		
		}
		
		else if(right > 100){
		draw_character(x,y,'_');
		x++;
		draw_character(x,y,'>');		
		}
		
		
		
	}while(0);
		
	return 0;
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
void draw_character(int x, int y, char use){
	mvaddch(x, y, use);
	refresh();
}