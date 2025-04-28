#include "Sort.h"

#define MAXLINE 10
#define PARAM_NO 2
#define MY_DEBUG_CONST

typedef void ( *pFType )( int* pTab, int nSize ); // moj typ wskaznikowy na funkcje

int createTab( int**, int );
void initTab( int* pTab, int nSize );
void printTab( int* pTab, int nSize );
void printTabTest( int* pTab, int nSize );


// parametr wejsciowy:
// Project -> Properties -> Debugging -> Command Arguments

int main( int argc, char* argv[] )
{

	if( argc != PARAM_NO ) {
		printf( "Usage: %s <tab_size> \n", argv[0] );
		return 1;
	} // tym razem jest tylko jeden dodatkowy parametr, rozmiar tablicy

	pFType pSortTab[] = {bubbleSort, simpleInsertionSort, simpleSelectionSort, mixedSort,halfFindSort,quickSort,heapSort};
	const char* sortNames[] = {"bubbleSort", "simpleInsertionSort", "simpleSelectionSort", "mixedSort", "halfFindSort", "quickSort", "heapSort"};
	// tutaj bede dodawal kolejne sortowania

	int nSize = atoi( argv[1] ); // funkcja biblioteczna - napis do inta, istnieje tez np. atof()

	int* controlArray = NULL;
	if( !createTab( &controlArray, nSize ) ) {
		printf( "controlArray - Memory allocation error!\n" );
		return 2;
	}

	int* testingArray = NULL;
	if( !createTab( &testingArray, nSize ) ) {
		printf( "Memory allocation error!\n" );
		return 3;
	}

	initTab( controlArray, nSize );

#ifdef MY_DEBUG_CONST
	printf( "Tablica nieposortowana:\n" );
	printTabTest( controlArray, nSize );
	printf( "\n" );
#endif // MY_DEBUG_CONST


	int sortsNo = sizeof( pSortTab ) / sizeof( pFType ); // obliczam rozmiar tablicy ze wskaznikami do funkcji

	double relativeTime = 0;

	for( int i = 0; i < sortsNo; i++ )
	{
		memcpy( testingArray, controlArray, nSize * sizeof( int ) ); // kopiuje DO testing Z control, tyle bajtow ile po prawej stronie (czyli przekopiowany rozmiar z malloca)

		relativeTime = (double)clock() / CLOCKS_PER_SEC; // najpierw mierze czas przed wykonaniem sortowania, zeby potem moc zmierzyc czas samego sortowania
		pSortTab[i]( testingArray, nSize );
		relativeTime = (double)clock() / CLOCKS_PER_SEC - relativeTime;

		printf( "%s: %.3lfs\n", sortNames[i], relativeTime );

#ifdef MY_DEBUG_CONST
		printf( "\n" );
		printTabTest( testingArray, nSize );
		printf( "\n" );
#endif // MY_DEBUG_CONST
	}


	free( controlArray );
	free( testingArray ); // zwolnienie zalokowanej pamieci

	return 0;
}

// tutaj te pomocnicze funkcje itp

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
	for( int i = 0; i < nSize && i < 50; i++ ) // tu jest dodany warunek, ¿eby zawsze wydrukowalo sie max 50 elementow
	{
		printf( "%d ", *pTab++ );
		if( ( i + 1 ) % MAXLINE == 0 ) printf( "\n" );
	}
}

void printTab( int* pTab, int nSize ) {
	for( int i = 0; i < nSize; i++ )
	{
		printf( "%d ", *pTab++ );
		if( ( i + 1 ) % MAXLINE == 0 ) printf( "\n" );
	}
}