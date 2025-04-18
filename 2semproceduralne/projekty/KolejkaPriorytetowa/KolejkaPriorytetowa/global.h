#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
	int  nKey;
	int* pTab; // moze byc dwuelementowa tablica
} PQInfo;    // PQINFO - the user identyfier

#define PQINFO PQInfo    // nazwy PQINFO - uzywac WSZEDZIE - NAWET W PROGRAMIE TESTUJACYM!

#endif // !GLOBAL_H

