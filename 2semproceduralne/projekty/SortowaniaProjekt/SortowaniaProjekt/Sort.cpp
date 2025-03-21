#include "Sort.h"



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
	srand( (unsigned)time( NULL ) ); // inicjujê generator liczb pseudolosowych
	for( int i = 0; i < nSize; i++ ) {
		*pTab++ = rand() % nSize; // rand daje du¿e liczby, w ten sposób je zmniejszam
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
		int j = i - 1; // indeks na lewo
		while(j>=0 && pTab[j] > x) {
			pTab[j + 1] = pTab[j];
			j--;
			// albo t[j+1] = t[j--]
		}
		pTab[j + 1] = x;
	}
	// schematy dzialania w zeszycie!
}