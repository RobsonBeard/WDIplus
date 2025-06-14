#ifndef TREE_H
#define TREE_H

#include "QFIFO.h"

//todo: mo�e zostawi� komentarze z Drzewa albo dorobi� na koniec

typedef struct tagTreeItem
{
	int key;
	char* str;//todo: pole wskaznik na slowo - zmienic (max 40 znakow), czyli na 41 elem bo trzeba znak 0
	int counter; // pole counter do liczby wystapien
	tagTreeItem* pLeft;
	tagTreeItem* pRight; 
	FQueue* pList; // wskaznik na fifo - lista do zapamietywania numerow linii (zawsze na koncu?)
} TreeItem, * LP_TreeItem; 

void inOrder( TreeItem* pRoot ); // przy drukowaniu inOrder dostane wartosci posortowane (bez uzycia sortowania) //! IMPLEMENT DO POPRAWY


TreeItem* TreeFinallyBalanced( int n ); // drzewo sklada sie z n elementow (dokladnie wywazone)


//  IMPLEMENTACJA DO POPRAWY
TreeItem* freeTree( TreeItem* pRoot ); // nulluje wskaznik do drzewa


// JEDNO Z TYCH I DO POPRAWY NAGLOWEK I IMPLEMENTACJA bedzie slowo, czyli char* i numer linii
 // BST - Binary Search Tree (dla ka�dego w�z�a drzewa na lewo s� mniejsze a na prawo wi�ksze li�cie), w inorder wypisuje si� lista rosn�ca
TreeItem* FindInsert( TreeItem* pRoot, char* str,int line); //, int line 


#endif