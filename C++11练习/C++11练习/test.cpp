#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
using namespace std;
struct Point
{
	int _x;
	int _y;
};
int main()
{
	//使用大括号对内置类型进行初始化
	int x1 = { 1 }; //可添加等号
	int x2{ 2 };    //可不添加等号

	//使用大括号对数组元素进行初始化
	int array1[]{ 1, 2, 3, 4, 5 }; //可不添加等号
	int array2[5]{ 0 };            //可不添加等号

	//使用大括号对结构体元素进行初始化
	Point p{ 1, 2 }; //可不添加等号

	//C++11中列表初始化也可以用于new表达式中（C++98无法初始化）
	int* p1 = new int[4]{ 0 };       //不可添加等号
	int* p2 = new int[4]{ 1,2,3,4 }; //不可添加等号
	return 0;
}


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
int main()
{
	//用大括号括起来的列表对容器进行初始化
	vector<int> v = { 1, 2, 3, 4, 5 };
	list<int> l = { 10, 20, 30, 40, 50 };
	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
	map<string, string> m{ make_pair("sort", "排序"), { "insert", "插入" } };

	//用大括号括起来的列表对容器赋值
	v = { 5, 4, 3, 2, 1 };
	return 0;
}
