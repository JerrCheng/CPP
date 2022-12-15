#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
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
//拷贝构造
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
	// 友元函数 -- 这个函数内部可以使用Date对象访问私有保护成员
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 1,int month = 1,int day = 1 )
	{
		cout << "Date()" << endl;
		_year  = year  ;
		_month = month;
		_day   = day;
	}


	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day > 0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}
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


	Date& operator= (const Date& x)
	{
		if (this != &x)
		{
			_year = x._year;
			_month = x._month;
			_day = x._day;

		}
	
	}

	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return n * flag;
	}


	Date& operator++() // 前置
	{
		//*this += 1;
		//return *this;

		return *this += 1;
	}

	Date operator++(int) // 后置
	{
		Date tmp(*this);
		*this += 1;

		return tmp;
	}
	// d1 + 100
	Date operator+(int day) const
	{
		//Date ret(*this);
		Date ret = *this;
		ret += day;

		return ret;
	}

	// d2 += d1 += 100
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	// d1 + 100;
	Date& operator+(int day)
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

	Date operator-(int day)
	{
		Date ret (*this);
		ret -= day;
		return ret;
	}



	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month <= 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}


	bool operator== (const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}


	// d1 != d2
	bool operator!=(const Date& d) const
	{
		return !(*this == d);
	}

	// d1 > d2
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

	bool operator>=(const Date& d) const
	{
		return (*this > d) || (*this == d);
	}

	bool operator<(const Date& d) const
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d) const
	{
		return !(*this > d);
	}




private:
	int  _year;
	int _month;
	int _day;
};

// 流插入重载
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

// 流提取重载
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;

	assert(d.CheckDate());

	return in;
}


int main()
{
	Date d1(2022, 12, 13);
	Date d2(2022, 12, 14);

	cout << d1.operator==(d2) << endl; // -> d1.operator==(&d1, d2)
	cout << (d1 == d2) << endl;

	Date ret(d1 + 20);


	return 0;
}