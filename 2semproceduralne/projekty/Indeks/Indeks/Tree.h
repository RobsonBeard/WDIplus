#ifndef TREE_H
#define TREE_H

#include "QFIFO.h" //? nie zrobi bledu?

//todo: mo¿e zostawiæ komentarze z Drzewa albo dorobiæ na koniec

typedef struct tagTreeItem
{
	int key;
	char* str;// pole wskaznik na slowo
	int counter; // pole counter do liczby wystapien
	tagTreeItem* pLeft;
	tagTreeItem* pRight; 
	FQueue* pList; // wskaznik na fifo - lista do zapamietywania numerow linii (zawsze na koncu?)
} TreeItem, * LP_TreeItem; 

void inOrder( TreeItem* pRoot ); // przy drukowaniu inOrder dostane wartosci posortowane (bez uzycia sortowania) //! IMPLEMENT DO POPRAWY


TreeItem* TreeFinallyBalanced( int n ); // drzewo sklada sie z n elementow (dokladnie wywazone)


// JEDNO Z TYCH TRZECH I IMPLEMENTACJA DO POPRAWY
void freeTree1( TreeItem* pRoot ); // nie nulluje drzewa! (czyli wskaznika)
void freeTree2( TreeItem** pRoot ); // nulluje wskaznik do drzewa
TreeItem* freeTree3( TreeItem* pRoot ); // nulluje wskaznik do drzewa


// JEDNO Z TYCH I DO POPRAWY NAGLOWEK I IMPLEMENTACJA bedzie slowo, czyli char* i numer linii
void FindInsert( TreeItem** pRoot, char* str, int line ); // BST - Binary Search Tree (dla ka¿dego wêz³a drzewa na lewo s¹ mniejsze a na prawo wiêksze liœcie), w inorder wypisuje siê lista rosn¹ca

TreeItem* FindInsert2( TreeItem* pRoot, char* str, int line );


#endif