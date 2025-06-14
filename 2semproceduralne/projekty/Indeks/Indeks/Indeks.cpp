#include "Tree.h"
#include <ctype.h>
#define PARAMNO 3

int ReadFile( char* sFile, TreeItem** pRoot ); // robie wskaznik do wskaznika pRoot bo chce go modyfikowac
int WriteFile( char* sFile, TreeItem* pRoot );
int isCorrectFirstIdentifierSign( char c );
int isCorrectOtherIdentifierSign( char c );

int main( int argc, char* argv[] )
{
	if( argc != PARAMNO ) {
		printf( "Usage: %s <file_name>\n", argv[0] ); // podpowiadam jak ma wygladac sciezka
		return 1;
	}

	TreeItem* pRoot = NULL;

	ReadFile( argv[1], &pRoot );
	WriteFile( argv[2], pRoot );

	pRoot = freeTree( pRoot );

	return 0;
}

int ReadFile( char* sFile, TreeItem** pRoot ) {

	FILE* fin = fopen( sFile, "r" ); // uchwyt pliku
	if( !fin ) return 0;

	char str[41] = {0};
	int pos = 0;
	int lineCounter = 1;
	char c;

	while( ( c = fgetc( fin ) ) != EOF ) {

		if( isCorrectFirstIdentifierSign( c ) )
		{
			pos = 0;
			str[pos++] = c; // tu sprawdzalem pierwszy znak, wiec go dodam

			while( ( c = fgetc( fin ) ) != EOF && isCorrectOtherIdentifierSign( c ) )
				if( pos < 40 ) str[pos++] = c;

			if( c == '\n' ) lineCounter++; // po wyjsciu z while mam pierwszy znak który przerywa identyfikator, wiec sprawdzam, czy jest to przypadkiem \n

			str[pos] = '\0'; // musze zakonczyc slowo, wiec daje znak 0


			char* newIdentifier = (char*)calloc( 1, 41 ); // alokuje pamiec, kopiuje do niej tego zrobionego stringa i wrzucam do drzewa
			if( !newIdentifier ) return  NULL;
			strcpy( newIdentifier, str );

			*pRoot = FindInsert( *pRoot, newIdentifier, lineCounter );

		}
		else if( c == '\n' ) lineCounter++; // jesli nie ma identyfikatora, ale byl \n, to zwiekszam numer linii	
	}

	fclose( fin );
	return 1;
}

int WriteFile( char* sFile, TreeItem* pRoot ) {
	FILE* fout = fopen( sFile, "w" ); // uchwyt pliku
	if( !fout ) return 0;

	inOrder( pRoot, fout );

	fclose( fout );
	return 1;
}

int isCorrectFirstIdentifierSign( char c ) {
	return ( c == '_' || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) );
}

int isCorrectOtherIdentifierSign( char c ) {
	return ( c == '_' || ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= '0' && c <= '9' ) );
}