#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
using namespace std;


//以二进制的形式对文件进行写入
void WriteBinary()
{
	ofstream ofile; //定义文件流对象
	ofile.open("test.bin", ofstream::out | ofstream::binary); //以二进制写入的方式打开test.bin文件
	char data[] = "2023chr";
	ofile.write(data, strlen(data)); //将data字符串写入文件
	ofile.put('!'); //将字符'!'写入文件
	ofile.close(); //关闭文件
}



//以二进制的形式对文件进行读取
void ReadBinary()
{
	ifstream ifile; //定义文件流对象
	ifile.open("test.bin", ofstream::in | ofstream::binary); //以二进制读取的方式打开test.bin文件
	ifile.seekg(0, ifile.end); //跳转到文件末尾
	int length = ifile.tellg(); //获取当前字符在文件当中的位置，即文件的字符总数
	ifile.seekg(0, ifile.beg); //重新回到文件开头
	char data[100];
	ifile.read(data, length); //将文件当中的数据全部读取到字符串data当中
	ifile.close(); //关闭文件
}



//以文本的形式对文件进行写入
void WriteTxt()
{
	ofstream ofile; //定义文件流对象
	ofile.open("test.txt"); //以写入的方式打开test.txt文件
	char data[] = "2023chr";
	ofile.write(data, strlen(data)); //将data字符串写入文件
	ofile.put('!'); //将字符'!'写入文件
	ofile.close(); //关闭文件
}


//以文本的形式对文件进行读取
void ReadTxt()
{
	ifstream ifile; //定义文件流对象
	ifile.open("test.txt"); //以读取的方式打开test.txt文件
	ifile.seekg(0, ifile.end); //跳转到文件末尾
	int length = ifile.tellg(); //获取当前字符在文件当中的位置，即文件的字符总数
	ifile.seekg(0, ifile.beg); //重新回到文件开头
	char data[100];
	ifile.read(data, length); //将文件当中的数据全部读取到字符串data当中
	cout << length << endl;
	cout << data << endl;
	ifile.close(); //关闭文件
}


//对文件进行写入操作
void WriteFile()
{
	ofstream ofs("data.txt"); //定义文件流对象，并打开文件
	ofs << "2023chr!"; //字符串“流入”文件
	ofs.close(); //关闭文件
}



//对文件进行读取操作
void ReadFile()
{
	ifstream ifs("data.txt"); //定义文件流对象，并打开文件
	char data[100];
	ifs >> data; //文件数据“流入”字符串data
	ifs.close(); //关闭文件
}


int main()
{
	//string rets;
	//stringstream s;
	//s << "2023" << "chr"; //将多个字符串放入stringstream中
	//s >> rets; //方式一获取
	//cout << rets << endl;
	//s.str(""); //将stringstream底层管理的string对象设置为空字符串
	//s.clear(); //将上次转换状态清空掉
	//s << "Thanks" << " " << "for" << " " << "reading"; //将多个字符串放入stringstream中
	//rets = s.str(); //方式二获取
	//cout << rets << endl;
	//return 0;



	int a = 10;
	string sa;
	stringstream s;
	s << a; //将int类型的a放入输入流
	s >> sa; //从s中抽取前面插入的int类型的值，赋值给string类型（方式一）
	cout << sa << endl;
	s.str(""); //将stringstream底层管理的string对象设置为""。
	s.clear(); //将上次转换状态清空掉
	//进行下一次转换
	double b = 3.14;
	s << b;
	sa = s.str(); //获取stringstream中管理的string类型（方式二）
	cout << sa << endl;
	return 0;
}