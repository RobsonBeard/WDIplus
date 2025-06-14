#ifndef TREE_H
#define TREE_H

#include "QFIFO.h"

typedef struct tagTreeItem
{
	char* str;// pole wskaznik na slowo (max 40 znakow), czyli na 41 elem bo trzeba znak 0
	int counter; // pole counter do liczby wystapien
	tagTreeItem* pLeft;
	tagTreeItem* pRight; 
	FQueue* pList; // wskaznik na fifo - lista do zapamietywania numerow linii 
} TreeItem, * LP_TreeItem; 

void inOrder( TreeItem* pRoot, FILE* fout ); // przy drukowaniu inOrder dostane wartosci posortowane (bez uzycia sortowania) 

TreeItem* freeTree( TreeItem* pRoot ); // nulluje wskaznik do drzewa

TreeItem* FindInsert( TreeItem* pRoot, char* str,int line); 

#endif