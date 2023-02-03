#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}


void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}


void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}



void TestHeapSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}


void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArry(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	QuickSort(a, 0,9);
	PrintArry(a, sizeof(a) / sizeof(int));
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	return 0;
}