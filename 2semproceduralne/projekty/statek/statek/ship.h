#ifndef SHIP_H
#define SHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef enum { UP, LEFT, DOWN, RIGHT } Directions;

//? usuwaæ te komentarze?

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
	int x, int y, int** pRoot, int x_dest, int y_dest );   //--- rekurencyjna
/* pTab tabl glebokosci   o romiarze nRow  i nCol
    nDepth - glebokosc zanurzenia statku (!)
    x, y - wspolrzedne skad robimy kolejny ruch
    pRoot tablica kolejnych ruchow (w pole wstawia sie numer kolejnego ruchu)
    x_dest, y_dest - wsporzedne portu
*/

void clearRoot( int** pRoot, int nRow, int nCol ); // zeruje tablice jednym memsetem ilosc elementow*sizeof(int)

int setTab( char* sFile, int** pTab, int nRow, int nCol ); // wczytuje dane z pliku

#endif // !SHIP_H
