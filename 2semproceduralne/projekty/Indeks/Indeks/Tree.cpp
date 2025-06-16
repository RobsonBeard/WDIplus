#include "Tree.h"
#include "QFIFO.h"

void Visit( TreeItem* pRoot, int line );
int compStr( char* s1, char* s2 );

void inOrder( TreeItem* pRoot, FILE* fout ) {
	if( !pRoot ) return; // stop rekurencji

	inOrder( pRoot->pLeft,fout ); // lewe poddrzewo

	//printf( "slowo: %40s, ilosc wystapien: %3d, numery linii: ", pRoot->str, pRoot->counter ); // wersja z wypisywaniem do konsoli
	//fprintf(fout, "slowo: %40s, ilosc wystapien: %3d, numery linii: ", pRoot->str, pRoot->counter ); // inne formatowanie 

	fprintf(fout, "%40s (%3d) ", pRoot->str, pRoot->counter ); 
	FQPrint(pRoot->pList,fout);

	//printf( fout,"\n" ); // wersja z wypisywaniem do konsoli

	fprintf( fout,"\n" );
	inOrder( pRoot->pRight,fout ); // prawe poddrzewo
}

TreeItem* freeTree( TreeItem* pRoot ) {
	if( pRoot ) {
		pRoot->pLeft = freeTree( pRoot->pLeft ); 
		freeTree( pRoot->pRight ); // tutaj coœ w stylu "lekcewa¿e zwracan¹ wartoœæ"
		FQRemove( &( pRoot->pList ) );
		free( pRoot->str );
		free( pRoot );
	}
	return NULL;
}

void Visit( TreeItem* pRoot, int line ) {
	if( !pRoot || !pRoot->pList ) return;

	pRoot->counter++;

	if(FQEmpty(pRoot->pList)|| pRoot->pList->pTail->lineNo != line ) // dodaje tylko jesli sie nie powtarza. musi byc warunek, ze kolejka jest pusta, bo inaczej nie doda numeru linii dla pierwszego elementu
		FQEnqueue( pRoot->pList, line );
}

int compStr( char* s1, char* s2 ) {
	// idea jest taka, ze chce porownac dwa stringi, ale nie interesuje mnie wielkosc znakow, wiec musze przekonwertowac je do samych duzych albo malych liter. musze dzialac na kopiach, poniewaz zmienilbym inaczej oryginalne stringi
	// kiedy stringi s¹ takie same to zwróci 0

	char* str1 = (char*)calloc( 1, strlen( s1 ) + 1 ); // alokuje pamieci
	if( !str1 ) return INT_MAX; //? co zwracac?

	char* str2 = (char*)calloc( 1, strlen( s2 ) + 1 );
	if( !str2 ) {
		free( str1 );
		return INT_MAX; //? co zwracac?
	} 

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

		v->pList = FQCreate();
		if( !v->pList ) {
			free( v );
			return NULL;
		}

		FQEnqueue( v->pList, line ); // to musi byæ tu aby za ka¿dym razem przypisywa³o do odpowiedniej ga³êzi a nie do korzenia
		
		v->str = str; // tworzenie tego stringa jest w funkcji czytajacej plik

		v->counter = 1; // slowo pojawilo sie pierwszy raz, wiec ustawiam counter na 1

		return v;
	}

	// rekurencyjnie szukamy albo elementu albo gdzie wstawiæ
	int comparedStrings = compStr( str, pRoot->str );

	if( comparedStrings < 0 )
		pRoot->pLeft = FindInsert( pRoot->pLeft, str,line );
	else if( comparedStrings > 0 )
		pRoot->pRight = FindInsert( pRoot->pRight, str,line );
	else Visit( pRoot, line ); // gdy slowo juz istnieje

	return pRoot;
}
