#include <fstream>
#include <functional>
#include <string>
#include <iostream>
#include <vector>

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

void StringSizeSample()
{
	std::function<void(const std::string&)> stringInfo = 
		[](const std::string& s)
	{
		cout << s << " : ";
		cout << s.size() << " ";
		cout << s.capacity() << " ";
		cout << s.max_size() << " ";
		cout << endl;
	};

	std::string str;
	stringInfo(str);

	str += "123345";
	stringInfo(str);

	str.resize(30);
	stringInfo(str);

	str.reserve(100);
	stringInfo(str);
	
	str.shrink_to_fit();
	stringInfo(str);
}

void StringCompareSample()
{
	std::string first{ "aaa" };
	std::string second{ "aaaa" };

	cout << (first < second) << endl;
	cout << (first <= first) << endl;
}

void StringAccessSample()
{
	std::string str = { "0123456789" };
	cout << "str.front() : " << str.front() << endl;
	cout << "str.back() : " << str.back() << endl;
	cout << "str[0] : "<< str[0] << " str[1] : " << str[1] << endl;

	cout << "*(&str[0] + 5) : " << *(&str[0] + 5) << endl;
}

void StringInputOutputSample()
{
	std::function<void(const char*)> writeFile =
		[](const char* fileName)
	{
		std::ofstream file(fileName);
		if(!file)
		{
			std::cerr << "Could not open the file " << fileName << ".";
			exit(EXIT_FAILURE);
		}
		
		std::vector<std::string> lines;
		lines.push_back(std::string("sample"));
		lines.push_back(std::string("file"));
		for (auto v : lines) file << v << endl;
		
		
	};

	std::function<std::vector<std::string>(const char*)> readFile =
		[](const char* fileName)
	{
		std::ifstream file(fileName);
		if (!file)
		{
			std::cerr << "Could not open the file " << fileName << ".";
			exit(EXIT_FAILURE);
		}
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(file, line)) lines.push_back(line);
		
		return lines;
	};


	std::string fileName("stringIO.txt");
	
	writeFile(fileName.c_str());

	std::vector<std::string> lines = readFile(fileName.c_str());
	int num = 0;
	for (auto v : lines) cout << ++num << ": " << v << endl;
	cout << endl;
}

void StringFindSample()
{
	std::string str;
	auto idx = str.find("a");
	if (idx == std::string::npos) cout << "string::npos" << endl;

	str = { "abcdef123456789abcdefghijklmn" };
	std::string str2{ "12" };

	cout << "str : " << str << endl;
	
	cout << "str.find('b') : " << str.find('b') << endl;
	cout << "str.rfind('b') : "<< str.rfind('b') << endl;
	cout << "str.find(str2) : " << str.find(str2) << endl;
	
	cout << "str.find_first_of(\"345\") : " << str.find_first_of("345") << endl;
	cout << "str.find_last_of(\"345\") : " << str.find_last_of("345") << endl;
	cout << "str.find_first_of(\"145\") : " << str.find_first_of("145") << endl;
	cout << "str.find_first_not_of(\"345\") : " << str.find_first_not_of("345") << endl;
	cout << "str.find_last_not_of(\"345\") : " << str.find_last_not_of("345") << endl;
}

void StringMain()
{
	StringConstructorSample();

	CStringConvertSample();

	StringSizeSample();

	StringCompareSample();


	StringAccessSample();

	StringInputOutputSample();


	StringFindSample();

	
}
