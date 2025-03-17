#include "Stack.h"
#include "Util.h"
#include "dbl.h"

using namespace std;

void ONP(); // bardzo prymitywne, znakowo, bez spacji, bez nawiasow


int main()
{
	// ZROBIC W DOMU STOS LICZBOWY double (nie na ocene)

	 // poprosic kacpra zeby wyslal ten kod, bo bazowalismy na starym pliku ze stosem a chyba mam to na starym laptopie

	StackItem* pStack = NULL;
	createStack(&pStack);

	push(&pStack, 'A');
	push(&pStack, 'B');
	push(&pStack, 'C');

	//printf("%c %c %c\n",pop(),pop(),pop() ); // to jest zle, bo te sama strukture modyfikuje w jednej linijce!!!
	// powinno wyjsc CBA

	printf( "%c\n", pop(&pStack) ); //! patrzec gdzie sa spacje!, wazne przy oddawaniu, poprawic w tym laptopie stylizacje formatowania! 
	printf( "%c\n", pop(&pStack) ); // przypomniec sobie dzielenie przez odejmowanie z wykladu
	printf( "%c\n", pop(&pStack) );
	printf( "%c\n", pop(&pStack) );
	// za 4 razem bedzie wydrukowany error, ale nie wywali programu

	printf("\n");

	DblItem* pDbl = NULL;
	createStack(&pDbl);

	push(&pDbl, 1.23);
	push(&pDbl, 4.56);
	push(&pDbl, 3.14);

	printf("%.2f\n", pop(&pDbl));
	printf("%.2f\n", pop(&pDbl));
	printf("%.2f\n", pop(&pDbl));
	printf("%.2f\n", pop(&pDbl));


	//printf("Podaj wyrazenie znakowo bez spacji: ");
	//ONP();

	return 0;
}

void ONP() {
	char c;

	StackItem* pStack = NULL;
	createStack(&pStack);

	putchar( getchar() );
	while(isOper(c = getOper()))
	{
		while(prior(c) <= prior(top(pStack)))
			putchar(pop(&pStack));
		push(&pStack,c);
		putchar( getchar() );
	}
	while (!isEmpty(pStack))
		putchar(pop(&pStack));
}
// tam gdzie dwie gwiazdki to z adresem, z jedna gwiazdka to bez