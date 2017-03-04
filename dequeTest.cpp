// dequeTest.cpp : �������̨Ӧ�ó������ڵ㡣
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
deque�����������vectorһ��
���push_front��pop_front��˫�����֧�ֶ�ͷ�Ͷ�β����
*/

int main()
{
	int array[] = { 7,8,9,10 };
	deque<int> intDeque(array, array+sizeof(array)/sizeof(int));	/* ʹ�����鹹�� */
	printDeque(intDeque);
	intDeque.push_back(11);
	printDeque(intDeque);
	intDeque.push_front(12);	/* push_front ����ͷ����Ԫ�� */
	printDeque(intDeque);
	intDeque.pop_back();
	printDeque(intDeque);
	intDeque.pop_front();		/* pop_front ɾ����ͷԪ�� */
	printDeque(intDeque);

	intDeque.clear();
    return 0;
}

