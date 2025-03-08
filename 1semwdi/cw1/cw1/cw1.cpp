
#include <iostream>
using namespace std;
#include <stdio.h> // naglowki z C maj¹ na koncu .h

int main()
{
	int x = 0;
	printf("Podaj liczbe calkowita: ");
	cin >> x;

	//int res = x * x;
	//res = res * res;
	//res = res * x;

	int res = x * x * x * x * x;

	printf("%d^5 = %d\n",x,res);

	return 0;
}

