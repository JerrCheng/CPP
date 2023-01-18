#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#include<time.h>
#include <assert.h>


#include "RBTree.h"

void test_map1()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	//map<string, int> countMap;
	//for (auto& str : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(str);
	//	if (it != countMap.end())
	//	{
	//		//(*it).second++;
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}
	map<string, int> countMap;
	for (auto& str : arr)
	{
		// 1、str不在countMap中，插入pair(str, int()),然后在对返回次数++
		// 2、str在countMap中，返回value(次数)的引用，次数++;
		countMap[str]++;
	}

	map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict["insert"];
	dict["insert"] = "插入";
	dict["left"] = "左边";

	multimap<string, string> mdict;
	mdict.insert(make_pair("sort", "排序"));
	mdict.insert(make_pair("left", "左边"));
	mdict.insert(make_pair("left", "左边"));
	mdict.insert(make_pair("left", "剩余"));
}

int main()
{
	//test_map1();

	//TestAVLTree2();


	return 0;
}