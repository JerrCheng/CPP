#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


////����
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
//	string _name = "����";
//	int _age = 18;
//};
//
////����
//class Student : public Person
//{
//protected:
//	int _stuid;             //ѧ��
//};
//
////����
//class Teacher :public Person
//{
//protected:
//	int _jobid;            //����
//};


////����
//class Person
//{
//public:
//	//���캯��
//	Person(const string& name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	//�������캯��
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	//��ֵ��������غ���
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	//��������
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; //����
//};
//
//
//
////������
//class Student : public Person
//{
//public:
//	//���캯��
//	Student(const string& name, int id)
//		:Person(name) //���û���Ĺ��캯����ʼ���������һ���ֳ�Ա
//		, _id(id) //��ʼ��������ĳ�Ա
//	{
//		cout << "Student()" << endl;
//	}
//	//�������캯��
//	Student(const Student& s)
//		:Person(s) //���û���Ŀ������캯����ɻ����Ա�Ŀ�������
//		, _id(s._id) //��������������ĳ�Ա
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	//��ֵ��������غ���
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s); //���û����operator=��ɻ����Ա�ĸ�ֵ
//			_id = s._id; //����������Ա�ĸ�ֵ
//		}
//		return *this;
//	}
//	//��������
//	~Student()
//	{
//		cout << "~Student()" << endl;
//		//������������������ڱ�������ɺ��Զ����û������������
//	}
//private:
//	int _id; //ѧ��
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
//	B b = d; //��Ƭ��Ϊ
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

	B b = d; //��Ƭ��Ϊ
	return 0;
}
