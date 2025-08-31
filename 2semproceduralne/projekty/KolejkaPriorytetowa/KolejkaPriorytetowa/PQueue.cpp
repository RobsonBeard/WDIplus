#include "PQueue.h"

// pomocnicze w implementacji 2 funkcje
void UpdateDown( PQItem** pQueue, int l, int p );  // update heap down between index l and p  <--- modified Update() from HeapSort
void UpdateUp( PQItem** pQueue, int l, int p );    // update heap up between index l and p  

PQueue* PQInit( int qSize ) {
	if( qSize <= 0 ) return NULL;

	PQueue* newQueue = (PQueue*)calloc( 1, sizeof( PQueue ) ); // alokuje i wype�nia zerami jeden element PQueue
	if( !newQueue ) return NULL; // niepowodzenie calloca

	newQueue->pPQueue = (PQItem**)calloc( qSize, sizeof( PQItem* ) ); // alokuje i wype�nia zerami qSize (czyli tyle ile rozmiar) element�w PQItem*
	if( !newQueue->pPQueue ) {
		free( newQueue ); // na tym etapie powiod�o si� stworzenie newQueue, wi�c przed returnem musz� wyczy�ci� newQueue
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
	// 1. "pobra�" informacje - utworzyc now� zmienn� wska�nikow�, wskazuj�c� PQINFO (zadeklarowac i poodstawic PQINFO)
	// 2. usunac PQItem, freemem? - trzymam informacje (punkt 1.), wiec moge usunac
	// 3. ostatni wrzucam do zerowego, robie update down itp
	// wpisac ostatni do 0-wego  - robi sie to po to, aby usun�� element, kt�ry nie ma ju� dzieci, czyli jest li�ciem, wtedy jest bezpiecznie

	if( PQisEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wska�nik 

	PQItem* itemToRemove = q->pPQueue[0]; // potrzebuje tego do zwolnienia pamieci, najwyzszy priorytet
	PQINFO* p = itemToRemove->pInfo; // biore wartosc korzenia (pierwszego elementu)
	free( q->pPQueue[0] );

	//q->nPQCurrSize--; // zmniejszam rozmiar kolejki

	int queueSize = --q->nPQCurrSize; // zmienna pomocniczna, bo potem wiele razy korzystam z CurrSize

	if( queueSize > 0 ) // je�li kolejka nie jest pusta (czyli wczesniej nie miala tylko 1 elementu), to przenosz� ostatni element na miejsce pierwszego
	{
		q->pPQueue[0] = q->pPQueue[queueSize]; // po to najpierw zdekrementowa�em nPQCurrSize, �eby teraz w ten spos�b dosta� si� do ostatniego elementu, przenosz� go na pocz�tek
	}
		q->pPQueue[queueSize] = NULL;
	if( queueSize > 1 )
		UpdateDown( q->pPQueue, 0, queueSize - 1 ); // ostatni element nowego kopca b�dzie mia� indeks = q->nPQCurrSize - 1, naprawiam kopiec

	return p; // zwraca informacje o elemencie z najwyzszym priorytetem
}

int PQEnqueue( PQueue* q, PQINFO* pNewInfo, int newInfoPrior ) {
	int queueSize = PQSize( q );

	if( !q || queueSize >= q->nPQSize ) return 0; // je�li lista nie istnieje lub kolejka jest pe�na

	PQItem* newItem = (PQItem*)malloc( sizeof( PQItem ) ); // bede wstawial informacje pod ten element
	if( !newItem ) return 0; // je�li alokacja pami�ci si� nie powiod�a

	newItem->pInfo = pNewInfo;
	newItem->nPrior = newInfoPrior;

	q->pPQueue[queueSize] = newItem; // indeks pierwszego wolnego miejsca to q->nPQCurrSize, czyli queueSize


	if( queueSize > 0 ) // jezeli pierwotny rozmiar byl > 0 to trzeba zrobic update
		UpdateUp( q->pPQueue, 0, queueSize ); // wyniesienie nowego elementu w g�r� kopca, naprawa od 0 do indeksu tego nowego elementu q->nPQCurrSize - 1

	q->nPQCurrSize++; // rozmiar kolejki zwiekszyl sie
	return 1;
}

void PQRelease( PQueue** q, void( __cdecl* freeMem )( const void* ) ) {
	if( !q || !*q ) {
		printf( "PQRelease: Kolejka lub funkcja freeMem nie istnieje\n" );
		return;
	}

	PQClear( *q, freeMem ); // usuwam wszystkie elementy listy


	free( ( *q )->pPQueue ); // zwalniam pami�� tablicy wska�nik�w PQueue
	free( *q ); // zwalniam pamiec samego PQueue

	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void PQPrint( PQueue* q, int currentPos, void( __cdecl* printInfo )( const void* ) ) {
	// currentPos - indeks w�z�a do wydrukowania

	if( currentPos >= PQSize( q ) ) return; // je�li indeks jest poza rozmiarem kolejki
	if( PQisEmpty( q ) || !printInfo ) {
		printf( "PQPrint: Kolejka pusta lub nie istnieje lub funkcja printInfo nie istnieje\n" );
		return;
	}

	PQItem* p = q->pPQueue[currentPos]; // bior� pierwszy element kolejki
	printf( "(%d) [%d] -> ", p->nPrior, currentPos );
	printInfo( p->pInfo );

	PQPrint( q, 2 * currentPos + 1, printInfo ); // rekurencyjne wywo�anie dla lewego i prawego dziecka
	PQPrint( q, 2 * currentPos + 2, printInfo );
}

void UpdateDown( PQItem** pQueue, int l, int p ) {
	// naprawa od l do p (czyli najczesciej do konca kopca)
	// l - indeks w�z�a, od kt�rego zaczynamy napraw� kopca
	// p - indeks ostatniego elementu w kopcu

	if( l >= p ) return; // gdy l==p, to w�ze� startowy jest ostatnim elementem kopca, wi�c nie ma sensu nic robi�, gdy l>p, to l jest poza zakresem kopca, 2 * l + 1 to indeks lewego dziecka, gdy jest wiekszy od indeksu ostatniego elementu, to nie ma ju� dzieci do por�wnywania
	int i = l; // zaczynam od w�z�a l
	int j = 2 * i + 1; // indeks lewego dziecka
	PQItem* x = pQueue[i]; // zapisuje element, ktory bede spychac w dol ( o indeksie l )
	while( j <= p ) // dopoki lewe dziecko (czyli przynajmniej jedno dziecko) jest w granicach kopca
	{
		if( j < p && pQueue[j]->nPrior < pQueue[j + 1]->nPrior ) j++; // teraz j b�dzie wskazywa�o na dziecko o wi�kszym priorytecie, warunki: istnieje dwoje dzieci, priorytet prawego jest wi�kszy ni� priorytet lewego
		if( x->nPrior >= pQueue[j]->nPrior ) break; // por�wnuj� priorytety elementu spychanego i dziecka o wi�kszym priorytecie, je�li spychany ma wi�kszy lub r�wny priorytet, to w�asno�� kopca jest zachowana

		// a to sie wykona, gdy priorytet elementu spychanego jest mniejszy ni� jego dziecka
		pQueue[i] = pQueue[j]; // przesuwam dziecko w g�r�
		i = j; // schodz� w d� z indeksami, czyli moj nowy wezel to ten, w ktorym bylo dziecko
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
	PQItem* x = pQueue[i]; // element, kt�ry idzie w g�r�
	while( ixParent >= l && x->nPrior > pQueue[ixParent]->nPrior ) // dop�ki nie jeste�my korzeniem (elementem o najw. prior.) i priorytet x jest wi�kszy ni� priorytet rodzica
	{
		pQueue[i] = pQueue[ixParent]; // przesuwam rodzica w d� na miejsce dziecka i przechodz� w g�r� kopca
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

	// musze sprawdzic czy na danej pozycji jest jaki� element i czy w og�le pozycja z parametru ma sens 
	//if( infoPos == POS_ERROR || infoPos == PRIOR_ERROR || infoPos >= queueSize ) return PRIOR_ERROR;

	PQItem* pInfoFound = q->pPQueue[infoPos];

	int oldPrior = PQgetPrior( q, infoPos ); // musze zachowac do returna
	if( oldPrior == PRIOR_ERROR ) return PRIOR_ERROR;

	pInfoFound->nPrior = newPrior;

	if( newPrior > oldPrior ) {
		UpdateUp( q->pPQueue, 0, infoPos ); // naprawa w g�r� od 0 do znalezionego elementu
	}
	else if( newPrior < oldPrior ) {
	
		UpdateDown( q->pPQueue, infoPos, PQSize(q)-1 ); // naprawa w d� od znalezionego elementu do ko�ca kopca
	}


	return oldPrior;
}

int PQGetPrior( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	// korzystam z innych metod 
	return PQgetPrior( q, PQFind( q, pInfoToFind, compareInfo ) );
}

int PQgetPrior( PQueue* q, int infoPos ) {
	if( PQisEmpty( q ) ) return PRIOR_ERROR;

	// musze sprawdzic czy na danej pozycji jest jaki� element i czy w og�le pozycja z parametru ma sens 
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