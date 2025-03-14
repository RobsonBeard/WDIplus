#include <stdio.h>
#include <stdarg.h> //! istotne, standard argument

// przyklad funkcji o zmiennej liczbie parametrow

int sum( int nFirst, ... ); //! spacje tutaj ( )
// tutaj (WINDOWS) nFirst oznacza ilosc parametrow dalej na liscie
// nie musi byc intem, ale na podstawie tego parametru musi dac sie obliczyc ile dalej jest parametrow

int sumV( int nFirst, va_list args );
// ta funkcja pobiera kolejne parametry z args i sumuje

void mojtest(char* str);

/*
int main()
{
	// nie zmieniac, tylko uzupelnic to, czego brakuje
	// za tydzien projekt sprawdzany, nalezy zmodyfikowac visuala juz tak, zeby byl do pokazania

	// ZMIENNA LICZBA PARAM

	int res = sum( 8, 1, 1, 2, 3, 4, 5, 0, 1 ); // 8 parametrow i tez spacje po srodku ( )!
	printf( " res = %d\n", res );

	res = sum( 4, 1, 2, 3, 4 );
	printf( " res = %d\n", res );

	//putchar( 'g' );
	//putchar( 'm' );

	char abc[] = "abecadlo";
	mojtest( abc );


	return 0;
}
*/
void mojtest( char* str ) {
	while(char c = *str ) {
		putchar( c );
		str++;
	}
}

int sum( int nFirst, ... ) //! wszystko tu jest wazne
{
	// set the pointer at the beginning of the args list
	// wszystko z przedrostkiem va s¹ w³aœnie z tego includa
	va_list args; // pointer to the list of arguments
	va_start( args, nFirst ); // initialize args pointer

	int ret_val = sumV( nFirst, args );

	va_end( args ); // reset variable arguments
	return ret_val;
}

// WINDOWS - nFirst to ilosc parametrow w args
int sumV( int nFirst, va_list args ) {
	int suma = 0;
	for( int i = 0; i < nFirst; i++ )
	{
		suma += va_arg( args, int );
	}

	return suma;
}