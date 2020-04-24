#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>


using std::cout;
using std::endl;




template<typename T>
T StringTo(const std::string& source)
{
	std::istringstream iss(source);
	T ret;
	iss >> ret;
	return ret;
}

template<typename T>
std::string ToString(const T& n)
{
	std::ostringstream oss;
	oss << n;
	return oss.str();
	
}


void SStreamSample()
{
	std::stringstream ss;
	ss << "New String";
	cout << ss.str() << endl;
	ss.str("Another new String");
	cout << ss.str() << endl;

	cout << "5= " << StringTo<int>("5") << endl;
	cout << "5 + 6= " << StringTo<int>("5") + 6 << endl;
	cout << ToString(StringTo<int>("5") + 6) << endl;
	cout << "5e10: " << std::fixed << StringTo<double>("5e10") << endl;
}

void RandomAccessSample()
{
	std::function<void(const std::string)> writeFile = [](const std::string name)
	{
		std::ofstream outFile(name);
		if(!outFile)
		{
			std::cerr << "Could not open file " << name << endl;
		}
		else
		{
			for(unsigned int i = 0; i < 10; i++)
			{
				outFile << i << "       0123456789" << endl;
			}
		}
	};


	cout << std::dec;
	std::string line;

	std::string randTxt{ "random.txt" };
	writeFile(randTxt);
	std::ifstream inFile(randTxt);
	if(inFile)
	{
		cout << "=== inFile.rdbuf() === " << endl;
		cout <<  inFile.rdbuf() << endl;
		cout << "inFile.tellg() : " << inFile.tellg() << endl;

		inFile.seekg(0);
		std::getline(inFile, line);
		cout << line << endl;

		inFile.seekg(20, std::ios::cur);
		std::getline(inFile, line);
		cout << line << endl;

		inFile.seekg(-20, std::ios::end);
		std::getline(inFile, line);
		cout << line << endl;

		
	}
}

void StringStreamMain()
{
	SStreamSample();

	RandomAccessSample();
	
		
}

