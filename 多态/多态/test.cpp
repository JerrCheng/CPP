#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "优先买票" << endl; }
//};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数



//void Func(Person& p)
//{
//	//通过父类的引用调用虚函数
//	p.BuyTicket();
//}
//void Func(Person* p)
//{
//	//通过父类的指针调用虚函数
//	p->BuyTicket();
//}



////基类
//class A
//{};
////子类
//class B : public A
//{};
////基类
//class Person
//{
//public:
//	//返回基类A的指针
//	virtual A* fun()
//	{
//		cout << "A* Person::f()" << endl;
//		return new A;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//返回子类B的指针
//	virtual B* fun()
//	{
//		cout << "B* Student::f()" << endl;
//		return new B;
//	}
//};



//
//int main()
//{
//	Person p;   //普通人
//	Student st; //学生
//	Soldier sd; //军人
//
//	Func(p);  //买票-全价
//	Func(st); //买票-半价
//	Func(sd); //优先买票
//
//	Func(&p);  //买票-全价
//	Func(&st); //买票-半价
//	Func(&sd); //优先买票
//	return 0;
//}

////父类
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//
//int main()
//{
//	//分别new一个父类对象和子类对象，并均用父类指针指向它们
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//使用delete调用析构函数并释放对象空间
//	delete p1;
//	delete p2;
//	return 0;
//}


////父类
//class Person
//{
//public:
//	//被final修饰，该虚函数不能再被重写
//	virtual void BuyTicket() final
//	{
//		cout << "买票-全价" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//重写，编译报错
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
////子类
//class Soldier : public Person
//{
//public:
//	//重写，编译报错
//	virtual void BuyTicket()
//	{
//		cout << "优先-买票" << endl;
//	}
//};
