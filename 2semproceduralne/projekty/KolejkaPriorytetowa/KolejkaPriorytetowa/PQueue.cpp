#include "PQueue.h"

PQueue* PQInit( int qSize ) {
	return (PQueue*)calloc( qSize, sizeof( PQueue ) );
}

int PQisEmpty( PQueue* q ) {
	// co tu musi byc?
	
	//return !q || q->nPQCurrSize;
	return -420;
}

//UpdateDown()
//{
	// analogicznie jak w sortowaniu stogowym ale zmienionic
	// przetestowac najpierw ta funkcje w sortowaniu malejacym!!!
	//    (wybiera sie element o wiekszym priorytcie)
	// tak aby pierwszy element mial najwiêkszy proirytet
//}

//UpdateUp()
//{
	// analog jak w UpdateDown
	// tylko uaktualnienie w gore stogu i jest tylko jeden rodzic 
//}

//PQDeQueue()
//{
	// zwraca informacje z indeksu 0
	// wpisac ostatni do 0-wego
	// uaktualnic w dol (update na dol)
//}

//PQEnQueue() // parametr: kolejka, informacja wstawiana, priorytet
//{
	// sprawdzic czy nie przepelnione, czy jest kolejka ( 2 rozne bledy )
// funkcja jest typu int - czy sie powiodlo czy nie
// dynamiczna alokacja pamieci, wstawiam informacje pod ten element
  // wstawic na koncu
  // uaktualnic w gore - tutaj przydalaby sie wiedza z odwrocenia kolejnosci sortowania heapsorta (z rosnacego na malejace), jest troszke prostsze, jest tylko jeden przodek zamiast dwoch potomkow, tu jakies sprytniejsze wyrazenie
// jakos currentsize +1?
//}

