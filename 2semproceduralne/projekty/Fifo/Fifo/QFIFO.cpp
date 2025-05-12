#include "QFIFO.h"

FQueue* FQCreate() {
	FQueue* q = (FQueue*)malloc( sizeof( FQueue ) );
	if( !q ) return NULL;
	q->pHead = q->pTail = NULL; // takie podstawienie wykonuje sie od prawej do lewej
	return q;
}

int FQEmpty( FQueue* q ) {
	return !q || !( q->pHead ); // gdy q==0 lub q==NULL lub q->pHead == 0, to zwroci 1, w przeciwnym wypadku zwroci 0
}

int FQEnqueue( FQueue* q, QINFO* pNewInfo ) {
	if( !q ) return 0; // jeœli lista nie istnieje

	FQItem* p = (FQItem*)malloc( sizeof( FQItem ) );
	if( !p ) return 0; // jeœli alokacja pamiêci siê nie powiod³a

	p->pInfo = pNewInfo;
	p->pNext = NULL; // bo to jest nasz ostatni, a musze inicjalizowac

	if( !( q->pHead ) )
		q->pHead = p; // ustawiam na head, jeœli nie ma head, czyli ten element jest pierwszy
	else
		q->pTail->pNext = p; // jeœli nie jest pierwszy, to jest ostatni, wiêc dowi¹zujê go do ogona (wskazuje ze to on jest nastepny w dotychczasowej kolejce, kolejny po ogonie)

	q->pTail = p; // i w koncu wstawiam go jako ogon (bo jest ostatni)

	return 1;
}

QINFO* FQDequeue( FQueue* q ) {
	if( FQEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wskaŸnik 

	QINFO* p = q->pHead->pInfo; // biore wartosc glowy (pierwszego elementu)
	FQDel( q ); // usuwam ten pierwszy element z kolejki

	return p;
}

void FQClear( FQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	if( FQEmpty( q ) || !freeMem) {
		printf( "FQClear: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	while( !FQEmpty( q ) ) // dopóki kolejka nie jest pusta
		freeMem( FQDequeue( q ) ); // zwalniam dynamicznie alokowane pInfo, ale przed tym zwalniam dynamicznie alokowan¹ tablicê pTab, która jest w pInfo, nie robiê Del, bo zrobi³ to ju¿ FQDequeue
}

void FQRemove( FQueue** q, void( __cdecl* freeMem )( const void* ) ) {
	if( !q || !*q || !freeMem ) {
		printf( "FQRemove: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	FQClear( *q, freeMem ); // usuwam wszystkie elementy listy
	free( *q ); // zwalniam pamiec
	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void FQDel( FQueue* q ) {
	if( FQEmpty( q ) ) {
		printf( "FQDel: Kolejka pusta lub nie istnieje" );
		return;
	}

	FQItem* p = q->pHead; // biore pierwszy element (glowe, dlatego to jest FIFO - first in first out)
	q->pHead = p->pNext; // za niego podstawiam kolejny element (po prostu nastepnik tej naszej glowy), on ma ju¿ dowi¹zan¹ resztê kolejki, ogon zostaje taki sam

	if( !( q->pHead ) ) {
		q->pTail = NULL; // jeœli g³owa w tym miejscu bêdzie NULL (czyli usunêliœmy ostatni element), to muszê ustawiæ równie¿ ogon na NULL (bo usuwaj¹c ten ostatni element usun¹³em równie¿ ogon, ale nigdzie wczeœniej tego nie zaznaczy³em)
	}

	free( p ); // zwalniam pamiec
}

void FQPrint( FQueue* q, void( __cdecl* printInfo )( const void* ) ) {
	if( FQEmpty( q ) || !printInfo) {
		printf( "FQPrint: Kolejka pusta lub nie istnieje lub funkcja printInfo nie istnieje" );
		return;
	}

	FQItem* p = q->pHead; // biorê pierwszy element kolejki
	while( p ) // dopóki nie jest on NULLem
	{
		printInfo( p->pInfo ); // wypisujê jego zawartoœæ, funkcja printInfo jest w .cpp, tutaj przekazana jako parametr
		p = p->pNext; // i zamieniam p na kolejny element kolejki, ostatni element kolejki jako pNext bêdzie mia³ NULL, wtedy skoncze wypisywac
	}
}
