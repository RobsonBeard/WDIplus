#include <stdio.h>

void Hanoi(int n, char cFrom, char cTo, char cWith);

//int main() {
//
//	Hanoi(5, 'A', 'C', 'B');
//
//
//	return 0;
//}

void Hanoi(int n, char cFrom, char cTo, char cWith) {
	if(n == 1)
		printf("Move disc from %c to %c \n",cFrom,cTo);
	else
	{
		Hanoi(n - 1, cFrom, cWith, cTo);
		Hanoi(1, cFrom, cTo, cWith);
		Hanoi(n - 1, cWith, cTo, cFrom);
	}
}