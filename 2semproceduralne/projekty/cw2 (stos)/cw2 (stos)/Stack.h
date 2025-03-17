#ifndef STACK_H_12AFB
#define STACK_H_12AFB

#include <stdio.h>
#include <stdlib.h>


// trzeba dodac przedrostek, ktory nic nie znaczy, zeby nie bylo tej samej nazwy; tag uzywamy wtedy, gdy w strukturze uzywamy tej samej nazwy
typedef struct tagStackItem
{
	char key;
	tagStackItem* pNext;
} StackItem;

void createStack(StackItem** pStack);
void push(StackItem** pStack,char c);
char pop(StackItem** pStack);
char top(StackItem* pStack);
void del(StackItem** pStack);
int isEmpty(StackItem* pStack);

#endif // !STACK_H_12AFB