#include <stdio.h>


// #define FUN_PTR_TYPE // te linijke moge komentowac i odkomentowywac i bedzie dzialac inny fragment kodu

int f1();
int f2();

int* fun1( int i ); // mozna pisaæ nazwe parametru, ale nie musze
int* fun2( int );

int tab[] = {10,20,30,40,50,60,70}; // nie lubimy globalnych zmiennych, ale niech tutaj bedzie

#ifdef FUN_PTR_TYPE 
// inny sposób, przeciwwaga, warunkowa kompilacja ifndef
// tutaj robimy typy, powinnismy je robic w plikach naglowkowych

typedef int ( *pFType )( ); // pFType to typ wskaznikowy na funkcje bezparametrowe zwracajace int
typedef int* ( *pFunType )( int );

#endif 

int main()
{
	// int t[3]
	// int (*t1)[3] // rozne rzeczy, zastanowic sie

	#ifdef FUN_PTR_TYPE

	pFType pF = f2;
	pFunType pFun = fun1;

	#else

	int ( *pF )( ) = f2; // pF to wskaznik do funkcji bezparametrowej zwracajacej int
	// nazwa funkcji np f2 jest jej adresem, mozna tez uzyc &f2
	//! nie ma nawiasów przy wskazniku (*pF)!

	int* ( *pFun )( int ) = fun1; // wskaznik do funkcji z parametrem int i zwracajaca wartosc typu int*

	#endif //FUN_PTR_TYPE


	

	printf( "f2() = %d   fun1(2) = %d\n", pF(), *pFun( 2 ) );
	printf( "pFun(2) = %x    &(tab[3])= %x\n",pFun(2),&(tab[3]) );


	return 0;
}

int f1() {

	return 1;
}

int f2() {

	return 2;
}

int* fun1( int i ) {

	return tab + i + 1; // uprzedzam: nie sprawdzam, czy wyjde poza zakres tablicy, i>=6 wychodze poza tablice 
	//! przerobic BetterComments, zeby nie zmienialo >=
}

int* fun2( int i ) {

	return tab + i + 2;
}
