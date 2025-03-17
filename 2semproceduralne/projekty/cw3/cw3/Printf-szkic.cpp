#include <stdio.h>
#include <stdarg.h>

int Printf( const char* sFormat, ...  ); //<zdeklarowac parametry>

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
  int n  = -0;
  char c = '$';
  double x = 12000000.34500000012;   // nie wiecej jak 8 po pkropce  // .0000012 <=1e-6
  double y = -.12;
  double z = -1.5;
  char*  str = (char*)"to jest string";
  
  n = Printf( "%s\n%f%c  n=%%d \\ \% /\ny=%f ` ` z=%%f\n%", str, x, c, n, y, z );  // ` -> '
  Printf( "\nilosc formatow=%d\n", n );
  return 0;
}
// implementacja uproszczonej funkcji "Printf": %c %d %f %s oraz 
// zamienia `(klawisz ~) na '( klawisz ")
// do wypisywania mozna uzyc JEDYNIE putchar() (raz) (poprzez outChar())


//-----------------------------------------------
int Printf( const char* sFormat  )
{
  // Initialize variable arguments 
  // set the pointer at the beggining of the arg list and get the first argument from the args list
  
    va_list args;
    va_start( args, sFormat );


    int res = Printf(args,sFormat);
  
  // Reset variable arguments
    va_end( args );
    return res;
}
//-----------------------------------------------
int PrintfV( const char* sFormat, va_list args )
{
  char c;
  int ilosc=0;
  while( c=*sFormat /*c = znak_z_we_stringu*/ )
  {
    switch( c )
    {
      case '%': 
       switch( c+1 /*c = znak_z_we_stringu*/ )
        {
          case 'd': 
          case 'f': 
          case 's': 
          case 'c': 
          default:  
        }		   
      
      case '`':  // to bez break-a
      default: 
    }
    sFormat++; 
  }
  return <ilosc formatow>;
}

//-----------------------------------------------
void outChar( char c )    
{
   putchar( c );
}
//-----------------------------------------------
void outStr( char* pStr )     
{
  
}
//-----------------------------------------------
void outDec( int x )       
{
  // wypisac znak jesli trzeba i wykorzystac outNum()
}

//-----------------------------------------------
void outDouble( double x ) 
{
// wykorzystac outDec()
// przerwac drukowanie jesli reszta <=1e-6  ewentualnie do  8-miu cyfr po kropce
}
//-----------------------------------------------
void outNum( int x ) //rekurencyjny  //x>0
{
  
}
