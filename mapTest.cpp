// mapTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

/* 
map��Ԫ����һ�ԣ���һ����key���ڶ�����value��һ��map�е�key��Ψһ��
��pair��ʾ��pair.first��ʾkey��pair.second��ʾvalue
*/
#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

void printMap(map<char, int> pMap)
{
	map<char, int>::iterator iter;
	cout << "print map by iterator:" << endl;
	for (iter = pMap.begin(); iter != pMap.end(); ++iter)
	{
		cout << iter->first << " => " << iter->second << endl;	/* map��������first��ʾkey��second��ʾvalue */
	}
}
int main()
{
	map<char, int> mymap;
	pair<map<char, int>::iterator, map<char, int>::iterator> ret;

	mymap['a'] = 10;	/* keyΪa��valueΪ10 */
	mymap['b'] = 20;
	mymap['c'] = 30;

	ret = mymap.equal_range('b');	/* equal_range����������һ��������һ�Ե����� */

	cout << "lower bound points to: ";
	cout << ret.first->first << " => " << ret.first->second << endl;

	cout << "upper bound points to: ";
	cout << ret.second->first << " => " << ret.second->second << endl;

	mymap.insert(pair<char, int>('d', 40));	/* map��insert����������Ķ���Ϊpair */
	printMap(mymap);
	mymap.insert(pair<char, int>('d', 50));	/* key�ظ���������Ч */
	printMap(mymap);

	multimap<char, int> mulmap(mymap.begin(), mymap.end());
	multimap<char, int>::iterator miter;
	cout << "print multimap by iterator:" << endl;
	for (miter = mulmap.begin(); miter != mulmap.end(); ++miter)
	{
		cout << miter->first << " => " << miter->second << endl;
	}
	mulmap.insert(pair<char, int>('d', 50));	/* keyֵ�����ظ� */
	cout << "after insert:" << endl;
	for (miter = mulmap.begin(); miter != mulmap.end(); ++miter)
	{
		cout << miter->first << " => " << miter->second << endl;
	}
	mymap.clear();
	return 0;
}

