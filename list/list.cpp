#define _CRT_SECURE_NO_WARNINGS 1
#include<list>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

void test_list1()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << endl;
		++it;
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}



void test_list2()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	lt.remove(3);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list3()
{
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int> copy = lt;

	for (auto& e : lt)
	{
		e *= 2;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

//int main()
//{
//	test_list3();
//	return 0;
//}


﻿int main()

{

	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };

	int n = sizeof(array) / sizeof(int);

	list<int> mylist(array, array + n);

	auto it = mylist.begin();

	while (it != mylist.end())

	{

		if (*it != 0)

			cout << *it << " ";

		else

			it = mylist.erase(it);

		++it;

	}

	return 0;

}