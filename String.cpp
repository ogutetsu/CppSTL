#include <string>
#include <iostream>

using std::cout;
using std::endl;


void StringConstructorSample()
{
	std::string other{ "123456789" };
	std::string str1(other);
	std::string tmp(other);
	std::string str2(std::move(tmp));
	std::string str3(other.begin(), other.end());
	std::string str4(other, 2);
	std::string str5(other, 2, 5);
	std::string str6("123456789", 5);
	std::string str7(5, '1');
	std::string str8({ '1', '2', '3', '4', '5' });
}

void CStringConvertSample()
{
	std::string str{ "Sample" };
	str += " String";
	cout << str << endl;
	const char* cString = str.c_str();
	char buff[10];
	str.copy(buff, 10);
	str += "works";
	std::string str2(buff, buff + 10);
	cout << str2 << endl;
}

void StringMain()
{
	StringConstructorSample();

	CStringConvertSample();
	

	
}
