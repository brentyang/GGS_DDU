// ggs_ddu.cpp : 定义控制台应用程序的入口点。
#include <tchar.h>
#include <iostream>

#include "TCallBack.h"

using namespace std;

void PrintFunc(int a)
{
	cout <<"Print func: " << a << endl;
}

void PrintParam(int a)
{
	cout <<"Print Param: "<< a << endl;
}

typedef void (*pPrintFunc)(int);

int _tmain(int argc, _TCHAR* argv[])
{
	TCallBack<int, pPrintFunc> stCallBack;

	//register
	stCallBack.Register(1, PrintFunc);
	stCallBack.Register(2, PrintParam);

	//call back
	stCallBack.CallBack(1, 100);
	stCallBack.CallBack(2, 200);

	char a;
	cin >> a;

	return 0;
}

