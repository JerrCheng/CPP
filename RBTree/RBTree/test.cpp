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
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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
		// 1��str����countMap�У�����pair(str, int()),Ȼ���ڶԷ��ش���++
		// 2��str��countMap�У�����value(����)�����ã�����++;
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
	dict.insert(make_pair("sort", "����"));
	dict["insert"];
	dict["insert"] = "����";
	dict["left"] = "���";

	multimap<string, string> mdict;
	mdict.insert(make_pair("sort", "����"));
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "ʣ��"));
}

int main()
{
	//test_map1();

	//TestAVLTree2();


	return 0;
}