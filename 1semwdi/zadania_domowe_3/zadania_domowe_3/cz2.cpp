using namespace std;
#include <stdio.h>
#include <iostream>

char toLower(char c);
int max(int a, int b);
int mult(int x, int y);
void swap(int x, int y);
void swap2(int* x, int* y);
int div(int x, int y, int* pRest);

//int main() {
//	//char c = getchar();
//	//putchar(toLower(c));
//
//	int x = 10;
//	int y = 20;
//	printf("max: %d\n", max(x,y));
//	printf("mult: %d\n", mult(x,y));
//	swap(x, y);
//	printf("swap?: x: %d, y: %d\n", x,y); // nie swapuje, bo w funkcji zmienne s¹ lokalne
//
//	swap2(&x, &y);
//	printf("swap?: x: %d, y: %d\n", x, y); // teraz swapuje
//
//
//	int z = 3;
//	printf("adres z: %d\n",&z);
//	printf("inny zapis z: %d\n", *(&z));
//
//	int a = 47;
//	int b = 5;
//	int reszta = 0;
//	printf("%d / %d = %d r. %d\n", a, b, div(a, b, &reszta), reszta);
//	return 0;
//}


char toLower(char c) {
	return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int mult(int x, int y) {
	int res = 0;
	/*while(y > 0) {
		res += x;
		y--;
	}*/
	while(y-- > 0) {
		res += x;
	}
	return res;
}

void swap(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void swap2(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int div(int x, int y, int* pRest) {
	int q = 0;
	*pRest = x;
	while(*pRest >= y) {
		q++;
		*pRest -= y;
	}
	return q;
}
