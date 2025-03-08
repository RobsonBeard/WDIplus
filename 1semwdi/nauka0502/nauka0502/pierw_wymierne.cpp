#include <stdio.h>
#include <math.h>
#define ST 3
#define ROZM 1000
#include <iostream>
using namespace std;

//int main() {
//
//	int wsp[ST + 1] = { 6, 5, 4, 12 };
//	//podzielniki p;
//	int p = wsp[0];
//	int pp[ROZM] = { 0 };
//	pp[0] = p;
//	pp[1] = 1;
//	int i = 2;
//	for(int k = 2; k*k <= p; k++) {
//		if(p % k == 0) {
//			pp[i] = k;
//			i++;
//			int temp = p / k;
//			if(temp != k) {
//				pp[i] = temp;
//				i++;
//			}
//		}
//	}
//	//podzielniki q
//	int q = wsp[ST];
//	int pq[ROZM] = { 0 };
//	pq[0] = q;
//	pq[1] = 1;
//	int j = 2;
//	for(int k = 2; k <= sqrt(q); k++) {
//		if(q % k == 0) {
//			pq[j] = k;
//			j++;
//			int temp = q / k;
//			if(temp != k) {
//				pq[j] = temp;
//				j++;
//			}
//		}
//	}
//	cout << "Pierwiastki:" << endl;
//	for(int l = 0; l < ROZM; l++) {
//		if(pp[l] != 0) {
//			for(int m = 0; m < ROZM; m++) {
//				if(pq[m] != 0) {
//					cout << pp[l] << "/" << pq[m] << " ";
//				}
//			}
//		}
//	}
//
//	return 0;
//}