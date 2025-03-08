using namespace std;
#include <stdio.h>
#include <iostream>

#define MAXSTR 100

int StrLen(char* str);
void StrCpy(char* str_out, char* str_in);


//int main()
//{
//
//	int nDay;
//	printf("Wprowadz liczbe 1-3\n");
//	cin >> nDay;
//
//	char dayName;
//
//	switch(nDay) {
//	case 1: dayName = 'P'; break;
//	case 2: dayName = 'W'; break;
//	case 3: dayName = 'S'; break;
//	default: dayName = 'X'; break;
//	}
//	printf("Dzien: %c\n", dayName);*/
//
//	// -----
//
//	//int t1[] = { 1,2,3,4,5,6 };
//	//int nSize = sizeof(t1)/sizeof(int);
//
//	//printf("Rozmiar: %d\n",nSize);
//
//	//int* p = t1;
//
//	//for(int i = 0; i < nSize; i++)
//	//{
//	//	printf("t[%d]=%d ",i,*p++);
//	//}
//	//printf("\n%d",*p); // nie czaje
//
//	// ----
//
//	char str[10] = "abcdef";
//	char str2[] = "abcdef"; // ma na koñcu znak 0
//	printf("strlen = %d   sizeof str = %d\n",(int)StrLen(str2),(int)sizeof(str2));
//
//	char s[MAXSTR] = { 0 };
//
//	StrCpy(s, str);
//	printf("kopia = %s",s);
//
//	// jeœli nie chcê definiowaæ MAXSTR, to trzeba zrobiæ dynamicznie
//	//char s[StrLen(str2) + 1] = { 0 }; // tak mam w zeszycie niby, ale nie dzia³a
//
//	return 0;
//
//}


int StrLen(char* str) {
	int len = 0;
	//while(str[len]) len++;
	while(*str++)len++; // lepsze
	return len;
}

void StrCpy(char* str_out, char* str_in) {
	/*for(int i = 0; i < str_in[i]; i++)
	{
		str_out[i] = str_in[i];
	}*/
	while(*str_out++ = *str_in++); // lepsze
}
