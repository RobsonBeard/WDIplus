#include "Util.h"


char getOper() // teraz jest bez sensu, ale chcemy miec potem np. pomijanie spacji
{
	return getchar();
}

int isOper(char c){
	switch (c)
	{
	case '+': 
	case '-':
	case '*':
	case '/':
	case '^': return 1;
	}
	return 0;
}

int prior(char c){
	switch (c)
	{
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3; // nie musi byc konkretnie 1,2,3, chodzi o to, zeby mnozenie bylo wieksze od dodawania itp
	}
	return 0;
}