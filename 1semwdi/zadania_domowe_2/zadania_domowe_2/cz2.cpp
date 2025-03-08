#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXVEC1 10
#define MAXVEC2 10

void initVec(int v[], int nSize);
void printVec(int v[], int nSize);

void vectorSum(int v1[], int v2[],int v3[], int nSize);

/*
int main() {

    // SUMA WEKTOROW

    if(MAXVEC1 != MAXVEC2) {
        printf("Wektory z roznych przestrzeni wektorowych!\n");
        return 1; // wazne, zeby wyjsc z kodem innym niz 0
    }

    int v1[MAXVEC1] = { 0 };
    int v2[MAXVEC2] = { 0 };
    int v3[MAXVEC1] = { 0 };

    printf("v1= ");
    initVec(v1, MAXVEC1);
    printVec(v1, MAXVEC1);
    printf("\nv2= ");
    initVec(v2, MAXVEC2);
    printVec(v2, MAXVEC2);
    printf("\n");

    printf("Suma wektorow wynosi: \nv3= ");
    vectorSum(v1,v2,v3,MAXVEC1);
    printVec(v3, MAXVEC1);

	return 0;
}
*/

void vectorSum(int v1[], int v2[],int v3[], int nSize) {
    for(int i = 0; i < nSize; i++)
    {
        v3[i]=v1[i]+v2[i];
    }
}

void wait(clock_t ilosc) {
    clock_t t = clock() + ilosc;
    while(clock() < t);
}

void initVec(int v[], int nSize) {
    wait(2);
    srand((unsigned)clock()); 
    for(int i = 0;i < nSize;i++) {
        v[i] = rand() % nSize - nSize / 2; 
    }
}
void printVec(int v[], int nSize) {
    printf("[");
    for(int i = 0;i < nSize;i++) {
        printf("%d", v[i]);
        if(i < nSize - 1) {
            printf(", ");
        }
    }
    printf("]");
}