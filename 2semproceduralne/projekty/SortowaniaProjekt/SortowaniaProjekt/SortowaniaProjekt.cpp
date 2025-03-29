#include "Sort.h"

#define PARAM_NO 2
#define MY_DEBUG_CONST

typedef void ( *pFType )( int *pTab, int nSize ); // moj typ wskaznikowy na funkcje
//? czy to ma byc w tym miejscu?

int createTab( int**, int );
void initTab( int* pTab, int nSize );
void printTab( int* pTab, int nSize );
void printTabTest( int* pTab, int nSize );
//? czy to ma byc w tym miejscu?

int main(int argc, char* argv[])
{

	if( argc != PARAM_NO ) {
		printf( "Usage: %s <tab_size> \n", argv[0] );
		return 1;
	} // tym razem jest tylko jeden dodatkowy parametr, rozmiar tablicy
	
	pFType pSortTab[] = { bubbleSort, simpleInsertionSort, simpleSelectionSort, mixedSort,halfFindSort,quickSort,heapSort };
	const char* sortNames[] = { "bubbleSort","simpleInsertionSort","simpleSelectionSort", "mixedSort", "halfFindSort", "quickSort","heapSort" };
	// tutaj bede dodawal kolejne sortowania

	int nSize = atoi( argv[1] ); // funkcja biblioteczna - napis do inta, istnieje tez np. atof()

	int* controlArray = NULL; 
	if( !createTab( &controlArray, nSize ) ) {
		printf( "Memory allocation error!\n" );
		return 2;
	} 

	int* testingArray = NULL;
	if( !createTab( &testingArray, nSize ) ) {
		printf( "Memory allocation error!\n" );
		return 3;
	}

	initTab( controlArray, nSize );

	#ifdef MY_DEBUG_CONST
	printTabTest( controlArray, nSize );
	printf( "\n");
	#endif // MY_DEBUG_CONST


	int sortsNo = sizeof( pSortTab ) / sizeof( pFType ); // obliczam rozmiar tablicy ze wskaznikami do funkcji

	double relativeTime = 0;

	for( int i = 0; i < sortsNo; i++ )
	{
		memcpy( testingArray, controlArray, nSize * sizeof( int ) ); // kopiuje DO testing Z control, tyle bajtow ile po prawej stronie (czyli przekopiowany rozmiar z malloca)

		relativeTime = (double) clock() / CLOCKS_PER_SEC; // najpierw mierze czas przed wykonaniem sortowania, zeby potem moc zmierzyc czas samego sortowania
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

