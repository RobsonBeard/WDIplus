#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define DEBUG //? czy w tym miejscu debug jest ok?

int CreateMatrix( double*** pTab, int nDim );   //!!! zwraca  0  gdy error  1 - ok
void DeleteMatrix( double*** pTab, int nDim );  // *pTab=NULL
void TransMatrix( double** pTab, int nDim );	// transponowanie macierzy, bez pomocniczej
void InverseMatrix( double** pInv, double** pTab, int nDim, double det ); // macierz odwrotna, na we obliczony wczesniej w main() det  (tu w funkcji juz na pewno musi byc det!=0)
double Det( double** pTab, int nDim ); //rozwiniecie wzgl 1-go wiersza, wyznacznik rekurencyjnie 
void PrintMatrix( double** pTab, int nDim );	// drukuje macierz 

#endif