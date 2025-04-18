#include "PQueue.h"

// w pliku z funkcja main()

// naglowek funkcji drukujacej info uzytkownika (parametr typu const void* )
// naglowek funkcji porownujacej info uzytkowniak. Zwraca -1 pierwszy mniejszy, 1 jesli pierwszy wiekszy else 0.
//          (parametry const void* )
// naglowek funkcji zwalniajacej pamiec (parametr typu const void* )
// implementacja tych trzech funkcji


void freeInfo( const void* pInfo );
PQINFO* allocInfo( int a, int b, int c );
void printInfo( const void* pInfo );
int compare( const void* firstInfo, const void* secondInfo );


int main()
{
	/*
	//---test, dopiero jak wszystko dziala, debuggerem mozna sprawdzic czy dobrze jest wszystko zalokowane w pamieci:
	-wykreowac kolejke 20 - sto elementowa
		- dodac 6 elementow z roznymi priorytetami i w ró¿nej kolejnosci priorytetów - wydrukowac
		- usunac z kolejki( z najwiekszym priorytetem ) - wydrukowac
		- dodac dwa elementy - wydrukowac
		- wyszukac jeden elem
		- zwiekszyc mu priorytet( unikalny ) - wydrukowac
		- zmniejszyc priorytet innemu elementowi( unikalny ) - wydrukowac
		- usunac cala kolejke

		- przetestowac jak bedzie sie zachowywac modul jesli powtorza sie priorytety niektorych elementow
		( zmienic priorytet np na maksymalny - powtorzy sie i sciagnac dwa razy, po kazdym drukowanie )

	*/

	PQueue* q = PQInit( 10 ); //? ten parametr ma byc z argumentow funkcji main?

	// robie komunikaty dla funkcji, ktore nie maja ich w implementacji

	if( !q ) {
		printf( "ERROR: Queue allocation error" );
		return 1;
	}


	return 0;
}


void freeInfo( const void* pInfo ) {
	// to pInfo zrzutowac na QINFO*

	if( pInfo ) {
		free( ( (PQINFO*)pInfo )->pTab );
		free( (PQINFO*)pInfo );
	}
}

PQINFO* allocInfo( int a, int b, int c ) {
	// zaalokowac infomracje
	// sprawdzic (jak blad to NULL)
	// alokacja pTab (pole struktury)
	// sprawdzic (blad to free na info i zwrocic NULL)
	// wstawic a do klucza oraz b i c odpowiednio do 0-wego i pierwszego elementu tablicy
	// zwrocic wskaznik na info

	PQINFO* q = (PQINFO*)malloc( sizeof( PQINFO ) );
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
	q->nKey = a;
	return q;
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
