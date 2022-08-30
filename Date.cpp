#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}


// 任何一个类，只需要写一个> == 或者 < ==重载 剩下比较运算符重载复用即可
bool Date::operator== (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}


// d1 != d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}



// d1 > d2
bool Date::operator>(const Date& d)
{
	//年相同，比较月，月相同比较日
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



bool Date::operator>=(const Date& d)
{
	return (*this > d) || (*this == d);
}


bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}


bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}



Date Date::operator+(int day)
{
	//Date ret(*this);  两种写法都是拷贝构造
	Date ret = *this;
	ret += day;

	return ret;
}

//d1 += 10  自己要改变
Date& Date::operator+=(int day)
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


//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}


//后置++
Date Date::operator++(int)
{
	Date tmp(*this);//拷贝构造
	*this += 1;
	return tmp;
}



Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}



Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


//前置--
Date& Date::operator--()
{
	return *this -= 1;
}

//后置--
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}



//日期相减
int Date::operator- (const Date& d)
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