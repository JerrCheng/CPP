#define _CRT_SECURE_NO_WARNINGS 1
#include"SmartPtr.h"


int main()
{
	vector<Goods> v = { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
	sort(v.begin(), v.end(), ComparePriceLess());    //按价格升序排序

	sort(v.begin(), v.end(), ComparePriceGreater()); //按价格降序排序
	sort(v.begin(), v.end(), CompareNumLess());      //按数量升序排序
	sort(v.begin(), v.end(), CompareNumGreater());   //按数量降序排序
	return 0;
}