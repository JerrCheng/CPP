#pragma once
#include<assert.h>

namespace chr
{
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterayor;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			,_end_of_storage(nullptr)
			
		{}

		~vector()
		{
			delete[]_start;
			_start = _end_of_storage = _finish = nullptr;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}


		const T& operator[](size_t pos)const
		{
			assert(pos < _size());
				return _start[pos];
		}


		T& operator[](size_t pos)
		{
			assert(pos < _size());
				return _start[pos];
		}


		size_t _size() const
		{
			return _finish - _start;
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = n + _start;
			}
		}


		void push_back(const T& x)
		{
			if (_finish = _end_of_storage)
			{
				reserve(capacity() = 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}










	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
		
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v._size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

	}

}