#include <stdio.h>
#include <stdarg.h>

#define DECIMAL_PLACES 8
#define MIN_LEFTOVER 1e-6
#define ZERO 0 // ewentualnie poprawic na 1e-100 albo cos takiego

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

    n = Printf( "%s\n%f%c  *%a*  n=%%d \\ \% /\ny=%f ` ` z=%%f\n%", str, x, c, n, y, z );  // ` -> '
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
    while( c = *sFormat++ /*c = znak_z_we_stringu*/ )
    {
        switch( c )
        {
        case '%':
        
            switch( c=*sFormat++ ) /* tutaj sprawdzam kolejny znak po c, wczesniej mialem tu zmienna char c2 */ 
            {
            case 'd': outDec( va_arg(args, int) );         ilosc++; /* pomija wypisywanie literki, tutaj "d" */; break;
            case 'f': outDouble( va_arg( args, double ) ); ilosc++; break;
            case 's': outStr( va_arg( args, char* ) );     ilosc++; break; 
            case 'c': outChar( va_arg( args, char ) );     ilosc++; break;
            default: outChar( '%' );
                     sFormat--;
            }
            break;
            
        case '`': c = '\'';  // to bez break-a
        default: outChar( c );
        }
        //sFormat++;
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
    //char c;
    while(*pStr ) {
        outChar( *pStr++ );
        //pStr++;
        //TODO: SPRAWDZIC CZY DZIALA
    }
}
//-----------------------------------------------
void outDec( int x )
{
    // wypisac znak jesli trzeba i wykorzystac outNum()

    if( x < ZERO )
    {
        outChar( '-' );
        //outNum( -x );
        x = -x;
    }
    outNum( x );
}

//-----------------------------------------------
void outDouble( double x )
{
    if(x < ZERO) 
    {
        outChar('-');
        x = -x;
    }

    // wykorzystac outDec()
    outDec( (int)x );

    x = x - (int)x;

    outChar( '.' );

    // przerwac drukowanie jesli reszta <=1e-6
    // jesli reszta wieksza, to drukowac do 8-miu cyfr po kropce

    for( int i = 0; i < DECIMAL_PLACES && ( x - (int)x ) > MIN_LEFTOVER; i++ ) {
        // sprytnie dodaje drugi warunek dzialania petli, zamiast tworzyc ifa w jej srodku
        // ten warunek mowi, ze przejde przez petle, jesli i<8 i dalsza czesc ulamkowa jest wieksza niz 1e-6

        outChar( (int)(x*=10) % 10 + '0' ); // zamiast robic to w innej linii, to tutaj od razu mnoze x przez 10
    } 
    
}
//-----------------------------------------------
void outNum( int x ) //rekurencyjny  //x>0
{
    if( x > 9 ) outNum( x / 10 );
    outChar( x%10+'0');
}
