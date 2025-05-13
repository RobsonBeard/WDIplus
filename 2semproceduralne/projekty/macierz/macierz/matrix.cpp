#include "matrix.h"

// wycina wiersz nRow i kolumne nCol z tab we pTabI i reszte kopiuje do 
// tabl wyjsciowej pTabO 
// nalezy uzyc dwa razu continue pomijajac wiersz nRow i kolumne nCol
void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim );

// oblicza macierz dopelnien pTabD na podstawie tablic wejsc pTab
void ComplMatrix( double** pTabD, double** pTab, int nDim ); //macierz dopelnien


int CreateMatrix( double*** pTab, int nDim ) {
	if( !pTab || nDim < 1 ) return 0;

	// dwie wersje - obie poprawne

	double** p = (double**)calloc( nDim, sizeof( double* ) );
	//*pTab = (double**)calloc( nDim, sizeof( double* ) ); // *pTab to jest double**
	if( !p ) return 0;
	//if( !(*pTab ) return 0;

	for( int i = 0; i < nDim; i++ )
	{
		p[i] = (double*)calloc( nDim, sizeof( double ) );
		//(*pTab)[i] = (double*)calloc( nDim, sizeof( double ) );
		if( !p[i] ) return 0;
		//if( !( ( *pTab )[i] ) ) return 0;
	}
	*pTab = p;
	return 1;
}

void DeleteMatrix( double*** pTab, int nDim ) {
	if( !pTab || !( *pTab ) || nDim<1) {
		printf( "ERROR DeleteMatrix - wrong or incomplete data" );
		return;
	}

	double** p = *pTab;

	for( int i = 0; i < nDim; i++ )
	{
		free( p[i] );
		p[i] = NULL;
	}

	free( p );
	p = NULL;
}

// od pierwszego ZA g³ówn¹ przek¹tn¹, w ostatnim wierszu nie ma nic do zamiany, druga petla idzie od i+1 do nDim-1 (chodzi o to ze w ostatnim przejsciu nie bedzie co zamieniac)
// czyli i!=j

void PrintMatrix( double** pTab, int nDim ) {
	if( !pTab || nDim<1 ) {
		printf( "ERROR PrintMatrix - wrong or incomplete data" );
		return;
	}

	for( int i = 0; i < nDim; i++ )
	{
		for( int j = 0; j < nDim; j++ ) {
			printf( "%lf ", pTab[i][j]);
		}
		printf( "\n" );
	}
	printf( "\n" );
}

