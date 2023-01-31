#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
//
////namespace chr
////{
////	//ģ��ʵ��string��
////	class string
////	{
////	public:
////		//[]��������أ��ɶ���д��
////		char& operator[](size_t i)
////		{
////			assert(i < _size); //����±�ĺϷ���
////			return _str[i]; //���ض�Ӧ�ַ�
////		}
////		//...
////	private:
////		char* _str;       //�洢�ַ���
////		size_t _size;     //��¼�ַ�����ǰ����Ч����
////		//...
////	};
////}
////int main()
////{
////	chr::string s("hello");
////	s[3] = 'x';    //���÷��أ�֧���ⲿ�޸�
////	return 0;
////}
////
////
////int main()
////{
////	//���µ�p��b��c��*p������ֵ
////	int* p = new int(0);
////	int b = 1;
////	const int c = 2;
////
////	//���¼����Ƕ�������ֵ����ֵ����
////	int*& rp = p;
////	int& rb = b;
////	const int& rc = c;
////	int& pvalue = *p;
////	return 0;
////}
//
//
//
//
//
//namespace chr
//{
//	//ģ��ʵ��string��
//	class string
//	{
//	public:
//		//[]��������أ��ɶ���д��
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //����±�ĺϷ���
//			return _str[i]; //���ض�Ӧ�ַ�
//		}
//		//...
//	private:
//		char* _str;       //�洢�ַ���
//		size_t _size;     //��¼�ַ�����ǰ����Ч����
//		//...
//	};
//}
////int main()
////{
////	chr::string s("hello");
////	s[3] = 'x';    //���÷��أ�֧���ⲿ�޸�
////	return 0;
////}
//
//
////int main()
////{
////	//���µ�p��b��c��*p������ֵ
////	int* p = new int(0);
////	int b = 1;
////	const int c = 2;
////
////	//���¼����Ƕ�������ֵ����ֵ����
////	int*& rp = p;
////	int& rb = b;
////	const int& rc = c;
////	int& pvalue = *p;
////	return 0;
////}
//
//
//namespace chr
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str; //�����ַ����е�һ���ַ��ĵ�ַ
//		}
//		iterator end()
//		{
//			return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
//		}
//		//���캯��
//		string(const char* str = "")
//		{
//			_size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
//			_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
//			_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
//			strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
//		}
//		//�����������������
//		void swap(string& s)
//		{
//			//���ÿ����swap
//			::swap(_str, s._str); //�������������C�ַ���
//			::swap(_size, s._size); //������������Ĵ�С
//			::swap(_capacity, s._capacity); //�����������������
//		}
//		//�������캯�����ִ�д����
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//
//			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
//			swap(tmp); //��������������
//		}
//		//��ֵ��������أ��ִ�д����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- ���" << endl;
//
//			string tmp(s); //��s�������������tmp
//			swap(tmp); //��������������
//			return *this; //������ֵ��֧��������ֵ��
//		}
//		//��������
//		~string()
//		{
//			delete[] _str;  //�ͷ�_strָ��Ŀռ�
//			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
//			_size = 0;      //��С��0
//			_capacity = 0;  //������0
//		}
//		//[]���������
//		char& operator[](size_t i)
//		{
//			assert(i < _size); //����±�ĺϷ���
//			return _str[i]; //���ض�Ӧ�ַ�
//		}
//		//�ı���������С����
//		void reserve(size_t n)
//		{
//			if (n > _capacity) //��n���ڶ���ǰ����ʱ����ִ�в���
//			{
//				char* tmp = new char[n + 1]; //�࿪һ���ռ����ڴ��'\0'
//				strncpy(tmp, _str, _size + 1); //������ԭ����C�ַ�����������������'\0'��
//				delete[] _str; //�ͷŶ���ԭ���Ŀռ�
//				_str = tmp; //���¿��ٵĿռ佻��_str
//				_capacity = n; //�������Ÿı�
//			}
//		}
//		//β���ַ�
//		void push_back(char ch)
//		{
//			if (_size == _capacity) //�ж��Ƿ���Ҫ����
//			{
//				reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
//			}
//			_str[_size] = ch; //���ַ�β�嵽�ַ���
//			_str[_size + 1] = '\0'; //�ַ����������'\0'
//			_size++; //�ַ����Ĵ�С��һ
//		}
//		//+=���������
//		string& operator+=(char ch)
//		{
//			push_back(ch); //β���ַ���
//			return *this; //������ֵ��֧������+=��
//		}
//		//����C���͵��ַ���
//		const char* c_str()const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//
//void func1(chr::string s)
//{}
//void func2(const chr::string& s)
//{}
//int main()
//{
//	chr::string s("hello world");
//	func1(s);  //ֵ����
//	func2(s);  //��ֵ���ô���
//
//	s += 'X';  //��ֵ���÷���
//	return 0;
//}
//
//
//namespace chr
//{
//	chr::string to_string(int value)
//	{
//		bool flag = true;
//		if (value < 0)
//		{
//			flag = false;
//			value = 0 - value;
//		}
//		chr::string str;
//		while (value > 0)
//		{
//			int x = value % 10;
//			value /= 10;
//			str += (x + '0');
//		}
//		if (flag == false)
//		{
//			str += '-';
//		}
//		std::reverse(str.begin(), str.end());
//		return str;
//	}
//}
//
//int main()
//{
//	chr::string s = chr::to_string(1234);
//	return 0;
//}
//
//
//namespace chr
//{
//	class string
//	{
//	public:
//		//�ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
//
//int main()
//{
//	chr::string s = chr::to_string(1234);
//	return 0;
//}
//
////namespace chr
////{
////	class string
////	{
////	public:
////		//�ƶ���ֵ
////		string& operator=(string&& s)
////		{
////			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
////			swap(s);
////			return *this;
////		}
////	private:
////		char* _str;
////		size_t _size;
////		size_t _capacity;
////	};
////}


