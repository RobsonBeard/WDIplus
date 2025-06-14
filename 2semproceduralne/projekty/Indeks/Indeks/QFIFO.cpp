#include "QFIFO.h"

FQueue* FQCreate() {
	return (FQueue*)calloc( 1, sizeof( FQueue) );
}

int FQEmpty( FQueue* q ) {
	return !q || !( q->pHead ); // gdy q==0 lub q==NULL lub q->pHead == 0, to zwroci 1, w przeciwnym wypadku zwroci 0
}

int	FQEnqueue( FQueue* q, int newInfo ) {
	if( !q ) return 0; // je�li lista nie istnieje

	FQItem* p = (FQItem*)malloc( sizeof( FQItem ) );
	if( !p ) return 0; // je�li alokacja pami�ci si� nie powiod�a

	p->lineNo = newInfo;
	p->pNext = NULL; // bo to jest nasz ostatni, a musze inicjalizowac

	if( !( q->pHead ) )
		q->pHead = p; // ustawiam na head, je�li nie ma head, czyli ten element jest pierwszy
	else
		q->pTail->pNext = p; // je�li nie jest pierwszy, to jest ostatni, wi�c dowi�zuj� go do ogona (wskazuje ze to on jest nastepny w dotychczasowej kolejce, kolejny po ogonie)

	q->pTail = p; // i w koncu wstawiam go jako ogon (bo jest ostatni)

	return 1;
}

int FQDequeue( FQueue* q ) {
	if( FQEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wska�nik 

	int p = q->pHead->lineNo; // biore wartosc glowy (pierwszego elementu)
	FQDel( q ); // usuwam ten pierwszy element z kolejki

	return p;
}

void FQClear( FQueue* q ) {
	if( FQEmpty( q )) {
		printf( "FQClear: Kolejka nie istnieje" );
		return;
	}

	while( !FQEmpty( q ) ) // dop�ki kolejka nie jest pusta
		FQDequeue( q ); 
}

void FQRemove( FQueue** q) {
	if( !q || !*q ) {
		printf( "FQRemove: Kolejka nie istnieje" );
		return;
	}

	FQClear( *q ); // usuwam wszystkie elementy listy
	free( *q ); // zwalniam pamiec
	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void FQDel( FQueue* q ) {
	if( FQEmpty( q ) ) {
		printf( "FQDel: Kolejka pusta lub nie istnieje" );
		return;
	}

	FQItem* p = q->pHead; // biore pierwszy element (glowe, dlatego to jest FIFO - first in first out)
	q->pHead = p->pNext; // za niego podstawiam kolejny element (po prostu nastepnik tej naszej glowy), on ma ju� dowi�zan� reszt� kolejki, ogon zostaje taki sam

	if( !( q->pHead ) ) {
		q->pTail = NULL; // je�li g�owa w tym miejscu b�dzie NULL (czyli usun�li�my ostatni element), to musz� ustawi� r�wnie� ogon na NULL (bo usuwaj�c ten ostatni element usun��em r�wnie� ogon, ale nigdzie wcze�niej tego nie zaznaczy�em)
	}

	free( p ); // zwalniam pamiec
}

void FQPrint( FQueue* q, FILE* fout ) {
	if( FQEmpty( q ) ) {
		printf( "FQPrint: Kolejka pusta lub nie istnieje" );
		return;
	}

	FQItem* p = q->pHead; // bior� pierwszy element kolejki
	while( p ) // dop�ki nie jest on NULLem
	{
		//printf( "%3d ", p->lineNo ); // wersja do konsoli
		fprintf( fout, "%3d ", p->lineNo ); // zmienic formatowanie ewentualnie

		p = p->pNext; // i zamieniam p na kolejny element kolejki, ostatni element kolejki jako pNext b�dzie mia� NULL, wtedy skoncze wypisywac
	}
}
