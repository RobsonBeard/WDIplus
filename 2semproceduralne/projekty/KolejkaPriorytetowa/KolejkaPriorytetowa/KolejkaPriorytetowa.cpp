#include "PQueue.h"

void freeInfo( const void* pInfo ); // funkcja zwalniajaca pamiec
PQINFO* allocInfo( int a, int b, int c );
void printInfo( const void* pInfo ); // funkcja drukujaca info uzytkownika
int compare( const void* firstInfo, const void* secondInfo ); // funkcja porownujaca info uzytkownika


int main()
{
	// wykreowac kolejke 20 - sto elementowa
	PQueue* q = PQInit( 20 );

	//! robie komunikaty dla funkcji, ktore nie maja ich w swojej implementacji

	if( !q ) {
		printf( "ERROR: Queue allocation error" );
		return 1;
	}


	//dodac 6 elementow z roznymi priorytetami i w ró¿nej kolejnosci priorytetów - wydrukowac
	for( int i = 1; i <= 6; i++ )
	{
		PQINFO* p = allocInfo( i, i + 1, i + 2 );
		if( !p ) {
			printf( "ERROR: allocInfo - Memory allocation error" );
			return 2;
		}
		if( !PQEnqueue( q, p, 5 * i ) ) {
			printf( "ERROR: Enqueue error" );
			return 3;
		}
	}
	printf( "Dodane 6 elementow:\n" );
	PQPrint( q, 0, printInfo );
	printf( "\n" );

	// usunac z kolejki( z najwiekszym priorytetem ) - wydrukowac
	PQINFO* el1 = PQDequeue( q );

	if( !el1 ) {
		printf( "ERROR: Dequeue error" );
		return 4;
	}

	printf( "Po dequeue:\n" );
	PQPrint( q, 0, printInfo );

	//dodac dwa elementy - wydrukowac
	PQINFO* el2 = allocInfo( 2, 1, 3 );
	if( !el2 ) {
		printf( "ERROR: allocInfo - Memory allocation error" );
		return 5;
	}

	if( !PQEnqueue( q, el2, 7 ) ) {
		printf( "ERROR: Enqueue error" );
		return 6;
	}

	PQINFO* el3 = allocInfo( 10, 13, 14 );
	if( !el3 ) {
		printf( "ERROR: allocInfo - Memory allocation error" );
		return 7;
	}

	if( !PQEnqueue( q, el3, 42 ) ) {
		printf( "ERROR: Enqueue error" );
		return 8;
	}

	printf( "\nPo dodaniu 2 elemetow:\n" );
	PQPrint( q, 0, printInfo );

	//wyszukac jeden elem
	PQINFO* el4 = allocInfo( 3, 4, 5 );

	if( !el4 ) {
		printf( "ERROR: allocInfo - Memory allocation error" );
		return 9;
	}

	int foundPos = PQFind( q, el4, compare );

	if( foundPos == POS_ERROR ) {
		printf( "ERROR: PQFind error" );
		return 11;
	}

	printf( "\nZnaleziona pozycja elementu: %d\n", foundPos );

	//zwiekszyc mu priorytet( unikalny ) - wydrukowac
	PQsetPrior( q, foundPos, 33 );
	printf( "\nPo zwiekszeniu mu priorytetu:\n" );
	PQPrint( q, 0, printInfo );


	//zmniejszyc priorytet innemu elementowi( unikalny ) - wydrukowac
	PQINFO* el5 = allocInfo( 5, 6, 7 );
	if( !el5 ) {
		printf( "ERROR: allocInfo - Memory allocation error" );
		return 10;
	}
	PQSetPrior( q, el5, 9, compare );
	printf( "\nPo zmniejszeniu priorytetu z 25 na 9:\n" );
	PQPrint( q, 0, printInfo );

	//przetestowac jak bedzie sie zachowywac modul jesli powtorza sie priorytety niektorych elementow
	//( zmienic priorytet np na maksymalny - powtorzy sie i sciagnac dwa razy, po kazdym drukowanie )
	PQsetPrior( q, 2, 42 ); // priorytet z 10 na 42, juz sie nie chcialem alokowac, dlatego podalem indeks
	printf( "\nPo zwiekszeniu priorytetu z 10 na 42, aby sie powtarzal:\n" );
	PQPrint( q, 0, printInfo );

	PQINFO* el6 = PQDequeue( q );
	PQINFO* el7 = PQDequeue( q );

	printf( "\nPo dequeue dwa razy:\n" );
	PQPrint( q, 0, printInfo );


	freeInfo( el1 );
	freeInfo( el4 );
	freeInfo( el5 );
	freeInfo( el6 );
	freeInfo( el7 );
	//usunac cala kolejke
	PQRelease( &q, freeInfo );

	return 0;
}


