#include "ship.h"

int setTab( char* sFile, int** pTab, int nRow, int nCol ) {

	FILE* fin = NULL; // uchwyt pliku
	if( ( ( fin = fopen( sFile, "r" ) ) == NULL ) ) return 0;

	for( int i = 0; i < nRow; i++ )
	{
		for( int j = 0; j < nCol; j++ )
		{
			if( fscanf( fin, "%d", &( pTab[i][j] ) ) == EOF ) //! tutaj zastosowac sposob ze wskaznikami
			{
				fclose( fin ); // tu w przypadku niepowodzenia (end of file)
				return 0; // tu fscanf przypisze po kolei warto�ci tablicy w formacie intow	
			} 
		}
	}
	fclose( fin );
	return 1;
}

int move( int** pTab, int nRow, int nCol, int nDepth,
	int move, int x, int y, int* px, int* py, int** pRoot )
{
	int xNext = x; // tworz� te zmienne, bo ze wska�nikami jest taki problem, �e jak wyjd� poza tablic�, to *px i *py b�d� mia�y z�e warto�ci, a funkcja zwr�ci po prostu 0, wtedy musia�bym wr�ci� z tymi warto�ciami
	int yNext = y;

	// y - kolumna, x - wiersz -> odwrotnie jak w uk�adzie wsp�rz�dnych!!
	switch( move )
	{
	case UP:	xNext--; break; // modyfikuj� warto��, na kt�r� wskazuje px i py (czyli nowe wspolrzedne)
	case LEFT:	yNext--; break;
	case DOWN:	xNext++; break;
	case RIGHT: yNext++; break;
	}

	if( xNext < 0 || xNext >= nRow || yNext< 0 || yNext>= nCol || pTab[xNext][yNext] <= nDepth || pRoot[xNext][yNext] ) 	
		return 0;

	// opis warunk�w w ifie:
	// je�li wychodz� poza zakres tablicy, to ruch jest niepoprawny
	// je�li g��boko�� jest za ma�a, to nie mog� tam pop�yn��
	
	// gdy pRoot[*px][*py] != 0, je�li jest inne ni� 0, to wejdzie w if  
	// pole zosta�o ju� odwiedzone, a nie chce p�ywa� w k�ko

	*px = xNext; // i przypisuje te wyliczone warto�ci do parametrow wyjsciowych
	*py = yNext;

	return 1; // ruch jest mo�liwy
}

void clearRoot( int** pRoot, int nRow, int nCol ) {
	if( !pRoot || !pRoot[0] || nRow < 1 || nCol < 1 ) {
		printf( "clearRoot: parameters skulik error" );
		return;
	}
	memset( pRoot[0], 0, nRow * nCol * sizeof( int ) ); // 1 argument - pocz�tek bloku pamieci, 2 - co wpisuje, 3 - liczba bajt�w do wype�nienia
}

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot,
	int x_dest, int y_dest )
{
	static int stepNo = 1; // zmienna statyczna b�dzie przechowywa� kolejny numer ruchu
	// gdyby wywo�ywa� kilka razy funkcje root w programie, to za kolejnym razem nie zacznie liczy� od 1, tylko od poprzedniej ko�cowej warto�ci


	pRoot[x][y] = stepNo++; // przypisuje do tablicy, czyli zaczynam od 1 , potem inkrementuje stepNo (przy kazdym wejsciu w root)

	if( x == x_dest && y == y_dest )
		return 1; // jesli statek dotarl do portu

	int xNew = 0; // jesli jeszcze nie dotarl, definiuje nowe wspolrzedne (dzia�am na nie przez move)
	int yNew = 0;

	for( int direction = UP; direction <= RIGHT; direction++ ) // sprawdzam mozliwosc ruchu w kazdym kierunku, to dzia�a ze wzgl�du na w�a�ciwo�ci enum
	{
		if( move( pTab, nRow, nCol, nDepth, direction, x, y, &xNew, &yNew, pRoot ) ) // jesli ruch jest mozliwy w danym kierunku (zwrocilo 1)
		{
			if( root( pTab, nRow, nCol, nDepth, xNew, yNew, pRoot, x_dest, y_dest ) ) // jesli wykonanie kolejnego ruchu sie powiodlo (zwrocilo 1, czyli w koncu doszlo do konca), rekurencja
				return 1;
		}
	}

	// jesli wracamy (slepy zaulek), to ustawiamy w pRoot, ze ruch byl zly - ustawiam na 0
	stepNo--; // i wtedy dekrementuje numer ruchu, bo nie chce go zaliczyc, inaczej by nie liczy�o numerow po kolei, tylko po prostu rosnaco
	pRoot[x][y] = 0;

	return 0;
}