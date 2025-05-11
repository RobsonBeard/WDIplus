// unie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	// union to struktura danych podobna do struct
	// z tym ze poszczegolne pola nak³adaj¹ sie na siebie

	union {
		char c;
		short int x;
	} u;

	u.x = 0x4142;

	// zakladajac, ze zmienna u jest od adresu 0x1000 to u.x zajmuje 2 bajty
	// Little endian
	// 

	union {
		float Real; // 4 bajty
		char Char; // 1 bajt i nakladaja sie na siebie
	} Eqv;

	Eqv.Real = (float)48.8;
	printf( "EX 6: %0d %x-%c\n\n", (int)*(float*)&Eqv.Real, Eqv.Char, Eqv.Char );

	//typedef union {

	//} unType;

	//unType un;


	//! bardzo ciekawy przyklad

	int x = *"\33"; // podaje kod znaku w wersji osemkowej
	char c = *"@";

	printf( "%d %d\n\n", x, c );

	while( --x ) {
		putchar( ++c );
	}


	printf( "\n\n" );

	char arr[8 - 3] = {'a','b'}; // mozna to drukowac jako string!
	char* ptr = &arr[4];
	char* ref = arr + !0; // wskazuje na drugi element tablicy arr, czyli adres arr[1]
	switch(ptr-ref){
	case 13 % 5: putchar( '*' );
	case 13 / 5: putchar( '?' ); // pytanie - co sie wydrukuje??
	}

	printf( "\n\n" );

	printf( "%s","abc"+1); //!

	printf( "\n\n" );

	// typ wyliczeniowy

	enum {BLACK,YELLOW,GINGER=10,GRAY,GREEN};
	printf( "hair = %d %d %d \n", BLACK, YELLOW, GRAY ); // popatrzec jakie s¹ wartoœci! takie jak indeksy w tablicy, chyba ze zmienie! wtedy znowu po kolei
	typedef enum {_BLACK,_YELLOW,_GINGER,_GRAY,_GREEN} HairType;
	HairType hair = _GREEN;
	printf( "hair = %d\n",hair );


	// pola bitowe

	struct {
		int a : 3; // to tez jest 2 bitowe, ale na poczatku jest bit znaku
		unsigned char b : 6; // na ilu bitach to pole jest reprezentowane
		unsigned int c : 2; // tu moge konkretnie wstawiac wartosci 2-bitowe, mozna je nawet wyliczyc: 00,01,10,11
		unsigned int : 5; // wype³niacz do 16 bitow
		int lli : 20; // suma bitow moze byc wieksza od 32
	} bits1 = {0x5,14,3,0x70000};

	// bits1.a to jest liczba ujemna, no bo 0x5 to jest 101, ma bit znaku 1
	// -1 binarnie lub hex to jest FFFFF lub same jedynki
	// 110 to -2
	// 101 to -3 i to jest to samo co bits1.a

	printf( "%d\n", bits1.a );

	// MAKRO

	typedef unsigned char BYTE; 
	typedef unsigned short WORD;
	typedef unsigned long DWORD;

	#define RGB(r,g,b) ( (BYTE) (r) | ((WORD)((BYTE) (g) ) << 8) | (((DWORD) (BYTE) (b)) <<16) )

	#define max(a,b) (( (a)>=(b) )? (a) : (b))

	return 0;
}
