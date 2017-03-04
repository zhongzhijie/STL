// listTest.cpp : �������̨Ӧ�ó������ڵ㡣
//
// list::assign
#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

bool mycomparison(int first, int second)
{
	return first < second;
}

bool decComp(int first, int second)
{
	return first > second;
}

int isOdd(int i)
{
	return i%2;
}
/* ��������ͨ������operator()ʵ�� */
class is_odd
{
public:
	bool operator() (const int& value) { return (value % 2) == 1; }
};

void printList(list<int> intList)
{
	list<int>::iterator iter;
	cout << "print by list iterator: ";
	for (iter = intList.begin(); iter != intList.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}
int main()
{
	list<int> first, second;

	first.push_back(5);
	first.push_back(2);
	first.push_back(3);

	second.push_back(9);
	second.push_back(1);
	second.push_back(8);

	first.sort();	/* list��sort������Ĭ�ϰ��հ����������� */
	second.sort(decComp);	/* �Զ���ıȽϺ��������ս������� */
	printList(first);
	printList(second);

	second.sort();	/* mergeĬ�����������У�������������second���� */
	first.merge(second);	/* ��second�ϲ���first�в����second��Ĭ�ϰ������� */
	printList(first);

	second.push_back(4);	/* secondΪ 4 */
	first.sort(decComp);
	printList(first);	/* firstΪ 9 8 5 3 2 1 */
	first.merge(second, decComp);	/* ���ս���ϲ���merge�ıȽϺ��������������Ѿ��źõ�˳��һ�� */
	printList(first);
	
	first.reverse();	/* list��reverse��������ת�����е�Ԫ�� */
	printList(first);

	first.remove(5);	/* ɾ��Ԫ��5 */
	printList(first);
	first.remove_if(is_odd());	/* ɾ���������ȽϺ���Ϊ��������Ҳ�����ú���ָ�룬�������� isOdd */
	printList(first);	/* firstΪ2 4 8 */

	first.push_front(2);
	first.push_back(4);
	printList(first);	/* 2 2 4 8 4 */
	first.unique();		/* ɾ�����ڵ��ظ�Ԫ�� */
	printList(first);

	int array[] = { 4, 3, 5, 9, 7, 2 };
	second.assign(array, array + sizeof(array) / sizeof(int));	/* assign�÷����޸�����Ԫ�ص�ֵ */
	printList(second);

	/* �������ص�splice�÷� */
	first.splice(++first.begin(), second);	/* ��second���뵽first�ĵ�2��Ԫ�ص�λ�ã�secondΪ�� */
	printList(first);
	printList(second);	/* secondΪ�� */

	second.splice(second.begin(), first, first.begin());	/* ��first�ĵ�1��Ԫ���Ƶ�second */
	printList(first);
	printList(second);	/* secondΪ�� */
	list<int>::iterator iter = first.begin();
	advance(iter, 3);	/* iterָ��first�ĵ�4��Ԫ�� */
	first.splice(first.begin(), first, iter, first.end());	/* ��first�ĵ�4��Ԫ�������һ��Ԫ�أ��Ƶ�first��begin */
	printList(first);

	first.clear();
	second.clear();
	return 0;

}

