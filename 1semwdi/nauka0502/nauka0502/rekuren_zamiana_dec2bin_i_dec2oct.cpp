#include <stdio.h>
#include "moje_funkcje.cpp"
#include <iostream>

void mojebin(int n);
void mojeoct(int n);

using namespace std;

//int main()
//{
//    int x;
//
//    printf("Podaj liczbe: ");
//    cin >> x;
//
//    mojebin(x);
//
//    printf("\n");
//
//    mojeoct(x);
//
//    printf("\n");
//
//    return 0;
//}

void mojebin(int n)
{
    int reszta = n % 2;
    if(n > 1) mojebin(n / 2);
    printf("%d", reszta);
    return;
}

void mojeoct(int n)
{
    int reszta = n % 8;
    if(n > 7) mojeoct(n / 8);
    printf("%d  ", reszta);
    return;
}