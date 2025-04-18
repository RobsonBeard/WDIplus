#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

double* createTab_m( int nSize ); // m - malloc
double* createTab_c( int nSize ); // c - calloc

int main()
{
	// w debugu w okienku watch mo¿na wpisywaæ wyra¿enia w C
	// projekt ma byc gotowy na 05.05 - ma dzialac, pan moze pomoc z efektywnoscia
	//! pisac samodzielnie, nawet jesli do kitu (nieefektywnie)
	// nie ma kolejki priorytetowej w ksiazce Wirth
	// moga byc konsultacje wieczorem zdalnie
	// 
	// stare
	//double* pTab = NULL;
	//if( !createTab( &pTab, 10 ) ) {
		//komunikat
		//return 1;
	//}

	// nowe, tylko jeden parametr
	double* pTab = createTab_m(10);
	if( !pTab ) {
		printf( "pTab allocation error" );
		return 1;
	}

	pTab[0] = 34.567;
	pTab[1] = -13.546;


	free( pTab );
	return 0;
}

double* createTab_m( int nSize ) {
	double* p = (double*)malloc( nSize * sizeof( double ) ); // w takiej kolejnosci w mallocu - ilosc elementow * rozmiar elementu
	if( !p ) return NULL; // null bo zwracam wskaznik
	memset( p, 0, nSize * sizeof( double ) );
	return p; // jest rozne od 0, wiec jest prawd¹
}

double* createTab_c( int nSize ) {
	// od teraz uzywamy calloc
	return (double*)calloc( nSize, sizeof( double ) ); // tu wystarczy zmieniæ gwiazdkê na przecinek, calloc to typowo funkcja do tablic (ktore mamy wyzerowac)
	//! pan nie daje nawiasow przy sizeof(double)
	// funkcja calloc zeruje pamiec! wiec bez memseta
	// i tez gdyby bylo 0 to zwraca null a gdy sie powiodlo to zwraca p, wyrzucamy ifa
}
