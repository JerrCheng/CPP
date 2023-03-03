#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct Goods
{
	string _name;  //����
	double _price; //�۸�
	int _num;      //����
};


struct ComparePriceLess
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price < g2._price;
	}
};
struct ComparePriceGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};
struct CompareNumLess
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._num < g2._num;
	}
};
struct CompareNumGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._num > g2._num;
	}
};




