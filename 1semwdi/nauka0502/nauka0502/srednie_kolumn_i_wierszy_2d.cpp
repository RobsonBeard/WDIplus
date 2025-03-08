#include <stdio.h>
#include "moje_funkcje.cpp"

#define AW 3
#define AK 4

#define CW 4
#define CK 3

//int main()
//{
//    // SREDNIE KOLUMN TABLICY 2-WYMIAROWEJ
//
//    int a[AW][AK] = { 0 };
//    double b[AK] = { 0 };
//
//    initTab2D(a, AW, AK);
//    printTab2D(a, AW, AK);
//
//    for(int i = 0; i < AK; i++)
//    {
//        for(int j = 0; j < AW; j++)
//            b[i] += a[j][i];
//
//        b[i] /= AW;
//    }
//
//    printTab(b, AK);
//    printf("\n\n");
//
//
//    // SREDNIE WIERSZY TABLICY 2-WYMIAROWEJ
//
//    int c[CW][CK] = {};
//    double d[CW] = {};
//
//    initTab2D(c, CW, CK);
//    printTab2D(c, CW, CK);
//
//    for(int i = 0; i < CW; i++)
//    {
//        for(int j = 0; j < CK; j++)
//            d[i] += c[i][j];
//
//        d[i] /= CK;
//    }
//
//    printTab(d, CW);
//    printf("\n\n");
//
//    return 0;
//}
