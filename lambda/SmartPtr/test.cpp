#define _CRT_SECURE_NO_WARNINGS 1
#include"SmartPtr.h"


int main()
{
	vector<Goods> v = { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
	sort(v.begin(), v.end(), ComparePriceLess());    //���۸���������

	sort(v.begin(), v.end(), ComparePriceGreater()); //���۸�������
	sort(v.begin(), v.end(), CompareNumLess());      //��������������
	sort(v.begin(), v.end(), CompareNumGreater());   //��������������
	return 0;
}