#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//	/*catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}*/
//
//	cout << "Func() end" << endl;
//}
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (int errid)
//		{
//			cout << errid << endl;
//		}
//		catch (char errmsg)
//		{
//			cout << errmsg << endl;
//		}
//		/*catch (const char* errmsg)
//		{
//		cout << errmsg << endl;
//		}*/
//		catch (...) // �����������͵��쳣 -- ��ֹ����δ�����쳣ʱ��������ֹ
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//
//	return 0;
//}

class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _errid(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

	int GetErrid()
	{
		return _errid;
	}

protected:
	string _errmsg;
	int _errid;
};

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		Exception e("��0����", 1);
		throw e;
	}
	else
	{
		return ((double)a / (double)b);
	}
}

void Func1()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

void Func2()
{

}

// 1�����쳣�������������Ͷ���
// 2������ʱ��Ҫ������ƥ��
int main()
{
	while (1)
	{
		try
		{
			Func1();
		}
		catch (const Exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...) // �����������͵��쳣 -- ��ֹ����δ�����쳣ʱ��������ֹ
		{
			cout << "δ֪�쳣" << endl;
		}
	}

	return 0;
}