//#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4


void initTab2D(int t[][COLS], int nRows, int nCols);
void printTab2D(int t[][COLS], int nRows, int nCols);
void trans(int t[][COLS], int nRows, int nCols);

//int main()
//{
//	int tab[ROWS][COLS] = {
//		{1,2,1,3},
//		{8,2,4,1},
//		{4,2},
//		{1,2,3},
//	};
//	printTab2D(tab, ROWS, COLS);
//
//	trans(tab, ROWS, COLS);
//	printTab2D(tab, ROWS, COLS);
//
//
//	return 0;
//}

void initTab2D(int t[][COLS], int nRows, int nCols) {
	srand((unsigned)time(NULL));
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 0;j < nCols;j++) {
			t[i][j] = rand() % (nRows * nCols);
		}
	}
}
void printTab2D(int t[][COLS], int nRows, int nCols) {
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 0;j < nCols;j++) {
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void trans(int t[][COLS], int nRows, int nCols) {
	if(nRows != nCols) {
		printf("ERROR: macierz nie jest kwadratowa\n");
		return;
	}
	for(int i = 0; i < nRows-1; i++)
	{
		for(int j = i + 1;j < nCols;j++) {
			int temp = t[i][j];
			t[i][j] = t[j][i];
			t[j][i] = temp;
		}
	}
}