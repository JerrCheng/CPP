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

			//��������
			~vector()
		{
			if (_start) //����Կ�ָ������ͷ�
			{
				delete[] _start; //�ͷ������洢���ݵĿռ�
				_start = nullptr; //_start�ÿ�
				_finish = nullptr; //_finish�ÿ�
				_endofstorage = nullptr; //_endofstorage�ÿ�
			}
		}

	};

}



