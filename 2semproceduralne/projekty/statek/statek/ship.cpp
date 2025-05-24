#include "ship.h"

int setTab( char* sFile, int** pTab, int nRow, int nCol ) {

	FILE* fin = NULL; // uchwyt pliku
	if( ( ( fin = fopen( sFile, "r" ) ) == NULL ) ) return 0;

	for( int i = 0; i < nRow; i++ )
	{
		for( int j = 0; j < nCol; j++ )
		{
			if( fscanf( fin, "%d", &( pTab[i][j] ) ) == EOF ) return 0; // tu fscanf przypisze po kolei wartoœci tablicy w formacie intow	
		}
	}

}


int move( int** pTab, int nRow, int nCol, int nDepth,
    int move, int x, int y, int* px, int* py, int** pRoot )
{ // x  y - wsporzedne skad robimy nowy ruch
  // wykonac kolejny ruch w kierunku move obliczajac nowe wspolrzedne *px *py
       //(switch) 4 case'y: up right down left, w kazdym z nich licze *px *py, x- wiersz, y- kolumna (odwrotnie jak w ukladzie wspolrzednych!), case'y w jednej linijce!
  // sprawdzic czy nowe indeksy *px i *py sa w zakresie indeksow tablicy
    // a nastepnie sprawdzic warunek czy nie jest za plytko ">nDepth " oraz
  // czy nie bylo sie juz w lokalizacji (*px,*py) - wg tabl pRoot (wart 0 w nowej lokalicacji)

  //  jesli wszystkie warunki poprawne to zwracamy 1
  //    else 0
}

//----------------------------------------------------------------------------------
int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot,
    int x_dest, int y_dest )
{
    // nie wolno uzywac zmiennej globalnej - jak pamietac numery ruchu przy kazdym wywolaniu? nie moze byc to zmienna lokalna
    //! zmienna static zadeklarowana wewnatrz funkcji root (ona chyba jest o zasiegu jednego pliku)
    // (nie wiem czy to do tego zadania) mozna sie odwolac do zmiennej globalnej (czyli zadeklarowanej przed main na przyklad) z innego pliku .cpp, ale trzeba zadeklarowac jako extern

    // tabl pRoot pamieta droge   -   numer ruchu pole przez ktore odwiedzono (plynie statek) 
  //                                0 pole nie odwiedzone (czyli zaczynam od 1)
  // wstawic do tablicy pRoot kolejny numer ruchu (z inkrementacj¹)

    //if( statek_dotarl do portu ) // kiedy x,y jest rowne x_dest, y_dest
      //  return 1;

    //jesli nie:
   // zdefiniowac nowe wspolrzedne (zmienne lokalne xnew, ynew), mozna zainicjowac na 0
        // sprawdzic wszystkie mozliwosci ruchu (petla for)
           //jesli ruch jest mozliwy w zadanym kierunku (jesli move jest 1) 
              //jesli wykonanie kolejnego kroku sie powiodlo (jest 1) - rekurencyjnie root()
   // return 1;

    // jesli wracamy to ustawiamy w pRoot ze ruch byl zly
    //return 0;

}