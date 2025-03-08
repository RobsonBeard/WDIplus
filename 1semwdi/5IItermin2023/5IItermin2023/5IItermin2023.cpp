#include <iostream>
#include <math.h>

using namespace std;
double exp2x(double x, double eps);
int main()
{
    double x = 2;
    double eps = 1e-10; // 1>eps>0
       
    double kontrolna = (3*x - x*x)*exp(2*x);

    printf("biblioteczna wartosc: %.16lf\n", kontrolna);
    printf("moja wartosc: %.16lf", exp2x(x,eps));
        
    return 0;
}


double exp2x(double x, double eps) {
    double res = 3 * x + 5 * x * x;
    double t = x * x;
    int n = 3;

    while(fabs(t*(7-n)) >= eps || n == 7) // warunek wazny
    {
        t *= 2*x/(n-1);
        //printf("%.12lf\n",t*(7-n));
        res += t * (7 - n);
        n++;
    }
    return res;
}

