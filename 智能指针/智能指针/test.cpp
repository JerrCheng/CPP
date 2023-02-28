#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
	//private:
	int _a1 = 0;
	int _a2 = 0;
};

// 1、RAII
// 2、像指针一样
// 3、拷贝问题 -- > 很多解决方案
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			cout << "Delete:" << _ptr << endl;
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

//int main()
//{
//	SmartPtr<pair<string, int>> sp1(new pair<string, int>("sort", 1));
//	sp1->second++;
//
//	cout << sp1->first << ":" << sp1->second << endl;
//
//	return 0;
//}

namespace chr
{
	// C++98  auto_ptr 管理权转移，被拷贝对象的出现悬空问题
	// 很多公司是明确的要求了不能使用它
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
				{
					cout << "Delete:" << _ptr << endl;
					delete _ptr;
				}

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

	// boost -- 探路者
	// scoped_ptr/shared_ptr/weak_ptr

	// C++11 -- 抄boost库的作业
	// unique_ptr/shared_ptr/weak_ptr

	template<class T>
	class unique_ptr
	{
	private:
		// 防拷贝 C++98
		// 只声明不实现 
		//unique_ptr(unique_ptr<T>& ap);
		//unique_ptr<T>& operator=(unique_ptr<T>& ap);
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		// 防拷贝 C++11
		unique_ptr(unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};



	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(new int(1))
		{}

		void Release()
		{
			if (--(*_pCount) == 0)
			{
				cout << "Delete:" << _ptr << endl;
				delete _ptr;
				delete _pCount;
			}
		}

		~shared_ptr()
		{
			Release();
		}

		// sp1(sp2)
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			(*_pCount)++;
		}

		// sp1 = sp5
		// sp1 = sp1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this == &sp)
			if (_ptr == sp._ptr)
			{
				return *this;
			}

			// 减减被赋值对象的计数，如果是最后一个对象，要释放资源
			/*if (--(*_pCount) == 0)
			{
				delete _ptr;
				delete _pCount;
			}*/
			Release();

			// 共管新资源，++计数
			_ptr = sp._ptr;
			_pCount = sp._pCount;

			(*_pCount)++;

			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;

		// 引用计数
		int* _pCount;
	};
}