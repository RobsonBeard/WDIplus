#include "Stack.h"

//StackItem* pStack = NULL;

void createStack(StackItem** pStack) {
	*pStack = NULL;
}

void push(StackItem** pStack,char c) {
	StackItem* p = (StackItem*)malloc(sizeof(StackItem)); // zawsze jest jedna gwiazdka mniej po prawej stronie
	if (!p) {
		printf("ERROR push: Memory allocation error!\n"); // zawieramy nazwe funkcji w bledzie dla latwego debugowania
		return; // wychodzimy, bo nie mozemy dzialac na wskazniku ktory jest NULL
	}
	p->key = c;
	p->pNext = *pStack;
	*pStack = p;
}

char pop(StackItem** pStack) {
	if (isEmpty(*pStack)) {
		printf("ERROR pop: Stack is empty!\n");
		return 0; //! dla stosu liczbowego nie warto stosowac 0, tylko np INT_MIN, INT_MAX, DBL_MIN, DBL_MAX albo np. 1e-308
	}
	char c = top(*pStack);
	del(pStack);
	return c;
}

char top(StackItem* pStack) {
	if (!isEmpty(pStack))
		return pStack->key;
	return 0;
}

void del(StackItem** pStack) {
	if (isEmpty(*pStack)) {
		printf("ERROR del: Stack is empty!\n");
		return; 
	}
	StackItem* p = *pStack;
	*pStack = p->pNext;
	free(p); // schemat dzialania jest w jakiejs prezentacji
}

int isEmpty(StackItem* pStack) {
	return !pStack; // fajne, pomyslec, 0 to NULL
}