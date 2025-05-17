#include "matrix.h"

//#define MATRIX_SIZE 3
//#define COMPLEMENT_TEST_SIZE 5
//#define DET_TEST_SIZE 4

#define EPS 1e-15
#define PARAMNO 2

void ReadData( FILE* fin, double** pMatrix, int nDim ); 


int main( int argc, char* argv[] )
{
	//TODO: przede wszystkim dowiedzieæ siê o rzeczach, gdzie s¹ pytajniki i o tym, co ma zwracaæ Det w przypadku b³êdu, bo wtedy trzeba bêdzie obs³u¿yæ b³¹d w kilku miejscach

	// obliczyæ macierz odwrotn¹ 6x6 
	// dane wejsciiowe czytane z pliku wejsciowego (parametr funkcji main)

	if( argc != PARAMNO ) {
		printf( "ERROR wrong parameters, Usage: %s <file_name>\n", argv[0] ); // podpowiadam jak ma wygladac sciezka
		return 1;
	}

	// odtworzyc plik do odczytu (tekstowy)
	// odczytac rozmiar nDim	

	int nDim = 0; // zak³adam, ¿e muszê wydobyæ najpierw z pliku .txt rozmiar macierzy
	FILE* fin = NULL; // uchwyt pliku
	if( ( fin = fopen( argv[1], "r" ) ) == NULL ) // proba otworzenia pliku
	{
		printf( "Error open input file %s\n", argv[1] );
		return 2;
	}
	if( fscanf( fin, "%d", &nDim ) == EOF ) // tutaj fscanf przypisze wartoœæ pierwszej liczby do zmiennej nDim (format int - %d da³em)
	{
		printf( "ERROR fscanf in main" );
		return 3;
	}

#ifdef DEBUG
	//wydruk kontrolny rozmiaru
	printf( "Rozmiar macierzy: %d\n\n", nDim );
#endif

	// wykreowac macierz ukladu nDim x nDim
	// sprawdzic
	// wczytac dane ( ReadData() )

	double** pMatrix = NULL;
	if( !CreateMatrix( &pMatrix, nDim ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 4;
	}

	ReadData(fin, pMatrix,nDim);

#ifdef DEBUG
	//wydruk kontrolny wczytanych danych
	printf( "Macierz wczytana:\n" );
	PrintMatrix( pMatrix, nDim );
#endif

	// obl wyznacznik
	double matrixDet = Det( pMatrix, nDim);

	if( fabs( matrixDet ) < EPS || matrixDet == DBL_MAX ) {
		printf( "ERROR Det is equal to 0 or DBL_MAX\n" ); //? to mia³o byæ w ten sposób zrobione? gdzie sprawdziæ, czy wyznacznik jest równy 0? robiæ to z Epsilonem czy po prostu ==0?
		return 5;
	}

#ifdef DEBUG
	//wydruk kontrolny
	printf( "Wyznacznik wynosi: %.2lf\n\n", matrixDet );
#endif 


	// obrocic macierz
	double** inversedMatrix = NULL;
	if( !CreateMatrix( &inversedMatrix, nDim ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 6;
	}
	InverseMatrix(inversedMatrix,pMatrix,nDim,matrixDet);
	
#ifdef DEBUG
	// wydruk wyniku (ma byæ w debugu czy nie?)
	printf( "Macierz odwrotna:\n" );
	PrintMatrix( inversedMatrix, nDim ); //? jest taki problem(?) ¿e zamiast 0 pokazuje -0, co pewnie wynika ze zmiennoprzecinkowych liczb
#endif


	// zwolnic pamiec  (usuwanie macierzy)!!!
	fclose( fin );
	DeleteMatrix( &pMatrix,nDim );
	DeleteMatrix( &inversedMatrix, nDim );

	return 0;
}

void ReadData( FILE* fin, double** pMatrix, int nDim ) {
	for( int i = 0; i < nDim; i++ )
	{
		for( int j = 0; j < nDim; j++ )
		{
			if( fscanf( fin, "%lf", &( pMatrix[i][j] ) ) == EOF ) // tu fscanf przypisze po kolei wartoœci tablicy w formacie doubli
			{
				printf( "ERROR fscanf in ReadData" );
				return;
			}
		}
	}
}


/*
		test czytania z pliku - bez funkcji

	int testNDIM = 0;
	FILE* fin = NULL; // uchwyt pliku
	if( ( fin = fopen( argv[1], "r" ) ) == NULL )
	{
		printf( "Error open input file %s\n", argv[1] );
		return -69;
	}

	if( fscanf( fin, "%d", &testNDIM )==EOF ) {
		printf( "ERROR fscanf in main" );
		return -70;
	}

	printf( "%d\n\n",testNDIM );

	double** fileTestMatrix = NULL;
	if( !CreateMatrix( &fileTestMatrix, testNDIM ) ) {
		printf( "CreateMatrix failed in main\n" );
		return -71;
	}

	double matrixVal = 0;
	for( int i = 0; i < testNDIM; i++ )
	{
		for( int j = 0; j < testNDIM; j++ )
		{
			if( fscanf( fin, "%lf", &(fileTestMatrix[i][j] )) == EOF ) {
				printf( "ERROR fscanf in main" );
				return -72;
			}

			printf( "%.2lf ", fileTestMatrix[i][j] );
		}
	}

	printf( "\n\n" );

	PrintMatrix( fileTestMatrix, testNDIM );
	DeleteMatrix( &fileTestMatrix, testNDIM );

	fclose( fin );
	*/

/* testy funkcji
	double** testMatrix1 = NULL;
		if( !CreateMatrix( &testMatrix1, MATRIX_SIZE ) ) {
			printf( "CreateMatrix failed in main\n" );
			return 1;
		}

#ifdef DEBUG
	PrintMatrix( testMatrix1, MATRIX_SIZE );
#endif



	for( int i = 0; i < MATRIX_SIZE; i++ ) {
		for( int j = 0; j < MATRIX_SIZE; j++ ) {
			testMatrix1[i][j] = i * 10 + j;
		}
	}

#ifdef DEBUG
	PrintMatrix( testMatrix1, MATRIX_SIZE );
#endif

	TransMatrix( testMatrix1, MATRIX_SIZE );
#ifdef DEBUG
	PrintMatrix( testMatrix1, MATRIX_SIZE );
#endif


	DeleteMatrix( &testMatrix1, MATRIX_SIZE );
*/

/*
	test liczenia wyznacznika
	// test liczenia wyznacznika - ma wyjsc -71

	double** detTestMatrix = NULL;
	if( !CreateMatrix( &detTestMatrix, DET_TEST_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 4;
	}

	detTestMatrix[0][0] = 1;
	detTestMatrix[0][1] = -1;
	detTestMatrix[0][2] = 2;
	detTestMatrix[0][3] = 0;

	detTestMatrix[1][0] = 0;
	detTestMatrix[1][1] = 1;
	detTestMatrix[1][2] = 0;
	detTestMatrix[1][3] = -3;

	detTestMatrix[2][0] = 3;
	detTestMatrix[2][1] = 2;
	detTestMatrix[2][2] = -2;
	detTestMatrix[2][3] = 4;

	detTestMatrix[3][0] = 2;
	detTestMatrix[3][1] = 3;
	detTestMatrix[3][2] = 1;
	detTestMatrix[3][3] = 1;

#ifdef DEBUG
	PrintMatrix( detTestMatrix, DET_TEST_SIZE );
	printf( "Wyznacznik wynosi: %.2lf\n\n", Det( detTestMatrix, DET_TEST_SIZE ) ); // wynik dobry
#endif

	DeleteMatrix( &detTestMatrix, DET_TEST_SIZE );

*/

	/* test Complement - trzeba przenieœæ nag³ówek

	double** testMatrix2 = NULL;
	if( !CreateMatrix( &testMatrix2, COMPLEMENT_TEST_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 2;
	}

	double** testMatrix3 = NULL;
	if( !CreateMatrix( &testMatrix3, COMPLEMENT_TEST_SIZE - 1 ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 3;
	}

	for( int i = 0; i < COMPLEMENT_TEST_SIZE; i++ ) {
		for( int j = 0; j < COMPLEMENT_TEST_SIZE; j++ ) {
			testMatrix2[i][j] = i * 10 + j;
		}
	}
	#ifdef DEBUG
		PrintMatrix( testMatrix2, COMPLEMENT_TEST_SIZE );
	#endif

	Complement( testMatrix3, testMatrix2, 1, 2, COMPLEMENT_TEST_SIZE );
	#ifdef DEBUG
		PrintMatrix( testMatrix3, COMPLEMENT_TEST_SIZE - 1 );
	#endif
	DeleteMatrix( &testMatrix2, COMPLEMENT_TEST_SIZE );
	DeleteMatrix( &testMatrix3, COMPLEMENT_TEST_SIZE - 1 );
	*/

/*
	test liczenia macierzy odwrotnej
		double** invTestMatrix1 = NULL;
	if( !CreateMatrix( &invTestMatrix1, MATRIX_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 5;
	}

	invTestMatrix1[0][0] = 2;
	invTestMatrix1[0][1] = 5;
	invTestMatrix1[0][2] = 7;

	invTestMatrix1[1][0] = 6;
	invTestMatrix1[1][1] = 3;
	invTestMatrix1[1][2] = 4;

	invTestMatrix1[2][0] = 5;
	invTestMatrix1[2][1] = -2;
	invTestMatrix1[2][2] = -3;


#ifdef DEBUG
	PrintMatrix( invTestMatrix1, MATRIX_SIZE );
#endif

	double testDet = Det( invTestMatrix1, MATRIX_SIZE );

	if( fabs( testDet ) < EPS || testDet == DBL_MAX ) {
		printf( "ERROR Det is equal to 0 or DBL_MAX\n" ); //? to mia³o byæ w ten sposób zrobione?
		return 6;
	}

	double** invTestMatrix2 = NULL;
	if( !CreateMatrix( &invTestMatrix2, MATRIX_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 7;
	}

	InverseMatrix( invTestMatrix2, invTestMatrix1, MATRIX_SIZE, testDet ); // policzy³ poprawnie


#ifdef DEBUG
	PrintMatrix( invTestMatrix2, MATRIX_SIZE );
#endif


	DeleteMatrix( &invTestMatrix1, MATRIX_SIZE );
	DeleteMatrix( &invTestMatrix2, MATRIX_SIZE );

*/