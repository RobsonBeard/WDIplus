  
/*  TEMAT PROJEKTU ==================================*/
/* Obliczyæ macierz odwrotna (6x6)  A^-1  */
/*===================================================*/

Projekt ma skladac sie z programu glownego i modulu macierzy matrix.h  i matrix.cpp
Dane wejsciowe czytane z pliku we (parametr funkcji main*())

Maja byc w programie wydruki kontrolne np po wczytaniu rozmiaru, po transponowaniu, po obliczeniu 
macierzy dopelnien itp
na warunkowej kopilacji - zdefiniowac DEBUG i wydruki jesli zdefiniowano DEBUG
#ifdef DEBUG
 // wydruk
#endif


//====== matrix.h - interfejs modulu  macierzy (naglowki funckji "publicznych")

int CreateMatrix( double*** pTab, int nDim );   //!!! zwraca  0  gdy error  1 - ok
void DeleteMatrix( double*** pTab, int nDim );  // *pTab=NULL

//transponowanie macierzy
void TransMatrix( double** pTab, int nDim ); // bez pomocniczej, 

// macierz odwrotna, na we obliczony wczesniej w main() det  (tu w funkcji juz na pewno musi byc det!=0)
void InverseMatrix( double** pInv, double** pTab, int nDim, double det );

// wyznacznik rekurencyjnie 
double Det( double** pTab, int nDim ); //rozwiniecie wzgl 1-go wiersza 
// dla 2x2 uzyc znanego wzoru - mozna zaindeksowac (uzyc **pTab zamiast pTab[0][0])
// przed - wykreowac macierz pomocniczna o rozmiarze o 1 mniejszym, po - wyzerowac pamiec
// zaczynam od minusa bo (-1)^1, potem (-1)^2 itd. wiec po prostu bede robil sign = -sign po kazdej kolumnie
//! to sie tutaj rozni w zaleznosci od grupy, wiec nie kopiowac

// drukuje macierz 
void PrintMatrix( double** pTab, int nDim );


//======= matrix.cpp  - implementacja modulu
/* implementacja metod "publicznych" + prywatne   */

// wycina wiersz nRow i kolumne nCol z tab we pTabI i reszte kopiuje do 
// tabl wyjsciowej pTabO 
// nalezy uzyc dwa razu continue pomijajac wiersz nRow i kolumne nCol
void Complement(  double** pTabO, double** pTabI, int nRow, int nCol, int nDim ); 

// oblicza macierz dopelnien pTabD na podstawie tablic wejsc pTab
void ComplMatrix( double** pTabD, double** pTab, int nDim ); //macierz dopelnien




//============================================
//============================================
 PROGRAM GLOWNY
Program czyta dane z pliku wejsciowqego bedacego parametrem main()
Nalezy wiec sprawdzic czy ten parametr jest 

int main( int argc, char* argv[])
 argc - ilosc parametrow - tu musi byc 2 (pierwszym pod indeksem 0 jest ZAWSZE nazwa programu
        ale podczas debugowania poprzedza sciezka dostepu)
 argv - tablica stringow bedacych parametrami wiec argv[1] to nazwa pliku wejsciowego


W pliku z funkcja main() ma byc dodatkowo funkcja 

void ReadData( FILE* fin, double** pMatrix, int nDim );

#define DEBUG

//**** SZKIC MAIN()
 int main( int argc, char* argv[] )
{
  if( argc != 2 )
  {
    //mesg  "Usage: ukl <input_file>"  
    return 1;
  }

  // otworzyc plik do odczytu   -- argv[1] i sprawdzic czy sie powiodlo

/*=========================================
// dane czytamy przez fopen i fscanf
Uzywac fopen a nie fopen_s jak proponuje Visual Studio
Aby wylaczyc ewentualne bledy lub warningi nalezy do projektu dodac stosowna stala

menu->Project-> <nazwa_projektu> Properties -> Configuration Properties -> C/C++ -> Preprocessor
dodac stala preprocesora: _CRT_SECURE_NO_WARNINGS

I przekompilowac calosc od zera
====================================*/

  // odtworzyc plik do odczytu (tekstowy)
  // odczytac rozmiar nDim
#ifdef _DEBUG_
//wydruk kontrolnyc  rozmiaru
#endif
  double** pMatrix = NULL;
  // wykreowac macierz ukladu nDim x nDim
  // sprawdzic
  // wczytac dane ( ReadData() )

#ifdef _DEBUG_
//wydruk kontrolny wczytanych danych
#endif

  // obl wyznacznik
#ifdef _DEBUG_
//wydruk kontrolny
#endif  
  
  // obrocic macierz
  // wydruk wyniku

  // zwolnic pamiec  (usuwanie macierzy)!!!

 return 0;
}


UWAGI DODATKOWE:

- mozna najpierw przetestowac na ukladzie 3x3
- wydruki kontrolne na warunkowej kompilacji
- parametrem programu jest nazwa pliku z danymi - pierwsza linia 
  to rozmiar macierzy ukladu (lub ilosc rownan i niewiadomych) 
  a potem wiersz macierzy ukladu i wyraz wolny w tej samej linii np dla ukl 3x3 byloby
  3
  1   2  3        
  2   0  0   
  -1 -1 -1 
  
- tylko standardowe we/wy
-  _CRT_SECURE_NO_WARNINGS

// 1. sposob z pdf-a
// najpierw alokuje pTab**, potem w pêtli pTab[i], czyli *pTab chyba
// bo 2 metoda w przyszlym tygodniu (jak nie bedziemy mieli za duzego kaca)
