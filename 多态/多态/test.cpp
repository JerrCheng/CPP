#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};

class Student : public Person {
public:
	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
	// ��������д���������ع�ϵ
	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};

class Soldier : public Person{
public:
	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
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
