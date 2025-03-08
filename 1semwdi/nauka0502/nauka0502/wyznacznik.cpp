#include <stdio.h>
#include "moje_funkcje.cpp"
#define AW 3
#define BK 5

//int main()
//{
//    if(AW != 3) return -1;
//
//    int a[AW][AW] = {};
//    int b[AW][BK] = {};
//
//    initTab2D(a, AW, AW);
//
//    for(int i = 0; i < AW; i++)
//    {
//        for(int j = 0; j < BK; j++)
//        {
//            b[i][j] = a[i][j % 3]; // dopisuje dwie kolumny po prawej stronie tak jakby, zeby liczyc sarusa normalnie z iloczynu takiej niby przekatnej
//        }
//    }
//
//    printTab2D(a, AW, AW);
//    printTab2D(b, AW, BK);
//
//    int w = 0;
//    for(int k = 0; k < AW; k++)
//    {
//        int j = 0;
//        int iloczyn = 1;
//        int iloczyn1 = 1;
//
//        for(int i = 0; i < AW; i++)
//        {
//            iloczyn *= b[i][(k + j) % 3];
//            iloczyn1 *= b[i][(5 + k - j) % 3];
//            j++;
//        }
//
//        w = w + iloczyn - iloczyn1;
//    }
//
//
//    int w2 = (a[0][0] * a[1][1] * a[2][2])
//        + (a[1][0] * a[2][1] * a[0][2])
//        + (a[2][0] * a[0][1] * a[1][2])
//        - (a[0][2] * a[1][1] * a[2][0])
//        - (a[1][2] * a[2][1] * a[0][0])
//        - (a[2][2] * a[0][1] * a[1][0]);
//
//    printf("Wyznacznik: %d lub %d", w,w2);
//
//    return 0;
//}
