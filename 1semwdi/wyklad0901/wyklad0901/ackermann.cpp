#include <stdio.h>

int Ack(int m, int n);


int main() {

	printf("%d", Ack(3, 4));



	return 0;
}

int Ack(int m, int n) {
	if(m == 0) return n+1;
	if(m > 0 && n == 0) return Ack(m - 1, 1);
	return Ack(m - 1, Ack(m, n - 1));
}