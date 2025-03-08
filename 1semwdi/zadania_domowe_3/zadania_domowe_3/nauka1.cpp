using namespace std;
#include <iostream>
#include <stdio.h>

int nPoK(int n, int k);

//int main() {
//	int n = 10;
//	int k = 4;
//
//	if(k > n) {
//		int tmp = n;
//		n = k;
//		k = tmp;
//	}
//
//	printf("%d po %d wynosi: %d",n,k,nPoK(n,k));
//
//	return 0;
//}
int nPoK(int n, int k) {
	int res = 1;
	
	if(n == k || n == 0 || k == 0) return res;

	if(k == 1 || k == (n - 1)) return n;


	if((n - k) > k) k = n - k; // 7 po 5 teraz
	int roz = n - k; // 2

	for(int i = 1;i <= roz;i++) {
		res *= ++k;
		res /= i;
			//printf("%d %d\n", i, k);
	}

	return res;
}