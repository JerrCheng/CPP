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
	//ʹ�ô����Ŷ��������ͽ��г�ʼ��
	int x1 = { 1 }; //����ӵȺ�
	int x2{ 2 };    //�ɲ���ӵȺ�

	//ʹ�ô����Ŷ�����Ԫ�ؽ��г�ʼ��
	int array1[]{ 1, 2, 3, 4, 5 }; //�ɲ���ӵȺ�
	int array2[5]{ 0 };            //�ɲ���ӵȺ�

	//ʹ�ô����ŶԽṹ��Ԫ�ؽ��г�ʼ��
	Point p{ 1, 2 }; //�ɲ���ӵȺ�

	//C++11���б��ʼ��Ҳ��������new���ʽ�У�C++98�޷���ʼ����
	int* p1 = new int[4]{ 0 };       //������ӵȺ�
	int* p2 = new int[4]{ 1,2,3,4 }; //������ӵȺ�
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
	//�ô��������������б���������г�ʼ��
	vector<int> v = { 1, 2, 3, 4, 5 };
	list<int> l = { 10, 20, 30, 40, 50 };
	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
	map<string, string> m{ make_pair("sort", "����"), { "insert", "����" } };

	//�ô��������������б��������ֵ
	v = { 5, 4, 3, 2, 1 };
	return 0;
}
