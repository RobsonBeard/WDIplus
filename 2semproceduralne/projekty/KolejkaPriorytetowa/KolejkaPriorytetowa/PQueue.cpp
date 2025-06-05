#include "PQueue.h"

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
	return ( PQisEmpty( q ) ) ? 0 : q->nPQCurrSize; // zwracam aktualny rozmiar
}

int PQMaxPrior( PQueue* q ) {
	return ( PQisEmpty( q ) ) ? PRIOR_ERROR : q->pPQueue[0]->nPrior;
}

void PQClear( PQueue* q, void( __cdecl* freeMem )( const void* ) ) {
	// ma usuwac wszystkie PQItem z kolejki, najpierw usunac, potem zwolnic pamiec czyli freeMem( PQDequeue( ) ), dopoki kolejka nie jest pusta
	// ale mozna tez to zrobic na piechote, od 0 do currentSize, freememem zwalniac PQInfo i free na PQItem, nullowac costam, na koncu currentsize ustawic na 0
	//! sprobowac to zrobic na piechote

	if( !q || !freeMem ) {
		printf( "PQClear: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	while( !PQisEmpty( q ) )
		freeMem( PQDequeue( q ) );
}

PQINFO* PQDequeue( PQueue* q ) {
	// zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie, (trzeba pamietac o czyszczeniu pamieci)
	// 1. "pobra�" informacje - utworzyc now� zmienn� wska�nikow�, wskazuj�c� PQINFO (zadeklarowac i poodstawic PQINFO)
	// 2. usunac PQItem, freemem? - trzymam informacje (punkt 1.), wiec moge usunac
	// 3. ostatni wrzucam do zerowego, robie update down itp
	// zwraca informacje z indeksu 0
	// wpisac ostatni do 0-wego  - robi sie to po to, aby usun�� element, kt�ry nie ma ju� dzieci, czyli jest li�ciem, wtedy jest bezpiecznie
	// uaktualnic w dol (update na dol)

	if( PQisEmpty( q ) ) return NULL; // zwracam NULL a nie 0, bo wska�nik 

	PQItem* itemToRemove = q->pPQueue[0]; // potrzebuje tego do zwolnienia pamieci, najwyzszy priorytet
	PQINFO* p = q->pPQueue[0]->pInfo; // biore wartosc korzenia (pierwszego elementu)

	q->nPQCurrSize--;

	if( q->nPQCurrSize > 0 ) // je�li kolejka nie jest pusta (czyli wczesniej nie miala tylko 1 elementu), to przenosz� ostatni element na miejsce pierwszego
	{
		q->pPQueue[0] = q->pPQueue[q->nPQCurrSize]; // po to najpierw zdekrementowa�em nPQCurrSize, �eby teraz w ten spos�b dosta� si� do ostatniego elementu, przenosz� go na pocz�tek
		q->pPQueue[q->nPQCurrSize] = NULL;
		UpdateDown( q->pPQueue, 0, q->nPQCurrSize - 1 ); // ostatni element nowego kopca b�dzie mia� indeks = q->nPQCurrSize - 1, naprawiam kopiec
	}
	else
	{
		q->pPQueue[0] = NULL; // ustawiamy korze� na NULL, gdy kolejka jest pusta, robie w ten sposob, no bo juz nie potrzebuje UpdateDown
	}

	free( itemToRemove );

	return p;
}

int PQEnqueue( PQueue* q, PQINFO* pNewInfo, int newInfoPrior ) {
	// parametr: kolejka, informacja wstawiana, priorytet
	// sprawdzic czy nie przepelnione, czy jest kolejka ( 2 rozne bledy )
	// funkcja jest typu int - czy sie powiodlo czy nie
	// dynamiczna alokacja pamieci, wstawiam informacje pod ten element
	// wstawic na koncu
	// uaktualnic w gore - tutaj przydalaby sie wiedza z odwrocenia kolejnosci sortowania heapsorta (z rosnacego na malejace), jest troszke prostsze, jest tylko jeden przodek zamiast dwoch potomkow, tu jakies sprytniejsze wyrazenie

	if( !q || q->nPQCurrSize >= q->nPQSize ) return 0; // je�li lista nie istnieje lub kolejka jest pe�na
	PQItem* newItem = (PQItem*)malloc( sizeof( PQItem ) );
	if( !newItem ) return 0; // je�li alokacja pami�ci si� nie powiod�a

	newItem->pInfo = pNewInfo;
	newItem->nPrior = newInfoPrior;

	q->pPQueue[q->nPQCurrSize] = newItem; // indeks pierwszego wolnego miejsca to q->nPQCurrSize
	q->nPQCurrSize++; // rozmiar kolejki zwiekszyl sie

	UpdateUp( q->pPQueue, 0, q->nPQCurrSize - 1 ); // wyniesienie nowego elementu w g�r� kopca, naprawa od 0 do indeksu tego nowego elementu q->nPQCurrSize - 1

	return 1;
}

void PQRelease( PQueue** q, void( __cdecl* freeMem )( const void* ) ) {
	if( !q || !*q || !freeMem ) {
		printf( "PQRelease: Kolejka lub funkcja freeMem nie istnieje" );
		return;
	}

	PQClear( *q, freeMem ); // usuwam wszystkie elementy listy

	if( ( *q )->pPQueue ) //? ten if mo�na pomin�� czy nie?
	{
		free( ( *q )->pPQueue ); // zwalniam pami�� tablicy wska�nik�w PQueue
		( *q )->pPQueue = NULL;
	}

	free( *q ); // zwalniam pamiec
	*q = NULL; // kolejnosc ma znaczenie, jesli najpierw zNULLuje wskaznik, to potem nie bede mial adresu do zwolnienia pamieci
}

void PQPrint( PQueue* q, int currentPos, void( __cdecl* printInfo )( const void* ) ) {
	// currentPos - indeks w�z�a do wydrukowania

	if( currentPos >= q->nPQCurrSize ) return; // je�li indeks jest poza rozmiarem kolejki
	if( PQisEmpty( q ) || !printInfo ) {
		printf( "PQPrint: Kolejka pusta lub nie istnieje lub funkcja printInfo nie istnieje" );
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
	// analogicznie jak w sortowaniu stogowym ale zmienic
	// przetestowac najpierw ta funkcje w sortowaniu malejacym!!!
	//    (wybiera sie element o wiekszym priorytcie)
	// tak aby pierwszy element mial najwi�kszy proirytet

	// l - indeks w�z�a, od kt�rego zaczynamy napraw� kopca
	// p - indeks ostatniego elementu w kopcu

	if( l >= p || ( 2 * l + 1 ) > p ) return; // gdy l==p, to w�ze� startowy jest ostatnim elementem kopca, wi�c nie ma sensu nic robi�, gdy l>p, to l jest poza zakresem kopca, 2 * l + 1 to indeks lewego dziecka, gdy jest wiekszy od indeksu ostatniego elementu, to nie ma ju� dzieci do por�wnywania
	int i = l;
	int j = 2 * i + 1;
	PQItem* x = pQueue[i];
	while( j <= p ) {
		if( j < p && pQueue[j]->nPrior < pQueue[j + 1]->nPrior ) j++;
		if( x->nPrior >= pQueue[j]->nPrior ) break;
		pQueue[i] = pQueue[j];
		i = j;
		j = 2 * i + 1;
	}
	pQueue[i] = x;
}

void UpdateUp( PQItem** pQueue, int l, int p ) {
	// naprawa od l do p
	// analog jak w UpdateDown
	// tylko uaktualnienie w gore stogu i jest tylko jeden rodzic
	// uwazac przy liczeniu indeksu rodzica, petla z dwoma warunkami, bo przy UpdateDown cos jest i dopiero w srodku jest dodatkowy warunek z break
	// a tutaj ten warunek jest w naglowku petli i ten indeks ma byc >= l chyba, ale jesli l jest 0 to w pewnym momencie musze otrzymac -1, zeby sie petla przerwala
	// dlatego trzeba tutaj uzyc jakiegos sprytnego wyrazenia

	if( l >= p ) return;
	int i = p; // indeks dziecka
	int ixParent = ( i - 1 ) / 2; // indeks rodzica
	PQItem* x = pQueue[i]; // element, kt�ry idzie w g�r�
	while( i > l && x->nPrior > pQueue[ixParent]->nPrior ) // dop�ki nie jeste�my korzeniem (elementem o najw. prior.) i priorytet x jest wi�kszy ni� priorytet rodzica
	{
		pQueue[i] = pQueue[ixParent]; // przesuwam rodzica w d� na miejsce dziecka i przechodz� w g�r� kopca
		i = ixParent;
		ixParent = ( i - 1 ) / 2;
	}
	pQueue[i] = x;
}

int PQSetPrior( PQueue* q, PQINFO* pInfoToFind, int newPrior, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if( PQisEmpty( q ) || !pInfoToFind || !compareInfo ) return PRIOR_ERROR;

	int ixFound = POS_ERROR; // takie za�o�enie by�o, �e POS_ERROR to indeks tablicy, ktorego nie ma

	for( int i = 0; i < q->nPQCurrSize; i++ )
	{
		if( !compareInfo( q->pPQueue[i]->pInfo, pInfoToFind ) ) // gdy wynik compare da 0, to wejdzie do if'a
		{
			ixFound = i; // znalaz�o element
			break;
		}
	}

	if( ixFound == POS_ERROR ) return PRIOR_ERROR; // nie znalaz�o elementu

	PQItem* pInfoFound = q->pPQueue[ixFound]; // znaleziony element

	int oldPrior = pInfoFound->nPrior; // potrzebne do zwr�cenia

	pInfoFound->nPrior = newPrior; // ustawiam nowy priorytet

	// trzeba naprawi� kopiec, w zale�no�ci od tego, czy element ma pop�yn�� w g�r�, czy w d�, czyli od nowego priorytetu

	if( newPrior > oldPrior ) {
		UpdateUp( q->pPQueue, 0, ixFound ); // naprawa w g�r� od 0 do znalezionego elementu
	}
	else {
		UpdateDown( q->pPQueue, ixFound, q->nPQCurrSize - 1 ); // naprawa w d� od znalezionego elementu do ko�ca kopca
	}

	return oldPrior;
}

int PQsetPrior( PQueue* q, int infoPos, int newPrior ) {
	if( PQisEmpty( q ) ) return PRIOR_ERROR;

	// musze sprawdzic czy na danej pozycji jest jaki� element i czy w og�le pozycja z parametru ma sens (zastanawiam sie, czy nie wystarczy�by sam trzeci warunek)
	if( infoPos < 0 || infoPos >= q->nPQCurrSize || !q->pPQueue[infoPos] ) return PRIOR_ERROR;

	PQItem* pInfoFound = q->pPQueue[infoPos];

	int oldPrior = pInfoFound->nPrior;
	pInfoFound->nPrior = newPrior;

	if( newPrior > oldPrior ) {
		UpdateUp( q->pPQueue, 0, infoPos ); // naprawa w g�r� od 0 do znalezionego elementu
	}
	else {
		UpdateDown( q->pPQueue, infoPos, q->nPQCurrSize - 1 ); // naprawa w d� od znalezionego elementu do ko�ca kopca
	}

	return oldPrior;
}

int PQGetPrior( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if( PQisEmpty( q ) || !pInfoToFind || !compareInfo ) return PRIOR_ERROR;

	for( int i = 0; i < q->nPQCurrSize; i++ )
	{
		if( !compareInfo( q->pPQueue[i]->pInfo, pInfoToFind ) ) // gdy wynik compare da 0, to wejdzie do if'a
		{
			return q->pPQueue[i]->nPrior;
		}
	}

	return PRIOR_ERROR;
}

int PQgetPrior( PQueue* q, int infoPos ) {
	if( PQisEmpty( q ) ) return PRIOR_ERROR;

	// musze sprawdzic czy na danej pozycji jest jaki� element i czy w og�le pozycja z parametru ma sens (zastanawiam sie, czy nie wystarczy�by sam trzeci warunek)
	if( infoPos < 0 || infoPos >= q->nPQCurrSize || !q->pPQueue[infoPos] ) return PRIOR_ERROR; 

	return q->pPQueue[infoPos]->nPrior;
}

int PQFind( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if( PQisEmpty( q ) || !pInfoToFind || !compareInfo ) return POS_ERROR;

	for( int i = 0; i < q->nPQCurrSize; i++ )
	{
		if( !compareInfo( q->pPQueue[i]->pInfo, pInfoToFind ) ) // gdy wynik compare da 0, to wejdzie do if'a
		{
			return i; // indeks w pPQueue
		}
	}

	return POS_ERROR;
}