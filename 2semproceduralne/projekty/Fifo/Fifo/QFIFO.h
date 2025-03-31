#ifndef QFIFO_H
#define QFIFO_H

#include "global.h" // dostarczany przez uzytkownika tej kolejki


typedef struct tagFQItem
{
	int key;
	tagFQItem* pNext; /*ptr to the next QItem   - pNext; */
} FQItem;   //FIFO Queue Item

typedef struct
{
	FQItem* pHead;  // ptr to the first queue item
	FQItem* pTail;  // ptr to the last queue item
} FQueue;  // typ kolejkowy

FQueue* FQCreate();                    // queue initiating  (NULL - fail)
int     FQEmpty( FQueue* q );          // if FIFO empty returned 1 (gdy nie ma kolejki tez 1) else 0
int     FQEnqueue( FQueue* q, int x ); // insert new item at the end // zwraca INT_MIN?
int     FQDequeue( FQueue* q );        // take out the first item
void    FQClear( FQueue* q );          // clears the queue
void    FQRemove( FQueue** q );        // clears the queue  (=QFClear()) and removes
void    FQDel( FQueue* q );            // removes only first item

#endif // !QFIFO_H

