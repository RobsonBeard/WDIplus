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
		if( !p[i] ) {
			for( int j = 0; j < i; j++ )
				free( p[j] );

			free( p ); // jak bêdzie b³¹d, to czyszczê wszystko, co by³o do tej pory zalokowane
			return 0;
		}
		//if( !( ( *pTab )[i] ) ) return 0;
	}
	*pTab = p;
	return 1;
}

void DeleteMatrix( double*** pTab, int nDim ) {
	if( !pTab || !( *pTab ) || nDim < 1 ) {
		printf( "ERROR DeleteMatrix - wrong or incomplete data\n" );
		return;
	}

	double** p = *pTab; // dla czytelnosci mozna tak zrobic, tak jak w CreateMatrix

	for( int i = 0; i < nDim; i++ )
		free( p[i] );

	free( p );
	*pTab = NULL;
}


void TransMatrix( double** pTab, int nDim ) {
	// od pierwszego ZA g³ówn¹ przek¹tn¹, w ostatnim wierszu nie ma nic do zamiany, druga petla idzie od i+1 do nDim-1 (chodzi o to ze w ostatnim przejsciu nie bedzie co zamieniac) - w paincie mozna fajnie narysowac
	// czyli i!=j
	// tutaj w pTab nie wolno aktualizowac adresu, bo potem uzywamy do indeksowannia 

	if( !pTab || nDim < 1 ) {
		printf( "ERROR TransMatrix - wrong or incomplete data\n" );
		return;
	}

	for( int i = 0; i < nDim - 1; i++ )
	{
		for( int j = i + 1; j < nDim; j++ )
		{
			double temp = pTab[i][j];
			pTab[i][j] = pTab[j][i];
			pTab[j][i] = temp;
		}
	}
#ifdef DEBUG
	printf( "Po transponowaniu:\n" );
	PrintMatrix( pTab, nDim );
#endif 
}

void InverseMatrix( double** pInv, double** pTab, int nDim, double det ) {
	if( !pTab || !pInv || nDim < 2  ) {
		printf( "ERROR InverseMatrix - wrong or incomplete data\n" );
		return;
	}

	ComplMatrix( pInv, pTab, nDim );
	TransMatrix( pInv, nDim );
	for( int i = 0; i < nDim; i++ )
	{
		for( int j = 0; j < nDim; j++ )
			pInv[i][j] /= det; // to zamiast robic mnozenie przez alpha=1/det - szybciej
	}
}

double Det( double** pTab, int nDim ) {
	if( !pTab || nDim < 1 ) {
		printf( "ERROR Det - wrong or incomplete data\n" );
		return 0; 
	}

	if( nDim == 1 ) return **pTab; // **pTab to jest to samo co pTab[0][0]
	if( nDim == 2 ) return **pTab * pTab[1][1] - pTab[0][1] * pTab[1][0]; // z szybszego wzoru

	double** smallerMatrix = NULL; // wazne, zeby kreowac te macierz poza petla for
	if( !CreateMatrix( &smallerMatrix, nDim - 1 ) ) {
		printf( "ERROR CreateMatrix failed in Det\n" );
		return 0;
	}

	double calculatedDet = 0;
	double sign = -1;

	//rozwiniecie wzgl 1-go wiersza, rekurencyjnie (wiersz o indeksie 1)
	for( int j = 0; j < nDim; j++ )
	{
		Complement( smallerMatrix, pTab, 1, j, nDim ); // i nie musze nawet alokowac pamieci dla nowej tablicy w petli, bo po prostu nadpisuje wartosci

		calculatedDet += sign * pTab[1][j] * Det( smallerMatrix, nDim - 1 ); // * Det(tablica po complement, nDim-1), wzor na wyznacznik
		sign = -sign;
	}

	DeleteMatrix( &smallerMatrix, nDim - 1 ); // trzeba pamietac o zwolnieniu pamieci

	return calculatedDet;
}

void PrintMatrix( double** pTab, int nDim ) {
	if( !pTab || nDim < 1 ) {
		printf( "ERROR PrintMatrix - wrong or incomplete data\n" );
		return;
	}

	for( int i = 0; i < nDim; i++ )
	{
		double* v = *pTab++; // moge to zrobic, bo parametr jest przekazywany jako kopia, chyba ze potrzebowalbym pTab do indeksowania, wtedy musialbym zrobic na poczatku programu jeszcze jedna kopie

		for( int j = 0; j < nDim; j++ ) {
			printf( "%.2lf ", *v++ ); // moge napisac v[j]
		}

		printf( "\n" );
	}
	printf( "\n" );
}

void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim ) {
	// dim jest wiekszej tablicy

	if( !pTabO || !pTabI || nDim < 2 || nRow < 0 || nCol < 0 || nRow >= nDim || nCol >= nDim ) {
		printf( "ERROR Complement - wrong or incomplete data\n" );
		return;
	}

	for( int i = 0; i < nDim; i++ )
	{
		if( i == nRow ) continue;
		for( int j = 0; j < nDim; j++ )
		{
			if( j == nCol ) continue;
			// ale po miniêciu, czyli gdy j>ncol muszê wstawiæ do [j-1] element
			// tak samo gdy i>nRow to do [i-1]
			// najlepiej to po prostu narysowaæ
			int r = i;
			int c = j;
			if( i > nRow ) r--;
			if( j > nCol ) c--;

			pTabO[r][c] = pTabI[i][j];
		}
	}
}

void ComplMatrix( double** pTabD, double** pTab, int nDim ) {
	if( !pTab || !pTabD || nDim < 2 ) {
		printf( "ERROR ComplMatrix - wrong or incomplete data\n" );
		return;
	}

	double** smallerMatrix = NULL;
	if( !CreateMatrix( &smallerMatrix, nDim - 1 ) ) {
		printf( "ERROR CreateMatrix failed in ComplMatrix\n" );
		return;
	}

	for( int i = 0; i < nDim; i++ )
	{
		int sign = ( i % 2 ) ? -1 : 1;

		for( int j = 0; j < nDim; j++ )
		{
			Complement( smallerMatrix, pTab, i, j, nDim );
			pTabD[i][j] = sign * Det( smallerMatrix, nDim - 1 );

			sign = -sign;
		}
	}

	DeleteMatrix( &smallerMatrix, nDim - 1 );

#ifdef DEBUG
	printf( "Po zrobieniu macierzy dopelnien:\n" );
	PrintMatrix( pTabD, nDim );
#endif 
}