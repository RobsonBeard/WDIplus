#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAXLINE 10
#define MAX 50

using namespace std;

int dzielenieNWP(int x, int y);
int odejmowanieNWP(int x, int y);
int NWW(int x, int y);
void CzyZaprzyjaznione(int x, int y);
int sumaPodzielnikow(int x); // bez liczby x jako podzielnik
   
void initTab(int t[], int nSize);
void printTab(int t[], int nSize);

int main()
{
    // 5, 6, 9 z listy
    //NWP na dwa sposoby, NWW i liczba zaprzyjaŸniona dla x>2

    int a;
    int b;
    int tab[MAX];

    printf("Podaj dwie liczby naturalne dodatnie\n");
    cin >> a >> b;

    printf("NWP z liczb %d i %d przez dzielenie wynosi %d\n", a, b, dzielenieNWP(a,b));
    printf("NWP z liczb %d i %d przez odejmowanie wynosi %d\n", a, b, odejmowanieNWP(a, b));

    printf("NWW liczb %d i %d wynosi %d\n", a, b, NWW(a, b));
    
    CzyZaprzyjaznione(a,b);

    printf("\n");

    initTab(tab, MAX);
    printTab(tab, MAX);

    return 0;
}

int dzielenieNWP(int x, int y) {
    int tmp;
    while(y!=0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int odejmowanieNWP(int x, int y) {
    int tmp;
    while(x != y) {
        tmp = y;
        y = abs(x - y);
        x = tmp;
    }
    return x;
}

int NWW(int x, int y) {
    if(y > x) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int res=x; // chcialbym chyba zeby tu byla wieksza liczba, wtedy jest mniej operacji, ale bez tego tez dziala
    while(res % y) {
        res += x;
    }
    return res;
}

int sumaPodzielnikow(int x) {
    int res = 1;
    int p = 2;
    while((p * p) <= x) {
        if(!(x % p)) {
            res += p;
            int tmp = x / p;
            if(tmp != p) res += tmp;
        }
        p++;
    }

    return res;
}

void CzyZaprzyjaznione(int x, int y) {
    int px = sumaPodzielnikow(x);
    int py = sumaPodzielnikow(y);

    printf("Suma podzielnikow %d wynosi %d\n",x,px);
    printf("Suma podzielnikow %d wynosi %d\n",y,py);

    if(px == y&&py==x) {
        printf("Liczby %d i %d sa liczbami zaprzyjaznionymi\n",x,y);
    }
    else {
        printf("Liczby %d i %d nie sa liczbami zaprzyjaznionymi\n", x, y);
    }

}

void initTab(int t[], int nSize) {
    srand((unsigned)time(NULL)); // inicjujê generator liczb pseudolosowych
    for(int i = 0;i < nSize;i++) {
        t[i] = rand() % nSize; // rand daje du¿e liczby, w ten sposób je zmniejszam
    }
}
void printTab(int t[], int nSize){
    for(int i = 0;i < nSize;i++) {
        printf("%d ",t[i]);
        if((i + 1) % MAXLINE == 0) printf("\n");
    }
}