void freeInfo( const void* pInfo ) {
	// to pInfo zrzutowac na PQINFO*

	if( pInfo ) {
		free( ( (PQINFO*)pInfo )->pTab );
		free( (PQINFO*)pInfo );
	}
}

PQINFO* allocInfo( int a, int b, int c ) {
	PQINFO* q = (PQINFO*)malloc( sizeof( PQINFO ) ); // alokuje informacje

	if( !q ) {
		printf( "allocInfo: blad alokacji pamieci" );
		return NULL;
	}

	q->pTab = (int*)malloc( 2 * sizeof( int ) ); // alokuje pTab (pole struktury)
	if( !( q->pTab ) ) {
		printf( "allocInfo: blad alokacji pamieci" );
		free( q );
		return NULL;
	}

	q->pTab[0] = b; // wstawiam do kluczy
	q->pTab[1] = c;
	q->nKey = a;

	return q; // zwracam wskaznik na informacje
}

void printInfo( const void* pInfo )
{
	printf( "key = %d   pTab[0] = %d   pTab[1] = %d\n", ( (PQINFO*)pInfo )->nKey, ( (PQINFO*)pInfo )->pTab[0], ( (PQINFO*)pInfo )->pTab[1] );
}

int compare( const void* firstInfo, const void* secondInfo ) {
	// porownanie pola Key
	// zwraca 1, 0, -1 w zaleznosci od porownania
	if( ( (PQINFO*)firstInfo )->nKey > ( (PQINFO*)secondInfo )->nKey ) return 1;
	if( ( (PQINFO*)firstInfo )->nKey < ( (PQINFO*)secondInfo )->nKey ) return -1;
	return 0;
}



/*
		moje testy
	printf( "rozmiar poczatkowy: %d\n", PQSize( q ) );

	for( int i = 1; i <= 4; i++ )
	{
		PQINFO* p = allocInfo( i, i + 1, i + 2 );
		if( !p ) {
			printf( "ERROR: Memory allocation error or queue does not exist" );
			return 2;
		}
		if( !PQEnqueue( q, p , 5*i) ) {
			printf( "ERROR: Enqueue error" );
			return 3;
		}
	}

	printf( "curr size po dodaniu: %d\n", PQSize( q ) );
	printf( "Czy pusta? %s\n", PQisEmpty( q ) ? "Tak" : "Nie" );

	PQPrint( q, 0, printInfo );

	//PQINFO* pTest = allocInfo(1,2,3);
	PQINFO* pTest = allocInfo(4,5,6);
	if( !pTest ) {
		printf( "ERROR: Memory allocation error or queue does not exist" );
		return 4;
	}
	//printf( "\n" );
	//printInfo( pTest );

	int oldPriorTest1 = PQSetPrior(q,pTest,4,compare);
	if( oldPriorTest1 == PRIOR_ERROR || oldPriorTest1 == POS_ERROR ) {
		printf( "ERROR: Error while modifying priors" );
		return 5;
	}

	printf("\noldPriorTest1: %d\n",oldPriorTest1);
	PQPrint( q, 0, printInfo );

	int oldPriorTest2 = PQsetPrior( q, 2, 33 );
	printf( "\noldPriorTest2: %d\n", oldPriorTest2 );
	PQPrint( q, 0, printInfo );

	printf( "\n" );
	PQPrint( q, 1, printInfo ); // roznica miedzy tym pierwszym indeksem

	printf( "\n" );
	PQInfo* infoDoKosza = PQDequeue( q );
	freeInfo( infoDoKosza ); // zeby nie bylo wycieku pamieci
	//PQDequeue( q );
	PQPrint( q, 0, printInfo );

	printf( "Maks priorytet: %d\n", PQMaxPrior( q ) );
	printf( "Czy pusta? %s\n", PQisEmpty( q ) ? "Tak" : "Nie" );

	PQClear( q, freeInfo );
	PQPrint( q, 0, printInfo );

	PQINFO* p = allocInfo( 10, 20, 30 );
	if( !p ) {
		printf( "ERROR: Memory allocation error or queue does not exist" );
		return 6;
	}
	if( !PQEnqueue( q, p, 69 ) ) {
		printf( "ERROR: Memory allocation error or queue does not exist" );
		return 7;
	}

	PQPrint( q, 0, printInfo );

	PQRelease( &q, freeInfo );
	*/