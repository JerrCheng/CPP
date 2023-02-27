#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <memory>
using namespace std;

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (int errid)
	{
		cout << errid << endl;
	}
	/*catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}*/

	cout << "Func() end" << endl;
}


class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

	int getid() const
	{
		return _id;
	}

protected:
	string _errmsg;   // 错误信息
	int _id;          // 错误码
};

class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;

		return str;
	}
protected:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}

protected:
	// stack<string> _stPath;
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;

		return str;
	}

private:
	const string _type;
};

// PC
// App -- 小程序
// web

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}

	cout << "本次请求成功" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 200);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 201);
	}

	SQLMgr();
}

void SeedMsg(const string& s)
{
	// 要求出现网络错误重试三次
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("网络错误", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}

	cout << "发送成功:" << s << endl;
}


void HttpServer()
{
	// 要求出现网络错误，重试3次
	string str = "今晚一起看电影怎么样？";
	//cin >> str;
	int n = 3;
	while (n--)
	{
		try
		{
			SeedMsg(str);

			// 没有发生异常
			break;
		}
		catch (const Exception& e)
		{
			// 网络错误 且  重试3次内
			if (e.getid() == 100 && n > 0)
			{
				continue;
			}
			else
			{
				throw e; // 重新抛出
			}
		}
	}
}
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

int main()
{
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(1));
		Sleep(1000);

		try
		{
			HttpServer();
		}
		catch (const Exception& e) // 这里捕获父类对象就可以
		{
			// 多态
			cout << e.what() << endl;
			// 记录日志
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}

	return 0;
}
