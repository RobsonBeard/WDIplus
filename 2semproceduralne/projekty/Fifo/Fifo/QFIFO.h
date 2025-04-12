#ifndef QFIFO_H
#define QFIFO_H

#include "global.h" // dostarczany przez uzytkownika tej kolejki


typedef struct tagFQItem
{
	//int key; // pozbywamy sie key, zamiast tego mamy wykorzystac dane podane przez uzytkownika z global.h
	QINFO* pInfo; // teraz we wszystkich funkcjach bede wykorzystywal ten typ QINFO* (zamiast int key)
	tagFQItem* pNext; /*ptr to the next QItem - pNext; */
} FQItem;   //FIFO Queue Item

typedef struct
{
	FQItem* pHead;  // ptr to the first queue item
	FQItem* pTail;  // ptr to the last queue item
} FQueue;  // typ kolejkowy

// wedlug zalecanej praktyki, konwencji C/C++ to wywo³uj¹cy ma usuwaæ ze stosu (cos takiego)

FQueue* FQCreate();															// queue initiating  (NULL - fail)
int     FQEmpty( FQueue* q );												// if FIFO empty returned 1 (gdy nie ma kolejki tez 1) else 0
int		FQEnqueue( FQueue* q, QINFO* pNewInfo );							// insert new item at the end 
QINFO*  FQDequeue( FQueue* q );												// take out the first item
void    FQClear( FQueue* q, void (__cdecl* freeMem)( const void* ) );       // clears the queue
void    FQRemove( FQueue** q, void ( __cdecl* freeMem )( const void* ) );   // clears the queue  (=QFClear()) and removes
void    FQDel( FQueue* q );													// removes only first item
void    FQPrint( FQueue* q, void( __cdecl* printInfo )( const void* ) );	// drukowanie

#endif // !QFIFO_H

