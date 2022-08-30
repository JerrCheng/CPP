#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}


// �κ�һ���ֻ࣬��Ҫдһ��> == ���� < ==���� ʣ�±Ƚ���������ظ��ü���
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
	//����ͬ���Ƚ��£�����ͬ�Ƚ���
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
	//Date ret(*this);  ����д�����ǿ�������
	Date ret = *this;
	ret += day;

	return ret;
}

//d1 += 10  �Լ�Ҫ�ı�
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


//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}


//����++
Date Date::operator++(int)
{
	Date tmp(*this);//��������
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


//ǰ��--
Date& Date::operator--()
{
	return *this -= 1;
}

//����--
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}



//�������
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