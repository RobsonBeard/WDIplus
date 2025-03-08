#include <stdio.h>
#include "moje_funkcje.cpp"

#define AW 4
#define AK 3

//int main() {
//
//	int t[AW][AK] = { };
//	initTab2D(t, AW, AK);
//	printTab2D(t, AW, AK);
//
//
//	int czyJestSuma = 0;
//	int sumaw[AW] = { 0 };
//	int sumak[AK] = { 0 };
//
//	for(int i = 0; i < AW; i++) {
//		for(int j = 0; j < AK; j++) {
//			sumaw[i] += t[i][j];
//		}
//	}
//	for(int i = 0; i < AK; i++) {
//		for(int j = 0; j < AW; j++) {
//			sumak[i] += t[j][i];
//		}
//	}
//
//	for(int i = 0; i < AW; i++) {
//		for(int j = 0; j < AK; j++) {
//			if(sumaw[i] == sumak[j]) {
//				printf("Istnieje wiersz %d i kolumna %d o rownej sumie\n", i + 1, j + 1);
//				czyJestSuma = 1;
//			}
//		}
//	}
//	if(!czyJestSuma) printf("Nie istnieje wiersz i kolumna o rownej sumie");
//
//	return 0;
//}