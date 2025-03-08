#include "moje_funkcje.h"

int identyf(char napis[]);

/*
int main() {

	char test[] = "ABCDEF";

	printf("%d", identyf(test));

	return 0;
}*/

int identyf(char napis[])
{
	//Pierwszy znak nazwy identyfikatora musi byæ znakiem nondigit(czyli pierwszym znakiem musi byæ podkreœlenie lub wielkie lub ma³e litery)
	if(
		(napis[0] >= 'a' && napis[0] <= 'z') ||
		(napis[0] >= 'A' && napis[0] <= 'Z') ||
		(napis[0] == '_')
		)

	{
		int i = 1;
		/*
		while(napis[i] != 0) // sprawdzam po kolei znaki, czy s¹ od 0-9 lub ma³e lub du¿e litery lub podkreslenie. jeœli jest inny znak - return 0
		{
			if(
				!(
					(napis[i] >= 'a' && napis[i] <= 'z') ||
					(napis[i] >= 'A' && napis[i] <= 'Z') ||
					(napis[i] >= '0' && napis[i] <= '9') ||
					napis[i] == '_'
					)
				)
				return 0;

			i = i + 1;
		}
		*/

		// moje - powinno byæ to samo
		for(int i = 0; napis[i] != 0;i++) {
			if(
				!((napis[i] >= 'a' && napis[i] <= 'z') ||
					(napis[i] >= 'A' && napis[i] <= 'Z') ||
					(napis[i] >= '0' && napis[i] <= '9') ||
					napis[i] == '_')
				)
				return 0;
		}

		return 1;
	}
	else
		return 0;
}