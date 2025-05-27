#include "Tree.h"

int main()
{
	TreeItem* pRoot = NULL;
	//LP_TreeItem p = NULL; // wychodzi na to samo

	pRoot = TreeFinallyBalanced( 10 );
	
	printf( "PreOrder: " );
	preOrder( pRoot );
	
	printf( "\n\nInOrder: " );
	inOrder( pRoot );

	printf( "\n\nPostOrder: " );
	postOrder( pRoot );

	printf( "\n\n" );

	// twierdzenie: gdy mam preOrder i inOrder to jednoznacznie jestem w stanie odtworzyc drzewo binarne

	// zobaczyc sobie 3 metody freeTree debuggerem
	//freeTree1( pRoot );
	//freeTree2( &pRoot );
	pRoot = freeTree3( pRoot ); // ta metoda jest chyba najschludniejsza

	return 0;
}

// drzewo jako struktura danych jest struktur¹ rekurencyjn¹