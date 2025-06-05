#include "Tree.h"

void Visit( TreeItem* pRoot );

void preOrder( TreeItem* pRoot ) {
	if( !pRoot ) return; // koniec rekurencji

	printf( "%d ", pRoot->key );
	preOrder( pRoot->pLeft );
	preOrder( pRoot->pRight );
}

void inOrder( TreeItem* pRoot ) {
	if( !pRoot ) return; // koniec rekurencji

	inOrder( pRoot->pLeft );
	printf( "%d ", pRoot->key );
	inOrder( pRoot->pRight );
}

void postOrder( TreeItem* pRoot ) {
	if( !pRoot ) return; // koniec rekurencji

	postOrder( pRoot->pLeft );
	postOrder( pRoot->pRight );
	printf( "%d ", pRoot->key );
}

TreeItem* TreeFinallyBalanced( int n ) {
	if( n < 1 ) return NULL; // nie ma drzewa

	int nl = n / 2; // liczba elementow w lewym poddrzewie
	int np = n - nl - 1; // liczba elementow w prawym poddrzewie (tworze wezel, wiec jego tez musze wyrzucic - stad -1 na koncu)

	printf( "Podaj key: " );
	int x;
	scanf_s( "%d", &x ); //todo: przerobic to na scanf (bez s) i dodac flage CRT_SECURE...

	TreeItem* p = (TreeItem*)calloc( 1, sizeof( TreeItem ) ); // od razu mi wyzeruje strukture - ustawia wskazniki na NULL, nie musze p->pLeft=p->pRight=NULL
	p->key = x; //? sk¹d to podreslenie
	p->pLeft = TreeFinallyBalanced( nl );
	p->pRight = TreeFinallyBalanced( np );

	return p;
}

void freeTree1( TreeItem* pRoot ) {
	if( !pRoot ) return;
	freeTree1( pRoot->pLeft );
	freeTree1( pRoot->pRight );
	free( pRoot );
}

void freeTree2( TreeItem** pRoot ) {
	if( !*pRoot ) return;
	freeTree2( &( ( *pRoot )->pLeft ) );
	freeTree2( &( *pRoot )->pRight ); // to co wyzej, ale skorzystalem z priorytetow
	free( *pRoot );
	*pRoot = NULL;
}

TreeItem* freeTree3( TreeItem* pRoot ) {
	if( pRoot ) {
		pRoot->pLeft = freeTree3( pRoot->pLeft ); // tutaj coœ w stylu "lekcewa¿e zwracan¹ wartoœæ"
		freeTree3( pRoot->pRight );
		free( pRoot );
	}
	return NULL;
}


// w sizeof() i (*pRoot) nie trzeba spacji przy nawiasach

void FindInsert( TreeItem** pRoot, int x ) {
	if( !*pRoot )
	{
		*pRoot = (TreeItem*)calloc( 1, sizeof( TreeItem ) );
		( *pRoot )->key = x;
		//( *pRoot )->pLeft = ( *pRoot )->pRight = NULL; // potrzebne gdy malloc
	}
	else // rekurencyjnie szukamy albo elementu albo gdzie wstawiæ
	{
		if( x < ( *pRoot )->key )
			FindInsert( &( ( *pRoot )->pLeft ), x );
		else if( x > ( *pRoot )->key )
			FindInsert( &( ( *pRoot )->pRight ), x );
		else Visit( *pRoot );
	}
}

void Visit( TreeItem* pRoot ) {
	printf( "key: %d\n", pRoot->key );
}

TreeItem* FindInsert2( TreeItem* pRoot, int x ) {
	if( !pRoot )
	{
		TreeItem* v = (TreeItem*)calloc( 1, sizeof( TreeItem ) );
		v->key = x; //? znowu u pana nie ma tego podkreslenia
		//v->pLeft = v->pRight = NULL; // potrzebne gdy malloc
		return v;
	}

	// rekurencyjnie szukamy albo elementu albo gdzie wstawiæ
	if( x < pRoot->key )
		pRoot->pLeft = FindInsert2( pRoot->pLeft, x );
	else if( x > pRoot->key )
		pRoot->pRight = FindInsert2( pRoot->pRight, x );
	else Visit( pRoot );

	return pRoot;
}
