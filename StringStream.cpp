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

void StringStreamMain()
{
	SStreamSample();
}

