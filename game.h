#define ROW 9
#define COLUMN 9
#define ROWS ROW+2
#define COLS COLUMN+2
#define MINE 10
#include <stdlib.h>
#include<time.h>
#include<stdio.h>

void initBoard(char[][COLUMN+2], int, int,char );
void SetMine(char[][COLUMN + 2], int, int);
void displayBoard(char[][COLUMN + 2], int, int);
int findMine(int ,int ,char[][COLUMN + 2], char[][COLUMN + 2], int, int,int*);
