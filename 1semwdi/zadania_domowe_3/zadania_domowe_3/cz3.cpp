using namespace std;

#include <iostream>
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

double mojeExp(double x, double eps); // eps<=1
double mojCos(double x, double eps);
double degToRad(double deg);
double mojSin(double x, double eps);


int main() {
	// exp
	double x1 = 1;
	double eps1 = -1e-3 ;
	double r1 = mojeExp(x1, eps1);

	printf("Moje exp(%.2f) z dokladnoscia do %lf wynosi : %lf\n",x1,eps1,r1);
	printf("Biblioteczne exp(%.2lf) wynosi: %lf\n\n", x1, exp(x1));

	//double test1 = 60;
	//printf("%lf stopni to %lf PI radianow\n",test1,degToRad(test1));


	// cos

	//double x2 = 142;
	//double eps2 = -1e-3;
	//if(eps2 < 0) eps2 *= -1;
	//double r2 = mojCos(degToRad(x2), eps2); // trzeba robic w radianach

	//printf("Moj cos(%.2f) z dokladnoscia do %lf wynosi : %lf\n", x2, eps2, r2);
	//printf("Biblioteczne cos(%.2lf) wynosi: %lf\n\n", x2, cos(degToRad(x2)));

	//sin 

	/*double x3 = 60;
	double eps3 = -1e-3;
	if(eps3 < 0) eps3 *= -1;
	double r3 = mojSin(degToRad(x3), eps3);

	printf("Moj sin(%.2f) z dokladnoscia do %lf wynosi : %lf\n", x3, eps3, r3);
	printf("Biblioteczne sin(%.2lf) wynosi: %lf\n\n", x3, sin(degToRad(x3)));*/

	return 0;
}
//&& eps >= -t
double mojeExp(double x, double eps) {
	int n = 1; // pierwszy wyraz
	double res = 1; // to jest 0-wy wyraz x^0 = 1
	double t = res; // to jest taki mój mno¿nik, przez to bêdê mno¿y³ kolejne wyrazy (chyba jest równy 1 dlatego, ¿eby by³ równy res)
	while(eps <= t ) // on bêdzie coraz bardziej zbli¿a³ siê do 0
	{
		printf("%lf %lf\n",t,eps);
		t *= x / n++; // musi byæ *=, bo z = robi³o mi szereg harmoniczny
		res += t;
		// n++; //skrocilem
	}
	return res;
}

double mojCos(double x, double eps) {
	int n = 1;
	double res = 1; // 0-wy wyraz
	double t = res;
	double temp;
	while(t>=eps || t<=-eps)
	{
		temp = 2*n * (2*n - 1);
		t = t*((-1)*x*x)/temp;
		res += t;
		n++;
	}
	return res;
}

double mojSin(double x, double eps) {
	double res = x;
	double t = res;
	double temp;
	int n = 1;
	while(t >= eps || t <= -eps) {
		temp = 2 * n * (2 * n + 1);
		t *= (-1)*x*x/temp;
		res += t;
		n++;
	}
	return res;
}



//double degToRad(double deg) {
//	return PI * deg / 180;
//}
double degToRad(double deg) {
	while(deg > 500) {
		deg -= 360;
	}
	while(deg < -500) {
		deg += 360;
	} // pewnie nielegalne, ale tutaj u³atwi
	
	return PI * deg / 180;
}