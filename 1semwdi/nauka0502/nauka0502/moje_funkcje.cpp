#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 10
#define MAX 10

#define COLS 5
#define ROWS 4

#define AW 7
#define AK 8
#define BW 8
#define BK 6

double Pow(int x, int y);
void initTab(int t[], int nSize);
void initTab(double t[], int nSize);
void printTab(int t[], int nSize);
void printTab(double t[], int nSize);
void Odwracanie(int t[], int nSize);
void OdwracanieMoje(int t[], int nSize);
int nPoK(int n, int k);
void simpleInsertionSort(int t[], int nSize);
void printTab2D(double t[][COLS], int nRows, int nCols);
void printTab2D(int t[][COLS], int nRows, int nCols);
void initTab2D(int t[][COLS], int nRows, int nCols);
void initTab2D(double t[][COLS], int nRows, int nCols);
int MaxModulRoznicy(int t[], int nSize);
void initTab2D(int t[][AK], int nRows, int nCols);
void printTab2D(int t[][AK], int nRows, int nCols);
void initTab2D(int t[][BK], int nRows, int nCols);
void printTab2D(int t[][BK], int nRows, int nCols);


void initTab(int t[], int nSize) {
    srand((unsigned)time(NULL)); // inicjuje generator liczb pseudolosowych
    for(int i = 0;i < nSize;i++) {
        t[i] = rand() % nSize; // rand daje duze liczby, w ten sposób je zmniejszam
    }
}

void printTab(int t[], int nSize) {
    for(int i = 0;i < nSize;i++) {
        printf("%d ", t[i]);
        if((i + 1) % MAXLINE == 0) printf("\n");
    }
}


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
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void simpleInsertionSort(int t[], int nSize) {
    for(int i = 0; i < nSize; i++)
    {
        int x = t[i];
        int j = i - 1; // indeks na lewo
        while(t[j] > x) {
            t[j + 1] = t[j];
            j--;
            // albo t[j+1] = t[j--]
        }
        t[j + 1] = x;
    }
}

void initTab2D(int t[][AK], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}

void printTab2D(int t[][AK], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void initTab2D(int t[][BK], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}

void printTab2D(int t[][BK], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void initTab2D(int t[][3], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}

void printTab2D(int t[][3], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void initTab2D(int t[][4], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}

void printTab2D(int t[][4], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}