#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
//};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��



//void Func(Person& p)
//{
//	//ͨ����������õ����麯��
//	p.BuyTicket();
//}
//void Func(Person* p)
//{
//	//ͨ�������ָ������麯��
//	p->BuyTicket();
//}



////����
//class A
//{};
////����
//class B : public A
//{};
////����
//class Person
//{
//public:
//	//���ػ���A��ָ��
//	virtual A* fun()
//	{
//		cout << "A* Person::f()" << endl;
//		return new A;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	//��������B��ָ��
//	virtual B* fun()
//	{
//		cout << "B* Student::f()" << endl;
//		return new B;
//	}
//};



//
//int main()
//{
//	Person p;   //��ͨ��
//	Student st; //ѧ��
//	Soldier sd; //����
//
//	Func(p);  //��Ʊ-ȫ��
//	Func(st); //��Ʊ-���
//	Func(sd); //������Ʊ
//
//	Func(&p);  //��Ʊ-ȫ��
//	Func(&st); //��Ʊ-���
//	Func(&sd); //������Ʊ
//	return 0;
//}

////����
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
////����
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
//	//�ֱ�newһ����������������󣬲����ø���ָ��ָ������
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//ʹ��delete���������������ͷŶ���ռ�
//	delete p1;
//	delete p2;
//	return 0;
//}


////����
//class Person
//{
//public:
//	//��final���Σ����麯�������ٱ���д
//	virtual void BuyTicket() final
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	//��д�����뱨��
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//};
////����
//class Soldier : public Person
//{
//public:
//	//��д�����뱨��
//	virtual void BuyTicket()
//	{
//		cout << "����-��Ʊ" << endl;
//	}
//};
