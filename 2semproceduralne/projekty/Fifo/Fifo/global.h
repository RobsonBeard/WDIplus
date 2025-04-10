#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>


//ten tag jest na razie niepotrzebny
typedef struct tagQInfo
{
	int key;
	int* pTab;
} QInfo;

#define QINFO QInfo // pod stala preprocesora podkladam nazwe typu



#endif // !GLOBAL_H
