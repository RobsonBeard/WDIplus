#include "PQueue.h"

// pomocnicze w implementacji 2 funkcje
void UpdateDown( PQItem** pQueue, int l, int p );  // update heap down between index l and p  <--- modified Update() from HeapSort
void UpdateUp( PQItem** pQueue, int l, int p );    // update heap up between index l and p  

PQueue* PQInit( int qSize ) {
	if( qSize <= 0 ) return NULL;

	PQueue* newQueue = (PQueue*)calloc( 1, sizeof( PQueue ) ); // alokuje i wype³nia zerami jeden element PQueue
	if( !newQueue ) return NULL; // niepowodzenie calloca

	newQueue->pPQueue = (PQItem**)calloc( qSize, sizeof( PQItem* ) ); // alokuje i wype³nia zerami qSize (czyli tyle ile rozmiar) elementów PQItem*
	if( !newQueue->pPQueue ) {
		free( newQueue ); // na tym etapie powiod³o siê stworzenie newQueue, wiêc przed returnem muszê wyczyœciæ newQueue
		return NULL;
	}
	
	newQueue->nPQSize = qSize;
	return newQueue;
}

int PQisEmpty( PQueue* q ) {
	return !q || !( q->nPQCurrSize ); // jesli kolejka nie istnieje lub jej CurrSize jest 0, to zwracam 1
}

int PQSize( PQueue* q ) {
	return (!q) ? PRIOR_ERROR : q->nPQCurrSize; // zwracam aktualny rozmiar
}

int PQMaxPrior( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? PRIOR_ERROR : q->pPQueue[0]->nPrior;
}

void PQClear( PQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	// ale mozna tez to zrobic na piechote, od 0 do currentSize, freememem zwalniac PQInfo i free na PQItem, nullowac costam, na koncu currentsize ustawic na 0
	// ^ lepiej zrobic to takim sposobem, jedna petla for

	if( !q || !freeMem ) {
		printf( "PQClear: Kolejka lub funkcja freeMem nie istnieje\n" );
		return;
	}

	while( !PQisEmpty( q ) ) // dopoki kolejka nie jest pusta, zwalniam pamiec
		freeMem( PQDequeue( q ) );
}

