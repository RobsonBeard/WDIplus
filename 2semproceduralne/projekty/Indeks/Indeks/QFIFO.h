#ifndef QFIFO_H
#define QFIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

typedef struct tagFQItem
{
	int lineNo; // numer linii 
	tagFQItem* pNext; // wskaznik na kolejny element
} FQItem;   

typedef struct
{
	FQItem* pHead;  // ptr to the first queue item
	FQItem* pTail;  // ptr to the last queue item
} FQueue;  // typ kolejkowy


FQueue* FQCreate();															
int     FQEmpty( FQueue* q );												
int		FQEnqueue( FQueue* q, int newInfo);										
int		FQDequeue( FQueue* q);										
void    FQClear( FQueue* q);       
void    FQRemove( FQueue** q);   
void    FQDel( FQueue* q );													
void    FQPrint( FQueue* q, FILE* fout );	
void	FQPrintConsole( FQueue* q );

#endif // !QFIFO_H

