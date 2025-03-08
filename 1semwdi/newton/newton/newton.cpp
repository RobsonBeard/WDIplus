#include <stdio.h>
#include <iostream>
using namespace std;

int newton(int x, int y);

int main()
{
	int n;
	int k;

	printf("Podaj dwie liczby naturalne n i k, n>=k\n");
	cin >> n >> k;

	printf("Symbol newtona %d po %d wynosi %d",n,k,newton(n,k));

	return 0;
}

int newton(int x, int y) {
	int w=1;
	if(x == y || y == 0) return w;
	if(y == 1 || x == (y - 1)) return x;

	int roz = x - y; // ró¿nica n-k
	if(roz > y) {
		int tmp = y;
		y = roz;
		roz = tmp;
	}

	for(int i = roz; i > 0;i--) {
		w *= x;
		w /= i;
	}
	
	return w;
}