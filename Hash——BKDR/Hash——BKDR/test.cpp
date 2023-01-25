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
//	// Ҫ�ܿ��������ǲ�����ʹ��
//	int x2 = { 2 };
//	int x3 { 2 };
//
//	// �����ڵ��ù��캯��
//	Date d1(2022, 11, 22);
//	// C++11 Ҫ�ܿ��������ǲ�����ʹ��
//	Date d2 = {2022, 11, 11}; // ->���ù��캯��
//	Date d3{ 2022, 11, 11 };
//
//	// ����֧��list (initializer_list<value_type> il�����������Ĺ��캯��
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
//	// ����
//	map<string, string> dict = { { "sort", "����" }, { "insert", "����" } };
//
//	// ��ֵ����
//	initializer_list<pair<const string, string>> kvil = { { "left", "���" }, { "left", "���" } };
//	dict = kvil;
//
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////
//int main()
//{
//	int x = 10;
//
//	// typeid�õ�ֻ�����͵��ַ����������������ȥ�������ʲô��
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

	// C��������Խ���飬Խ���������鲻������Խ��д�ǳ��
	a1[N];
	//a1[N] = 1;
	a1[N + 5] = 1;


	// Խ���д�����Ա�������
	// ʵ�������array�õú��٣�һ��������c�����ù���
	// ��array������vector + resizeȥ���c����

	array<int, N> a2;
	a2[N];
	a2[N] = 1;
	a2[N + 5] = 1;

	return 0;
}