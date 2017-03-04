// vectorTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

#define MAX_NUM 20

/* ˳���ӡvector������Ԫ�� */
void printVector(vector<int> myVector)
{
	vector<int>::iterator intIter;
	cout << "print by vector::iterator: ";
	for (intIter = myVector.begin(); intIter != myVector.end(); ++intIter)
	{
		cout << *intIter << " ";	/* �������÷�������ָ�룬end��ʾ���һ��Ԫ�ص���һ�� */
	}
	cout << endl;
}
/* �����ӡvector������Ԫ�� */
void printVectorReverse(vector<int> myVector)
{
	vector<int>::reverse_iterator reIter;		/* ǰ������� */
	cout << "print by vector::reverse_iterator: ";
	for (reIter = myVector.rbegin(); reIter != myVector.rend(); ++reIter)	/* rbegin��ʾ���һ��Ԫ�أ�rend��ʾ��һ��Ԫ��ǰһ�� */
	{
		cout << *reIter << " ";	/* �������÷�������ָ�� */
	}
	cout << endl;
}
int main()
{
	vector<int> intVector;
	for (int i = 0; i < MAX_NUM; i++)
	{
		intVector.push_back(i);		/* push_back�÷� */
	}
	cout << "print by vector::at(index): ";
	for (size_t i = 0; i < intVector.size(); i++)		/* size���÷� */
	{
		 cout << intVector.at(i) << " ";	/* at���÷� */
	}
	cout << endl;
	cout << "print by vector:: [index]: ";
	for (size_t i = 0; i < intVector.size(); i++)		/* size���÷� */
	{
		cout << intVector[i] << " ";	/* ȡ�±������[]���÷� */
	}
	cout << endl;
	printVectorReverse(intVector);
	/* assign���÷� */
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign(8, 100);	/* ʹ��8��100 */
	second.assign(first.begin()+1, first.end()-1);	/* ʹ��first�ĵ���������һ����Χ��[first,last) */
	int array[] = { 3, 8, 19 };
	third.assign(array, array+3);	/* ʹ������ĵ�0����3��Ԫ�� */
	printVector(first);
	printVector(second);
	printVector(third);
	cout << "back() of third: " << third.back() << endl;	/* back���һ��Ԫ�� */
	cout << "front() of third: " << third.front() << endl;	/* front��һ��Ԫ�� */
	cout << "max_size() of second: " << second.max_size() << endl;	/* second����ܴ��Ԫ�ظ��� */
	cout << "capacity() of first: " << first.capacity() << endl;	/* first������ */

	first.clear();	/* clear�÷���������� */
	first.push_back(10);
	first.push_back(20);
	printVector(first);

	while (!third.empty())	/* empty�÷����ж������Ƿ�Ϊ�� Ҳ������size()�Ƿ�������ж� */
	{
		printVector(third);
		third.pop_back();	/* pop_back�÷���ɾ�����һ��Ԫ�� */
	}

	/* erase�÷� */
	intVector.erase(intVector.begin() + 3);	/* erase�÷���ɾ����4��(�±�Ϊ3)Ԫ�� */
	printVector(intVector);
	intVector.erase(intVector.begin() + 5, intVector.begin() + 10);	/* erase�÷���ɾ����6����11��Ԫ�� */
	printVector(intVector);

	/* get_allocator�÷� */
	int *p;
	p = intVector.get_allocator().allocate(intVector.size());
	for (size_t i = 0; i < intVector.size(); i++)
		p[i] = i;
	cout << "The allocated array contains:";
	for (size_t i = 0; i < intVector.size(); i++)
		cout << " " << p[i];
	cout << endl;
	intVector.get_allocator().deallocate(p, intVector.size());
    
	/* �Ⱥ������ = ��ʹ�� */
	vector<int> intVectorCopy = intVector;
	printVector(intVectorCopy);

	intVectorCopy.push_back(345);
	intVectorCopy.push_back(761);
	intVectorCopy.swap(intVector);	/* swap�÷��������������������� */
	printVector(intVector);
	printVector(intVectorCopy);

	/* resize�÷� */
	intVector.resize(5);
	cout << "after resize(5) intVector is:" << endl;	/* ֻ����ǰ5��Ԫ�� */
	printVector(intVector);
	intVector.resize(8, 20);
	cout << "after resize(8, 20) intVector is:" << endl;	/* ���ô�СΪ8���������20��� */
	printVector(intVector);
	intVector.resize(10);
	cout << "after resize(10) intVector is:" << endl;	/* ���ô�СΪ10����0��� */
	printVector(intVector);

	/* insert */
	intVector.insert(intVector.begin(), 2, 888);	/* �ڿ�ʼ�ĵط���������888 */
	printVector(intVector);
	int arrayInsert[] = { 9,8,7,6,5 };
	intVector.insert(intVector.begin() + 2, arrayInsert, arrayInsert + 4);	/* �ӵ�2��λ�ÿ�ʼ������һ�����鷶Χ[0, 4) */
	printVector(intVector);
	vector<int> vecInsert(5, 666);
	intVector.insert(intVector.begin(), vecInsert.begin() + 1, vecInsert.begin() + 3);	/* �ӿ�ʼ�ĵط�������һ��������һ��[1, 3) */
	printVector(intVector);

	/* ���캯�� */
	vector<int> vec1;	/* ����յ����� */
	vector<int> vec2(3, 100);	/* 3��100 */
	printVector(vec2);
	vector<int> vec3(intVector.begin(), intVector.begin() + 5);	/* ʹ����һ�������ĵ�������Χ[0, 5) */
	printVector(vec3);
	vector<int> vec4(vec2);	/* ����������Ҳ������ = ����� */
	printVector(vec4);
	vector<int> vec5(arrayInsert, arrayInsert + sizeof(arrayInsert) / sizeof(int));
	printVector(vec5);

	/* clear���� */
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

