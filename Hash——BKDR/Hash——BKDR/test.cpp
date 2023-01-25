#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	int x1 = 1;
//	// 要能看懂，但是不建议使用
//	int x2 = { 2 };
//	int x3 { 2 };
//
//	// 都是在调用构造函数
//	Date d1(2022, 11, 22);
//	// C++11 要能看懂，但是不建议使用
//	Date d2 = {2022, 11, 11}; // ->调用构造函数
//	Date d3{ 2022, 11, 11 };
//
//	// 调用支持list (initializer_list<value_type> il）类似这样的构造函数
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
//	vector<int> v2 { 1, 2, 3, 4, 5, 6 };
//
//	list<int> lt1 = { 1, 2, 3, 4, 5, 6 };
//	list<int> lt2{ 1, 2, 3, 4, 5, 6 };
//
//	auto x = { 1, 2, 3, 4, 5, 6 };
//	cout << typeid(x).name() << endl;
//
//	vector<Date> v3 = {d1, d2, d3};
//	vector<Date> v4 = { { 2022, 1, 1 }, {2022, 11, 11} };
//
//	string s1 = "11111";
//
//	// 构造
//	map<string, string> dict = { { "sort", "排序" }, { "insert", "插入" } };
//
//	// 赋值重载
//	initializer_list<pair<const string, string>> kvil = { { "left", "左边" }, { "left", "左边" } };
//	dict = kvil;
//
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	int x = 10;
//
//	// typeid拿到只是类型的字符串，不能用这个再去定义对象什么的
//	//typeid(x).name() y = 20;
//
//	decltype(x) y1 = 20.22;
//	auto y2 = 20.22;
//
//	cout << y1 << endl;
//	cout << y2 << endl;
//
//	return 0;
//}

int main()
{
	const size_t N = 100;
	int a1[N];

	// C语言数组越界检查，越界读基本检查不出来，越界写是抽查
	a1[N];
	//a1[N] = 1;
	a1[N + 5] = 1;


	// 越界读写都可以被检查出来
	// 实际情况：array用得很少，一方面大家用c数组用惯了
	// 用array不如用vector + resize去替代c数组

	array<int, N> a2;
	a2[N];
	a2[N] = 1;
	a2[N + 5] = 1;

	return 0;
}