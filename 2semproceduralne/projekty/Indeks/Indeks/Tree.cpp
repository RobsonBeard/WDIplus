#include "Tree.h"
#include "QFIFO.h"

void Visit( TreeItem* pRoot, int line );
int compStr( char* s1, char* s2 );


void inOrder( TreeItem* pRoot ) {
	if( !pRoot ) return; // koniec rekurencji

	inOrder( pRoot->pLeft );
	//printf( "%d ", pRoot->key );
	printf( "slowo: %40s, ilosc wystapien: %3d, numery linii: ", pRoot->str, pRoot->counter ); // zmienic formatowanie ewentualnie
	FQPrint(pRoot->pList);
	printf( "\n" );
	inOrder( pRoot->pRight );
}

TreeItem* TreeFinallyBalanced( int n ) {
	if( n < 1 ) return NULL; // nie ma drzewa

	int nl = n / 2; // liczba elementow w lewym poddrzewie
	int np = n - nl - 1; // liczba elementow w prawym poddrzewie (tworze wezel, wiec jego tez musze wyrzucic - stad -1 na koncu)

	printf( "Podaj key: " );
	int x;
	if(scanf( "%d", &x )!=1) return NULL; // chce zeby kompilator sie odczepil od bledu

	TreeItem* p = (TreeItem*)calloc( 1, sizeof( TreeItem ) ); // od razu mi wyzeruje strukture - ustawia wskazniki na NULL, nie musze p->pLeft=p->pRight=NULL
	if( !p ) return NULL;
	p->key = x; 
	p->pLeft = TreeFinallyBalanced( nl );
	p->pRight = TreeFinallyBalanced( np );

	return p;
}

TreeItem* freeTree( TreeItem* pRoot ) {
	if( pRoot ) {
		pRoot->pLeft = freeTree( pRoot->pLeft ); // tutaj coœ w stylu "lekcewa¿e zwracan¹ wartoœæ"
		freeTree( pRoot->pRight );
		free( pRoot->pList );
		free( pRoot );
	}
	return NULL;
}

void Visit( TreeItem* pRoot, int line ) {
	//printf( "key: %d\n", pRoot->key ); // stare
	pRoot->counter++;
	FQEnqueue( pRoot->pList, line );
}

int compStr( char* s1, char* s2 ) {
	// idea jest taka, ze chce porownac dwa stringi, ale nie interesuje mnie wielkosc znakow, wiec musze przekonwertowac je do samych duzych albo malych liter. musze dzialac na kopiach, poniewaz zmienilbym inaczej oryginalne stringi
	// kiedy stringi s¹ takie same to zwróci 0
	char* str1 = (char*)calloc( 1, strlen( s1 ) + 1 ); // alokuje pamieci
	char* str2 = (char*)calloc( 1, strlen( s2 ) + 1 );

	if( !str1 || !str2 ) return INT_MAX; //? co zwracac?

	strcpy( str1, s1 ); // przekopiowuje z parametrow
	strcpy( str2, s2 );

	_strlwr( str1 ); // zamieniam wszystko na ma³e znaki
	_strlwr( str2 );

	int cmpOutput = strcmp( str1, str2 ); // porownuje stringi

	free( str1 ); // zwalniam pamieci
	free( str2 );

	return cmpOutput;
}

TreeItem* FindInsert( TreeItem* pRoot, char* str, int line ) {
	if( !pRoot ) // s³owo dotar³o po raz pierwszy
	{
		TreeItem* v = (TreeItem*)calloc( 1, sizeof( TreeItem ) ); // to mi nulluje wszystko co jest w TreeItem, a chce jeszcze stworzyc kolejke
		if( !v ) return NULL;

		//v->str = str; // nie moge tak zrobic, bo caly czas bym nadpisywal slowo
		// takze robie tak jak w funkcji compare!
		v->str = (char*)calloc( 1, strlen( str ) + 1 );
		if( !v->str ) return NULL;
		strcpy( v->str, str );

		v->pList = FQCreate(); // mam sprawdzac czy kolejka sie zrobila?
		FQEnqueue( v->pList, line ); // to musi byæ tu aby za ka¿dym razem przypisywa³o do odpowiedniej ga³êzi a nie do korzenia

		v->counter = 1; // slowo pojawilo sie pierwszy raz, wiec ustawiam counter na 1

		return v;
	}

	// rekurencyjnie szukamy albo elementu albo gdzie wstawiæ
	if( compStr( str, pRoot->str ) < 0 )
		pRoot->pLeft = FindInsert( pRoot->pLeft, str,line );
	else if( compStr( str, pRoot->str ) > 0 )
		pRoot->pRight = FindInsert( pRoot->pRight, str,line );
	else Visit( pRoot, line ); // gdy slowo juz istnieje

	return pRoot;
}
