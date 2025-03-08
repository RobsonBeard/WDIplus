#include <stdio.h>
#include <iostream>
using namespace std;

#include <math.h>

int sumaPodz(int x);

// ZADANIE DOMOWE - 5,6,9 z listy algorytmow
// liczby zaprzyjaznione
// mozna sprobowac symbol newtona, ale dodatkowo

int main()
{
	// suma podzielnikow danej liczby
	
	printf("Podaj liczbe calkowita > 1\n");
	int x=0; // niby dobry nawyk implementacja
	cin >> x;
	if(x <= 1) {
		perror("ERROR: Wczytano bledna wartosc");
		return 1;
	}
	int sumaPodzielnikow = sumaPodz(x)-x;
	
	printf("Suma podzielnikow %d wynosi %d\n",x,sumaPodz(x));
	if(sumaPodzielnikow == x) {
		printf("Liczba %d jest doskonala", x);
	}

	return 0;
}

int sumaPodz(int x) {
	int suma = 1 + x;
	int p = 2;
	while(p <= sqrt(x)) // p*p <= x jest nawet lepiej
	{
		if(!(x % p)) {
			// jesli modulo == 0 to wejdzie
			suma +=p;
			int tmp = x / p;
			if(tmp != p) suma += tmp;
		}
		p++;
	}
	return suma;

}
