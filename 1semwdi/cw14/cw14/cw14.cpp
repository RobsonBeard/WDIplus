#include <stdio.h>
#include <iostream>

void filtr(double x[], double y[], int nSize); //nSize>1, x - tablica wejsciowa, y - tablica wyjsciowa
void printTab(int* pTab, int nSize);


int main()
{
 // algorytm filtrowania, wygladzania
	
	//int tab1[5] = { 1,2,3,4,5 };
	//printTab(tab1, 5);
	
	
	return 0;
}

void filtr(double x[], double y[], int nSize) {
	y[0] = (2 * x[0] + x[1]) / 3.; // mozna z kropka, mozna bez

		for(int i = 1; i < nSize-1; i++) // od 1 do nSize-2 potrzebuje, wiec <nSize-1
		{
			y[i] = (y[i - 1] + 2 * x[i] + x[i + 1])/4.;
		}

	y[nSize - 1] = (y[nSize - 2] + 2 * x[nSize - 1]) / 3.;//ostatni wyraz

	// dla chetnych mozna uzywac wskaznikow, to bedzie obowiazkowe dopiero w przyszlym semestrze

}


void printTab(int* pTab, int nSize) {
	for(int i = 0; i < nSize; i++,pTab++)
	{
		printf("%d ", *pTab); 
	}
}