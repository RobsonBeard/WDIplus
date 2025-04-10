#include "QFIFO.h"

FQueue* FQCreate() {
	FQueue* p = (FQueue*)malloc(sizeof(FQueue));
	if( !p ) return NULL;
	p->pHead = p->pTail = NULL; // takie podstawienie wykonuje sie od prawej do lewej
	return p;
}

int FQEmpty( FQueue* q ) {
	// gdy nie ma kolejki tez ma zwracac 1, ale gdy nie ma kolejki, to q jest NULL, czyli jest 0, wiec jest ok
	return !q || !(q->pHead); // gdy q==0 lub q->pHead == 0, to zwroci 1, w przeciwnym wypadku zwroci 0
}

int FQEnqueue( FQueue* q, QINFO*pNewInfo ) {
	if( !q ) return 0; // jeœli lista nie istnieje

	FQItem* p = (FQItem*)malloc( sizeof( FQItem ) );
	if( !p ) return 0; // jeœli alokacja pamiêci siê nie powiod³a

	//p->key = x;
	p->pInfo = pNewInfo;
	p->pNext = NULL; // bo to jest nasz ostatni

	if( !( q->pHead ) )
		q->pHead = p; // ustawiam na head, jeœli nie ma head, czyli ten element jest pierwszy
	else 
		q->pTail->pNext = p; // jeœli nie jest pierwszy, to jest ostatni, wiêc dowi¹zujê go do ogona (wskazuje ze to on jest nastepny w dotychczasowej kolejce)

	q->pTail = p; // i w koncu wstawiam go jako ogon

	return 1;
}

QINFO* FQDequeue( FQueue* q ) {
	if( FQEmpty( q ) ) return 0; 

	QINFO* p = q->pHead->pInfo; // biore wartosc glowy (pierwszego elementu)
	FQDel( q ); // usuwam ten pierwszy element z listy
	return p; 
}

void FQClear( FQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	if( FQEmpty( q ) ) {
		printf( "Kolejka nie istnieje" );
		return;
	}

	
	while( !FQEmpty(q) ) // dopóki lista nie jest pusta, usuwa pierwszy element (dzialanie FQDel opisane)
		FQDel( q );

	// trzeba jakos zwolnic dynamicznie alokowane pInfo


}

void FQRemove( FQueue** q, void( __cdecl* freeMem )( const void* ) ) {
	if( FQEmpty( *q ) ) {
		printf( "Kolejka nie istnieje" );
		return;
	}

	FQClear(*q, freeMem); // usuwam wszystkie elementy listy
	free(*q); // zwalniam pamiec
	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void FQDel( FQueue* q ) {
	if( FQEmpty( q ) ) {
		printf( "Kolejka pusta lub nie istnieje" );
		return;
	}

	FQItem* p = q->pHead; // biore pierwszy element (glowe)
	q->pHead = p->pNext; // za niego podstawiam kolejny element (po prostu nastepnik tej naszej glowy)
	// musze zwolnic dynamicznie alokowane pInfo
	free( p ); // zwalniam pamiec
}

void FQPrint( FQueue* q, void( __cdecl* printInfo )( const void* ) ) {

}
