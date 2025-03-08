#include <stdio.h>
#include <math.h>

#define EPS0 0.0000000000000000001 // moje przybli¿one 0 (no bo nie mo¿na porównywaæ z 0 we floatach)
#define EPSX 0.0001 // moja dokladnosc

double f(double x);

//int main() {
//
//    double a=1;
//    double b=6;
//    double x0;
//    double fa = f(a);
//    double fb = f(b);
//    double f0;
//
//    if(fa * fb > 0) {
//        printf("funkcja nie spe³nia za³o¿eñ");
//        return -1;
//    }
//   
//
//     while(fabs(a - b) > EPSX)
//        {
//            x0 = (a + b) / 2;
//            f0 = f(x0);
//            if(fabs(f0) < EPS0) break;
//            if(fa * f0 < 0) b = x0;
//            else
//            {
//                a = x0;
//                fa = f0;
//            }
//        }
//    printf("x0 = %.2lf", x0);
//
//
//
//	return 0;
//}

double f(double x)
{
    return (x * x)-(2*x)-8;
}