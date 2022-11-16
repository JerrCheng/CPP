#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


////父类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//protected:
//	string _name = "张三";
//	int _age = 18;
//};
//
////子类
//class Student : public Person
//{
//protected:
//	int _stuid;             //学号
//};
//
////子类
//class Teacher :public Person
//{
//protected:
//	int _jobid;            //工号
//};


////基类
//class Person
//{
//public:
//	//构造函数
//	Person(const string& name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	//赋值运算符重载函数
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //姓名
//};
//
//
//
////派生类
//class Student : public Person
//{
//public:
//	//构造函数
//	Student(const string& name, int id)
//		:Person(name) //调用基类的构造函数初始化基类的那一部分成员
//		, _id(id) //初始化派生类的成员
//	{
//		cout << "Student()" << endl;
//	}
//	//拷贝构造函数
//	Student(const Student& s)
//		:Person(s) //调用基类的拷贝构造函数完成基类成员的拷贝构造
//		, _id(s._id) //拷贝构造派生类的成员
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//赋值运算符重载函数
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s); //调用基类的operator=完成基类成员的赋值
//			_id = s._id; //完成派生类成员的赋值
//		}
//		return *this;
//	}
//	//析构函数
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
//	}
//private:
//	int _id; //学号
//};
//
//
//int main()
//{
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}



//
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	B b = d; //切片行为
//	return 0;
//}


#include <iostream>
using namespace std;
class A
{
public:
	int _a;
};
class B : virtual public A
{
public:
	int _b;
};
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	B b = d; //切片行为
	return 0;
}
