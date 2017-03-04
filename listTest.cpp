// listTest.cpp : 定义控制台应用程序的入口点。
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
/* 函数对象，通过重载operator()实现 */
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

	first.sort();	/* list的sort方法，默认按照按照升序排列 */
	second.sort(decComp);	/* 自定义的比较函数，按照降序排列 */
	printList(first);
	printList(second);

	second.sort();	/* merge默认是升序序列，这里重新排列second容器 */
	first.merge(second);	/* 将second合并到first中并清空second，默认按照升序 */
	printList(first);

	second.push_back(4);	/* second为 4 */
	first.sort(decComp);
	printList(first);	/* first为 9 8 5 3 2 1 */
	first.merge(second, decComp);	/* 按照降序合并，merge的比较函数必须与序列已经排好的顺序一致 */
	printList(first);
	
	first.reverse();	/* list的reverse方法，反转容器中的元素 */
	printList(first);

	first.remove(5);	/* 删除元素5 */
	printList(first);
	first.remove_if(is_odd());	/* 删除奇数，比较函数为函数对象，也可以用函数指针，即函数名 isOdd */
	printList(first);	/* first为2 4 8 */

	first.push_front(2);
	first.push_back(4);
	printList(first);	/* 2 2 4 8 4 */
	first.unique();		/* 删除相邻的重复元素 */
	printList(first);

	int array[] = { 4, 3, 5, 9, 7, 2 };
	second.assign(array, array + sizeof(array) / sizeof(int));	/* assign用法，修改容器元素的值 */
	printList(second);

	/* 几种重载的splice用法 */
	first.splice(++first.begin(), second);	/* 将second插入到first的第2个元素的位置，second为空 */
	printList(first);
	printList(second);	/* second为空 */

	second.splice(second.begin(), first, first.begin());	/* 将first的第1个元素移到second */
	printList(first);
	printList(second);	/* second为空 */
	list<int>::iterator iter = first.begin();
	advance(iter, 3);	/* iter指向first的第4个元素 */
	first.splice(first.begin(), first, iter, first.end());	/* 将first的第4个元素起到最后一个元素，移到first的begin */
	printList(first);

	first.clear();
	second.clear();
	return 0;

}

