template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 4)
		:_a(nullptr)
		,_capacity(0)
		,_top(0)
	{
		if (capacity > 0)
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
	}


	~Stack()
	{
		delete []_a;
		_a = nullptr;
		_capacity = _top = 0;
	}


	void Push(const T& x)
	{
		if (_top == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
			T* tmp = new T[newcapacity];
			if (_a)
			{
				memcpy(tmp, _a, sizeof(T) * _top);
				delete[]_a;
			}

			_a = tmp;
			_capacity = newcapacity;
		}

		_a[_top] = x;
		++_top;
	}

	void Pop()
	{
		assert(_top > 0);
		--_top;
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
	T* _a;
	size_t _top;
	size_t _capacity;
};


// 模板不支持分离编译。 声明放在.h  定义放在.cpp -- 原因：模板进阶再讲解
// 模板在同一个文件中，是可以声明和定义分离的
//template<class T>
//void Stack<T>::Push(const T& x)


int main()
{
	try
			{
				// 类模板都是显示实例化
				// 虽然他们用了一个类模板，但是Stack<int>，Stack<char> 两个类型
				//Stack<int> st1;
				//Stack<char> st2;
		
				//// 知道我要存100个数据，避免插入时扩容消耗
				//Stack<int> st3(100);
				//Stack<int> st4(0);
		
				////Stack<Date> st4;
		
				Stack<int> st1;
				st1.Push(1);
				st1.Push(2);
				st1.Push(3);
				st1.Push(4);
				st1.Push(5);
		
				//st1.Top()++;
				//st1.Top() *= 2;
		
				while (!st1.Empty())
				{
					cout << st1.Top() << " ";
					st1.Pop();
				}
			cout << endl;
		
				//Stack<> st2;
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}
		
			return 0;
}