#include "PQueue.h"

PQueue* PQInit( int qSize ) {
	return (PQueue*)calloc( qSize, sizeof( PQueue ) );
}

int PQisEmpty( PQueue* q ) {
	return !q || !(q->nPQCurrSize); // jesli kolejka nie istnieje lub jej CurrSize jest 0, to zwracam 1
}

int PQSize( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? 0 : q->nPQCurrSize; //! nie jestem pewien kt�ry tutaj size
} 

int PQMaxPrior( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? PRIOR_ERROR : q->pPQueue[0]->nPrior;
}

void PQClear( PQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	if( PQisEmpty( q ) || !freeMem) {
		printf( "PQClear: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	while( !PQisEmpty( q ) ) 
		freeMem( PQDequeue( q ) ); 
}

PQINFO* PQDequeue( PQueue* q ) {
	// zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie, (trzeba pamietac o czyszczeniu pamieci)

	if( PQisEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wska�nik 

	PQINFO* p = q->pPQueue[0]->pInfo; // biore wartosc glowy (pierwszego elementu)
	//TODO: tu sko�czy�em, trzeba my�le�
	// tutaj updateDown? nie wiem
	//FQDel( q ); // usuwam ten pierwszy element z kolejki

	return p;
}

//UpdateDown()
//{
	// analogicznie jak w sortowaniu stogowym ale zmienionic
	// przetestowac najpierw ta funkcje w sortowaniu malejacym!!!
	//    (wybiera sie element o wiekszym priorytcie)
	// tak aby pierwszy element mial najwi�kszy proirytet
//}

//UpdateUp()
//{
	// analog jak w UpdateDown
	// tylko uaktualnienie w gore stogu i jest tylko jeden rodzic 
//}

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

