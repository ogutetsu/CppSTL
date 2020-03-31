#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;


void CopySample()
{
	std::vector<int> vec{ 0,1,2,3,4,5,6,7,9 };
	std::vector<int> vec2(10);
	std::copy_if(vec.begin(), vec.end(), vec2.begin() + 3,
	             [](int a) {return a % 2; });

	for (auto v : vec2) cout << v << " ";
	cout << endl;

	std::string str{ "abcdefghijk" };
	std::string str2{ "--------------" };

	std::copy_backward(str.begin(), str.end(), str2.end());

	cout << "str2 : " << str2 << endl;

	std::copy_backward(str.begin(), str.begin() + 5, str.end());
	cout << "str : " << str << endl;
}

void ModifyMain()
{
	CopySample();
}

