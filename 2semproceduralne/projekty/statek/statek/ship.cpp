#include "ship.h"

int setTab( char* sFile, int** pTab, int nRow, int nCol ) {

	FILE* fin = NULL; // uchwyt pliku
	if( ( ( fin = fopen( sFile, "r" ) ) == NULL ) ) return 0;

	for( int i = 0; i < nRow; i++ )
	{
		for( int j = 0; j < nCol; j++ )
		{
			if( fscanf( fin, "%d", &( pTab[i][j] ) ) == EOF ) {
				fclose( fin ); // tu w przypadku niepowodzenia (end of file)
				return 0; // tu fscanf przypisze po kolei wartoœci tablicy w formacie intow	
			} 
		}
	}
	fclose( fin );
	return 1;
}


int move( int** pTab, int nRow, int nCol, int nDepth,
	int move, int x, int y, int* px, int* py, int** pRoot )
{
	int xNext = x; // tworzê te zmienne, bo ze wskaŸnikami jest taki problem, ¿e jak wyjdê poza tablicê, to *px i *py bêd¹ mia³y z³e wartoœci, a funkcja zwróci po prostu 0
	int yNext = y;


	// y - kolumna, x - wiersz -> odwrotnie jak w uk³adzie wspó³rzêdnych!!
	switch( move )
	{
	case UP: xNext--; break; // modyfikujê wartoœæ, na któr¹ wskazuje px i py (czyli nowe wspolrzedne)
	case LEFT: yNext--; break;
	case DOWN:xNext++; break;
	case RIGHT: yNext++; break;

	default: return 0;
	}

	if( xNext < 0 || xNext >= nRow || yNext< 0 || yNext>= nCol ) // jeœli wychodzê poza zakres tablicy, to ruch jest niepoprawny
		return 0;

	if( pTab[xNext][yNext] <= nDepth ) // jeœli g³êbokoœæ jest za ma³a, to nie mogê tam pop³yn¹æ
		return 0;

	if( pRoot[xNext][yNext] ) // gdy pRoot[*px][*py] != 0, jeœli jest inne ni¿ 0, to wejdzie w if  
		return 0; // pole zosta³o ju¿ odwiedzone, a nie chce p³ywaæ w kó³ko

	*px = xNext;
	*py = yNext;

	return 1; // ruch jest mo¿liwy
}

int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot,
	int x_dest, int y_dest )
{
	static int stepNo = 0; // zmienna statyczna bêdzie przechowywaæ kolejny numer ruchu
	// gdyby wywo³ywaæ kilka razy funkcje root w programie, to za kolejnym razem nie zacznie liczyæ od 0, tylko od poprzedniej koñcowej wartoœci


	pRoot[x][y] = ++stepNo; // najpierw inkrementuje stepNo (przy kazdym wejsciu w root), a potem przypisuje do tablicy, czyli zaczynam od 1

	if( x == x_dest && y == y_dest )
		return 1; // jesli statek dotarl do portu

	int xNew = 0; // jesli jeszcze nie dotarl, definiuje nowe wspolrzedne (dzia³am na nie przez move)
	int yNew = 0;

	for( int direction = UP; direction <= RIGHT; direction++ ) // sprawdzam mozliwosc ruchu w kazdym kierunku, to dzia³a ze wzglêdu na w³aœciwoœci enum
	{
		if( move( pTab, nRow, nCol, nDepth, direction, x, y, &xNew, &yNew, pRoot ) ) // jesli ruch jest mozliwy w danym kierunku (zwrocilo 1)
		{
			if( root( pTab, nRow, nCol, nDepth, xNew, yNew, pRoot, x_dest, y_dest ) ) // jesli wykonanie kolejnego ruchu sie powiodlo (zwrocilo 1), rekurencja
				return 1;
		}
	}

	// jesli wracamy (slepy zaulek), to ustawiamy w pRoot, ze ruch byl zly - ustawiam na 0
	pRoot[x][y] = 0; //! ale to ma problem przez œlepe zau³k, nie bêd¹ liczby po kolei

	return 0;
}

void clearRoot( int** pRoot, int nRow, int nCol ) {
	if( !pRoot || !pRoot[0] || nRow < 1 || nCol < 1 ) {
		printf( "clearRoot: parameters error" );
		return;
	}
	memset( pRoot[0], 0, nRow * nCol * sizeof( int ) ); // 1 argument - pocz¹tek bloku pamieci, 2 - co wpisuje, 3 - liczba bajtów do wype³nienia
}