#include "matrix.h"

#define DEBUG

#define MATRIX_SIZE 3
//#define COMPLEMENT_TEST_SIZE 5
#define DET_TEST_SIZE 4
#define EPS 1e-15

void ReadData( FILE* fin, double** pMatrix, int nDim );



int main( int argc, char* argv[] )
{
	//TODO: przede wszystkim dowiedzieæ siê o rzeczach, gdzie s¹ pytajniki i o tym, co ma zwracaæ Det w przypadku b³êdu, bo wtedy trzeba bêdzie obs³u¿yæ b³¹d w kilku miejscach

	// obliczyæ macierz odwrotn¹ 6x6 (docelowo)
	// docelowo dane wejsciiowe czytane z pliku wejsciowego (parametr funkcji main)

	double** testMatrix1 = NULL;
	if( !CreateMatrix( &testMatrix1, MATRIX_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 1;
	}

	PrintMatrix( testMatrix1, MATRIX_SIZE );

	//todo: przerobic te testy zeby byly warunkowe wydruki
#ifdef DEBUG
	// wydruk
#endif

	for( int i = 0; i < MATRIX_SIZE; i++ ) {
		for( int j = 0; j < MATRIX_SIZE; j++ ) {
			testMatrix1[i][j] = i * 10 + j;
		}
	}

	PrintMatrix( testMatrix1, MATRIX_SIZE );

	TransMatrix( testMatrix1, MATRIX_SIZE );
	PrintMatrix( testMatrix1, MATRIX_SIZE );

	DeleteMatrix( &testMatrix1, MATRIX_SIZE );

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

	PrintMatrix( testMatrix2, COMPLEMENT_TEST_SIZE );

	Complement( testMatrix3, testMatrix2, 1, 2, COMPLEMENT_TEST_SIZE );
	PrintMatrix( testMatrix3, COMPLEMENT_TEST_SIZE - 1 );
	DeleteMatrix( &testMatrix2, COMPLEMENT_TEST_SIZE );
	DeleteMatrix( &testMatrix3, COMPLEMENT_TEST_SIZE - 1 );
	*/	


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

	PrintMatrix( detTestMatrix, DET_TEST_SIZE );
	printf( "Wyznacznik wynosi: %.2f\n\n", Det(detTestMatrix,DET_TEST_SIZE) ); // wynik dobry

	DeleteMatrix( &detTestMatrix, DET_TEST_SIZE );


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

	PrintMatrix( invTestMatrix1, MATRIX_SIZE);

	double testDet = Det( invTestMatrix1, MATRIX_SIZE );

	if( fabs( testDet ) < EPS || testDet==DBL_MAX) {
		printf( "ERROR Det is equal to 0 or DBL_MAX\n" ); //? to mia³o byæ w ten sposób zrobione?
		return 6;
	}
	
	double** invTestMatrix2 = NULL;
	if( !CreateMatrix( &invTestMatrix2, MATRIX_SIZE ) ) {
		printf( "CreateMatrix failed in main\n" );
		return 7;
	}

	InverseMatrix( invTestMatrix2, invTestMatrix1, MATRIX_SIZE, testDet ); // policzy³ poprawnie

	PrintMatrix( invTestMatrix2, MATRIX_SIZE ); 


	DeleteMatrix(&invTestMatrix1,MATRIX_SIZE);
	DeleteMatrix(&invTestMatrix2,MATRIX_SIZE);


	return 0;
}