// vectorTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

#define MAX_NUM 20

/* 顺序打印vector容器内元素 */
void printVector(vector<int> myVector)
{
	vector<int>::iterator intIter;
	cout << "print by vector::iterator: ";
	for (intIter = myVector.begin(); intIter != myVector.end(); ++intIter)
	{
		cout << *intIter << " ";	/* 迭代器用法，类似指针，end表示最后一个元素的下一个 */
	}
	cout << endl;
}
/* 逆序打印vector容器内元素 */
void printVectorReverse(vector<int> myVector)
{
	vector<int>::reverse_iterator reIter;		/* 前向迭代器 */
	cout << "print by vector::reverse_iterator: ";
	for (reIter = myVector.rbegin(); reIter != myVector.rend(); ++reIter)	/* rbegin表示最后一个元素，rend表示第一个元素前一个 */
	{
		cout << *reIter << " ";	/* 迭代器用法，类似指针 */
	}
	cout << endl;
}
int main()
{
	vector<int> intVector;
	for (int i = 0; i < MAX_NUM; i++)
	{
		intVector.push_back(i);		/* push_back用法 */
	}
	cout << "print by vector::at(index): ";
	for (size_t i = 0; i < intVector.size(); i++)		/* size的用法 */
	{
		 cout << intVector.at(i) << " ";	/* at的用法 */
	}
	cout << endl;
	cout << "print by vector:: [index]: ";
	for (size_t i = 0; i < intVector.size(); i++)		/* size的用法 */
	{
		cout << intVector[i] << " ";	/* 取下标运算符[]的用法 */
	}
	cout << endl;
	printVectorReverse(intVector);
	/* assign的用法 */
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign(8, 100);	/* 使用8次100 */
	second.assign(first.begin()+1, first.end()-1);	/* 使用first的迭代器，是一个范围：[first,last) */
	int array[] = { 3, 8, 19 };
	third.assign(array, array+3);	/* 使用数组的第0到第3个元素 */
	printVector(first);
	printVector(second);
	printVector(third);
	cout << "back() of third: " << third.back() << endl;	/* back最后一个元素 */
	cout << "front() of third: " << third.front() << endl;	/* front第一个元素 */
	cout << "max_size() of second: " << second.max_size() << endl;	/* second最大能存放元素个数 */
	cout << "capacity() of first: " << first.capacity() << endl;	/* first的容量 */

	first.clear();	/* clear用法，清空容器 */
	first.push_back(10);
	first.push_back(20);
	printVector(first);

	while (!third.empty())	/* empty用法，判断容器是否为空 也可以用size()是否等于零判断 */
	{
		printVector(third);
		third.pop_back();	/* pop_back用法，删除最后一个元素 */
	}

	/* erase用法 */
	intVector.erase(intVector.begin() + 3);	/* erase用法，删除第4个(下标为3)元素 */
	printVector(intVector);
	intVector.erase(intVector.begin() + 5, intVector.begin() + 10);	/* erase用法，删除第6到第11个元素 */
	printVector(intVector);

	/* get_allocator用法 */
	int *p;
	p = intVector.get_allocator().allocate(intVector.size());
	for (size_t i = 0; i < intVector.size(); i++)
		p[i] = i;
	cout << "The allocated array contains:";
	for (size_t i = 0; i < intVector.size(); i++)
		cout << " " << p[i];
	cout << endl;
	intVector.get_allocator().deallocate(p, intVector.size());
    
	/* 等号运算符 = 的使用 */
	vector<int> intVectorCopy = intVector;
	printVector(intVectorCopy);

	intVectorCopy.push_back(345);
	intVectorCopy.push_back(761);
	intVectorCopy.swap(intVector);	/* swap用法，交换两个容器的内容 */
	printVector(intVector);
	printVector(intVectorCopy);

	/* resize用法 */
	intVector.resize(5);
	cout << "after resize(5) intVector is:" << endl;	/* 只保留前5个元素 */
	printVector(intVector);
	intVector.resize(8, 20);
	cout << "after resize(8, 20) intVector is:" << endl;	/* 设置大小为8，不足的用20填充 */
	printVector(intVector);
	intVector.resize(10);
	cout << "after resize(10) intVector is:" << endl;	/* 设置大小为10，用0填充 */
	printVector(intVector);

	/* insert */
	intVector.insert(intVector.begin(), 2, 888);	/* 在开始的地方插入两个888 */
	printVector(intVector);
	int arrayInsert[] = { 9,8,7,6,5 };
	intVector.insert(intVector.begin() + 2, arrayInsert, arrayInsert + 4);	/* 从第2个位置开始，插入一段数组范围[0, 4) */
	printVector(intVector);
	vector<int> vecInsert(5, 666);
	intVector.insert(intVector.begin(), vecInsert.begin() + 1, vecInsert.begin() + 3);	/* 从开始的地方插入另一个容器的一段[1, 3) */
	printVector(intVector);

	/* 构造函数 */
	vector<int> vec1;	/* 构造空的容器 */
	vector<int> vec2(3, 100);	/* 3个100 */
	printVector(vec2);
	vector<int> vec3(intVector.begin(), intVector.begin() + 5);	/* 使用另一个容器的迭代器范围[0, 5) */
	printVector(vec3);
	vector<int> vec4(vec2);	/* 复制容器，也可以用 = 运算符 */
	printVector(vec4);
	vector<int> vec5(arrayInsert, arrayInsert + sizeof(arrayInsert) / sizeof(int));
	printVector(vec5);

	/* clear方法 */
	intVector.clear();
	first.clear();
	second.clear();
	third.clear();
	intVectorCopy.clear();
	vecInsert.clear();
	vec1.clear();
	vec2.clear();
	vec3.clear();
	vec4.clear();
	vec5.clear();
	return 0;
}

