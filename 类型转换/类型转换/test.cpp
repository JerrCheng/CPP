#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething: " << i << endl;
//	return 0;
//}

//int main()
//{
//	FUNC f = reinterpret_cast<FUNC>(DoSomething);
//	f();
//	return 0;
//}

class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};


int main()
{
	A a1(1);
	//A a2 = 1; //error
	return 0;
}

