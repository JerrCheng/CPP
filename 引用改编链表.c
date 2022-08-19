typedef struct SeqList
{
	int* a;
	int size;
	int capacity;
}SL;

void SLInit(SL& s, int capacity)
{
	s.a = (int*)malloc(sizeof(int) * capacity);
	assert(s.a);
	// ...
	s.size = 0;
	s.capacity = capacity;
}

void SLPushBack(SL& s, int x)
{
	if (s.size == s.capacity)
	{
		// ...
	}

	s.a[s.size++] = x;
}

int& SLAt(SL& s, int pos)
{
	assert(pos >= 0 && pos <= s.size);

	return s.a[pos];
}




int main()
{
	SL sl;
	SLInit(sl, 4);
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);
	SLPushBack(sl, 4);

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	SLAt(sl, 0)++;

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	SLAt(sl, 0) = 10;

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;


	return 0;
}