// mapTest.cpp : 定义控制台应用程序的入口点。
//

/* 
map的元素是一对，第一个是key，第二个是value，一个map中的key是唯一的
用pair表示，pair.first表示key，pair.second表示value
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
		cout << iter->first << " => " << iter->second << endl;	/* map迭代器的first表示key，second表示value */
	}
}
int main()
{
	map<char, int> mymap;
	pair<map<char, int>::iterator, map<char, int>::iterator> ret;

	mymap['a'] = 10;	/* key为a，value为10 */
	mymap['b'] = 20;
	mymap['c'] = 30;

	ret = mymap.equal_range('b');	/* equal_range和其他容器一样，返回一对迭代器 */

	cout << "lower bound points to: ";
	cout << ret.first->first << " => " << ret.first->second << endl;

	cout << "upper bound points to: ";
	cout << ret.second->first << " => " << ret.second->second << endl;

	mymap.insert(pair<char, int>('d', 40));	/* map的insert方法，插入的对象为pair */
	printMap(mymap);
	mymap.insert(pair<char, int>('d', 50));	/* key重复，插入无效 */
	printMap(mymap);

	multimap<char, int> mulmap(mymap.begin(), mymap.end());
	multimap<char, int>::iterator miter;
	cout << "print multimap by iterator:" << endl;
	for (miter = mulmap.begin(); miter != mulmap.end(); ++miter)
	{
		cout << miter->first << " => " << miter->second << endl;
	}
	mulmap.insert(pair<char, int>('d', 50));	/* key值可以重复 */
	cout << "after insert:" << endl;
	for (miter = mulmap.begin(); miter != mulmap.end(); ++miter)
	{
		cout << miter->first << " => " << miter->second << endl;
	}
	mymap.clear();
	return 0;
}

