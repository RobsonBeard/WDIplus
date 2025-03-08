#include <stdio.h>
#include "moje_funkcje.cpp"

#define AW 4
#define AK 3
#define BW 4


//int main() {
//	int a[AW][AK] = { 0 };
//	
//	initTab2D(a, AW, AK);
//	printTab2D(a, AW, AK);
//
//	int min = a[0][0];
//	int max = a[0][0];
//
//	for(int i = 0; i < AK; i++)
//	{
//		for(int j = 0; j < AW; j++)
//		{
//			if(a[j][i] < min) min = a[j][i];
//			if(a[j][i] > max) max = a[j][i];
//		}
//	}
//	
//	printf("min: %d\n",min);
//	printf("max: %d",max);
//	
//	return 0;
//}