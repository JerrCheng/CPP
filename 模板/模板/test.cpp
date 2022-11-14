#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <array>
#include <time.h>
#include <queue>
using namespace std;

//template<class T,size_t N>
//
//class arry
//{
//private:
//	T _a[N];
//};
//
//class Date
//{
//
//};
//
//template<class T>
//bool Greater(T left, T right)
//{
//	return left > right;
//}
//
//
//template<>
//bool Greater<Date*>(Date* left, Date* right)
//{
//	return *left > *right;
//}
//
//int main()
//{
//	arry<int, 1000>a1;
//	arry<double, 100>a2;
//	return 0;
//}


struct Date
{
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator>(const Date& d) const
	{
		if ((_year > d._year)
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Date& d) const
	{
		if ((_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int _year;
	int _month;
	int _day;
};

// ����ģ�� -- ����ƥ��
template<class T>
bool Greater(T left, T right)
{
	return left > right;
}

// �ػ�--���ĳЩ���ͽ������⻯����
template<>
bool Greater<Date*>(Date* left, Date* right)
{
	return *left > *right;
}

/////////////////////////////////////////////////////////
// ��ģ��
namespace bit
{
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2) const
		{
			return x1 < x2;
		}
	};

	// �ػ�
	//template<>
	//struct less<Date*>
	//{
	//	bool operator()(Date* x1, Date* x2) const
	//	{
	//		return *x1 < *x2;
	//	}
	//};
}

int main()
{
	cout << Greater(1, 2) << endl;   // ���ԱȽϣ������ȷ

	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << Greater(d1, d2) << endl;  // ���ԱȽϣ������ȷ

	Date* p1 = &d1;
	Date* p2 = &d2;
	cout << Greater(p1, p2) << endl;  // ���ԱȽϣ��������

	bit::less<Date> lessFunc1;
	cout << lessFunc1(d1, d2) << endl;

	bit::less<Date*> lessFunc2;
	cout << lessFunc2(p1, p2) << endl;

	std::priority_queue<Date, vector<Date>, bit::less<Date>> dq1;
	std::priority_queue<Date*, vector<Date*>, bit::less<Date*>> dq2;
	dq2.push(new Date(2022, 9, 27));
	dq2.push(new Date(2022, 9, 25));
	dq2.push(new Date(2022, 9, 28));
	dq2.push(new Date(2022, 9, 29));


	return 0;
}