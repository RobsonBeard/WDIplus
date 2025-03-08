#include <stdio.h>
#include "moje_funkcje.cpp"

#define ROZM 20


int maxSuma(int tab[], int nSize);


//int main() {
//	// jakis chujowy ten algorytm
//
//	int ciag[ROZM] = { 12,-15,40,21,37,-45,12,10,10,-15 };
//
//	printf("Najwieksza suma: %d", maxSuma(ciag, ROZM));
//		
//	
//	return 0;
//}


int maxSuma(int tab[], int nSize)
 {
	int maxS = 0;
	for(int i = 0; i < nSize; i++) {
		for(int j = i; j < nSize; j++) {
			int sumaTemp = 0;
			for(int k = i; k <= j; k++) {
				sumaTemp += tab[k];
				if(sumaTemp > maxS) {
					maxS = sumaTemp;
				}
			}
		}
	}
	return maxS;
}