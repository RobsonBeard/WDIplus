
#include "moje_funkcje.h"


void initTab2D(int t[][NCOL], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}
void printTab2D(int t[][NCOL], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int myStrlen(char str[]) {
    int length = 0;
    while(str[length] != '\0') length++;
    return length;
}

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

void printTab(double t[], int nSize) {
    for(int i = 0;i < nSize;i++) {
        printf("%.2lf ", t[i]);
        if((i + 1) % MAXLINE == 0) printf("\n");
    }
}