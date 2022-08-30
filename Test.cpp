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

	// ����
	(d1 + 40).Print();

	// ����
	(d1 + 400).Print();

	// ������
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
	const char* WeeDayToStr[] = { "��һ", "�ܶ�", "����", "����", "����", "����", "����" };
	Date d1, d2;
	int day = 0;
	int option = 0;
	do {
		cout << "*******************************" << endl;
		cout << " 1�����ڼ�/������ 2�����ڼ�����" << endl;
		cout << " 3������->�ܼ�   -1���˳�" << endl;
		cout << "*******************************" << endl;

		cout << "��ѡ��:>";
		cin >> option;
		if (option == 1)
		{
			cout << "�������������ڼ�����(�����������븺��)��";
			cin >> d1 >> day;
			cout << "���ڼӼ�����������ڣ�" << d1 + day << endl;
		}
		else if (option == 2)
		{
			cout << "�����������������ڣ�";
			cin >> d1 >> d2;
			cout << "����������" << d1 - d2 << endl;
		}
		else if (option == 3)
		{
			cout << "���������ڣ�";
			cin >> d1;
			Date start(1, 1, 1);
			int n = d1 - start;
			int weekDay = 0; // ��һ
			weekDay += n;
			//weekDay += 9;
			//cout << "��" << weekDay % 7 + 1 << endl;
			cout << WeeDayToStr[weekDay % 7] << endl;
		}
		else
		{
			cout << "�޴�ѡ�������ѡ��" << endl;
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