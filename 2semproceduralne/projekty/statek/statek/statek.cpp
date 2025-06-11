#include "ship.h"

#define N 10 // trzeba zmieniac w zaleznosci od podanego .txt
#define M 10
#define SHIP_DEPTH 5

#define PARAMNO 2

int** CreateTab2D( int nRow, int nCol );
void freeTab2D( int*** pTab );
void printTab2D( int** pTab, int nRow, int nCol );


int main( int argc, char* argv[] )
{
	if( argc != PARAMNO ) {
		printf( "Usage: %s <file_name>\n", argv[0] ); // podpowiadam jak ma wygladac sciezka
		return 1;
	}

	int** depthTab = CreateTab2D( N, M );

	if( !setTab( argv[1], depthTab, N, M ) ) {
		printf( "ERROR setTab failed in main\n" );
		return 2;
	}

	printf( "Tablica glebokosci:\n" );
	printTab2D( depthTab, N, M );

	int** pathTab = CreateTab2D( N, M );

	if( root( depthTab, N, M, SHIP_DEPTH, 0, 0, pathTab, N - 1, M - 1 ) ) {
		printf( "Tablica ze sciezka:\n" );
		printTab2D( pathTab, N, M );
	}
	else {
		printf( "Nie ma mozliwosci doplynac do portu!!\n" );
	}

	freeTab2D( &depthTab );
	freeTab2D( &pathTab );

	return 0;
}

int** CreateTab2D( int nRow, int nCol ) // to jest duzo prostszy naglowek niz matrix
{
	// jest to druga metoda alokowania pamieci z pdf'a - ci¹g³y obszar pamieci, bez petli, jedna alokacja (calloc lub malloc) od razu wszystkie wiersze naraz
	// adres kolejnego wiersza to adres poprzedniego (np pTab[0] + ilosc elementow w wierszu), ale zeby tego nie pisac, to zrobic zmienna dodatkowa jako ptab[0] i zwiekszac ja o += nCol

	if( nRow < 1 || nCol < 1 ) return NULL;

	int** p = (int**)calloc( nRow, sizeof( int* ) ); // alokujemy od razu wszystkie wiersze naraz - nRow elementów, gdzie ka¿dy element ma rozmiar int*
	if( !p ) return NULL;

	p[0] = (int*)calloc( nRow * nCol, sizeof( int ) );
	if( !p[0] ) {
		free( p );
		return NULL;
	}

	int* pTemp = p[0];

	for( int i = 1; i < nRow; i++ ) // for od 1
	{
		pTemp += nCol;
		p[i] = pTemp;
	}

	return p; // zwraca adres do tablicy, tym razem on nie jest przekazywany jako parametr
}

void freeTab2D( int*** pTab )
{
	// zwrocic uwage, ze 3 gwiazdki
	// 1)zwolnic 0-owy elem tablicy 
	// 2)zwolnic tablice tablic
	// 3)wynulowac wskaznik

	free( ( *pTab )[0] ); // wazna jest ta kolejnosc nawiasow
	free( *pTab );
	*pTab = NULL;
}

void printTab2D( int** pTab, int nRow, int nCol ) {
	// przerobione z macierzy, tylko na inty

	if( !pTab || nCol < 1 || nRow < 1 ) {
		printf( "ERROR printTab2D - wrong or incomplete data\n" );
		return;
	}

	for( int i = 0; i < nRow; i++ )
	{
		int* v = *pTab++;
		for( int j = 0; j < nCol; j++ ) {
			printf( "%3d ", *v++); // tu zmieniac wyswietlanie
		}
		printf( "\n" );
	}
	printf( "\n" );
}

/* test create, print i free
	int** testTab2D = CreateTab2D( N, M );

	testTab2D[2][2] = 4;
	testTab2D[3][5] = 6;
	testTab2D[0][0] = 11;
	testTab2D[N - 1][M - 1] = 14;
	printTab2D( testTab2D, N, M );

	freeTab2D( &testTab2D );
	*/