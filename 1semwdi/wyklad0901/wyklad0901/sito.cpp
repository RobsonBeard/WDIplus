#include <stdio.h>
#include <math.h>
#define MAX 100

//int main() {
//
//	int t[MAX];
//	for(int i = 0; i < MAX; i++)
//	{
//		t[i] = i + 1;
//	}
//
//	int last = (int) sqrt(MAX);
//
//	for(int i = 1;i <= last;i++) {
//		int k = i + 1;
//
//		if(t[i] != 0) {
//			for(int j = 2 * i + 1;j < MAX;j += k) {
//				t[j] = 0;
//			}
//		}
//	}
//		for(int i = 0;i < MAX;i++) {
//			if(t[i]!=0&&t[i]!=1) printf("%d ", t[i]);
//		}
//
//
//		return 0;
//	
//}