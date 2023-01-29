#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
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
//		catch (...) // 捕获任意类型的异常 -- 防止出现未捕获异常时，程序终止
//		{
//			cout << "未知异常" << endl;
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
	// 当b == 0时抛出异常
	if (b == 0)
	{
		Exception e("除0错误", 1);
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

// 1、抛异常可以抛任意类型对象
// 2、捕获时，要求类型匹配
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
		catch (...) // 捕获任意类型的异常 -- 防止出现未捕获异常时，程序终止
		{
			cout << "未知异常" << endl;
		}
	}

	return 0;
}