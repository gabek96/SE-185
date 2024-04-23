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

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int main(int argc, char* argv[]) {
	int time, triangle, circle, x_button, square, left_joy, right_joy; //controlller functions
	int r1, r2, l1, l2, b_up, b_down, b_left, b_right, opt, shr;
	char* wordlist[MAXWORDS];
	int count;//words from the text file 
	int i, j, n;
	int timer = 200;// Time limit for button presses
	char str[WORDLENGTH];
	int d = 0; // Row position of the cursor
    int r = 0; // Column position of the cursor
	int table = 0;
	char spaces[50];
	int appendPlace = 0; // Position for appending words to the output string
    int strLen = 0; // Length of the last appended word
    int track = 0;
    int arr[100]; // Array for tracking the lengths of appended words
    arr[0] = 0;
    n = 0;
	
	initscr();
	// Read the words from the text file
	count = read_words(wordlist, argv[1]);
	strcpy(wordlist[0], "the");

	if (DEBUGM) {
		printf("Read %d words from %s \n", count, argv[1]);
		for (i = 0; i < count; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library 
	 // Set the spaces string to a space character
	strcpy(spaces, " ");
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 15; j++) {
			mvprintw(j, i * 12, "%s", wordlist[table]);
			table++;
			refresh();
		}
	}
	



	do {
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &triangle, &circle, &x_button, &square, &right_joy, &left_joy, &opt, &shr, &r2, &l2, &r1, &l1, &b_up, &b_left, &b_down, &b_right);
		 // Check if the time limit has passed
		if (time >= timer) {
			 // Move the cursor right if the right button is pressed
			if (b_right == 1 && r < 4) {
				mvprintw(d, 5 + (13 * r), "%c", ' ');
				r++;
				n = n + 15;
				timer = time + 200;
			}
			if (b_left == 1 && r > 0) {
				mvprintw(d, 5 + (13 * r), "%c", ' ');
				r--;
				n = n - 15;
				timer = time + 200;
			}
			if (b_down == 1 && d < 14) {
				mvprintw(d, 5 + (13 * r), "%c", ' ');
				n++;
				d++;
				timer = time + 200;
			}
			if (b_up == 1 && d > 0) {
				mvprintw(d, 5 + (13 * r), "%c", ' ');
				d--;
				n--;
				timer = time + 200;
			}
			
			
			
			if (triangle == 1) {
				mvprintw(20, appendPlace, "%s", wordlist[n]);
				strLen = 1 + strlen(wordlist[n]);
				appendPlace = appendPlace + strLen;
				track++;
				arr[track] = strLen;
				timer = time + 200;
			}
			if (square == 1) {
				mvprintw(20, appendPlace, "%s", wordlist[n]);
				strLen = strlen(wordlist[n]);
				appendPlace = appendPlace + strLen;
				track++;
				arr[track] = strLen;
				timer = time + 200;
			}
			if (x_button == 1) {
				appendPlace = appendPlace - strLen;
				track--;
				strLen = arr[track];
				if (appendPlace < 0) {
					appendPlace = 0;
				}
				mvprintw(20, appendPlace, "           ", wordlist);
				timer = time + 200;
			}
			
			
			
			if (r2 == 1 || l2 == 1) {
				mvprintw(20, 0, "                                                                               ", wordlist);
				appendPlace = 0;
				track = 0;
			}
			if (opt == 1 || shr == 1) {
				endwin();
				return 0;
			}
		}
		
		
		mvprintw(d, 5 + (13 * r), "%c", '*');
		refresh();
		
		
	} while (1);


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
