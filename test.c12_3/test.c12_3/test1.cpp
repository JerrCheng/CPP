#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year = 1,int month = 1,int day = 1 )
//	{
//		cout << "Date()" << endl;
//		_year  = year  ;
//		_month = month;
//		_day   = day;
//	}
//
//	//Date()
//	//{
//	//	cout << "Date()" << endl;
//	//	_year = 0;
//	//	_month = 0;
//	//	_day = 0;
//	//}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//};
//
//void func()
//{
//	Date d1(2022, 12, 13);
//	Date d2(d1);
//	Date d2 = d1;
//
//}
//
//
//int main()
//{
//	Date d1;
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//¿½±´¹¹Ôì
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		cout << "Date()" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		cout << "	Date(Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//	}
//	
//
//
//private:
//	size_t _year;
//	size_t _month;
//	size_t _day;
//};
//
//void get1(Date d)
//{}
//
//void get2(Date& d)
//{}
//
//void func()
//{
//	Date d1(2022, 12, 13);
//	get1(d1);
//	get2(d1);
//
//
//	//Date d2(d1);
//	//Date d3 = d1;
//
//}
//
//
//int main()
//{
//	Date d1;
//	func();
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////////////////////
class Date
{
public:
	Date(int year = 1,int month = 1,int day = 1 )
	{
		cout << "Date()" << endl;
		_year  = year  ;
		_month = month;
		_day   = day;
	}

	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		//if (month == 2 && IsLeapYear(year))
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return days[month];
		}
	}

	//Date()
	//{
	//	cout << "Date()" << endl;
	//	_year = 0;
	//	_month = 0;
	//	_day = 0;
	//}

	~Date()
	{
		cout << "~Date()" << endl;
		_year = 0;
		_month = 0;
		_day = 0;
	}

	bool operator==(const Date& x)
	{
		return _year == x._year
			&& _month == x._month
			&& _day == x._day;
	}


	int operator-(const Date& x)
	{

	}


	// d1 + 100;
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			++ret._month;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}

		return ret;
	}

	bool operator<(const Date& x);
	bool operator>(const Date& x);
	bool operator>=(const Date& x);
	bool operator<=(const Date& x);
	bool operator!=(const Date& x);


private:
	int  _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2022, 12, 13);
	Date d2(2022, 12, 14);

	cout << d1.operator==(d2) << endl; // -> d1.operator==(&d1, d2)
	cout << (d1 == d2) << endl;

	Date ret(d1 + 20);


	return 0;
}