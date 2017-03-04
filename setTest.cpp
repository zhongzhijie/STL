// setTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
set�������÷���vector��ͬС�죬ֻ��setΪ˳��������Ԫ���Ѿ��ź���
������Ԫ���ظ�
�����޸�Ԫ�ص�ֵ����Ϊ�Ѿ����������У��޸Ŀ��ܴ���˳��ֻ��ɾ��ĳ��Ԫ�أ�Ȼ������µ�Ԫ��
*/
#include "stdafx.h"
#include <set>
#include <iostream>
using namespace std;

int main()
{
	set<int> myset;
	pair<set<int>::iterator, set<int>::iterator> ret;

	for (int i = 1; i <= 5; i++) myset.insert(i * 10);   // set: 10 20 30 40 50

	/* equal_range����һ�Ե���������һ��ָ��С�ڸ���ֵ��Ԫ�أ��ڶ���ָ����ڸ���ֵ�ĵ�1��Ԫ�أ�û�����쳣�����
	lower_bound �� upper_bound */
	ret = myset.equal_range(30);

	cout << "lower bound points to: " << *ret.first << endl;
	cout << "upper bound points to: " << *ret.second << endl;

	multiset<int> mulset(myset.begin(), myset.end());	/* ʹ��mysetԪ�س�ʼ��mulset */
	myset.insert(40);	/* set�������ظ�Ԫ�أ����û�в��� */
	mulset.insert(40);	/* multiset�����ظ�Ԫ�أ�����40 */
	cout << "size of myset is: " << myset.size() << endl;
	cout << "size of mulset is: " << mulset.size() << endl;

	myset.clear();
	mulset.clear();
	return 0;
}

