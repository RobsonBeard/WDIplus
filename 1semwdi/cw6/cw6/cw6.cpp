#include <stdio.h>
#include <iostream>
using namespace std;

int mult(int a, int b);

int main()
{
	// mno¿enie dwóch liczb przez dodawanie
	int x;
	int y;
	printf("Podaj dwie liczby calkowite\n");
	cin >> x >> y;

	printf("%d * %d = %d", x, y, mult(x, y));


	return 0;
}

int mult(int a, int b) {
	int znak = 1;
	if(a < 0) {
		a = -a;
		znak = -znak;
	}
	if(b < 0) {
		b = -b;
		znak = -znak;
	}

	int iloczyn = 0;
	/*while(b > 0) {
		iloczyn += a;
		b--;
	}*/

	while(b--) {
		iloczyn += a; // gdy b nie jest zerem, to jest true, dlatego to dziala
	}
	return iloczyn*znak;
}