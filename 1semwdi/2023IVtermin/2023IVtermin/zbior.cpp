#include "moje_funkcje.h"

int isDigit(char c);
double getNumber();
void dec2hex(int a, int p);

int main() {

    //double x = getNumber();

    //printf("%lf",x);


    //int a = 0x12345678;
    //int maska = 0xFF;

    //int trzeci = (a>>16)&maska;

    //printf("%X",trzeci);

    dec2hex(255,1);

	return 0;
}

int isDigit(char c)   //Definiujê funkcjê pomocniczn¹
{
    return (c >= '0') && (c <= '9');
}
double getNumber()    //Funkcja w³aœciwa
{
    int calkowita = 0;
    char c = getchar();
    while((c == ' ') || (c == '\t') || (c == '\n'))
        c = getchar();
    int sgn = 0;
    if(c == '-') sgn = 1;
    else if(c != '+') ungetc(c, stdin);
    while(isDigit(c = getchar()))
    {
        calkowita *= 10;
        calkowita += (c - '0');
    }
    double wynik = calkowita;
    if(c == '.')
    {
        double rzeczywista = 0;
        double dzielnik = 10;
        while(isDigit(c = getchar()))
        {
            rzeczywista += (c - '0') / dzielnik;
            dzielnik *= 10;
        }
        wynik += rzeczywista;
    }
    ungetc(c, stdin);
    if(sgn) wynik = -wynik;
    return wynik;
}


void dec2hex(int a, int p) {
    if(p != 0 && p != 1) {
        printf("ERROR: Zle paramtery!!!!");
        return;
    }
    if(a == 0) {
        putchar('0');
        if(p == 1) putchar('X');
        else putchar('x');
        return;
    }

    dec2hex(a / 16, p);
    int reszta = a % 16;
    if((reszta / 10) > 0) {
        if(p == 1) putchar(reszta - 10 + 'A');
        else putchar(reszta - 10 + 'a');
    }
    else putchar(reszta + '0');
}
