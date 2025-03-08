#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>

#define ZERO 1.e-100 // 0 definiujemy jako pewna stala

int main()
{
	// rozwiazanie trojmianu kwadratowego

	double a;
	double b;
	double c; 

	double delta;
	double x1;
	double x2; //zdefiniowac x1 i x2

	printf("Podaj wspolczynniki trojmianu kwadratowego a,b,c\n");
	
	// powinnismy sprawdzic czy a=0, ale olewamy to na razie

	cin >> a >> b >> c; // wczytac wspolczyniki a,b,c
	printf("%.2lfx^2 + %.2lfx + %.2lf\n",a,b,c); // long float do dwoch miejsc po przecinku


	// najpierw sprawdzamy czy delta>0, potem =0, potem <0, sprawdzamy od najszerszego przypadku
	// jesli delta > 0 to obliczyc dwa pierwiastki i je wypisac
	// obliczyc x1 i x2 jako podwojny pierwiastek
	// jesli nie, to wypisac ze nie ma rozwiazan


	delta = b*b - 4*a*c; //obliczyc delte

	if(delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		printf("Pierwiastki to %f i %f",x1,x2);
	}
	else if(fabs(delta) < ZERO) //!!! fabs - wartosc absolutna, pewnie float, nie mozna zrobic delta==0
	{
		x2 = x1 = -b / (2 * a);
		printf("Pierwiastek podwojny to %f", x1);
	}
	else {
		printf("Brak pierwiastkow, delta<0");
	}

	return 0;
}


