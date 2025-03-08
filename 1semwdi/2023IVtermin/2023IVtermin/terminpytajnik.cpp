#include "moje_funkcje.h"

double expplusjeden(double eps, double x);
void sredniaKolumn(int t[][NCOL], int nRows, int nCols);

/*
int main() {
	double x = 2.5;
	double eps = 1.e-10;

	//printf("Wartosc kontrolna: %.13lf\n", exp(x+1));
	//printf("Wartosc moja: %.13lf\n", expplusjeden(eps,x));

	int tab[NROW][NCOL] = {};
	initTab2D(tab, NROW, NCOL);
	printTab2D(tab, NROW, NCOL);

	sredniaKolumn(tab,NROW,NCOL);

	return 0;
}
*/
double expplusjeden(double eps, double x) {
	double res=1;
	double t=res;
	int n = 1;

	// licznik i mianownik dodatnie
	while(t >= eps) {
		t *= (x + 1) / n;
		n++;
		res += t;
	}


	return res;
}

void sredniaKolumn(int t[][NCOL], int nRows, int nCols) {
	// nie da zwrocic tablicy jednowymiarowej bez jakiegos dynamicznego przydzielania pamieci
	double srednie[NCOL] = {};

	for(int i = 0; i < nCols; i++)
	{
		int temp = 0;
		for(int j = 0; j < nRows; j++)
		{
			temp += t[j][i];
		}
		srednie[i] = (double)temp / nRows;
	}

	printTab(srednie, NCOL);
}
