
//-->>> Modul Kolejki PIORRYTETOWEJ <<---
//UWAGA: mozna uzywac calloc() oraz 
//       #pragma once do plikow naglowkowych - NIE UZYWAC TEGO
//       NALEZY ZACHOWAC TAKIE NAZWY FUNKCJI, TYPOW I POL STRUKTUR JAK PODANO!!!!!!! - inaczej nie sprawdzam 


Kolejke priorytetowa mozna zrealizowac na dwa sposoby. 
Pierwsza przy pomocy tablicy - a dokladniej stogu ale odwrotnego niz w sortowaniu 
stogowym - to znaczy najwiekszy element (albo element ktorego priorytet jest najwiekszy) jest 
jako pierwszy w tablicy. Tutaj w stogu kazdy element jest wiekszy od swoich potomkow.
Potomkiem elementu i jest element 2*i+1 oraz 2*i+2
Druga metoda to  w postaci drzewa zrownazonego BST- trudniejsze gdyz trzeba dodatkowo
przywracac zrownowazenie drzewa.

Nalezy zrealizowac kolejke priorytetowa, przechowujaca dowolne elementy (elementy typu definiowanego 
przez u¿ytkownika) z okreslonym priorytetem przy pomocy stogu!.

 - Operacja usuwania z kolejki polega na usunieciu pierwszego (zerowego) elementu z kolejki, 
   zmniejszaj¹c ilosc elementow w kolejce oraz nastepnie wkopiowac ostatni z kolejki w pierwsza pozycje 
   i przywrocic warunken stogu metoda UpdateDown() z sortowania (zmodyfikowana jak do 
   sortowania malejacego - bo prioprytety od najwiekszego  do najmniejszego)

 - Operacja  dodania nowego elementu -> dodajemy na koncu, zwiêkszaj¹c ilosc elementow w kolejce
   i uaktualniamy stog ale od dolu do gory- UpdateUp (podobnie jak w dol ale latwiej bo jest tylko jeden rodzic)

 - zdefiniowaæ podobnie jak w przypadku FIFO oraz modulu Listy plik global.h z deklaracja typu
   definiowanego przez uzytkownika (jaka informacja bedzie przechowywana w kolejce)
   Prosze tu uzyc tego samego typu co w poprzendich projektach (struktura zalozona z int-a oraz wsk na int
   czyli tablicy dynamicznej int-ow)


//==============  global.h ====================================//

typedef struct
{ 
  int  nKey;
  int* pTab; // moze byc dwuelementowa tablica
} PQInfo;    // PQINFO - the user identyfier

#define PQINFO PQInfo    // nazwy PQINFO - uzywac WSZEDZIE - NAWET W PROGRAMIE TESTUJACYM!


//==============   KONIEC global.h  ============================//


//================================================================
// Modul MA SIE NAZYWAC:  PQueue - PQueue.h oraz  PQueue.cpp 

//---------------------------------
//  PQueue.h

// zdefiniowac dwie stale:
//   - PRIOR_ERROR  jako minimalna wartosc calkowita
//   - POS_ERROR    jako wartosc ujemna np -1 (indeks tablicy jakiego nie ma!)


typedef struct    // zachowac oryginalne nazwy!!!!!!  
{
  // pInfo;       // Ptr to user info  
  // nPrior;      // prior value (int) for the user info  
} PQItem;         // type of the queue item


typedef struct   // zachowac oryginalne nazwy!!!!!!
{
  // pPQueue     // kolejka realizowana w postaci stogu  (dynamiczna tablica wskaznikow do PQItem)
  // nPQSize      // rozmiar calkowity kolejki priorytetowej
  // nPQCurrSize  // ilosc elelemntow w kolejce (jednoczensie indeks pierwszego wolnego miejsc w kolejce) 
  
} PQueue;

//dopisac parametry!!!!, na pewno pierwszym parametrem wszedzie bedzie kolejka, wszedzie sprawdzac czy kolejka JEST, czasem PQisEmpty, czasem samo q
PQInit();     // kreuje kolejke o zadanym rozmiarze i zwraca wskaznik do niej lub NULL gdy blad (czyli typu PQueue*?, parametr - rozmiar)
PQisEmpty();  // zwraca 0 lub 1 - kolejka pusta/nie pusta, WYRAZENIEM PYTAJNIKOWYM 
PQSize();     // zwraca ilosc elementow w kolejce, tez wyrazenie pytajnikowe
PQMaxPrior(); // zwraca najwiekszy priorytet w kolejce (z zerowej pozycji) lub PRIOR_ERROR
PQEnqueue();  // wstawia do kolejki informacje o zadanym priorytecie, zwraca 0 (niepowodzenie) lub 1 (powodzenie), to zrobic na razie na koncu, tak samo dequeue
PQDequeue();  // zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie, (trzeba pamietac o czyszczeniu pamieci)
PQClear();    // czysci cala kolejke zwalniajac pamiec alokowana przez uzytkownika (na info), nie znana struktura do zwolnienia 
              // dlatego przekazac trzeba funkcje uzytkownika do zwolnienia pamieci przez parametr 
PQRelease();  // zwraca w parametrze we-wy NULL (kolejka) usuwaj¹c wszyskto wczesniej (czyszczenie kolejki)
PQPrint();    // drukuje w porzadku preorder (rekurencyjnie) od zadanej pozycji, aby wydrukowaæ info uzytkownika przekazac 
              // trzeba funkcje drukujaca ta informacje. Dodatkowo, drukuje priorytet w okraglych nawiasach oraz pozycje w 
              // kolejce w kwadratowych nawiasach

