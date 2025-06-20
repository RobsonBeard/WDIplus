#ifndef PQUEUE_H
#define PQUEUE_H

#include "global.h"

// dwie stale
//   - PRIOR_ERROR  jako minimalna wartosc calkowita
//   - POS_ERROR    jako wartosc ujemna np -1 (indeks tablicy jakiego nie ma!)

#define PRIOR_ERROR INT_MIN
#define POS_ERROR -1


typedef struct    // zachowac oryginalne nazwy!!!!!!  
{
	PQINFO* pInfo;       // Ptr to user info  
	int nPrior;      // prior value (int) for the user info  
} PQItem;         // type of the queue item


typedef struct   // zachowac oryginalne nazwy!!!!!!
{
	PQItem** pPQueue;     // kolejka realizowana w postaci stogu  (dynamiczna tablica wskaznikow do PQItem)
	int nPQSize;      // rozmiar calkowity kolejki priorytetowej
	int nPQCurrSize;  // ilosc elelemntow w kolejce (jednoczensie indeks pierwszego wolnego miejsc w kolejce) 

} PQueue;

//dopisac parametry!!!!, na pewno pierwszym parametrem wszedzie bedzie kolejka, wszedzie sprawdzac czy kolejka JEST, czasem PQisEmpty, czasem samo q
PQueue* PQInit( int qSize );     // kreuje kolejke o zadanym rozmiarze i zwraca wskaznik do niej lub NULL gdy blad (czyli typu PQueue*?, parametr - rozmiar)
int PQisEmpty( PQueue* q );  // zwraca 0 lub 1 - kolejka pusta/nie pusta 
int PQSize( PQueue* q );     // zwraca ilosc elementow w kolejce, wyrazenie pytajnikowe
int PQMaxPrior( PQueue* q ); // zwraca najwiekszy priorytet w kolejce (z zerowej pozycji) lub PRIOR_ERROR
int PQEnqueue( PQueue* q, PQINFO* pNewInfo, int newInfoPrior );  // wstawia do kolejki informacje o zadanym priorytecie, zwraca 0 (niepowodzenie) lub 1 (powodzenie), to zrobic na razie na koncu, tak samo dequeue
PQINFO* PQDequeue( PQueue* q );  // zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie, (trzeba pamietac o czyszczeniu pamieci)
void PQClear( PQueue* q, void( __cdecl* freeMem )( const void* ) );    // czysci cala kolejke zwalniajac pamiec alokowana przez uzytkownika (na info), nieznana struktura do zwolnienia 
// dlatego przekazac trzeba funkcje uzytkownika do zwolnienia pamieci przez parametr 
void PQRelease( PQueue** q, void( __cdecl* freeMem )( const void* ) );  // zwraca w parametrze we-wy NULL (kolejka) usuwaj�c wszyskto wczesniej (czyszczenie kolejki)
void PQPrint( PQueue* q, int currentPos, void( __cdecl* printInfo )( const void* ) );    // drukuje w porzadku preorder (rekurencyjnie) od zadanej pozycji, aby wydrukowa� info uzytkownika przekazac 
// trzeba funkcje drukujaca ta informacje. Dodatkowo, drukuje priorytet w okraglych nawiasach oraz pozycje w 
// kolejce w kwadratowych nawiasach

// ---------------- drugi krok

int PQSetPrior( PQueue* q, PQINFO* pInfoToFind, int newPrior, int( __cdecl* compareInfo )( const void*, const void* ) ); // ustawia nowy priorytet dla zadanej informacji uzytkownika, nie znana struktura informacji, kt�ra trzeba wyszukac
// dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika. Funkcja zwraca poprzedni priorytet lub PRIOR_ERROR 
// czwarty parametr - adres funkcji - parametry: kolejka, adres, nowy priorytet, adres funkcji
int PQsetPrior( PQueue* q, int infoPos, int newPrior ); // ustawia nowy priorytet dla informacji uzytkownika bedacej na zadanej pozycji w kolejce (indeks w tablicy),
// Funkcja zwraca poprzedni priorytet. W przypadku bledu zwraca PRIOR_ERROR 
// zwraca stary priorytet

int PQGetPrior( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) ); // zwraca priorytet informacji uzytkownika w kolejce lub PRIOR_ERROR, nie znana struktura informacji, kt�ra trzeba wyszukac
// dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika  
int PQgetPrior( PQueue* q, int infoPos ); // zwraca priorytet informacji uzytkownika z zadanej pozycji w kolejce lub PRIOR_ERROR

int PQFind( PQueue* q, PQINFO* pInfoToFind, int( __cdecl* compareInfo )( const void*, const void* ) );     // zwraca indeks wyszukiwanej informacji uzytkownika, nie znana struktura informacji uzytkownika dlatego
// przekazac trzeba funkjce porownujaca informacje uzytkownika
// Zwaraca POS_ERROR jesli nie ma info w kolejce


#endif // PQUEUE_H

// warto rysowac w celu zrozumienia struktur danych
// tablica to wskaznik na pierwszy element