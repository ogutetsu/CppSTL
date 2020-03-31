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

void ReplaceMain()
{
	std::string str{ "Only for testing purpose" };
	std::replace(str.begin(), str.end(), ' ', '1');
	cout << "replace \' \' to \'1\' : " << str << endl;

	std::replace_if(str.begin(), str.end(), [](char c) {return c == '1'; }, '2');
	cout << "replace_if \'1\' to \'2\' : " << str << endl;

	std::string str2;
	std::replace_copy(str.begin(), str.end(), std::back_inserter(str2), '2', '3');
	cout << "replace_copy \'2\' to \'3\' : " << str2 << endl;
	
	std::string str3;
	std::replace_copy_if(str2.begin(), str2.end(),
	                     std::back_inserter(str3), [](char c) { return c == '3'; }, '4');
	cout << "replace_copy_if \'3\' to \'4\' : " << str3 << endl;
}

void ModifyMain()
{
	CopySample();

	ReplaceMain();

	
}

