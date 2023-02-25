#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <unordered_set>
#include <time.h>
using namespace std;

int main()
{
	int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(NULL));
	//随机生成N个数字
	for (int i = 0; i < N; i++)
	{
		v.push_back(rand());
	}

	/****************插入效率测试****************/
	//将这N个数插入set容器
	set<int> s;
	clock_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	clock_t end1 = clock();

	//将这N个数插入unordered_set容器
	unordered_set<int> us;
	clock_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	clock_t end2 = clock();

	//分别输出插入set容器和unordered_set容器所用的时间
	cout << "set insert: " << end1 - begin1 << endl;
	cout << "unordered_set insert: " << end2 - begin2 << endl;

	/****************查找效率测试****************/
	//在set容器中查找这N个数
	clock_t begin3 = clock();
	for (auto e : v)
	{
		s.find(e);
	}
	clock_t end3 = clock();

	//在unordered_set容器中查找这N个数
	clock_t begin4 = clock();
	for (auto e : v)
	{
		us.find(e);
	}
	clock_t end4 = clock();

	//分别输出在set容器和unordered_set容器中查找这N个数所用的时间
	cout << "set find: " << end3 - begin3 << endl;
	cout << "unordered_set find: " << end4 - begin4 << endl;

	/****************删除效率测试****************/
	//将这N个数从set容器中删除
	clock_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	clock_t end5 = clock();

	//将这N个数从unordered_set容器中删除
	clock_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	clock_t end6 = clock();

	//分别输出将这N个数从set容器和unordered_set容器中删除所用的时间
	cout << "set erase: " << end5 - begin5 << endl;
	cout << "unordered_set erase: " << end6 - begin6 << endl;
	return 0;
}
