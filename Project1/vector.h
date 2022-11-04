#pragma once
#include<iostream>

namespace chr
{
	template <class T>
	class vector
	{
			vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

			//析构函数
			~vector()
		{
			if (_start) //避免对空指针进行释放
			{
				delete[] _start; //释放容器存储数据的空间
				_start = nullptr; //_start置空
				_finish = nullptr; //_finish置空
				_endofstorage = nullptr; //_endofstorage置空
			}
		}

	};

}



