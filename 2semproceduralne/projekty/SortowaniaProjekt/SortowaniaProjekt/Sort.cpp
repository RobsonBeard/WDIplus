#include "Sort.h"

void sortuj( int* pTab, int l, int p );
void updateUp( int* pTab, int l, int p );
void updateDown( int* pTab, int l, int p );


void bubbleSort( int* pTab, int nSize ) {
	for( int i = 1; i < nSize; i++ )
	{
		for( int j = nSize - 1; j >= i; j-- )
		{
			if( pTab[j] < pTab[j - 1] ) {
				int temp = pTab[j];
				pTab[j] = pTab[j - 1];
				pTab[j - 1] = temp;
			}
		}
	}
}

void simpleSelectionSort( int* pTab, int nSize ) {
	for( int i = 0; i < nSize - 1; i++ )
	{
		int min = pTab[i];
		int ix_min = i; // indeks minimum
		for( int j = i + 1; j < nSize; j++ )
		{
			if( pTab[j] < min ) {
				min = pTab[j];
				ix_min = j;
			}
		}
		pTab[ix_min] = pTab[i];
		pTab[i] = min;
	}
}

void simpleInsertionSort( int* pTab, int nSize ) {
	for( int i = 1; i < nSize; i++ )
	{
		int x = pTab[i];
		int j = i - 1;
		while( j >= 0 && pTab[j] > x ) {
			pTab[j + 1] = pTab[j--];
		}
		pTab[j + 1] = x;
	}

}


void mixedSort( int* pTab, int nSize ) {
	int l = 1;
	int p = nSize - 1; // ostatni indeks tablicy
	int k = nSize - 1;
	int temp;

	do {
		for( int i = p; i >= l; i-- ) // jadê w dó³
		{
			if( pTab[i - 1] > pTab[i] ) // jeœli element z lewej strony jest wiêkszy od obecnego (st¹d l=1, bo mo¿na porównaæ max do [0])
			{
				temp = pTab[i - 1];
				pTab[i - 1] = pTab[i];
				pTab[i] = temp; // zamieniam elementy z warunku miejscami
				k = i; // zapisuje indeks ostatniej zamiany
			}
		}
		l = k + 1;  // tam gdzie ostatnio zmienia³em + 1
		for( int i = l; i <= p; i++ ) // jadê do góry
		{
			if( pTab[i - 1] > pTab[i] )// taki sam warunek i dzia³anie jak u góry 
			{
				temp = pTab[i - 1];
				pTab[i - 1] = pTab[i];
				pTab[i] = temp;
				k = i;
			}
		}
		p = k - 1; // tam gdzie ostatnio zmienia³em - 1
	} while( l < p ); // dopóki prawy jest wiêkszy lub równy od lewego indeksu
}

void halfFindSort( int* pTab, int nSize ) {
	int l;
	int p;
	int m;
	int x;

	for( int i = 1; i < nSize; i++ ) //for od drugiego elementu tablicy 
	{
		x = pTab[i];
		l = 0;
		p = i - 1; // lewy i prawy koniec przedzia³u (indeks)
		while( l <= p ) {
			m = ( l + p ) / 2; // srodek przedzia³u (indeks)
			if( x < pTab[m] )
				p = m - 1;
			else l = m + 1; // po zakonczeniu while bedziemy mieli indeks l, w ktorym bedziemy wstawiac x, l to indeks pierwszego elementu, ktory jest >= x
		} 
		for( int j = i - 1; j >= l; j-- )
		{
			pTab[j + 1] = pTab[j]; // przesuwam wszystkie elementy >= x w prawo o 1
		}
		pTab[l] = x;
	}
}

void quickSort( int* pTab, int nSize ) {
	sortuj( pTab, 0, nSize - 1 );
}

void sortuj( int* pTab, int l, int p ) {
	int i = l; // lewy indeks
	int temp;
	int j = p; // prawy indeks
	int x = pTab[( l + p ) / 2]; // wartosc srodkowego indeksu tablicy
	do {
		// "dziele" tablice na elementy wieksze i mniejsze niz x?
		while( pTab[i] < x ) i++; // przesuwam lewy indeks w prawo
		while( x < pTab[j] ) j--;	// przesuwam prawy indeks w lewo
		if( i <= j ) // jesli lewy i prawy sie minely to zamieniam wartosci miejscami
		{
			temp = pTab[i];
			pTab[i++] = pTab[j];
			pTab[j--] = temp;
		}
	} while( i <= j );
	if( l < j ) sortuj( pTab, l, j );
	if( i < p ) sortuj( pTab, i, p );
}

