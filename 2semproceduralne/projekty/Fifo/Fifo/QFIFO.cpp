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

int FQEnqueue( FQueue* q, int x ) {
	if( !q ) return 0; // jeœli lista nie istnieje

	FQItem* p = (FQItem*)malloc( sizeof( FQItem ) );
	if( !p ) return 0; // jeœli alokacja pamiêci siê nie powiod³a

	p->key = x;
	p->pNext = NULL; // bo to jest nasz ostatni

	if( !( q->pHead ) )
		q->pHead = p; // ustawiam na head, jeœli nie ma head, czyli ten element jest pierwszy
	else 
		q->pTail->pNext = p; // jeœli nie jest pierwszy, to jest ostatni, wiêc dowi¹zujê go do ogona

	q->pTail = p;

	return 1;
}

int FQDequeue( FQueue* q ) {
	if( FQEmpty( q ) ) return INT_MIN; // zwracam INT_MIN bo 0 to jest akceptowalna wartosc, ktora normalnie moglaby wystapic, a chce ja zwrocic

	int p = q->pHead->key; // biore wartosc glowy (pierwszego elementu)
	FQDel( q ); // usuwam ten pierwszy element z listy
	return p; 
}

void FQClear( FQueue* q ) {
	if( !q ) {
		printf( "Kolejka nie istnieje" );
		return;
	}
	
	while( !FQEmpty(q) ) // dopóki lista nie jest pusta, usuwa pierwszy element (dzialanie FQDel opisane)
		FQDel( q );
}

void FQRemove( FQueue** q ) {
	if( !q ) {
		printf( "Kolejka nie istnieje" );
		return;
	}

	FQClear(*q); // usuwam wszystkie elementy listy
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
	// zastanawiam sie czy dzialaloby: q->pHead = q->pHead->pNext;
	free( p ); // zwalniam pamiec
}