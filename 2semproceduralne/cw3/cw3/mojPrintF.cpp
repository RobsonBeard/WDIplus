#include <stdio.h>
#include <stdarg.h>

int Printf( const char* sFormat, ... ); //<zdeklarowac parametry>

//zadeklarowac PrintfV()
int PrintfV( const char* sFormat, va_list args );

void outDec( int );       // znakowo wypisuje liczbe calk
void outChar( char );     // wypisuje znak  // putchar()
void outStr( char* );     // wypisuje znakowo string
void outDouble( double ); // wypisuje znakowo liczbe double    0.  (do 8 po kropce)
void outNum( int x );     // wypisuje znakowo liczbe int >0     rekurencyjnie

//----------------------------------
int main( int argc, char* argv[] )
{
    int n = -0;
    char c = '$';
    double x = 12000000.34500000012;   // nie wiecej jak 8 po kropce  // .0000012 <=1e-6
    double y = -.12;
    double z = -1.5;
    char* str = (char*)"to jest string";

    n = Printf( "%s\n%f%c  n=%%d \\ \% /\ny=%f ` ` z=%%f\n%", str, x, c, n, y, z );  // ` -> '
    Printf( "\nilosc formatow=%d\n", n );

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
            // ewentualnie tu zrobic ifa, ktory inkrementowalby ilosc i sFormat
            switch( c2 /*c = znak_z_we_stringu*/ )
            {
            case 'd': 
                outDec( va_arg( args, int ) );
                ilosc++;
                sFormat++; //pomija wypisywanie literki, tutaj d
                break;
            case 'f': 
                outDouble( va_arg( args, double ) ); 
                ilosc++;
                sFormat++;
                break;
            case 's':  
                outStr( va_arg( args, char* ) ); 
                ilosc++;
                sFormat++; 
                break; 
            case 'c': 
                outChar( va_arg( args, char ) ); 
                ilosc++;
                sFormat++;
                break;
            default: outChar( c );
            }
        }
            break;
            
        case '`': c = '\'';  // to bez break-a
        default: outChar( c );
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

    if( x < 0 ) // nie wiem czy moze byc porownanie do 0
    {
        outChar( '-' );
        outNum( -x );
    }
    else outNum( x );
}

//-----------------------------------------------
void outDouble( double x )
{
    if(x < 0) // nie wiem czy moze byc porownanie do 0
    {
        outChar('-');
        x = -x;
    }

    int calk = (int)x;
    outDec( calk );

    double ulamek = x - calk;

    outChar( '.' );

    for( int i = 0; i < 8; i++ ) {
        if((ulamek - (int)ulamek) <= 1e-6 ) {
            return;
        }
        ulamek *= 10;
        outChar((int)ulamek % 10 + 48);
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