void heapSort( int* pTab, int nSize ) {
	int l = nSize / 2;
	int p = nSize - 1;
	int temp;

	for( int i = l - 1; i >= 0; i-- )
	{
		updateUp( pTab, i, p );
	}

	for( ; p > 0; p-- ) //! bardzo ciekawy for
	{
		temp = pTab[0];
		pTab[0] = pTab[p];
		pTab[p] = temp;
		updateUp( pTab, 0, p-1 ); // poprzednio we while szedlem z l az do 0, wiec tutaj jest 0 zamiast l
	}
}

void updateUp( int* pTab, int l, int p ) {
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1; // 2*i w pascalu
	int x = pTab[i];
	while( j <= p ) {
		if( j < p && pTab[j] < pTab[j + 1] ) j++;
		if( x >= pTab[j] ) break;
		pTab[i] = pTab[j];
		i = j;
		j = 2 * i + 1;
	}
	pTab[i] = x;
}

void updateDown( int* pTab, int l, int p ) {
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1; // 2*i w pascalu
	int x = pTab[i];
	while( j <= p ) {
		if( j < p && pTab[j] > pTab[j + 1] ) j++; // tu by³a zmiana warunku
		if( x <= pTab[j] ) break; // i tu
		pTab[i] = pTab[j];
		i = j;
		j = 2 * i + 1;
	}
	pTab[i] = x;
}

/*

	stary while z heapsorta: 

* while( l > 0 ) {
		l--;
		update( pTab, l, p );
	}

	// delikatnie musze zmienic for, w stosunku do while, bo w forze dekrementuje po wykonaniu sie petli (trzeba zmienic obie petle na raz, inaczej nie dziala miedzy innymi z powodu modyfikacji l)
	while( p > 0 ) {
		temp = pTab[0];
		pTab[0] = pTab[p];
		pTab[p] = temp;
		p--;
		update( pTab, l, p );
	}


	* notatki

	program 2.8
	sort stogowe - heapsort
	nastepniki - nastepnik 0 to 1 i 2
	nastepik 1 to 2 i 3
	(2i + 1)
	nastepnik 2 to 4 i 5 ?
	i licze je tylko do polowy indeksow

	uaktualnienie stogu ma byc pomiedzy indeksami l i p

	void Update(l,p, tablica)
	{
		sprawdzenie czy l>=p, jesli tak - return
		mam indeks l, dla niego obliczam potomkow
		obliczam indeks elementu, z ktorym nalezy zamienic p - wybieram wiekszy z potomkow
		nastepuje zamiana z wiekszym z potomkow?
	}

	dwa ify z ksiazki mozna zapisac jednym ifem
	naglowek funkcji srodkowej nie ma byc w pliku naglowkowym, tylko gdzies w cpp
	najpierw sie tworzy stóg, a potem sie go sortuje. tworzymy go petla for a nie while
	sortowanie jadê pêtl¹ od koñca do 1 (nie  0)
	wymieniam ostatni element z zerowym i uaktualniam stog,
	potem przedostatni z czymstam i uaktualniam stog

	to jest najtrudniejsze, zrobic na koniec
	*/


	/*
		// w pascalu petla repeat until wykonuje sie dopoki warunek jest FALSZYWY

		// program 2.5, 2.2
		// sortowanie szybkie 2.10, dwie funkcje do napisania w nim, 3 parametry - tablice, lewe i prawe ograniczenie
		// potrzeba namiastki funkcji, ktora wywola quicksorta, bo on ma 3 parametry, a my przekazujemy 2

	quicksort:
	i=0;j=nTabSize-1;
	x wybierz jako srodkowy
	do{
		znajdz t[i]>x na lewo od x;
		znajdz t[j]<x na prawo od x;
		if i<=j
			zamien
			i++
			j++
	} while (i<j)

	rekurencyjnie dla lewej polowki
	rekurencyjnie dla prawej polowki

	*/



	/*
	//TODO gdy zrobimy heapsort to probujmy odwrocic sortowanie na malejace
	czyli costam w ifach pozmieniac, no i zachowac te funkcje w komentarzu
	//!bez odwolan rekurencyjnych, ktore sa w internecie, bo bedzie karny projekt - mamy korzystac tylko z wirtha!
	// ma nie byc spacji przy rzutowaniu!! (double) a nie ( double ), po nazwie funkcji nie ma spacji, wylaczone formatowanie gdy zamknie sie srednik lub zamknie blok, bo mamy sobie samemu formatowac (chyba?)
	*/