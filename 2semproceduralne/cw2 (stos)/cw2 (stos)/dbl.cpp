#include "dbl.h"

void createStack(DblItem** pDbl) {
	*pDbl = NULL;
}


void push(DblItem** pDbl, double d) {
	DblItem* p = (DblItem*)malloc(sizeof(DblItem)); 
	if( !p ) {
		printf("ERROR push: Memory allocation error!\n"); 
		return; 
	}
	p->key = d;
	p->pNext = *pDbl;
	*pDbl = p;
}


double pop(DblItem** pDbl) {
	if( isEmpty(*pDbl) ) {
		printf("ERROR pop: Stack is empty!\n");
		return NAN; 
	}
	double d = top(*pDbl);
	del(pDbl);
	return d;

}


double top(DblItem* pDbl) {
	if( !isEmpty(pDbl) )
		return pDbl->key;
	return NAN;
}


void del(DblItem** pDbl) {
	if( isEmpty(*pDbl) ) {
		printf("ERROR del: Stack is empty!\n");
		return;
	}
	DblItem* p = *pDbl;
	*pDbl = p->pNext;
	free(p);
}


int isEmpty(DblItem* pDbl) {
	return !pDbl; 
}