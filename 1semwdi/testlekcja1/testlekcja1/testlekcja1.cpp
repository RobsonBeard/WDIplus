// testlekcja1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <stdio.h> // to jest trochê nadmiarowe, ale niech zostanie dla przyzwyczajenia

int main()
{
	// odpalamy program bez debugowania

	// cout << - wypisywanie
	// cin >> - wczytywanie, kierunek operatorów wa¿ny

	//cout << "To jest moj pierwszy program w C/C++\n"; // strumieniowo
	printf("To jest moj pierwszy program w C/C++\n"); // standardowo, C
	
	cout << "Podaj liczbe calkowita: ";
	int x = 0;
	cin >> x; // do wczytywania lepszy jest cin, do wyrzucania lepszy printf raczej

	cout << "x = " << x << '\n'; // tu lepiej uzywac chara zamiast stringa bo zajmuje mniej pamieci
	printf("x = %d\n",x); // z procentem jest format w jakim ma sie wypisac x
	// poniewaz jest jeden format, to jest jedno wyrazenie po przecinku, czyli x
	printf("x = %d (hex)%X (oct)%o\n",x,x,x); // 3 formaty - 3 zmienne, przyklad dlaczego printf lepszy
	
	cout << "x = " << x << "   (hex)"<<hex<<x<<"   (oct)"<<oct<<x<<dec<<'\n'; // coutem jest trudno

	return 0;
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
