#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
using namespace std;


//�Զ����Ƶ���ʽ���ļ�����д��
void WriteBinary()
{
	ofstream ofile; //�����ļ�������
	ofile.open("test.bin", ofstream::out | ofstream::binary); //�Զ�����д��ķ�ʽ��test.bin�ļ�
	char data[] = "2023chr";
	ofile.write(data, strlen(data)); //��data�ַ���д���ļ�
	ofile.put('!'); //���ַ�'!'д���ļ�
	ofile.close(); //�ر��ļ�
}



//�Զ����Ƶ���ʽ���ļ����ж�ȡ
void ReadBinary()
{
	ifstream ifile; //�����ļ�������
	ifile.open("test.bin", ofstream::in | ofstream::binary); //�Զ����ƶ�ȡ�ķ�ʽ��test.bin�ļ�
	ifile.seekg(0, ifile.end); //��ת���ļ�ĩβ
	int length = ifile.tellg(); //��ȡ��ǰ�ַ����ļ����е�λ�ã����ļ����ַ�����
	ifile.seekg(0, ifile.beg); //���»ص��ļ���ͷ
	char data[100];
	ifile.read(data, length); //���ļ����е�����ȫ����ȡ���ַ���data����
	ifile.close(); //�ر��ļ�
}



//���ı�����ʽ���ļ�����д��
void WriteTxt()
{
	ofstream ofile; //�����ļ�������
	ofile.open("test.txt"); //��д��ķ�ʽ��test.txt�ļ�
	char data[] = "2023chr";
	ofile.write(data, strlen(data)); //��data�ַ���д���ļ�
	ofile.put('!'); //���ַ�'!'д���ļ�
	ofile.close(); //�ر��ļ�
}


//���ı�����ʽ���ļ����ж�ȡ
void ReadTxt()
{
	ifstream ifile; //�����ļ�������
	ifile.open("test.txt"); //�Զ�ȡ�ķ�ʽ��test.txt�ļ�
	ifile.seekg(0, ifile.end); //��ת���ļ�ĩβ
	int length = ifile.tellg(); //��ȡ��ǰ�ַ����ļ����е�λ�ã����ļ����ַ�����
	ifile.seekg(0, ifile.beg); //���»ص��ļ���ͷ
	char data[100];
	ifile.read(data, length); //���ļ����е�����ȫ����ȡ���ַ���data����
	cout << length << endl;
	cout << data << endl;
	ifile.close(); //�ر��ļ�
}


//���ļ�����д�����
void WriteFile()
{
	ofstream ofs("data.txt"); //�����ļ������󣬲����ļ�
	ofs << "2023chr!"; //�ַ��������롱�ļ�
	ofs.close(); //�ر��ļ�
}



//���ļ����ж�ȡ����
void ReadFile()
{
	ifstream ifs("data.txt"); //�����ļ������󣬲����ļ�
	char data[100];
	ifs >> data; //�ļ����ݡ����롱�ַ���data
	ifs.close(); //�ر��ļ�
}


int main()
{
	//string rets;
	//stringstream s;
	//s << "2023" << "chr"; //������ַ�������stringstream��
	//s >> rets; //��ʽһ��ȡ
	//cout << rets << endl;
	//s.str(""); //��stringstream�ײ�����string��������Ϊ���ַ���
	//s.clear(); //���ϴ�ת��״̬��յ�
	//s << "Thanks" << " " << "for" << " " << "reading"; //������ַ�������stringstream��
	//rets = s.str(); //��ʽ����ȡ
	//cout << rets << endl;
	//return 0;



	int a = 10;
	string sa;
	stringstream s;
	s << a; //��int���͵�a����������
	s >> sa; //��s�г�ȡǰ������int���͵�ֵ����ֵ��string���ͣ���ʽһ��
	cout << sa << endl;
	s.str(""); //��stringstream�ײ�����string��������Ϊ""��
	s.clear(); //���ϴ�ת��״̬��յ�
	//������һ��ת��
	double b = 3.14;
	s << b;
	sa = s.str(); //��ȡstringstream�й����string���ͣ���ʽ����
	cout << sa << endl;
	return 0;
}