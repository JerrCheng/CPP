#pragma once
#include<iostream>
#include<assert.h>

using namespace std;
class Date
{
	// 友元函数 -- 这个函数内部可以使用Date对象访问私有保护成员
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 2022, int month = 8, int day = 28)
	{
		_year = year;
		_month = month;
		_day = day;

		assert(CheckDate());
	}

	//获取某年某月天数，频繁调用写进类里面成为内敛函数
	int GetMonthDay(int year, int month)
	{
		//数组放在静态区
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
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


	//d1 = d3  d3传给d，d1传给this
	Date& operator = (const Date& d)
	{
		if (this != &d)   //取地址  防止出现d2 = d2这种情况
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}


		return *this;
	}

	void Print();

	//运算符
	bool operator ==(const Date& d);
	bool operator !=(const Date& d);
	bool operator >(const Date& d);
	bool operator <(const Date& d);
	bool operator >=(const Date& d);
	bool operator <=(const Date& d);


	//日期+天数
	Date operator+(int day);
	Date& operator+=(int day);

	// ++d1;
	// d1++;
	// 直接按特性重载，无法区分
	// 特殊处理，使用重载区分，后置++重载增加一个int参数跟前置构成函数重载进行区分
	Date& operator++(); // 前置
	Date operator++(int); // 后置


	//日期-天数
	Date operator-(int day);
	Date& operator-=(int day);

	//--
	Date& operator--();
	Date operator--(int);


	//日期相减
	int operator- (const Date& d);

private:
	int _year;
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