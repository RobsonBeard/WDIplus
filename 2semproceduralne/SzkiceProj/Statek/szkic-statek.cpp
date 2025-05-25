/*==================
BACKTRACKING  algorytm z nawrotami
-------------
ogólny algorytm wyszukiwania wszystkich (lub kilku) rozwi¹zañ niektórych problemów 
obliczeniowych, który stopniowo generuje kandydatów na rozwi¹zanie jednak, 
gdy stwierdzi, ¿e znaleziony kandydat x nie mo¿e byæ poprawnym rozwi¹zaniem, 
nawraca (ang. "backtracks") do punktu, gdzie mo¿e podj¹æ inn¹ decyzje 
zwi¹zan¹ z jego budow¹
==============================*/

modul:   ship.cpp  ship.h

//zdefini stale N i M - wymiary  (na 10)  tam gdzie main()
#define SHIP_DEPTH 5    // glebokosc zanurzenia okretu   tam gdzie main()

// gdy jest 5 to bêdzie szorowa³ po dnie, wiêc warunek to jest glebokosc >5 czyli co najmniej 6

// zdefiniowac typ wyliczeniowy: kierunki ruchu : UP LEFT DOWN RIGHT  (wartosci kolejne od 0)


int move( int** pTab, int nRow, int nCol, int nDepth, 
     	    int move, int x, int y, int* px, int* py, int** pRoot );

/* pTab - tablica okreslajaca glebokosc w kazdym kwadracie
   nRow, nCol - rozmiar pTab, 
   nDepth - glebokosc zanurzenia statku 
   move - kierunek ruchu (wart typu wylicz) up right down left
   x, y - indeksy w tablicy skad wykonujemy kolejny ruch np. zaczynamy od 0,0
   px, py - nowe wspolrzedne  (parametry WYjsciowe) // albo zostawiam wiersz i zmieniam kolumne, albo na odwrot (i zawsze zmieniam o 1)
   pRoot - tablica pamietajaca ruchy o rozm nRow, nCol
*/
int root( int** pTab, int nRow, int nCol, int nDepth,  
		  int x, int y, int** pRoot, int x_dest, int y_dest  );   //--- rekurencyja
/* pTab tabl glebokosci   o romiarze nRow  i nCol
    dDepth - glebokosc zanurzenia statku (!)
    x, y - wspolrzedne skad robimy kolejny ruch
    pRoot tablica kolejnych ruchow (w pole wstawia sie numer kolejnego ruchu)
    x_dest, y_dest - wsporzedne portu
*/

void clearRoot( int** pRoot, int nRow, int nCol );
// zeruje tablice  (JEDNYM memsetem - do szczegolow przejdziemy) - bo to jest ciagly element pamieci, po prostu ilosc elementow*sizeof(int)

int setTab( char* sFile, int** pTab, int nRow, int nCol ); 
// wczytuje dane z pliku
// wczytywane z maina
  // sFile -  nazwa pliku wejsciowego - parametr main()
  // pTab  - tablica glebokosci morza
      // param: nRow, nCol wymiary tablicy glebokosci morza
  // w razie niepowodzenia otwarcia pliku do odczytu zwraca 0 
  // else 1

//===================================================================================
//=======================================
// implamentacja

//-------------------------------------------------------------
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
int root( int** pTab, int nRow, int nCol, int nDepth,  int x, int y, int** pRoot,
           int x_dest, int y_dest )
{  
    // nie wolno uzywac zmiennej globalnej - jak pamietac numery ruchu przy kazdym wywolaniu? nie moze byc to zmienna lokalna
    //! zmienna static zadeklarowana wewnatrz funkcji root (ona chyba jest o zasiegu jednego pliku)
    // (nie wiem czy to do tego zadania) mozna sie odwolac do zmiennej globalnej (czyli zadeklarowanej przed main na przyklad) z innego pliku .cpp, ale trzeba zadeklarowac jako extern
    
    // tabl pRoot pamieta droge   -   numer ruchu pole przez ktore odwiedzono (plynie statek) 
  //                                0 pole nie odwiedzone (czyli zaczynam od 1)
  // wstawic do tablicy pRoot kolejny numer ruchu (z inkrementacj¹)

  if( statek_dotarl do portu ) // kiedy x,y jest rowne x_dest, y_dest
    return 1;
    
  //jesli nie:
 // zdefiniowac nowe wspolrzedne (zmienne lokalne xnew, ynew), mozna zainicjowac na 0
      // sprawdzic wszystkie mozliwosci ruchu (petla for)
	     //jesli ruch jest mozliwy w zadanym kierunku (jesli move jest 1) 
            //jesli wykonanie kolejnego kroku sie powiodlo (jest 1) - rekurencyjnie root()
               return 1;
	
	// jesli wracamy to ustawiamy w pRoot ze ruch byl zly
    return 0;
  
}   



//=============================================================
//  pLIK CPP
//-------------------------------------------------------------
int main()
{
  //!!argc
  //Wykreowac dynamicznie dwie tablice dwuwymiarowe (ogolnie moga byc rozne wymiary szerok i wysok)
    // kreowanie  druga metoda tworzenia dynamicznego tablic 2D
  
  // wyzerowac obie tablice (zaleznie czy bylo malloc czy calloc) // (czyli tego nie robic, bo uzywam calloc)
  // wczytac dane (sprawdzic argc)  glebokosci 
  10 12 9 10 8 6 4 4 7 8
  10 12 9 10 8 4 5 6 6 5
   6 9  9  5 4 6 4 4 7 8
  ....
  // Jezeli nie znaleziono drogi od (0,0) do (N-1,M-1)- funkcja rekur root - wypisac
  // "** Nie ma mozliwosci doplynac do portu!!\n\n";

  // jesli ok to wypisac trase
  //zwolnic pamiec!! - w funkcji
  return 0;
}
//==========================================================


int** CreateTab2D( int nCol, int nRow ) // to jest duzo prostszy naglowek niz matrix
{
    // jest to druga metoda alokowania pamieci z pdf'a - ci¹g³y obszar pamieci, bez petli, jedna alokacja (calloc lub malloc) od razu wszystkie wiersze naraz
    // adres kolejnego wiersza to adres poprzedniego (np pTab[0] + ilosc elementow w wierszu), ale zeby tego nie pisac, to zrobic zmienna dodatkowa jako ptab[0] i zwiekszac ja o += nCol
  int** p = (int**)calloc. . . .
  if( !p ) return NULL;
  . . .

  return p; // zwraca adres do tablicy, tym razem on nie jest przekazywany jako parametr
}

void freeTab2D( int*** pTab )
{
    // zwrocic uwage, ze 3 gwiazdki
 // zwolnic 0-owy elem tablicy 
 // zwolnic tablice tablic
 // wynulowac wskaznik
}

// i wziac printtab2d z matrixa, tylko przerobic na prostok¹tn¹ macierz (ROWS, COLS), no i tez intow, nie doubli

// potem do testu powstawiac jakies losowe wartosci w komorki i wydrukowac, a na koncu freeTab2D

// nie wolno uzywac zmiennej globalnej - jak pamietac numery ruchu przy kazdym wywolaniu? nie moze byc to zmienna lokalna
//! zmienna static zadeklarowana wewnatrz funkcji root (ona chyba jest o zasiegu jednego pliku)
// (nie wiem czy to do tego zadania) mozna sie odwolac do zmiennej globalnej (czyli zadeklarowanej przed main na przyklad) z innego pliku .cpp, ale trzeba zadeklarowac jako extern
