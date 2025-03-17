#include <stdio.h>
#include <stdlib.h> // dla malloca
#include <memory.h> // dla memseta
// costam jeszcze? dla memcpy (kopiowanie blokow pamieci)

typedef struct {
    double mX;
    double mY; // m - member (skladowa)
} Point;

#define MAX 8 // 1. nie uzywamy liczb, tylko stalych!

void printTab(int* pTab, int nSize);

int main()
{
    // rzeczy moga byc tutaj nie po kolei


    Point pt = { 0 }; // zeruje sie jak tablice
    int t[MAX] = {1,2,3};
    // t to STA£Y wskaŸnik (chyba na pierwszy element tablicy)

    //int* p, x; // wskaznikiem jest tylko p, dlatego nie wolno tak pisac!

    int x = 5;
    int* p = &x; // *(&x) == x
    int** v = &p;


    pt.mX = 6;
    pt.mY = -3.45;
    printf("(%lf,%lf)\n",pt.mX,pt.mY);

    // zeby dynamicznie zaalokowac pamiec, musimy miec wskaznik (adres)

    // Point* pPt = &pt; // notacja wegierska, p - pointer
    // 2. KAZDA ZMIENNA WSKAZNIKOWA MUSI MIEC PRZYPISANA WARTOSC PRZY DEKLARACJI

    // to byla jedna mozliwosc, teraz druga

    // Point* pPt = NULL; // musi byc zainicjalizowane!

    // trzecia mozliwosc

    Point* pPt = (Point*)malloc(sizeof(Point)); // 3. malloc zawsze musi byc zrzutowana na typ po lewej stronie!
        // pierwszy parametr - ile bajtow ze sterty wolnej pamieci mozna pobrac, stosujemy rozmiar typu

    // 5. Po kazdej alokacji nalezy sprawdzic ... (debugowanie)

    // if (pPt == NULL); // ewentualnie mozna napisac na odwrot
    // if (NULL == pPt); // zeby nie pomylic sie piszac jedno "="
    if (!pPt) // tak jest w sumie najlepiej
    {
        printf("pPt: Memory allocation error\n"); // mozna dopisac cos unikalnego, zeby latwiej bylo zlapac blad
        return 1;
    } 

    // 6. trzeba wyzerowac pamiec!

    memset(pPt,0, sizeof(Point));
       // drugi parametr - jaka wartoscia wypelnic kazdy bajt, trzeci parametr - ile tych bajtow jest (skopiowac z malloca!)


    (*pPt).mX=3; // operator "." jest silniejszy od "*"
    pPt->mX = 12;// ale O WIELE LEPIEJ jest tak
    pPt->mY = -5;
    printf("(%lf,%lf)\n", pPt->mX,pPt->mY);


    printTab(t, MAX);
    printf("\n");


    // dynamicznie zalokowana tablica 

    int* pTab = (int*)malloc(MAX * sizeof(int)); // max. liczba elementow * rozmiar jednego elementu
    if (!pTab) {
        printf("pPt: Memory allocation error\n");
        return 2;
    }
    memset(pTab, 0, MAX * sizeof(int));

    pTab[0] = 2;
    pTab[2] = 5;
    pTab[5] = 12;

    printTab(pTab, MAX);

    free(pTab);
    free(pPt); // 4. gdy alokuje pamiec, to od razu musze ja zwolnic! zeby nie bylo wyciekow pamieci
    printf("\n");

    return 0;
}

void printTab(int* pTab, int nSize) {
    for (int i = 0;i < nSize; i++) {
        // printf("%d ", pTab[i]); // to jest to samo co *( pTab + i*sizeof(int) ), bardzo kosztowne
        // pTab moge inkrementowac
        printf("%d ", *pTab++); 
    }

    // a moze tak??
    // for (int i = 0;i < nSize;i++, pTab++) // to ma swoje zastosowanie np. przy stosowaniu continue

    printf("\n");
}
