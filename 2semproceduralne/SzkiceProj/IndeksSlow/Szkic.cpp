DZEWO BST - szkic
===============
PROBLEM
------
Napisac program wczystujacy slowa (identyfikatory) z pliku tekstowego i wstawiajacy je do drzewa BST
wraz z numerem linii, w ktorej to slowo wystapilo,
przy czym jesli slowo w drzewie juz istnieje to zwiekszny jest licznik wystapien oraz 
dodawany jest kolejny numer linii, w ktorym slowo wystapilo ponownie (lista wystapien z podwojna glowa- jak w fifo
                                                                      bo dadawanie na koncu listy aby byla od razu posortowana).
Numery linii nie epowtarzaja sie na liscie


UWAGA:
slowo to dowolny ciag znakow zaczynajacy sie od podkreslenia lub litery i potem sa litery lub cyfry lub podkreslenia
(czyli dokladnie jest to identyfikator w jezyku programowania). NIe wolno uzywac w pliku teksowym 
polskich znakow diakrytycznych (dla ULATWIENIA)

NA wejsciu: wiec dowolny plik tekstowy - parametr programu (jak bylo juz w poprzenidch projektach)
-------------
NA Wyjsciu: wydrukowane drzewo w inorder (slowa beda w kolejnosci alfabetycznej z iloscia wystapien i lista wystapien od 
                                          najmniejszej liczby do najwiekszej - czyli tak jak sa dodawane)
-------------

int main( int argc, char* argv[] )
{
  sprawdzic parametr programu (czy jest)
  wywolac funkcje wczytujaca plik (w niej otworzyc i zamknac) i budujACA DDRZEWO bst
  wywolac funkcje drukujaca do plik (np IndeksSlow.txt)
  zwolnic drzewo
  koniec
}

----------
w pliku naglowkowym zdefiniowac odpowiedni typ dla elementu drzewa binarnego o nazwie TreeItem:
Podobnie jak dla listy tylko teraz definujemy poddrzewa: pLeft, pRight 
(wsk na ta sama strukture TreeItem jak w liscie)
Dodatkowo, w typie musi byc pole wskaznik na slowo (alokacja tablicy 41 znakowa - slowa 40 znakowe),
pole counter do pamietania liczby wystapien 
oraz wskaznik na FIFO - lista do zapamietywania numerow linii - ale zawsze na koncu. 

Prosze wykorzystac modul FIFO z dwoma wskazniklami
pHead i pTail (co bylo pisane) i polem int (numer linii).
Typ dla listy (te dwa wskazniki) musi byc wczesniej przed typem elementu drzewa 
a typ dla elementu listy jeszcze wczesniej 

Dzieki temu bedzie mozna bardzo latwo wypisac numery linii w jakich wystapilo slowo przelgadajac liste 
od pierwszego elementu do ostatniego
----------

!!!Przy wstawianiu do drzewa nie alokowac nowej pamieci ale podwiazac wsk na slowo pod wskaznik w elemencie drzewa


Wydruk do pliku:
Przegladac drzewo w InOrder i wypisywac kolejno odwiedzane wezly drzewa. wW ten sposob dostaniemy 
posortowany indeks slow
wypisuje sie slowo a potem ilosc wystapien w nawiasie 
a potem numery linii w ktorych wystapilo (wszyskto w jednej linii)


UWAGA:
nalezy napisac wlasna funkcje porownujaca 
    int compStr( char* s1, char* s2 ) - napisana wylacznie z funkcji bibliotecznych

lancuchy znakowe bo ma byc niezalezne od duzych i malych liter

SZKIC: (stosujemy wylacznie funkcje biblioteczne standardowego C )
-----------
alokowac pamiec str1 na kopie parametru pierwszego (calloc alokuje strlen(str1)+1) musze dodac 1 na null
alokowac pamiec str2 na kopie parametru drugiego
wkopiowc do str1 pierwszy parametr  (odpowienida funkcja biblioteczna --> string.h) strcpy()
wkopiowc do str2 drugi parametr     (odpowienida funkcja biblioteczna --> string.h) 
zamienic w str1 wszystko na male ( funkcja _strlwr()  ---> string.h )  // _strupr
zamienic w str2 wszystko na male ( funkcja _strlwr()  ---> string.h )
porownac i zapamietac wynik  (odpowiednia funckja porownujaca lancuchy znakowe ---> string.h) strcmp()
zwolnic str1 - free()
zwolnic str2
zwrocic zapamietany wynik


--------

FIFO zmodyfikowac, uproscic
int Info zamiast pInfo w global.h - wywalic
dzieki temu nie ma freememow

fgetc - czytanie po znaku

jakos zrobic petle w tym, sprawdzac najlepiej wlasna funkcja (prywatna) czy to jest indentyfikator (zewnetrzna)
wewnetrzna petla czyta znaki tego identyfikatora, trzeba zwracac uwage na koniec pliku

sprawdzac nowe linie
jak skoncze czytac identyfikator to dowi¹zuje lub wstawiam do drzewa?

mozna olac sprawdzanie alokacji pamieci

w Visit? musze sprawdzac, porównaæ nowe s³owo z Tailem? zeby sie jakos numery linii nie powtarzaly

w FindInsert zrobic przed tym duzym if else if porownywanie strcmp, nie w srodku




nieobowiazkowe:
realloc() czyli alokowac 5 znakow na start, jesli okaze sie, ze jest wiecej, to realokowac pamiec na wiecej
int AllocAddMemBets( int*** pTab, int nCurrSize ) {
    Player** pTemp = (Player**) realloc(*pTab,(nCurrSize+ALLOCPLAYER)*sizeof(Player*))
    if(!pTemp ) return 0
    *pTab = pTemp
    memset(*pTab+nCurrsize,0,ALLOCBET)
    return ALLOCBET
}

czyli my wstawiamy do drzewa SLOWA