#define _CRT_SECURE_NO_WARNINGS 1
#include<list>
#include<iostream>
#include<algorithm>
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


int main()
{
	test_list2();
	return 0;
}
