#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void TestDate1()
{
	Date d1(2022, 8, 28);
	Date d2(d1);

	Date d3(2022, 8, 29);
	d1 = d3;          //d1.operator = (&d1,d3)

	cout << (d1 == d3) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 > d3) << endl;
	cout << (d1 >= d3) << endl;
	cout << (d1 <= d3) << endl;


}



void TestDate2()
{
	Date d1(2022, 7, 24);

	//Date d2 =d1 + 4;
	//d2.Print();

	(d1 + 4).Print();

	// 跨月
	(d1 + 40).Print();

	// 跨年
	(d1 + 400).Print();

	// 跨闰年
	(d1 + 4000).Print();
}

void TestDate3()
{
	Date d1(2022, 7, 25);
	(d1 - 4).Print();
	(d1 - 40).Print();
	(d1 - 400).Print();
	(d1 - 4000).Print();

	Date d2(2022, 7, 25);
	Date d3(2023, 2, 15);

	cout << d2 - d3 << endl;
	cout << d3 - d2 << endl;
}


void TestDate5()
{
	const char* WeeDayToStr[] = { "周一", "周二", "周三", "周四", "周五", "周六", "周天" };
	Date d1, d2;
	int day = 0;
	int option = 0;
	do {
		cout << "*******************************" << endl;
		cout << " 1、日期加/减天数 2、日期减日期" << endl;
		cout << " 3、日期->周几   -1、退出" << endl;
		cout << "*******************************" << endl;

		cout << "请选择:>";
		cin >> option;
		if (option == 1)
		{
			cout << "请依次输入日期及天数(减天数就输入负数)：";
			cin >> d1 >> day;
			cout << "日期加减天数后的日期：" << d1 + day << endl;
		}
		else if (option == 2)
		{
			cout << "请依次输入两个日期：";
			cin >> d1 >> d2;
			cout << "相差的天数：" << d1 - d2 << endl;
		}
		else if (option == 3)
		{
			cout << "请输入日期：";
			cin >> d1;
			Date start(1, 1, 1);
			int n = d1 - start;
			int weekDay = 0; // 周一
			weekDay += n;
			//weekDay += 9;
			//cout << "周" << weekDay % 7 + 1 << endl;
			cout << WeeDayToStr[weekDay % 7] << endl;
		}
		else
		{
			cout << "无此选项，请重新选择" << endl;
		}
	} while (option != -1);
}



//Date ret1 = ++d1; // d1.operator++(&d1)
//Date ret2 = d1++; // d1.operator++(&d2, 0)

int main()
{
	TestDate1();
	TestDate2();
	TestDate3();
	TestDate5();

	return 0;
}