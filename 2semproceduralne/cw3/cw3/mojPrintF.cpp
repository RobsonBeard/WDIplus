#include <stdio.h>
#include <stdarg.h>
//#include <float.h>

int Printf( const char* sFormat, ... ); //<zdeklarowac parametry>

//zadeklarowac PrintfV()
int PrintfV( const char* sFormat, va_list args );

void outDec( int );       // znakowo wypisuje liczbe calk
void outChar( char );     // wypisuje znak  // putchar()
void outStr( char* );     // wypisuje zanakowo string
void outDouble( double ); // wypisuje znakowow liczbe double    0.  (do 8 po kropce)
void outNum( int x );     // wypisuje znakowo liczbe int >0     rekurencyjnie

//----------------------------------
int main( int argc, char* argv[] )
{
    int n = -0;
    char c = '$';
    double x = 12000000.34500000012;   // nie wiecej jak 8 po pkropce  // .0000012 <=1e-6
    double y = -.12;
    double z = -1.5;
    char* str = (char*)"to jest string";

    n = Printf( "%s\n%f%c  n=%%d \\ \% /\ny=%f ` ` z=%%f\n%", str, x, c, n, y, z );  // ` -> '
    Printf( "\nilosc formatow=%d\n", n );



    printf( "\n" );
    double test1 = 123.456;
    //double test2 = test1 - (int)test1;
    //printf("%f",test2);
    outDec( test1 );
    //outNum( 123 );
    //outDec( -0 );

    return 0;
}
// implementacja uproszczonej funkcji "Printf": %c %d %f %s oraz 
// zamienia `(klawisz ~) na '( klawisz ")
// do wypisywania mozna uzyc JEDYNIE putchar() (raz) (poprzez outChar())


//-----------------------------------------------
int Printf( const char* sFormat, ... )
{
    // Initialize variable arguments 
    // set the pointer at the beggining of the arg list and get the first argument from the args list

    va_list args;
    va_start( args, sFormat );


    int res = PrintfV( sFormat,args );

    // Reset variable arguments
    va_end( args );
    return res;
}
//-----------------------------------------------
int PrintfV( const char* sFormat, va_list args )
{
    char c;
    int ilosc = 0;
    //! NIE WOLNO ROBIC BLOKOW W CASE
    while( c = *sFormat /*c = znak_z_we_stringu*/ )
    {
        switch( c )
        {
        case '%':
        {
            char c2 = *(sFormat+1);
            switch( c2 /*c = znak_z_we_stringu*/ ) //! wziac pod uwage przypadek gdzie na koncu stringa jest %
            {
            case 'd': 
                outDec( va_arg( args, int ) );
                ilosc++;
                sFormat++;
             break;
            case 'f': outDouble( va_arg( args, double ) ); break;
            case 's':  
                outStr( va_arg( args, char* ) ); 
                ilosc++;
                sFormat++;
             break; //! w jakis sposob musze pominac wypisywanie s, wchodzi mi znowu do tego pierwszego switcha i wypisuje domyslnie
            case 'c': outChar( va_arg( args, char ) ); break;
            default: outChar( c );
            }
        }
            break;
            
        case '`': c = '\'';  // to bez break-a
        default:outChar( c );
        }
        sFormat++;
    }
    return ilosc;
}

//-----------------------------------------------
void outChar( char c )
{
    putchar( c );
}
//-----------------------------------------------
void outStr( char* pStr )
{
    char c;
    while(c = *pStr ) {
        outChar( c );
        pStr++;
    }
}
//-----------------------------------------------
void outDec( int x )
{
    // wypisac znak jesli trzeba i wykorzystac outNum()

    if( x < 0 ) // jesli mam korzystac z tej funkcji z doublami to nie moze byc porownania do 0
    {
        outChar( '-' );
        outNum( -x );
    }
    else outNum( x );
}

//-----------------------------------------------
void outDouble( double x )
{
    double ulamek = x - (int)x;
    outDec( (int)x );
    outChar( '.' );
    if( ulamek <= 1e-6 ) {
        
    }
    for( int i = 0; i < 8; i++ ) {

    }

    // wykorzystac outDec()
    // przerwac drukowanie jesli reszta <=1e-6  ewentualnie do  8-miu cyfr po kropce
}
//-----------------------------------------------
void outNum( int x ) //rekurencyjny  //x>0
{
    if( x > 9 ) outNum( x / 10 );
    outChar( x%10+48 );
}
