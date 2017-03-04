// setTest.cpp : 定义控制台应用程序的入口点。
//

/*
set的其他用法和vector大同小异，只是set为顺序容器，元素已经排好序
不允许元素重复
不能修改元素的值，因为已经是排序序列，修改可能打乱顺序，只能删除某个元素，然后插入新的元素
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

	/* equal_range返回一对迭代器，第一个指向不小于给定值的元素，第二个指向大于给定值的第1个元素（没考虑异常情况）
	lower_bound 和 upper_bound */
	ret = myset.equal_range(30);

	cout << "lower bound points to: " << *ret.first << endl;
	cout << "upper bound points to: " << *ret.second << endl;

	multiset<int> mulset(myset.begin(), myset.end());	/* 使用myset元素初始化mulset */
	myset.insert(40);	/* set不允许重复元素，因此没有插入 */
	mulset.insert(40);	/* multiset允许重复元素，插入40 */
	cout << "size of myset is: " << myset.size() << endl;
	cout << "size of mulset is: " << mulset.size() << endl;

	myset.clear();
	mulset.clear();
	return 0;
}

