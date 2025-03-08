#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{ // Zadanie - trojkat wyswietlany, cyfry od 1 do 9

	// moja wersja
	/*int rzedy = 9;

	for(int i = 1;i <= rzedy;i++) {
		
		
		for(int j = 1;j <= i;j++) {
			printf("%d ",j);
		}
		printf("\n");
	}*/


	//tablica

	// petla drukujaca wiersze - 9 razy
	// drukuje:
	// 1) 9-i spacji
	// 2) drukujemy cyfry od 1 do i
	// 3) drukujemy cyfry od i-1 do 1
	// 4) nowa linia

	int rzedy = 9;

	for(int i = 1;i <= rzedy;i++)
	{
		for(int j = 1;j <= (rzedy - i);j++) // tu mozna zrobic np j= 19-i i wtedy trojkat sie przesunie w prawo
		{
			printf(" ");
		}
		for(int j = 1; j <= i;j++) {
			printf("%1d",j); // w sumie nie wiem czemu tu akurat %1d, bez wyglada tak samo
		}
		for(int j = (i - 1);j >= 1;j--) {
			printf("%1d",j);
		}

		printf("\n");
	}



	return 0;
}

