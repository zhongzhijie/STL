// dequeTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <deque>
#include <iostream>
using namespace std;

void printDeque(deque<int> intDeque)
{
	deque<int>::iterator it;
	cout << "print by iterator:" << endl;
	for (it = intDeque.begin(); it != intDeque.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
deque方法大多数和vector一样
多出push_front和pop_front，双向队列支持队头和队尾操作
*/

int main()
{
	int array[] = { 7,8,9,10 };
	deque<int> intDeque(array, array+sizeof(array)/sizeof(int));	/* 使用数组构造 */
	printDeque(intDeque);
	intDeque.push_back(11);
	printDeque(intDeque);
	intDeque.push_front(12);	/* push_front 往队头加入元素 */
	printDeque(intDeque);
	intDeque.pop_back();
	printDeque(intDeque);
	intDeque.pop_front();		/* pop_front 删除队头元素 */
	printDeque(intDeque);

	intDeque.clear();
    return 0;
}

