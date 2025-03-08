using namespace std;
#include <iostream>
#include <stdio.h>

void podzielniki(int x);

//int main() {
//
//	podzielniki(1254);
//
//	return 0;
//}

void podzielniki(int x) {
	printf("Podzielniki %d: 1, %d, ", x,x);
	int p = 2;
	int suma = x+1;
	while(p<=sqrt(x)) {
		if(x % p == 0) {
			printf("%d, ", p);
			suma += p;

			if((x / p) != p) {
				printf("%d, ", (x / p));
				suma += (x / p);
			}
		}
		p++;
	}

	printf("suma podzielnikow: %d",suma);
}