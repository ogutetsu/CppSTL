#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>


using std::cout;
using std::endl;

int toInt(const std::string& s)
{
	std::stringstream buff;
	buff.str("");
	buff << s;
	int value;
	buff >> value;
	return value;
;}

void MinMaxElementMain()
{
	std::vector<std::string> myStr{ "94", "3", "55", "-4", "100", "1010", "-78", "6", "-94" };
	auto str = std::minmax_element(myStr.begin(), myStr.end());
	cout << *str.first << ":" << *str.second << endl;

	auto val = std::minmax_element(myStr.begin(), myStr.end(),
		[](std::string a, std::string b) {return toInt(a) < toInt(b); });
	cout << *val.first << ":" << *val.second << endl;
	
}
