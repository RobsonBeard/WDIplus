#ifndef DBL_STACK_H_ADF12

#define DBL_STACK_H_ADF12
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagDblItem
{
	double key;
	tagDblItem* pNext;
} DblItem;


void createStack(DblItem** pDbl);
void push(DblItem** pDbl, double d);
double pop(DblItem** pDbl);
double top(DblItem* pDbl);
void del(DblItem** pDbl);
int isEmpty(DblItem* pDbl);

#endif // !DBL_STACK_H_ADF12
