#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <memory>
using namespace std;

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
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
	string _errmsg;   // ������Ϣ
	int _id;          // ������
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
// App -- С����
// web

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
	}

	cout << "��������ɹ�" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 200);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 201);
	}

	SQLMgr();
}

void SeedMsg(const string& s)
{
	// Ҫ��������������������
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("�������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}

	cout << "���ͳɹ�:" << s << endl;
}


void HttpServer()
{
	// Ҫ����������������3��
	string str = "����һ�𿴵�Ӱ��ô����";
	//cin >> str;
	int n = 3;
	while (n--)
	{
		try
		{
			SeedMsg(str);

			// û�з����쳣
			break;
		}
		catch (const Exception& e)
		{
			// ������� ��  ����3����
			if (e.getid() == 100 && n > 0)
			{
				continue;
			}
			else
			{
				throw e; // �����׳�
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
//		catch (...) // �����������͵��쳣 -- ��ֹ����δ�����쳣ʱ��������ֹ
//		{
//			cout << "δ֪�쳣" << endl;
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
		catch (const Exception& e) // ���ﲶ�������Ϳ���
		{
			// ��̬
			cout << e.what() << endl;
			// ��¼��־
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}

	return 0;
}
