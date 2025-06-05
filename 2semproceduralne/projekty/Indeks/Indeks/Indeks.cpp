#include "Tree.h"

int ReadFile( char* sFile );

int main(int argc, char* argv[])
{





	return 0;
}

int ReadFile( char* sFile ) {
	FILE* fin = NULL; // uchwyt pliku
	if( ( ( fin = fopen( sFile, "r" ) ) == NULL ) ) return 0;

	
	fclose( fin );
	return 1;
}