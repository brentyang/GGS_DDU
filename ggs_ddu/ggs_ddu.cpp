// ggs_ddu.cpp : 定义控制台应用程序的入口点。
#include <tchar.h>
#include <iostream>

#include "TStack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	TStack<int, 10> stack;

	cout<<"====="<<stack.Size()<<"===="<<endl;

	int i = 1;
	while(!stack.Full())
	{

		stack.Push(i);
		cout<<i<<endl;
		++i;
	}

	cout<<"====="<<stack.Size()<<"===="<<endl;

	while(!stack.Empty())	
	{
		int a;
		stack.Pop(a);
		cout<<a<<endl;
	}

	cout<<"====="<<stack.Size()<<"===="<<endl;

	char input;
	std::cin>>input;

	return 0;
}

