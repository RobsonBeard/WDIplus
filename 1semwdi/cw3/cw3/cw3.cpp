#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	double a = 2; // kazda zmienna w osobnej linijce
	double b = 3;
	double c = -4;
	double d = 1;
	double x = 1.345;
	double w = ((a*x+b)*x+c)*x+d;
	//printf("wartosc wielomianu = %lf\n",w); // %lf - long float, dluga liczba zmiennoprzecinkowa
	//printf("wartosc wielomianu = %14.8lf\n",w); // tutaj ustawiamy ile chcemy liczb z przodu i po przecinku
	//printf("wartosc wielomianu = %.8lf\n",w); // tutaj ustawiamy ile chcemy liczb po przecinku, mozna 0.8 ale lepiej .8
	int t = 122;
	printf("liczba testowa = %08d\n",t); // od lewej strony uzupelnia zerami, jakos nie dziala na double

	return 0;
}
