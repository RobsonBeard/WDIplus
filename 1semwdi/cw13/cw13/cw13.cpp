using namespace std;
#include <iostream>
#include <stdio.h>

int Fib1(int n);
int Fib2(int n);

int main()
{
	// alg 17 moglby byc na kartkowce, trzeba pamietac, ze tablica jest indeksowana od 0
	// na kartkowke znac sortowania i wyszukiwanie polowkowe, sin, cos, exp, zrobic to w domu!
	// alg 36 polega na porownywaniu stringow, no i nie liczy sie tam czy jest duza czy mala litera
	// nie bedzie na pewno rekurencji! (na kartkowce, na egzaminie moze byc)
	// zadnego wyjscia, wejscia funkcji main, trzba patrzec na polecenie! trzeba bedzie napisac funkcje, czyli naglowek, typy, zawartosc
	// drugie zadanie to jest algorytm - bez funkcji, trzeba napisac odpowiednie struktury danych
	// pomijamy wszystkie mainy, includy itp
	// jesli strzeba zdefiniowac stala, to to zrobic - np. tablica z ROZMIAREM przy alg. sortowania - ale nic poza tym

	int n;
	printf("Podaj wyraz\n");
	cin >> n;
	//n-ty element ciagu Fibonacciego
	printf("%d. element ciagu fibonacciego wynosi %d\n", n, Fib1(n));
	printf("%d. element ciagu fibonacciego wynosi %d\n", n, Fib2(n));


	return 0;
}

int Fib1(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;

	int fn;
	int f0 = 0;
	int f1 = 1;

	for(int i = 2;i <= n;i++) {
		fn = f0 + f1;
		f0 = f1;
		f1 = fn;
	}
	return fn;
}

int Fib2(int n) {
	if(n == 0) return 0;
	int a = 1; // inicjalizacja odwrotna niz poprzednio!
	int b = 0; // wynik

	for(int i = 1;  i <=n;  i++)
	{
		b = b + a;
		a = b - a;
		// zwizualizowac sobie w paincie, logiczne
	}
	return b;
}
