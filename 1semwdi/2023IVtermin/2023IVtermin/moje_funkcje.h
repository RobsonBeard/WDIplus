#ifndef MOJE_FUNKCJE_H
#define MOJE_FUNKCJE_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define NROW 5
#define NCOL 10
#define MAXLINE 10

void initTab2D(int t[][NCOL], int nRows, int nCols);
void printTab2D(int t[][NCOL], int nRows, int nCols);
int myStrlen(char str[]);
void printTab(int t[], int nSize);
void initTab(int t[], int nSize);
void printTab(double t[], int nSize);

#endif