#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{

Date(int year, int month, int day)
	: _year(year)
	, _month(month)
	, _day(day)
{}

private:
	int _year;
	int _month;
	int _day;

};




int main()
{
	return 0;
}