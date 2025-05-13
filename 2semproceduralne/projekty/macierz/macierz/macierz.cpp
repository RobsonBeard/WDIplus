#include "matrix.h"

#define DEBUG

#define MATRIX_SIZE 3

void ReadData( FILE* fin, double** pMatrix, int nDim );

int main( int argc, char* argv[] )
{
	// obliczyæ macierz odwrotn¹ 6x6 (docelowo)
	// docelowo dane wejsciiowe czytane z pliku wejsciowego (parametr funkcji main)

	double** testMatrix1 = NULL;
	if( !CreateMatrix( &testMatrix1, MATRIX_SIZE ) ) {
		printf( "CreateMatrix failed in main" );
		return 1;
	}

	PrintMatrix( testMatrix1, MATRIX_SIZE );

	#ifdef DEBUG
		// wydruk
	#endif

	//double testMatrix2[MATRIX_SIZE][MATRIX_SIZE] = {{1,2},{1},{0,2,3}};

	testMatrix1 = 

	PrintMatrix( testMatrix1, MATRIX_SIZE );

	return 0;
}