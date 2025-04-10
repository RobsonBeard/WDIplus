#include "QFIFO.h"
// zainkl interfejs kolejki

void freeInfo( const void* pInfo);
QINFO* allocInfo( int a, int b, int c );
void printInfo( const void* pInfo );

int main()
{
	FQueue* q = FQCreate();
	// sprawdzic q i komunikat
	if( !q ) {
		printf( "ERROR: Memory allocation error (chyba)" );
		return 1;
	}
	

	for( int i = 1; i <= 4; i++ )
	{
		// dodac do kolejki 4 elementy (wydrukowac kolejke)
		QINFO* p = allocInfo( i, i + 1, i + 2 );
		FQEnqueue(q,p);
	}
	FQPrint( q, printInfo );

	// usunac 3 elementy (wypisac info)
	// wypisac pozostala kolejke

	// dodac 2 elementy (wydrukowac kolejke)
	// wyczyscic kolejke
	
	FQClear( q, freeInfo );
	
	// dodac trzy elementy (wydrukowac kolejke)
	// usunac jeden element (Wypisac go) i wydrukowac kolejke
	// usunac CALA kolejke
	
	FQRemove( &q, freeInfo );




	/*
		stare:
	
	// mozna funkcje sobie dopisac, ktora wypisze wszystkie elementy az do NULLa
	// na nastepny raz ma byc wszystko zrobione

	//! potestowac jeszcze te wszystkie funkcje i pozastanawiac sie


	FQEnqueue( q, 10 );
	FQEnqueue( q, 11 );
	FQEnqueue( q, 12 );
	FQEnqueue( q, 13 );

	printf( "%d\n", FQDequeue( q ) );
	printf( "%d\n", FQDequeue( q ) );
	FQDel( q );
	printf( "empty? %d\n", FQEmpty(q) );
	printf( "%d\n", FQDequeue( q ) );
	printf( "empty? %d\n", FQEmpty(q) );
	*/


	return 0;
}

void freeInfo( const void* pInfo) {
	// to pInfo zrzutowac na QINFO*

	if( pInfo ) {
		free( ((QINFO*)pInfo)->pTab );
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
	q->pTab = (int*)malloc(2*sizeof( int ));
	if( !( q->pTab ) ) {
		free( q );
		return NULL;
	}
	q->pTab[0] = b;
	q->pTab[1] = c;
	q->key = a;
	return q;
}

void printInfo( const void* pInfo ) {
	printf( "key = %d   pTab[0] = %d   pTab[1] = %d\n", ( (QINFO*)pInfo )->key, ( (QINFO*)pInfo )->pTab[0], ( (QINFO*)pInfo )->pTab[1]);
}