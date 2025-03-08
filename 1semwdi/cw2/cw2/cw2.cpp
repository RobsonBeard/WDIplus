
#include <iostream>
using namespace std;
#include <stdio.h>

int f();

int main()
{
	//mozna sobie ustawic zeby nie trzeba bylo wciskac FN
	// DEBUGOWANIE - F10, potem step over tez F10
	// F11 do sledzenia srodka funkcji

	int abc = f();

	int x = 13;
	int y = 5;
	int r = x % y; //x - (x / y) * y;

	printf("Reszta z dzielenia %d przez %d wynosi %d\n",x,y,r);

}

int f() {
	return 13;
}

