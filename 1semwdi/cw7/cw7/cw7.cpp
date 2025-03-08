#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
 // dzielenie z reszta przez odejmowanie
    int x;
    int y;
    printf("Podaj dwie liczby calkowite > 0\n");
    cin >> x >> y;
      
    int q = 0;
    int r = x;
    //{ x = q*y + r, r>=0 }
    while(r >= y) {
        // { x = q*y + r, r>=y }
        q++;
        // { x = q*y + r-y, r>=y }
        r -= y;
        // { x = q*y + r, r>=0 }
    }
    // { x = q*y + r, y>r>=0 } - definicja dzielenia calkowitego z reszta
    
    // w { } jest matematyczny dowod
    printf("%d / %d = %d reszty %d", x,y,q,r);

}

