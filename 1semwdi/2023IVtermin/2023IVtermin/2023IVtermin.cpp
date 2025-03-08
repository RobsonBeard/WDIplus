#include <stdio.h>
#include <math.h>
#include "moje_funkcje.h"

#define PI 3.14159265358979323846
#define DBL_MIN 1.e-308
#define NROW 5
#define NCOL 10

double mojSinCos(double eps, double x);
double mojaPotega(double x, int p);
void sortRows2D(int tab[][NCOL], int nRows, int nCols);
int podstring(char s2[], char s1[]);
void Hanoi123(int n, int nFrom, int nTo);
void HanoiABC(int n, char cFrom, char cTo, char cWith);
void HanoiABCMoje(int n, char cFrom, char cTo, char cWith);


/*
int main()
{

	double x = PI / 3;
	double eps = 1.e-6;

	double x2 = 0.3;
	int p = 10;


	//printf("Wartosc kontrolna: %.8lf\n",sin(x)*cos(x)); 
	//printf("Wartosc moja: %.8lf\n", mojSinCos(eps,x));

	//printf("Wartosc kontrolna: %.10lf\n", pow(x2+1,p));
	//printf("Wartosc moja: %.10lf",mojaPotega(x2,p));

	//int tab[NROW][NCOL] = {};
	//initTab2D(tab, NROW, NCOL);
	//printTab2D(tab, NROW, NCOL);

	//printf("\n\n");
	//sortRows2D(tab, NROW, NCOL);
	//printTab2D(tab, NROW, NCOL);

	char s1[] = "abCdfFghAabcdefgh";
	char s2[] = "fgh";

	//printf("%d",podstring(s2,s1)); 
	
	
	//HanoiABCMoje(3, 'A', 'C', 'B');
	//printf("\n\n");
	//HanoiABC(3, 'A', 'C', 'B');
	//printf("\n\n");
	Hanoi123(3,1,3);

	return 0;
}
*/

// PO PROSTU WZOR Z EGZAMINU JEST ZLY JA PIERDOLE
double mojSinCos(double eps, double x) {
	double res = x;
	double t = res;
	int n = 1;

	while(t >= eps || t<=-eps) {
		t *=  (x * x * 4) / ((2*n + 1)*2*n);
		t = -t;
		res += t;
		n++;
	}

	return res;
}

double mojaPotega(double x, int p) {
	// to tez jest zly wzor, bo szereg jest napisany jako nieskonczony

	if(p <= 1 || x >= 1 || x <= -1) return DBL_MIN;

	double res = 1.;
	int n = 1;
	while(p>=n) {
		int newton = 1;
		int i = 1;
		double t = 1.;

		while(i <= n) { // nie mam pojecia czy da sie lepiej
			newton *= p - n + i;
			newton /= i;

			t *= x;

			i++;
		}
	
		res += t*newton;
		n++;
	}

	return res;
}

void sortRows2D(int tab[][NCOL],int nRows, int nCols) {
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 1;j < nCols;j++) {
			int x = tab[i][j];
			int k = j - 1;
			while(k>=0 && tab[i][k] > x) {
				tab[i][k + 1] = tab[i][k--];
			}
			tab[i][k + 1] = x;
		}
	}
}

int podstring(char s2[], char s1[]) { // ma ignorowac wielkosc liter
	int jest = 0;
	int dl1 = myStrlen(s1);
	int dl2 = myStrlen(s2);
	int index = 0;

	for(int i = 0;i <= dl1 - dl2;i++) {
		jest = 1;
		for(int j = 0;j < dl2;j++) {
			if(s2[j] != s1[i + j] && s2[j] != s1[i + j]+32 && s2[j] != s1[i + j] - 32){
				jest = 0;
				break;
			}
		}
		if(jest) {
			index = i;
			break;
		}
	}

	if(jest) return index;
	return -1;
}

void Hanoi123(int n, int nFrom, int nTo) {
	if(n == 1)
	printf("Move disc %d from %d to %d\n",n,nFrom,nTo);
	else {
		Hanoi123(n - 1, nFrom, 6 - nFrom - nTo);
		printf("Move disc %d from %d to %d\n", n, nFrom, nTo);
		Hanoi123(n - 1, 6 - nFrom - nTo, nTo); //?? czemu 6??? to tylko dzia³a dla specjalnego wywo³ania Hanoi123(3,1,3)?
	}
}

void HanoiABC(int n, char cFrom, char cTo, char cWith) {
	if(n == 1)
	printf("Move disc %d from %c to %c\n", n, cFrom, cTo);

	else {
		HanoiABC(n - 1, cFrom, cWith, cTo);
		printf("Move disc %d from %c to %c\n", n, cFrom, cTo);
		HanoiABC(n - 1, cWith, cTo, cFrom);
	}
}

void HanoiABCMoje(int n, char cFrom, char cTo, char cWith) {
	if(n == 1)
		printf("Move disc from %c to %c \n", cFrom, cTo);
	else
	{
		HanoiABCMoje(n - 1, cFrom, cWith, cTo);
		HanoiABCMoje(1, cFrom, cTo, cWith);
		HanoiABCMoje(n - 1, cWith, cTo, cFrom);
	}
}