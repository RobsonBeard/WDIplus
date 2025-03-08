using namespace std;
#include <stdio.h>
#include <iostream>

int getNum();
int isDigit(char c);
void skipSpaces();

int main()
{
	// chce wczytac liczbe inaczej niz cin
	// jak program czyta liczbe
	//int x;
	//cin >> x;
	
	printf("Podaj liczbe naturalna: ");
	printf("Wczytano %d\n",getNum());

	return 0;
}

int getNum() {
	char c;
	int res = 0;
	/*while((c = getchar()) >= '0' && c <= '9') {
		res = res * 10 + (c - '0');
	}*/
	while(isDigit(c=getchar())) {
		res = res * 10 + (c - '0');
	}
	return res;
}

int isDigit( char c) {
	return c >= '0' && c <= '9';
// TUTAJ NIE WOLNO UZYWAC IFOW BO SA UJEMNE PUNTKY!!!
}

void skipSpaces() {
	char c;
	while((c = getchar()) == ' ') {
		// kreci sie
	}
	ungetc(c, stdin); // nie dziala, nie wiem
}