// ---------------- drugi krok

PQSetPrior(); // ustawia nowy priorytet dla zadanej informacji uzytkownika, nie znana struktura informacji, która trzeba wyszukac
              // dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika. Funkcja zwraca poprzedni priorytet lub PRIOR_ERROR 
              // czwarty parametr - adres funkcji - parametry: kolejka, adres, nowy priorytet, adres funkcji
PQsetPrior(); // ustawia nowy priorytet dla informacji uzytkownika bedacej na zadanej pozycji w kolejce (indeks w tablicy),
              // Funkcja zwraca poprzedni priorytet. W przypadku bledu zwraca PRIOR_ERROR 
              // zwraca stary priorytet

PQGetPrior(); // zwraca priorytet informacji uzytkownika w kolejce lub PRIOR_ERROR, nie znana struktura informacji, która trzeba wyszukac
              // dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika  
PQgetPrior(); // zwraca priorytet informacji uzytkownika z zadanej pozycji w kolejce lub PRIOR_ERROR

PQFind();     // zwraca indeks wyszukiwanej informacji uzytkownika, nie znana struktura informacji uzytkownika dlatego
              // przekazac trzeba funkjce porownujaca informacje uzytkownika
              // Zwaraca POS_ERROR jesli nie ma info w kolejce


//-----------------------------------------
// pomocnicze w implementacji 2 funkcje !!!!
void UpdateDown();  // update heap down between index l and p  <--- modified Update() from HeapSort 
void UpdateUp();    // update heap up between index l and p  

//===================================================================
//===================================================================

UpdateDown() 
{
  // analogicznie jak w sortowaniu stogowym ale zmienionic
  // przetestowac najpierw ta funkcje w sortowaniu malejacym!!!
  //    (wybiera sie element o wiekszym priorytcie)
  // tak aby pierwszy element mial najwiêkszy proirytet
}

UpdateUp()
{
  // analog jak w UpdateDown
  // tylko uaktualnienie w gore stogu i jest tylko jeden rodzic 
}

PQDeQueue()
{
  // zwraca informacje z indeksu 0
  // wpisac ostatni do 0-wego
  // uaktualnic w dol (update na dol)
}

PQEnQueue() // parametr: kolejka, informacja wstawiana, priorytet
{
	// sprawdzic czy nie przepelnione, czy jest kolejka ( 2 rozne bledy )
// funkcja jest typu int - czy sie powiodlo czy nie
// dynamiczna alokacja pamieci, wstawiam informacje pod ten element
  // wstawic na koncu
  // uaktualnic w gore - tutaj przydalaby sie wiedza z odwrocenia kolejnosci sortowania heapsorta (z rosnacego na malejace), jest troszke prostsze, jest tylko jeden przodek zamiast dwoch potomkow, tu jakies sprytniejsze wyrazenie
// jakos currentsize +1?
}



//========================== w pliki z funkcja main()

// naglowek funkcji drukujacej info uzytkownika (parametr typu const void* )
// naglowek funkcji porownujacej info uzytkowniak. Zwraca -1 pierwszy mniejszy, 1 jesli pierwszy wiekszy else 0.
//          (parametry const void* )
// naglowek funkcji zwalniajacej pamiec (parametr typu const void* )

// implementacja tych trzech funkcji

//---test, dopiero jak wszystko dziala, debuggerem mozna sprawdzic czy dobrze jest wszystko zalokowane w pamieci:
 - wykreowac kolejke 20-sto elementowa
 - dodac 6 elementow z roznymi priorytetami i w ró¿nej kolejnosci priorytetów - wydrukowac
 - usunac z kolejki (z najwiekszym priorytetem)  - wydrukowac 
 - dodac dwa elementy - wydrukowac
 - wyszukac jeden elem 
 - zwiekszyc mu priorytet (unikalny) - wydrukowac
 - zmniejszyc priorytet innemu elementowi (unikalny) - wydrukowac
 - usunac cala kolejke

 - przetestowac jak bedzie sie zachowywac modul jesli powtorza sie priorytety niektorych elementow
   (zmienic priorytet np na maksymalny - powtorzy sie i sciagnac dwa razy, po kazdym drukowanie)

     
 // funkcja compare() - zwraca 1, 0, -1 w zaleznosci od porownania
 //(zdjecie)12. jeszcze PQSize PQMaxPrior PQisEmpty
 //14. najpierw EnQueue

     void PQPrint( PQueue* q, int, void() ) {
     if( !q || !printItem ) return; 
     if( i >= PQSize( q ) ) reteurn;

     printItem( q->pQueue[i].pInfo ); // tutaj jest niedokladnie, bo pan robil na strukturach a nie tablicach
         printf(" {%0d} {%d}......... ", q->pQueue[i].nPrior,i);
         PQPrint( q, 2 * i + 1, printItem );
         PQPrint( q, 2 * i + 2, printItem );
 
 }

 // drukuje priorytet i indeks w kolejce
 // preorder - najpierw odwiedzam wierzcho³ek, potem rekurencja dla lewej ga³êzi i dla prawej ga³êzi, my z tego korzystamy
 //  - najpierw lewe poddrzewo, prawe poddrzewo
 // w pliku jest napisane co sie bedzie dzialo gdy 2 priorytety beda takie same