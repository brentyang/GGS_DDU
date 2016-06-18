// ggs_ddu.cpp : 定义控制台应用程序的入口点。
#include <tchar.h>
#include <iostream>

#include "Stack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	YL::LStack<int> stack;

	cout<<"Size:"<<stack.Size()<<endl;

	int i = 1;
	while(i<20)
	{
		stack.Push(i);
		cout<<"Size:"<<stack.Size()<<endl; 
		++i;
	}

	while(!stack.IsEmpty())	
	{
		int a;
		a = stack.Top();
		stack.Pop();
		cout<<a<<"  "<<"Size:"<<stack.Size()<<endl; 
	}

	char input;
	std::cin>>input;

	return 0;
}

