#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagTreeItem
{
	int key;
	tagTreeItem* pLeft;
	tagTreeItem* pRight; // wskazniki na kolejne elementy
} TreeItem, * LP_TreeItem; // definiuje typ wskaznikowy na TreeItem (LP_TreeItem) za jednym zamachem

//przegladanie
void preOrder( TreeItem* pRoot );
void inOrder( TreeItem* pRoot ); // przy drukowaniu inOrder dostane wartosci posortowane (bez uzycia sortowania)
void postOrder( TreeItem* pRoot );

TreeItem* TreeFinallyBalanced( int n ); // drzewo sklada sie z n elementow (dokladnie wywazone)

void freeTree1( TreeItem* pRoot ); // nie nulluje drzewa! (czyli wskaznika)
void freeTree2( TreeItem** pRoot ); // nulluje wskaznik do drzewa
TreeItem* freeTree3( TreeItem* pRoot ); // nulluje wskaznik do drzewa


#endif