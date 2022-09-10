#pragma once
#include<string>
#include<assert.h>
#include<iostream>
#include<list>
using namespace std;

namespace bit
{
	class string
	{

	public:
		string(const char* str)
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capacity(strlen(str))
		{
			strcpy(_str, str);
		}


		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}




		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}


	private:
		size_t  _capacity;
		size_t _size;
		char* _str;

	};
}