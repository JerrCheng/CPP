#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<list>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello");

	cout << s2 << endl;
	cout << s1 << endl;
}



void test_string2()
{
	string s1;
	string s2 = "hellp,seocn";

	s1 = s2;
	s1 = "sefhshfoe";
	s1 = 'Y';
}




void test_string3()
{
	list<int> lt(10, 1);
	list<int>::iterator lit = lt.begin();

	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;

	}
	cout << endl;
}




void PrintString(const string& str)
{
	//string::const_iterator it = str.begin();
	auto it = str.begin();
	while (it != str.end())
	{
		//*it = 'x';
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//auto rit = str.begin();
	string::const_reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}



int main()
{
	PrintString("hello");
	return 0;
}