PQINFO* PQDequeue( PQueue* q ) {
	// 1. "pobraæ" informacje - utworzyc now¹ zmienn¹ wskaŸnikow¹, wskazuj¹c¹ PQINFO (zadeklarowac i poodstawic PQINFO)
	// 2. usunac PQItem, freemem? - trzymam informacje (punkt 1.), wiec moge usunac
	// 3. ostatni wrzucam do zerowego, robie update down itp
	// wpisac ostatni do 0-wego  - robi sie to po to, aby usun¹æ element, który nie ma ju¿ dzieci, czyli jest liœciem, wtedy jest bezpiecznie

	if( PQisEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wskaŸnik 

	PQItem* itemToRemove = q->pPQueue[0]; // potrzebuje tego do zwolnienia pamieci, najwyzszy priorytet
	PQINFO* p = itemToRemove->pInfo; // biore wartosc korzenia (pierwszego elementu)
	free( q->pPQueue[0] );

	//q->nPQCurrSize--; // zmniejszam rozmiar kolejki

	int queueSize = --q->nPQCurrSize; // zmienna pomocniczna, bo potem wiele razy korzystam z CurrSize

	if( queueSize > 0 ) // jeœli kolejka nie jest pusta (czyli wczesniej nie miala tylko 1 elementu), to przenoszê ostatni element na miejsce pierwszego
	{
		q->pPQueue[0] = q->pPQueue[queueSize]; // po to najpierw zdekrementowa³em nPQCurrSize, ¿eby teraz w ten sposób dostaæ siê do ostatniego elementu, przenoszê go na pocz¹tek
	}
		q->pPQueue[queueSize] = NULL;
	if( queueSize > 1 )
		UpdateDown( q->pPQueue, 0, queueSize - 1 ); // ostatni element nowego kopca bêdzie mia³ indeks = q->nPQCurrSize - 1, naprawiam kopiec

	return p; // zwraca informacje o elemencie z najwyzszym priorytetem
}

int PQEnqueue( PQueue* q, PQINFO* pNewInfo, int newInfoPrior ) {
	int queueSize = PQSize( q );

	if( !q || queueSize >= q->nPQSize ) return 0; // jeœli lista nie istnieje lub kolejka jest pe³na

	PQItem* newItem = (PQItem*)malloc( sizeof( PQItem ) ); // bede wstawial informacje pod ten element
	if( !newItem ) return 0; // jeœli alokacja pamiêci siê nie powiod³a

	newItem->pInfo = pNewInfo;
	newItem->nPrior = newInfoPrior;

	q->pPQueue[queueSize] = newItem; // indeks pierwszego wolnego miejsca to q->nPQCurrSize, czyli queueSize


	if( queueSize > 0 ) // jezeli pierwotny rozmiar byl > 0 to trzeba zrobic update
		UpdateUp( q->pPQueue, 0, queueSize ); // wyniesienie nowego elementu w górê kopca, naprawa od 0 do indeksu tego nowego elementu q->nPQCurrSize - 1

	q->nPQCurrSize++; // rozmiar kolejki zwiekszyl sie
	return 1;
}

void PQRelease( PQueue** q, void( __cdecl* freeMem )( const void* ) ) {
	if( !q || !*q ) {
		printf( "PQRelease: Kolejka lub funkcja freeMem nie istnieje\n" );
		return;
	}

	PQClear( *q, freeMem ); // usuwam wszystkie elementy listy


	free( ( *q )->pPQueue ); // zwalniam pamiêæ tablicy wskaŸników PQueue
	free( *q ); // zwalniam pamiec samego PQueue

	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void PQPrint( PQueue* q, int currentPos, void( __cdecl* printInfo )( const void* ) ) {
	// currentPos - indeks wêz³a do wydrukowania

	if( currentPos >= PQSize( q ) ) return; // jeœli indeks jest poza rozmiarem kolejki
	if( PQisEmpty( q ) || !printInfo ) {
		printf( "PQPrint: Kolejka pusta lub nie istnieje lub funkcja printInfo nie istnieje\n" );
		return;
	}

	PQItem* p = q->pPQueue[currentPos]; // biorê pierwszy element kolejki
	printf( "(%d) [%d] -> ", p->nPrior, currentPos );
	printInfo( p->pInfo );

	PQPrint( q, 2 * currentPos + 1, printInfo ); // rekurencyjne wywo³anie dla lewego i prawego dziecka
	PQPrint( q, 2 * currentPos + 2, printInfo );
}

void UpdateDown( PQItem** pQueue, int l, int p ) {
	// naprawa od l do p (czyli najczesciej do konca kopca)
	// l - indeks wêz³a, od którego zaczynamy naprawê kopca
	// p - indeks ostatniego elementu w kopcu

	if( l >= p ) return; // gdy l==p, to wêze³ startowy jest ostatnim elementem kopca, wiêc nie ma sensu nic robiæ, gdy l>p, to l jest poza zakresem kopca, 2 * l + 1 to indeks lewego dziecka, gdy jest wiekszy od indeksu ostatniego elementu, to nie ma ju¿ dzieci do porównywania
	int i = l; // zaczynam od wêz³a l
	int j = 2 * i + 1; // indeks lewego dziecka
	PQItem* x = pQueue[i]; // zapisuje element, ktory bede spychac w dol ( o indeksie l )
	while( j <= p ) // dopoki lewe dziecko (czyli przynajmniej jedno dziecko) jest w granicach kopca
	{
		if( j < p && pQueue[j]->nPrior < pQueue[j + 1]->nPrior ) j++; // teraz j bêdzie wskazywa³o na dziecko o wiêkszym priorytecie, warunki: istnieje dwoje dzieci, priorytet prawego jest wiêkszy ni¿ priorytet lewego
		if( x->nPrior >= pQueue[j]->nPrior ) break; // porównujê priorytety elementu spychanego i dziecka o wiêkszym priorytecie, jeœli spychany ma wiêkszy lub równy priorytet, to w³asnoœæ kopca jest zachowana

		// a to sie wykona, gdy priorytet elementu spychanego jest mniejszy ni¿ jego dziecka
		pQueue[i] = pQueue[j]; // przesuwam dziecko w górê
		i = j; // schodzê w dó³ z indeksami, czyli moj nowy wezel to ten, w ktorym bylo dziecko
		j = 2 * i + 1; // i licze indeks nowego dziecka
	}
	pQueue[i] = x; // wstawiam x w dobre miejsce
}

void UpdateUp( PQItem** pQueue, int l, int p ) {
	// naprawa od l do p
	// tylko uaktualnienie w gore stogu i jest tylko jeden rodzic

	if( l >= p ) return;
	int i = p; // indeks dziecka
	int ixParent = ( i - 1 ) / 2; // indeks rodzica
	PQItem* x = pQueue[i]; // element, który idzie w górê
	while( ixParent >= l && x->nPrior > pQueue[ixParent]->nPrior ) // dopóki nie jesteœmy korzeniem (elementem o najw. prior.) i priorytet x jest wiêkszy ni¿ priorytet rodzica
	{
		pQueue[i] = pQueue[ixParent]; // przesuwam rodzica w dó³ na miejsce dziecka i przechodzê w górê kopca
		i = ixParent;
		ixParent = ( i + 1 ) / 2 - 1;
	}
	pQueue[i] = x;
}

int PQSetPrior( PQueue* q, PQINFO* pInfoToFind, int newPrior, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	// korzystam z innych metod 
	return PQsetPrior( q, PQFind( q, pInfoToFind, compareInfo ), newPrior );
}

int PQsetPrior( PQueue* q, int infoPos, int newPrior ) {
	//if( PQisEmpty( q ) ) return PRIOR_ERROR;

	//int queueSize = PQSize( q );

	// musze sprawdzic czy na danej pozycji jest jakiœ element i czy w ogóle pozycja z parametru ma sens 
	//if( infoPos == POS_ERROR || infoPos == PRIOR_ERROR || infoPos >= queueSize ) return PRIOR_ERROR;

	PQItem* pInfoFound = q->pPQueue[infoPos];

	int oldPrior = PQgetPrior( q, infoPos ); // musze zachowac do returna
	if( oldPrior == PRIOR_ERROR ) return PRIOR_ERROR;

	pInfoFound->nPrior = newPrior;

	if( newPrior > oldPrior ) {
		UpdateUp( q->pPQueue, 0, infoPos ); // naprawa w górê od 0 do znalezionego elementu
	}
	else if( newPrior < oldPrior ) {
	
		UpdateDown( q->pPQueue, infoPos, PQSize(q)-1 ); // naprawa w dó³ od znalezionego elementu do koñca kopca
	}


	return oldPrior;
}

int PQGetPrior( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	// korzystam z innych metod 
	return PQgetPrior( q, PQFind( q, pInfoToFind, compareInfo ) );
}

int PQgetPrior( PQueue* q, int infoPos ) {
	if( PQisEmpty( q ) ) return PRIOR_ERROR;

	// musze sprawdzic czy na danej pozycji jest jakiœ element i czy w ogóle pozycja z parametru ma sens 
	if( infoPos == POS_ERROR || infoPos == PRIOR_ERROR || infoPos >= PQSize( q ) || infoPos < 0 ) return PRIOR_ERROR;

	return q->pPQueue[infoPos]->nPrior;
}

int PQFind( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if( PQisEmpty( q ) || !pInfoToFind ) return PRIOR_ERROR;
	if( !compareInfo ) return POS_ERROR;

	for( int i = 0; i < PQSize( q ); i++ )
	{
		if( !compareInfo( q->pPQueue[i]->pInfo, pInfoToFind ) ) // gdy wynik compare da 0, to wejdzie do if'a
		{
			return i; // indeks w pPQueue
		}
	}

	return POS_ERROR;
}