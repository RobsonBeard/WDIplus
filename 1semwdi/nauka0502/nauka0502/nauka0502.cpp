#include <stdio.h>
#include <iostream>


// UZYWAM W USTAWIENIACH LINKERA FORCE MULTIPLE BO SIE ZJEBALO NW CZEMU

//#include "naglowki.h"
//#include "moje_funkcje.cpp"

#define MAXLINE 10
#define MAX 10

#define COLS 5
#define ROWS 4

//int main()
//{
//    // --------------------------
//
//    /*int tab[MAX] = {};
//    initTab(tab, MAX);
//    printTab(tab, MAX);
//    printf("\n\n");
//
//    OdwracanieMoje(tab, MAX);
//    printTab(tab, MAX);
//    printf("\n\n");*/
//
//    // -----------------------------
//
//    //printf("\n%d",nPoK(7,5));
//   
//    // ----------------------------
//
//    //printf("%.2lf",Pow(2,-3));
//
//    // -------------------------------
//
//   
//    // alg laczenia ciagow (wstêpnie niemalej¹cych)
//    //#define N 10
//    //#define M 20
//    //#define W ((N)+(M))
//
//    //int a[N];
//    //int b[M];
//    //int c[W];
//
//    //initTab(a, N);
//    //initTab(b, M);
//    //simpleInsertionSort(a, N);
//    //simpleInsertionSort(b, M);
//
//
//    //// czêœæ g³ówna!
//
//    //int i = 0;
//    //int j = 0;
//    //int k = 0;
//
//    //while((i < N) && (j < M))
//    //{
//    //    if(a[i] <= b[j])
//    //        c[k++] = a[i++];
//    //    else
//    //        c[k++] = b[j++];
//    //}
//    //while(i < N)
//    //    c[k++] = a[i++];
//    //while(j < M)
//    //    c[k++] = b[j++];
//
//    //printf("Tab a: \n");
//    //printTab(a, N);
//    //printf("\n\n");
//    //printf("Tab b: \n");
//    //printTab(b, M);
//    //printf("\n\n");
//    //printf("Tab c: \n");
//    //printTab(c, W);
//
//    // -------------------------
//    
//    //int tab[MAX] = {};
//    //initTab(tab, MAX);
//    //printTab(tab, MAX);
//    //printf("\n");
//    //printf("Max modulu roznicy: %d", MaxModulRoznicy(tab,MAX));
//
//    // -------------------------
//
//
//    return 0;
//}

double Pow(int x, int y) {
    if(!y) return 1; // czyli gdy wykladnik to 0
    int minus = 0;
    if(y < 0) {
        minus = 1;
        y = -y;
    }
    double res = x;
    for(int i = 1; i < y; i++)
    {
        res *= x;
    }

    if(minus) res = 1. / res;

    return res;
}

void Odwracanie(int t[], int nSize)
{
    int j;
    for(int i = 0; i < (nSize / 2); i++)
    {
        j = t[i];
        t[i] = t[(nSize - 1) - i];
        t[(nSize - 1) - i] = j;
    }
}

void OdwracanieMoje(int t[], int nSize) {
    int r = nSize - 1;
    int l = 0;
    int temp;
    while(l < r) {
        temp = t[l];
        t[l] = t[r];
        t[r] = temp;

        //printf("%d %d ", l, r); // git
        r--;
        l++;
    }
}

int nPoK(int n, int k) {
    int res = 1;

    if(n == k || n == 0 || k == 0) return res;

    if(k > n) {
        /* int temp = k;
         k = n;
         n = temp;*/
        return -1;
    }

    if(k == 1 || k == (n - 1)) return n;


    if((n - k) > k) k = n - k;
    int roz = n - k;

    for(int i = 1;i <= roz;i++) {
        res *= ++k;
        printf("%d %d ", i, k);
        res /= i;
    }

    return res;
}

int MaxModulRoznicy(int t[], int nSize)
{
    // nie da sie tego inaczej ni¿ kwadratowo?

    int max = abs(t[0] - t[1]);
    for(int i = 0; i < nSize; i++)
    {
        for(int j = i; j < nSize - 1; j++)
        {
            if(abs(t[j] - t[j + 1]) > max)
            {
                max = abs(t[j] - t[j + 1]);
            }
        }
    }
    return max;
}




void initTab(double t[], int nSize) {
    srand((unsigned)time(NULL)); // inicjuje generator liczb pseudolosowych
    for(int i = 0;i < nSize;i++) {
        t[i] = rand() % nSize; // rand daje duze liczby, w ten sposób je zmniejszam
    }
}

void printTab(double t[], int nSize) {
    for(int i = 0;i < nSize;i++) {
        printf("%.2lf ", t[i]);
        if((i + 1) % MAXLINE == 0) printf("\n");
    }
}

void initTab2D(double t[][COLS], int nRows, int nCols) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            t[i][j] = rand() % (nRows * nCols);
        }
    }
}

void printTab2D(double t[][COLS], int nRows, int nCols) {
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0;j < nCols;j++) {
            printf("%.2lf ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
