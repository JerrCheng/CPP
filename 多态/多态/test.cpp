#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person {
public:
	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
	// 不符合重写，就是隐藏关系
	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

class Soldier : public Person{
public:
	virtual void BuyTicket() { cout << "优先买票" << endl; }
};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
//
void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;
	Soldier sd;

	Func(ps);
	Func(st);
	Func(sd);
	
	return 0;
}
