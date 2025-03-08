#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

#define MAXVEC1 10
#define MAXVEC2 10

void initVec(int v[], int nSize);
void printVec(int v[], int nSize);

int scalarMult(int v1[], int v2[], int nSize);
void wait(clock_t ilosc);

int main()
{
    // Iloczyn skalarny

    // DOM: SREDNIA ARYTMETYCZNA NIEPARZYSTYCH (pamietac zeby nie dzielic przez 0)
    // DRUGIE MINIMUM
    // SUMA WEKTOROW
    // ROZKLAD NA CZYNNIKI PROSTE (petla w petli, wyswietlic te czynniki)


    int v1[MAXVEC1] = { 0 };
    int v2[MAXVEC2] = { 0 };
    
    printf("v1= ");
    initVec(v1, MAXVEC1);
    printVec(v1, MAXVEC1);
    printf("\nv2= ");
    initVec(v2, MAXVEC2);
    // one sa takie same, bo srand bierze czas w sekundach, komputer dziala po prostu za szybko
    // przerobilismy time na clock
    printVec(v2, MAXVEC2);

    if(MAXVEC1 != MAXVEC2) {
        printf("Wektory z roznych przestrzeni wektorowych!\n");
        return 1; // wazne, zeby wyjsc z kodem innym niz 0
    }

    printf("\n\nIloczyn skalarny = %d\n", scalarMult(v1,v2,MAXVEC1));

    return 0;
}

int scalarMult(int v1[], int v2[], int nSize) {
    int sum = 0;
    for(int i = 0; i < nSize; i++)
    {
        sum += v1[i] * v2[i];
    }
    return sum;
}

void wait(clock_t ilosc) {
    clock_t t = clock()+ilosc;// moze byc int lub long zamiast clock_t
    while(clock() < t); // krece sie przez 2ms
}

void initVec(int v[], int nSize) {
    //srand((unsigned)time(NULL));  // ewentualnie przeniesc to do maina?
    //wait((clock_t)CLOCKS_PER_SEC); // taka jest druga opcja dla time
    wait(2);
    srand((unsigned)clock() ); // ALE TERAZ SA TE SAME TABLICE
    for(int i = 0;i < nSize;i++) {
        v[i] = rand() % nSize - nSize/2; // tutaj bede mial ujemne i dodatnie wartosci
    }
}
void printVec(int v[], int nSize) {
    printf("[");
    for(int i = 0;i < nSize;i++) {
        printf("%d", v[i]);
        if(i < nSize - 1) {
            printf(", ");
        }
        //if((i + 1) % MAXLINE == 0) printf("\n");
    }
    printf("]");
}