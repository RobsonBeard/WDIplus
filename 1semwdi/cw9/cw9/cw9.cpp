#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAXLINE 10
#define MAX 50

using namespace std;


void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
int min(int t[], int nSize);

int main()
{
    // zdefiniowac tablice intow (50 elementow)
    // zainicjowac losowo
    // wydrukowac

    // Alg 11. Ile razy liczba k wystepuje w tablicy
    // Alg 10. Suma podzielnych przez k
    // Alg 12. Minimum
    // Alg 14. Odwrocenie elementow
    // Roznica miedzy iloscia parzystych i nieparzystych

    int tab[MAX];

    initTab(tab, MAX);
    printTab(tab, MAX);
    printf("Minimum z tablicy wynosi %d\n", min(tab, MAX));

    int k;
    printf("Podaj liczbe k: \n");
    cin >> k;

    int ileK = 0;
    int podzielnyK = 0;
    int r = 0; // roznica
    //int parz = 0;
    //int niep = 0;
    printf("Podzielne przez %d: ", k);
    for(int i = 0; i < MAX; i++)
    {
        if(tab[i] == k) ileK++;
        if(!(tab[i] % k)) {
            podzielnyK += tab[i];
            printf("%d ", tab[i]);
        }
        if(!(tab[i] % 2)) {
            r++;
            //parz++;
        }
        else {
            r--;
            //niep++;
        }
    }

    printf("\nLiczba %d wystepuje w tablicy %d razy\n",k,ileK);
    printf("Suma liczb podzielnych przez %d wynosi %d\n",k,podzielnyK);
    printf("Roznica miedzy iloscia parzystych i nieparzystych wynosi %d\n",r);
    //printf("parz: %d, niep: %d\n", parz, niep);

    int po = 0;
    int ko = MAX - 1;

    while(po < ko) // for (po=0; po<ko; po++,ko--)
    {
        int temp = tab[po];
        tab[po] = tab[ko];
        tab[ko] = temp;

        po++;
        ko--;

        // mozna tab[po++] i tab[ko--]
        //int temp = tab[po];
        //tab[po++] = tab[ko];
        //tab[ko--] = temp;
    }
    printf("\nTablica odwrocona\n");
    printTab(tab,MAX);

	return 0;
}

int min(int t[], int nSize) {
    int m = t[0];
    for(int i = 1; i < nSize; i++)
    {
        if(t[i] < m)m = t[i];
    }
    return m;
}



void initTab(int t[], int nSize) {
    srand((unsigned)time(NULL)); // inicjujê generator liczb pseudolosowych
    for(int i = 0;i < nSize;i++) {
        t[i] = rand() % nSize; // rand daje du¿e liczby, w ten sposób je zmniejszam
    }
}
void printTab(int t[], int nSize) {
    for(int i = 0;i < nSize;i++) {
        printf("%d ", t[i]);
        if((i + 1) % MAXLINE == 0) printf("\n");
    }
}