#include "QFIFO.h"
// zainkl interfejs kolejki

void freeInfo( const void* pInfo );
QINFO* allocInfo( int a, int b, int c );
void printInfo( const void* pInfo );

int main()
{
	FQueue* q = FQCreate();

	//! wszêdzie, gdzie nie wypisujê komunikatów w QFIFO.cpp, tylko zwracam NULL albo 0, muszê zrobiæ komunikaty w tym pliku
	
	if( !q ) {
		printf( "ERROR: Memory allocation error" );
		return 1;
	}	

	// dodac do kolejki 4 elementy (wydrukowac kolejke)
	for( int i = 1; i <= 4; i++ )
	{
		QINFO* p = allocInfo( i, i + 1, i + 2 );
		if( !p ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 2;
		}
		if( !FQEnqueue( q, p ) ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 3;
		}
	}
	FQPrint( q, printInfo );

	printf( "\n\n" );

	// usunac 3 elementy (wypisac info)
	// wypisac pozostala kolejke
	for( int i = 0; i < 3; i++ )
	{
		QINFO* p = FQDequeue( q );
		printInfo( p );
	}
	printf("Pozostala kolejka:\n");
	FQPrint( q, printInfo );

	printf( "\n\n" );

	// dodac 2 elementy (wydrukowac kolejke)
	for( int i = 1; i <= 2; i++ )
	{
		QINFO* p = allocInfo( i * 20, i * 30, i * 40 );
		if( !p ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 4;
		}
		if( !FQEnqueue( q, p ) ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 5;
		}
	}
	FQPrint( q, printInfo );
	
	
	// wyczyscic kolejke
	FQClear( q, freeInfo );

	printf( "\n\n" );

	// dodac trzy elementy (wydrukowac kolejke)
	for( int i = 1; i <= 3; i++ )
	{
		QINFO* p = allocInfo( i, i + 22, i + 33 );
		if( !p ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 2;
		}
		if( !FQEnqueue( q, p ) ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 3;
		}
	}
	FQPrint( q, printInfo );

	printf( "\n\n" );

	// usunac jeden element (Wypisac go) i wydrukowac kolejke
	
	QINFO* p = FQDequeue( q );
	printInfo( p );
	printf( "Pozostala kolejka:\n" );
	FQPrint( q, printInfo );

	printf( "\n\n" );

	// usunac CALA kolejke
	FQRemove( &q, freeInfo );


	return 0;
}

void freeInfo( const void* pInfo ) {
	// to pInfo zrzutowac na QINFO*

	if( pInfo ) {
		free( ( (QINFO*)pInfo )->pTab );
		free( (QINFO*)pInfo );
	}
}

QINFO* allocInfo( int a, int b, int c ) {
	// zaalokowac infomracje
	// sprawdzic (jak blad to NULL)
	// alokacja pTab (pole struktury)
	// sprawdzic (blad to free na info i zwrocic NULL)
	// wstawic a do klucza oraz b i c odpowiednio do 0-wego i pierwszego elementu tablicy
	// zwrocic wskaznik na info

	QINFO* q = (QINFO*)malloc( sizeof( QINFO ) );
	if( !q ) {
		return NULL;
	}
	q->pTab = (int*)malloc( 2 * sizeof( int ) );
	if( !( q->pTab ) ) {
		free( q );
		return NULL;
	}
	q->pTab[0] = b;
	q->pTab[1] = c;
	q->key = a;
	return q;
}

void printInfo( const void* pInfo )
{
	printf( "key = %d   pTab[0] = %d   pTab[1] = %d\n", ( (QINFO*)pInfo )->key, ( (QINFO*)pInfo )->pTab[0], ( (QINFO*)pInfo )->pTab[1] );
}