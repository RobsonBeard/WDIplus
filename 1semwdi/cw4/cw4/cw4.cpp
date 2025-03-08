#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	// mozna usuwac ukryty plik .vs, szczegolnie przy przesylaniu sobie na dysk, gita itp, on sie odbuduje przy wlaczeniu programu i tak
	// tak samo niektore debugi mozna usuwac, x64 tez, wazny jest za to plik .sln - wystarczy tylko jego spakowac, przetestowac, mozna tez sobie kompilowac na release itp., mniej miejsca zajmuje

	int x = 2;
	int w = x - 5;
	//if (w < 0) w = -w; // uzywac tego, a nie (-1)*w
	//dla debugowania warto miec instrukcje w osobnej linijce

	if (w < 0)
		w = -w;
	
	w = w * 2 / 3;
	//w *= 2 / 3; // tu najpierw oblicza sie to co jest po prawej - 2/3 = 0, wiec jest inny wynik
	
// ustawic sobie formatowanie po swojemu
	// nie moze byc spacji po slowach kluczowych!!!
	printf("2*|%d-6|/3 = %d\n", x, w); // 8/3=2

	return 0;
}