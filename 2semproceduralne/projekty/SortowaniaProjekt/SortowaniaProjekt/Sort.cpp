#include "Sort.h"

void sortuj(int* pTab, int l, int p);
void update(int* pTab, int l, int p);


int createTab( int** pTab, int nSize ) {
	*pTab = (int*)malloc( nSize * sizeof( int ) );
	if( !*pTab ) // if(*pTab == NULL)
	{
		// tutaj nie robie komunikatu o bledzie, tylko zrobilismy typ funkcji jako int po to, zeby przez 0 lub 1 informowac czy funkcja sie powiodla
		return 0;
	}

	//tutaj chce wyzerowac tablice
	memset( *pTab, 0, nSize * sizeof( int ) ); //! kopiowac ilosc bajtow z malloca!
	return 1;
}

void initTab( int* pTab, int nSize ) {
	srand( (unsigned)time( NULL ) ); 
	for( int i = 0; i < nSize; i++ ) {
		*pTab++ = rand() % nSize; 
	}
}

void printTabTest( int* pTab, int nSize ) {
	for( int i = 0; i < nSize && i<50; i++ ) 
	{
		printf( "%d ", *pTab++ );
		if( ( i + 1 ) % MAXLINE == 0 ) printf( "\n" );
	}

}

void printTab( int* pTab, int nSize ) {
	for( int i = 0; i < nSize ; i++ )
	{
		printf( "%d ", *pTab++ ); 
		if( ( i + 1 ) % MAXLINE == 0 ) printf( "\n" );
	}

}

void bubbleSort( int* pTab, int nSize) {
	for(int i = 1; i < nSize; i++)
	{
		for(int j = nSize - 1; j>=i ; j--)
		{
			if( pTab[j] < pTab[j - 1]) {
				int temp = pTab[j];
				pTab[j] = pTab[j - 1];
				pTab[j - 1] = temp;
			}
		}
	}
}

void simpleSelectionSort( int* pTab, int nSize) {
	for(int i = 0; i < nSize-1; i++)
	{
		int min = pTab[i];
		int ix_min = i; // indeks minimum
		for(int j = i+1; j < nSize; j++)
		{
			if( pTab[j] < min) {
				min = pTab[j];
				ix_min = j;
			}
		}
		pTab[ix_min] = pTab[i];
		pTab[i] = min;
	}
}

void simpleInsertionSort( int* pTab, int nSize) {
	for(int i = 1; i < nSize; i++)
	{
		int x = pTab[i];
		int j = i - 1; 
		while(j>=0 && pTab[j] > x) {
			pTab[j + 1] = pTab[j--];
		}
		pTab[j + 1] = x;
	}
	
}

//TODO: spróbowaæ jak najbardziej zoptymalizowaæ te kody, POPRAWIC I ZROZUMIEC HEAPSORT (tak jak jest w komentarzu), zrozumieæ po co tworzymy dodatkowe zmienne

void mixedSort( int* pTab, int nSize ) {
	int l = 1;
	int p = nSize - 1;
	int k = nSize - 1;
	int temp;
	
	do {
		for( int i = p; i >= l; i-- )
		{
			if( pTab[i-1]>pTab[i] ) {
				temp = pTab[i-1];
				pTab[i - 1] = pTab[i];
				pTab[i] = temp;
				k = i;
			}
		}
		l = k + 1;
		for( int i = l; i <= p; i++ )
		{
			if( pTab[i - 1] > pTab[i] ) {
				temp = pTab[i-1];
				pTab[i - 1] = pTab[i];
				pTab[i] = temp;
				k = i;
			}
		}
		p = k - 1;
	} while(l<=p);
}

void halfFindSort(int* pTab, int nSize) {
	int l;
	int p;
	int m;
	int x;

	for(int i = 1; i < nSize; i++) //for od drugiego elementu tablicy 
	{
		x = pTab[i];
		l = 0;
		p = i - 1; // lewy i prawy koniec przedzia³u (indeks), na start to jest ca³a tablica
		while(l <= p) {
			m = (l + p) / 2; // srodek przedzia³u (indeks)
			(x < pTab[m]) ? p = m - 1 : l = m + 1; // skrocony if
		} // ta petla robi sie na poczatku raz po nic?
		for(int j = i - 1; j >= l; j--)
		{
			pTab[j + 1] = pTab[j];
		}
		pTab[l] = x; // jeœli tu zamieniê x na pTab[i], to nie dzia³a, nie bardzo wiem dlaczego, bo wygl¹da mi na to, ¿e da³oby siê usun¹æ iksa
	}
}

void quickSort( int* pTab, int nSize ) {
	sortuj(pTab,0, nSize-1);
}

void sortuj(int* pTab, int l, int p) {
	int i = l;
	int temp;
	int j = p;
	int x = pTab[(l + p) / 2];
	do {
		while(pTab[i] < x) i++;
		while(x < pTab[j]) j--;
		if(i <= j) {
			temp = pTab[i];
			pTab[i] = pTab[j];
			pTab[j] = temp;
			i++;
			j--; // to da sie skrocic chyba
		}
	} while(i <= j);
	if(l < j) sortuj(pTab, l, j);
	if(i < p) sortuj(pTab, i, p);
}

void heapSort(int* pTab, int nSize) {
	int l = nSize/2 ;
	int p = nSize-1;
	int x;
	while(l > 0) {
		l--;
		update(pTab, l, p);
	}
	while(p > 0) {
		x = pTab[0]; // na pierwszy wyraz
		pTab[0] = pTab[p];
		pTab[p] = x;
		p--;
		update(pTab, l, p);
	}
}

void update(int* pTab,int l,int p) {
	int i = l;
	int j= 2*i; // czy 2*i+1
	int x = pTab[i];
	while(j <= p) {
		if(j < p) {
			if(pTab[j] < pTab[j + 1]) j++;
		}
		if(x >= pTab[j]) break;
		pTab[i] = pTab[j];
		i = j;
		j = 2 * i; // czy 2*i+1
	}
	pTab[i] = x;
}

/*
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
	// w pascalu petla repeat while wykonuje sie dopoki warunek jest FALSZYWY

	// program 2.5, 2.2
	// sortowanie szybkie 2.10, dwie funkcje do napisania w nim, 3 parametry - tablice, lewe i prawe ograniczenie
	// potrzeba namiastki funkcji, ktora wywola quicksorta, bo on ma 3 parametry, a my przekazujemy 2

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
jakas kolejka priorytetowa - (lifo albo fifo? ktores z tych?) na tablicy
//TODO gdy zrobimy heapsort to probujmy odwrocic sortowanie na malejace
czyli costam w ifach pozmieniac, no i zachowac te funkcje w komentarzu
//!bez odwolan rekurencyjnych, ktore sa w internecie, bo bedzie karny projekt - mamy korzystac tylko z wirtha!
// ma nie byc spacji przy rzutowaniu!! (double) a nie ( double ), po nazwie funkcji nie ma spacji, wylaczone formatowanie gdy zamknie sie srednik lub zamknie blok, bo mamy sobie samemu formatowac (chyba?)
*/