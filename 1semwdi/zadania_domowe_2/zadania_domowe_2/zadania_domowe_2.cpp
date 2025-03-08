#include <iostream>
#include <stdio.h>


using namespace std;

#define MAXLINE 10
#define MAX 50

void initTab(int t[], int nSize);
void printTab(int t[], int nSize);

void bubbleSort(int t[], int nSize);
void simpleSelectionSort(int t[], int nSize);
void simpleInsertionSort(int t[], int nSize);

int halfFind(int t[], int nSize, int x);

double sredniaNp(int t[], int nSize);
int drugieMin(int[], int nSize);


int main()
{
	// SREDNIA ARYTMETYCZNA NIEPARZYSTYCH(pamietac zeby nie dzielic przez 0)
	// DRUGIE MINIMUM

	int tab[MAX] = { 0 };
	initTab(tab, MAX);

	//bubbleSort(tab, MAX);
	//simpleSelectionSort(tab, MAX);
	simpleInsertionSort(tab, MAX);
	printTab(tab, MAX);

	//printf("Srednia arytmetyczna nieparzystych wyrazow tablicy wynosi: %.2f\n", sredniaNp(tab,MAX));
	//printf("Drugie minimum tablicy to: %d\n",drugieMin(tab,MAX));

	/*
	int x;
	int ix;
	printf("Wpisz wartosc elementu do wyszukania: ");
	cin >> x;

	if((ix = halfFind(tab, MAX, x)) == -1) {
		printf("Elementu %d nie ma w tablicy", x);
	}
	else {
		printf("Element %d wystepuje pod indeksem %d",x,ix);
	}
	*/



	return 0;
}


int drugieMin(int t[], int nSize) {

	if(nSize < 2) {
		printf("Tablica ma mniej ni¿ dwa elementy");
		return -1;
	}

	int ix=1;

	while(t[ix] == t[0]) { // przez to wyrazy nie musza byc rozne?
		ix++;
	}

	int min1 = t[0];
	//int min2 = t[1];
	int min2 = t[ix];

	int tmp;

	if(min2 < min1) {
		tmp = min1;
		min1 = min2;
		min2 = tmp;
	}

	for(int i = ix+1; i < nSize; i++) // i=2
	{
		if(t[i] < min1) {
			min2 = min1;
			min1 = t[i];
			continue; // tak bedzie dzialac? jesli nie to w nastepnym ifie inny warunek
		}
		if(t[i] < min2) {
			min2 = t[i];
		}
	}
	return min2;
}


double sredniaNp(int t[], int nSize) {
	int suma = 0;
	int ilosc = 0;
	for(int i = 0; i < nSize; i++)
	{
		if(t[i] % 2) // moze byc 0 lub 1, wiec nie musze dawac ==
		{
			//printf("%d ", t[i]);
			suma += t[i];
			ilosc++;
		}
	}
	printf("\nNieparzystych suma: %d, ilosc: %d\n",suma, ilosc);

	if(ilosc) {
		return (double)suma / ilosc; // musze wymusic dzielenie zmiennoprzecinkowe
	}
	else {
		printf("Nie znaleziono wyrazow nieparzystych!\n");
		return -1;
	}
	}

void bubbleSort(int t[], int nSize) {
	for(int i = 1; i < nSize; i++)
	{
		for(int j = nSize - 1; j>=i ; j--)
		{
			if(t[j] < t[j - 1]) {
				int temp = t[j];
				t[j] = t[j - 1];
				t[j - 1] = temp;
			}
		}
	}
}

void simpleSelectionSort(int t[], int nSize) {
	for(int i = 0; i < nSize-1; i++)
	{
		int min = t[i];
		int ix_min = i; // indeks minimum
		for(int j = i+1; j < nSize; j++)
		{
			if(t[j] < min) {
				min = t[j];
				ix_min = j;
			}
		}
		t[ix_min] = t[i];
		t[i] = min;
	}
}

void simpleInsertionSort(int t[], int nSize) {
	for(int i = 1; i < nSize; i++)
	{
		int x = t[i];
		int j = i - 1; // indeks na lewo
		while(j>=0 && t[j] > x) {
			t[j + 1] = t[j];
			j--;
			// albo t[j+1] = t[j--]
		}
		t[j + 1] = x;
	}
	// schematy dzia³ania w zeszycie!
}

int halfFind(int t[], int nSize, int x) {
	// wyszukiwanie liczby w tablicy wraz z jej indeksem 
	// (przy kilku tych samych wartoœciach indeks jest podawany losowo), TRZEBA UMIEC NAPISAC MODYFIKACJE, KTORA WYBIERZE MI INDEKS PIERWSZY OD LEWEJ
	// dzia³a dla tablicy posortowanej rosn¹co!
	int p = 0;
	int k = nSize - 1;
	int m; // indeks srodka
	do {
		m = (p + k) / 2;
		if(x < t[m]) {
			k = m - 1;
		}
		else if(x > t[m]) {
			p = m + 1;
		}
		else break;
	} while(p <= k);
	if(p <= k) return m;
	return -1; // nie ma takiego indeksu tablicy, to jest, gdy warunek siê nie spe³ni³
}

void initTab(int t[], int nSize) {
	srand((unsigned) time(NULL));
	for(int i = 0; i < nSize; i++)
	{
		t[i] = rand() % nSize;
	}
}

void printTab(int t[], int nSize) {
	for(int i = 0; i < nSize; i++)
	{
		printf("%d ",t[i]);
		if((i + 1) % MAXLINE == 0) printf("\n");
	}
}