namespace chr
{
    class string
    {
    public:
        typedef char* iterator;
        iterator begin()
        {
            return _str; //�����ַ����е�һ���ַ��ĵ�ַ
        }
        iterator end()
        {
            return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
        }
        //���캯��
        string(const char* str = "")
        {
            _size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
            _capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
            _str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
            strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
        }
        //�����������������
        void swap(string& s)
        {
            //���ÿ����swap
            ::swap(_str, s._str); //�������������C�ַ���
            ::swap(_size, s._size); //������������Ĵ�С
            ::swap(_capacity, s._capacity); //�����������������
        }
        //�������캯�����ִ�д����
        string(const string& s)
            :_str(nullptr)
            , _size(0)
            , _capacity(0)
        {
            cout << "string(const string& s) -- ���" << endl;

            string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
            swap(tmp); //��������������
        }
        //��ֵ��������أ��ִ�д����
        string& operator=(const string& s)
        {
            cout << "string& operator=(const string& s) -- ���" << endl;

            string tmp(s); //��s�������������tmp
            swap(tmp); //��������������
            return *this; //������ֵ��֧��������ֵ��
        }
        //��������
        ~string()
        {
            delete[] _str;  //�ͷ�_strָ��Ŀռ�
            _str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
            _size = 0;      //��С��0
            _capacity = 0;  //������0
        }
        //[]���������
        char& operator[](size_t i)
        {
            assert(i < _size); //����±�ĺϷ���
            return _str[i]; //���ض�Ӧ�ַ�
        }
        //�ı���������С����
        void reserve(size_t n)
        {
            if (n > _capacity) //��n���ڶ���ǰ����ʱ����ִ�в���
            {
                char* tmp = new char[n + 1]; //�࿪һ���ռ����ڴ��'\0'
                strncpy(tmp, _str, _size + 1); //������ԭ����C�ַ�����������������'\0'��
                delete[] _str; //�ͷŶ���ԭ���Ŀռ�
                _str = tmp; //���¿��ٵĿռ佻��_str
                _capacity = n; //�������Ÿı�
            }
        }
        //β���ַ�
        void push_back(char ch)
        {
            if (_size == _capacity) //�ж��Ƿ���Ҫ����
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
            }
            _str[_size] = ch; //���ַ�β�嵽�ַ���
            _str[_size + 1] = '\0'; //�ַ����������'\0'
            _size++; //�ַ����Ĵ�С��һ
        }
        //+=���������
        string& operator+=(char ch)
        {
            push_back(ch); //β���ַ���
            return *this; //������ֵ��֧������+=��
        }
        //����C���͵��ַ���
        const char* c_str()const
        {
            return _str;
        }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}


void func1(chr::string s)
{}
void func2(const chr::string& s)
{}

int main()
{
    chr::string s("hello world");
    func1(s);  //ֵ����
    func2(s);  //��ֵ���ô���

    s += 'X';  //��ֵ���÷���
    return 0;
}
