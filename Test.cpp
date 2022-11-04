#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};



//int main()
//{
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail:");
//	}
//	new (p2)A(10);
//	return 0;
//}

//template<class T>
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//
//int main()
//{
//	int i = 2;
//	int j = 3;
//	Swap(i, j);
//	return 0;
//}

template<typename T>
class Stack
{
public:
	//初始化列表
	Stack(size_t capacity = 4)
		:_a(nullptr)
		, _top(0)
		, _capacity(0)

	{
		if (capacity > 0)
		{
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}

	void Push(const T& x)
	{
		if (_capacity == _top)
		{
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;

			//开辟新空间，如果失败，抛异常，转到try catch
			T* tmp = new T[newCapacity];
			if (_a)
			{
				memcpy(tmp, _a, sizeof(T) * _top);
				delete[]_a;

			}
			_a = tmp;
			_capacity = newCapacity;
		}
		_a[_top] = x;
		++_top;
	}

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}


	//析构
	~Stack()
	{
		delete[]_a;
		_a= nullptr;
		_top = _capacity = 0;
	}

	bool Empty()
	{
		return _top == 0;
	}

	const T& Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}

private:
	size_t _top;
	size_t _capacity;
	T* _a;
};

int main()
{
	try
	{
		//类模板都是显示实例化
		Stack<int> s1;
		s1.Push(1);
		s1.Push(2);
		s1.Push(3);
		s1.Push(4);
		s1.Push(5);

		s1.Top();
		
		while (!s1.Empty())
		{
			cout << s1.Top() << " ";
			s1.Pop();
		}
		cout << endl;


	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}