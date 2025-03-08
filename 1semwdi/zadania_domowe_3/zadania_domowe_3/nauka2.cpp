using namespace std;
#include <iostream>
#include <stdio.h>

void factorization(int x); // x ma byc >=2

//int main() {
//
//
//    //factorization(21);
//
//#define ROWS 5
//#define COLS 6
//
//    double t[ROWS][COLS];
//    double ave[COLS] = { 0 };
//
//    for(int i = 0; i < COLS; i++)
//    {
//        for(int j = 0; j < ROWS; j++)
//            ave[i] += t[j][i];
//        ave[i] /= ROWS;
//    }
//    double aveAll = 0;
//    for(int i = 0; i < COLS; i++)
//        aveAll += ave[i];
//    aveAll /= COLS;
//
//    for(int i = 0; i < ROWS; i++)
//    {
//        for(int j = 0; j < COLS; j++)
//        {
//            printf("%.2lf ", t[i][j]);
//        }
//        printf("\n");
//    }
//
//	return 0;
//}

//void factorization(int x) {
//	if(x < 2) printf("Liczba %d mniejsza od 2!",x);
//
//	int p = 2; // pierwsza liczba pierwsza
//	int sqrtx = (int)sqrt((double)x);
//
//	while(x > 1 && p <= sqrtx) {
//		while(x% p == 0) {
//			printf("%d\n",p);
//			x /= p;
//		}
//		p++;
//	}
//
//}


// z dysku - ale to np. dla 21 nie dzia³a, bo pierwiastek jest mniejszy ni¿ 7, chyba ¿e trzeba wypisywaæ x/p te¿ jak w podzielnikach
void factorization(int x)  // x ma byc wieksze lub rowne 2
{
    if(x < 2) cout << "Liczba " << x << " mniejsza od 2!!\n";

    int p = 2;  //pierwsza liczba pierwsza
    int sqrtx = (int)sqrt((double)x);  // w VS2019 nie trzba rzutowac na double ale w innych srodowiskach
    // nie koniecznie visualowych moze byc konieczne - dlatego lepiej zrobic
    while(x > 1 && p <= sqrtx)  // optymalny alg do pierwiastka
    {
        while(x % p == 0)
        {
            cout << p << endl;
            x /= p;
        }
        p++;
        
    }
}