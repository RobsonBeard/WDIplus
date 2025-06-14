#include "Tree.h"
#include <ctype.h>
#define PARAMNO 3

int ReadFile( char* sFile );
int WriteFile( char* sFile );



int main( int argc, char* argv[] )
{
	if( argc != PARAMNO ) {
		printf( "Usage: %s <file_name>\n", argv[0] ); // podpowiadam jak ma wygladac sciezka
		return 1;
	}

	ReadFile( argv[1] );
	//WriteFile( argv[2] );




	return 0;
}

int ReadFile( char* sFile ) {
	FILE* fin = fopen( sFile, "r" ); // uchwyt pliku
	if( !fin ) return 0;

	TreeItem* pRoot = NULL;

	char c;
	char str[41];
	int pos = 0;
	int lineCounter = 1;

	// slowo to dowolny ciag znakow zaczynajacy sie od podkreslenia lub litery i potem sa litery lub cyfry lub podkreslenia
	// slowo wstawiam do drzewa, ale jesli juz istnieje to zwiekszam licznik i zamieniam numer wiersza

	// a wiec musze sprawdzic 1 znak osobno, potem reszte znakow i jesli lamie zasade identyfikatora to pomijam slowo?
	// albo najpierw zapisuje ca³e s³owo a potem sprawdzam czy jest identyfikatorem

	//! na razie uproszczona wersja

	while( !feof( fin ) ) {
		c = fgetc( fin );
		//printf( "%c", c );
		if( c == '\n' ) lineCounter++;
		if( (( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= 0 && c <= 9 ) || c == '_' ) && pos<=40 ) {
			str[pos++] = c;
		}
		else {
			str[pos] = '\0'; // jesli nie spelnia warunku to musze skonczyc slowo (na przyklad wystapila spacja albo zly znak)
			if( pos > 0 ) {
				//printf( "Slowo: %s, linia: %d\n", str, lineCounter ); // daje taki warunek bo wypisywalo stringi z samymi spacjami
				// i tu musze zapisywac do drzewa
				pRoot = FindInsert( pRoot, str,lineCounter );
			}
			pos = 0;
		}
	}
	
	str[pos] = '\0'; // musze tez zakonczyc ostatniego stringa
	pRoot = FindInsert( pRoot, str, lineCounter );

	inOrder( pRoot );

	fclose( fin );
	return 1;
}

int WriteFile( char* sFile ) {
	FILE* fout = fopen( sFile, "w" ); // uchwyt pliku
	if( !fout ) return 0;

	fprintf( fout, "test pisania do pliku %d", 420 ); // dziala

	fclose( fout );
	return 1;
}

