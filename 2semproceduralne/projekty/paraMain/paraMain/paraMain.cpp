#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// funkcja main ma normalnie 2 parametry. ten visual akurat ich nie wypisuje.
// argv jest tablic¹ tablic. system operacyjny tworzy t¹ tablicê zawsze i przekazuje do funkcji main. dzieki temu argc to rozmiar tablicy argv, zawsze >= 1
// argv[0] to zawsze nazwa naszego programu .exe
// w niektorych przypadkach to cos wiecej niz nazwa programu
// jesli argc > 1 to znaczy ze po nazwie programu sa jakies inne parametry

//! initTab bedzie potrzebne do projektu, z drobna zmiana

//! rozmiar tablicy np. intow = sizeof(tab) / sizeof(int)
//! clock trzeba popatrzec w dokumentacji
//! my robimy te funkcje sortujace, ktore znamy na razie (chyba)
//! wazne zeby program dzialal na za tydzien
//! na przyszly raz pobrac z internetu w pdf ksiazke Nicklaus Wirth "Algorytmy + Struktury danych = programy"
//! bedziemy umiejetnie przepisywac sortowania z Pascala do C, sa drobne roznice np. indeksowanie tablic w pascalu od 1 do n zamiast od 0 do n-1 (C)
//! w tej ksiazce jest blad w sortowaniu przez proste wybieranie, w Pascalu zamiast break robia goto
//! sortowanie przez kopcowanie = sortowanie stogowe, przesiewanie = update
//! robic sobie komentarze, pisac mnemonicznie, kod samokomentujacy sie
//! w pliku naglowkowym tylko sortowania

#define PARAMNO 3 // param number 3

int createTab(int** pTab, int nSize); // zwrocic uwage, ze tu dwie gwiazdki, bo chce adres (chyba)
void printTab(int* pTab, int nSize);


//! Project -> properties -> Debugging -> Command Arguments
//! Project ->  C/C++ -> Preprocessor -> dodac CRT......
//! gdy uruchamiamy z linii komend (cmd)  - dodajemy plik .txt tam gdzie jest .EXE!
// w innym przypadku, gdy uruchamiamy z projektu, to umieszczamy tam, gdzie jest Source Files
int main(int argc, char* argv[])
{
	if( argc != PARAMNO ) {
		printf( "Usage: %s <tab_size> <file_name>\n",argv[0]); // podpowiadamy uzytkownikowi co zrobil zle i co ma poprawic, zeby uruchomic program
		return 1; //! wazne - uzyc unikalnego kodu, innego niz 0 (za kazdym razem, gdy jest blad, wychodzic z inna liczba)
	}

	int nSize = atoi( argv[1] ); // funkcja biblioteczna - napis do inta, istnieje tez np. atof()
	printf( "nSize = %d\n",nSize );

	int* pTab = NULL; //! bede ja kreowal wewnatrz funkcji, tutaj MUSZE zainicjowac
	if( !createTab( &pTab, nSize ) ) {
		printf( "Memory allocation error!\n" );
		return 2;
	} // w naszym kodzie tego ifa bedziemy robic dwa razy, pamietac o tym zeby return byl inny

	FILE* fin = NULL;
	if( ( fin = fopen( argv[2],"r" ) ) == NULL ) // wlasnie do tego wykorzystujemy parametr argv, nie chce miec stalej nazwy pliku
		// mozna pisac "rt" jako parametr, ale "t" jest domyslnie
	{
		printf("Error open input file %s\n",argv[2]);
		return 3;
	}

	int* p = pTab;
	for( int i = 0; i < nSize; i++ ) {
		//! adresowe tez bez spacji &(x)
		// scanf( "%d", &(pTab[i]) ); // czytanie z klawiatury (stdin), inny printf?
		fscanf( fin, "%d", p++ ); //! sk¹d ten b³¹d? kacper chyba go nie ma
	}
	printTab(pTab,nSize);

	free( pTab );
	fclose( fin ); //! wazne praktyki na koniec

	return 0;
}

int createTab( int** pTab, int nSize ) {
	*pTab = (int*)malloc( nSize * sizeof( int ) );
	if( !*pTab ) // if(*pTab == NULL)
	{
		// tutaj nie robie komunikatu o bledzie, tylko zrobilismy typ funkcji jako int po to, zeby przez 0 lub 1 informowac czy funkcja sie powiodla
		return 0;
	}

	//tutaj chce wyzerowac tablice
	//! dla !zerowania! NIGDY nie uzywac petli for (albo jakiejs innej)
	memset( *pTab, 0, nSize * sizeof( int ) ); //! kopiowac ilosc bajtow z malloca!
	return 1;
}

void printTab( int* pTab, int nSize ) {
	for( int i = 0; i < nSize; i++ )
	{
		printf("%d ",*pTab++); // tutaj dopisujemy to co bylo poprzednio w printTab, ale musimy zdefiniowac stala preprocesora
		//! nie uzywac pTab[i] w printTab i initTab, teraz wskazniki
		// nie niszcze oryginalnego wskaznika do tablicy, bo pracuje na kopiach (parametry to kopie)
		// gdyby w forze by³o continue to trzeba robiæ obok i++, *pTab++
	}
}

/*
POPRAWKI
double w moim printf:

0.2350000001

nie uzywac dodatkowej zmiennej
x = x - (int)x; - tak mozna! //done

jakis taki warunek w forze!!!!
for(int i=0; i<8 && (x-(int)x>1e-6); i++) // done

(int)(x*=10)%10 + '0'  - tak dla cyfr po przecinku! // done

rozpatrzenie 0 w outDec
w outNum i ifie dwie instrukcje albo cos takiego?

sprobowac wyeliminowac blok z case i te zmienna lokalna

*/
