#include "PQueue.h"

PQueue* PQInit( int qSize ) {
	return (PQueue*)calloc( qSize, sizeof( PQueue ) );
}

int PQisEmpty( PQueue* q ) {
	return !q || !( q->nPQCurrSize ); // jesli kolejka nie istnieje lub jej CurrSize jest 0, to zwracam 1
}

int PQSize( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? 0 : q->nPQCurrSize; //! nie jestem pewien który tutaj size
}

int PQMaxPrior( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? PRIOR_ERROR : q->pPQueue[0]->nPrior;
}

void PQClear( PQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	if( PQisEmpty( q ) || !freeMem ) {
		printf( "PQClear: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	while( !PQisEmpty( q ) )
		freeMem( PQDequeue( q ) );

	// ma usuwac wszystkie PQItem z kolejki, najpierw usunac, potem zwolnic pamiec czyli freeMem( PQDequeue( ) ), dopoki kolejka nie jest pusta
	// ale mozna tez to zrobic na piechote, od 0 do currentSize, freememem zwalniac PQInfo i free na PQItem, nullowac costam, na koncu currentsize ustawic na 0
}

PQINFO* PQDequeue( PQueue* q ) {
	// zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie, (trzeba pamietac o czyszczeniu pamieci)

	if( PQisEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wskaŸnik 

	PQINFO* p = q->pPQueue[0]->pInfo; // biore wartosc glowy (pierwszego elementu)

	free( q->pPQueue[0]->pInfo );

	//TODO moze sprawdzic czy CurrSize nie jest juz rowny nSize?, cos sie na pewno kombinuje tutaj z rozmiarem
	q->pPQueue[0] = q->pPQueue[q->nPQCurrSize];

	//UpdateDown(q->pPQueue,0,q->nPQCurrSize); // tu cos z priorytetami trzeba kombinowac

	return p;

	// 1. "pobraæ" informacje - utworzyc now¹ zmienn¹ wskaŸnikow¹, wskazuj¹c¹ PQINFO (zadeklarowac i poodstawic PQINFO)
	// 2. usunac PQItem, freemem? - trzymam informacje (punkt 1.), wiec moge usunac
	// 3. ostatni wrzucam do zerowego, robie update down itp
}

void UpdateDown( PQItem** pQueue, int l, int p )
{
	// analogicznie jak w sortowaniu stogowym ale zmienionic
	// przetestowac najpierw ta funkcje w sortowaniu malejacym!!!
	//    (wybiera sie element o wiekszym priorytcie)
	// tak aby pierwszy element mial najwiêkszy proirytet
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1; 
	PQItem* x = pQueue[i];
	while( j <= p ) {
		if( j < p && pQueue[j]->nPrior > pTab[j + 1] ) j++; 
		if( x <= pTab[j] ) break; 
		pTab[i] = pTab[j];
		i = j;
		j = 2 * i + 1;
	}
	pTab[i] = x;
}

void UpdateUp( PQItem** pQueue, int l, int p )
{
	if( l >= p ) return;
	int i = l;
	int j = 2 * i + 1;
	int x = pTab[i];
	while( j <= p ) {
		if( j < p && pTab[j] < pTab[j + 1] ) j++;
		if( x >= pTab[j] ) break;
		pTab[i] = pTab[j];
		i = j;
		j = 2 * i + 1;
	}
	pTab[i] = x;
	// analog jak w UpdateDown
	// tylko uaktualnienie w gore stogu i jest tylko jeden rodzic
	// uwazac przy liczeniu indeksu rodzica, petla z dwoma warunkami, bo przy UpdateDown cos jest i dopiero w srodku jest dodatkowy warunek z break
	// a tutaj ten warunek jest w naglowku petli i ten indeks ma byc >= l chyba, ale jesli l jest 0 to w pewnym momencie musze otrzymac -1, zeby sie petla przerwala
	// dlatego trzeba tutaj uzyc jakiegos sprytnego wyrazenia
}

//PQDeQueue()
//{
	// zwraca informacje z indeksu 0
	// wpisac ostatni do 0-wego
	// uaktualnic w dol (update na dol)
//}

//PQEnQueue() // parametr: kolejka, informacja wstawiana, priorytet
//{
	// sprawdzic czy nie przepelnione, czy jest kolejka ( 2 rozne bledy )
// funkcja jest typu int - czy sie powiodlo czy nie
// dynamiczna alokacja pamieci, wstawiam informacje pod ten element
  // wstawic na koncu
  // uaktualnic w gore - tutaj przydalaby sie wiedza z odwrocenia kolejnosci sortowania heapsorta (z rosnacego na malejace), jest troszke prostsze, jest tylko jeden przodek zamiast dwoch potomkow, tu jakies sprytniejsze wyrazenie
// jakos currentsize +1?
//}

