using namespace std;
//#include <iostream>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

// kolekcja danych roznego typu, dostep przez operator .
typedef struct
{
	double mx;
	double my; // m - member, skladowa klasy
} Point;

double ave(double a, double b);
double deg2rad(int alpha);

int main()
{
	// obrot odcinka wokol jego srodka
	// zdefiniowac konce odcinka i zainicjowac

	Point pt1 = { 1,0 };
	Point pt2 = { 0,1 }; // konce odcinka

	// zdefiniowac kat obrotu w stopniach

	int alpha = 45;

	// zdefiniowac i obliczyc wspolrzedne srodka odcinka [xsr, ysr]
	
	Point sr;
	sr.mx = ave(pt1.mx, pt2.mx);
	sr.my = ave(pt1.my, pt2.my);

	// srodek wyznacza wektor wzgledem poczatku ukladu wspolrzednych (w nim jest koniec strzalki)
	// przesunac odcinek o wektor [-xsr,-ysr]

	Point pt1p; // wspolrzedne punktu po przesunieciu
	Point pt2p;

	pt1p.mx = pt1.mx - sr.mx;
	pt1p.my = pt1.my - sr.my;

	pt2p.mx = pt2.mx - sr.mx;
	pt2p.my = pt2.my - sr.my;
	
	// przekonwertowac stopnie do radianow
	
	double radians = deg2rad(alpha);
	double test = sin(radians);

	// obrot obu punktow o kat w radianach
	Point pt1o; // wspolrzedne po obrocie
	Point pt2o;

	pt1o.mx = pt1p.mx * cos(radians)- pt1p.my*sin(radians);
	pt1o.my = pt1p.mx * sin(radians)+ pt1p.my*cos(radians); // przeczytac jeszcze raz o macierzy obrotu!

	pt2o.mx = pt2p.mx * cos(radians)-pt2p.my*sin(radians);
	pt2o.my = pt2p.mx * sin(radians)+pt2p.my*cos(radians);

	// przesunac obrocony odcinek o wektor [xsr,ysr]
	pt1o.mx += sr.mx;
	pt1o.my += sr.my;

	pt2o.mx += sr.mx;
	pt2o.my += sr.my;

	//cout << "odcinek ["<<pt1.mx<<", "<<pt1.my<<"]--["<<pt2.mx<<", "<<pt2.my<<"] po obrocie o kat "<< alpha<<" = ["<<pt1o.mx<<", "<<pt1o.my<<"]--["<<pt2o.mx<<", "<<pt2o.my<<"]\n";
	printf("odcinek [%.2f, %.2lf]--[%.2f, %.2lf] po obrocie o kat %d = [%.2f, %.2lf]--[%.2f, %.2lf]\n",pt1.mx,pt1.my,pt2.mx,pt2.my,alpha,pt1o.mx, pt1o.my,pt2o.mx,pt2o.my);

	return 0;
}
double ave(double a, double b) {
	return (a + b) / 2;
}

double deg2rad(int alpha) {
	return alpha * PI / 180;
}