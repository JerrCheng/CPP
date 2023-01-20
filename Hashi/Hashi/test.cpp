﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <time.h>



void test_set()
{
	unordered_set<int> s;
	//set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(5);

	//unordered_set<int>::iterator it = s.begin();
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_op()
{
	int n = 10000000;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		//v.push_back(i);
		v.push_back(rand() + i);  // ظ
		//v.push_back(rand());  // ظ
	}

	size_t begin1 = clock();
	set<int> s;
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	unordered_set<int> us;
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();

	cout << "size:" << s.size() << endl;

	cout << "set insert:" << end1 - begin1 << endl;
	cout << "unordered_set insert:" << end2 - begin2 << endl;


	size_t begin3 = clock();
	for (auto e : v)
	{
		s.find(e);
	}
	size_t end3 = clock();

	size_t begin4 = clock();
	for (auto e : v)
	{
		us.find(e);
	}
	size_t end4 = clock();
	cout << "set find:" << end3 - begin3 << endl;
	cout << "unordered_set find:" << end4 - begin4 << endl;


	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase" << endl;

	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase" << endl;

	cout << "set erase:" << end5 - begin5 << endl;
	cout << "unordered_set erase:" << end6 - begin6 << endl;

	unordered_map<string, int> countMap;
	countMap.insert(make_pair("ƻ", 1));
}


int main()
{
	//test_set();
	//test_op();
	//TestHT1();
	//TestHT2();



	return 0;
}