#include "QFIFO.h"
// zainkl interfejs kolejki

int main()
{
	FQueue* q = FQCreate();

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

	return 0;
}
