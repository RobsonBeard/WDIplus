#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define MAXLINE 10

// w tym pliku same naglowki sortowan

void bubbleSort( int* pTab, int nSize );
void simpleSelectionSort( int* pTab, int nSize);
void simpleInsertionSort( int* pTab, int nSize );
void mixedSort( int* pTab, int nSize );
void halfFindSort( int* pTab, int nSize );
void quickSort( int* pTab, int nSize );
void heapSort( int* pTab, int nSize );


/*
 - wstawianie   simpleInsertion()
 - wybieranie   simpleSelection()
 - babelkowe    bubbleSort()
 - mieszane (bablekowe)
 - polowkowe (modyfikacja wstawiania o wyszukiwanie polowkowe)
 - stogowe (HeapSort)
 - szybkie  (QuickSort)
*/

#endif // !SORT_H
