#include <algorithm>
#include <iostream>
#include <cctype>
#include <chrono>
#include <random>
#include <vector>
#include <string>

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

void RemoveSample()
{
	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	auto it = std::remove_if(vec.begin(), vec.end(),
	                         [](int a) {return a % 2; });
	for (auto v : vec) cout << v << " ";
	cout << endl;

	vec.erase(it, vec.end());
	for (auto v : vec) cout << v << " ";
	cout << endl;

	std::string str{ "Only for Testing Purpose" };
	str.erase(std::remove_if(str.begin(), str.end(),
	                         [](char c) { return std::isupper(c); }));

	cout << str << endl;
}


int getNext()
{
	static int next{ 0 };
	return ++next;
}


void GenerateSample()
{
	std::vector<int> vec(10);
	std::fill(vec.begin(), vec.end(), 2011);
	for (auto v : vec) cout << v << " ";
	cout << endl;
	
	std::generate_n(vec.begin(), 5, getNext);
	for (auto v : vec) cout << v << " ";
	cout << endl;
}

void MoveSample()
{
	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec2(vec.size());
	std::move(vec.begin(), vec.end(), vec2.begin());
	for (auto v : vec2) cout << v << " ";
	cout << endl;

	std::string str{ "abcdefghijk" };
	std::string str2{ "------------------" };
	std::move_backward(str.begin(), str.end(), str2.end());
	cout << str2 << endl;
}

void RangeSample()
{
	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec2(9);
	std::swap(vec, vec2);
	cout << "vec : ";
	for (auto v : vec) cout << v << " ";
	cout << endl;
	cout << "vec2 : ";
	for (auto v : vec2) cout << v << " ";
	cout << endl;

	std::string str{ "abcdefghijk" };
	std::string str2{ "-----------" };
	std::swap_ranges(str.begin(), str.begin() + 5, str2.begin() + 5);
	cout << "str  : " << str << endl;
	cout << "str2 : " << str2 << endl;
}

void TransformSample()
{
	std::string str{ "abcdefghijklmnopqrstuvwxyz" };
	std::transform(str.begin(), str.end(), str.begin(),
	               [](char c) { return std::toupper(c); });

	cout << str << endl;

	std::vector<std::string> vecStr{ "Only", "for", "testing", "purpose" };
	std::vector<std::string> vecStr2(4, "-");
	std::vector<std::string> vecRes;
	std::transform(vecStr.begin(), vecStr.end(),
	               vecStr2.begin(), std::back_inserter(vecRes),
	               [](std::string a, std::string b) {return std::string(b) + a + b; });
	for (auto v : vecRes) cout << v << " ";
	cout << endl;
}

void ReverseSample()
{
	std::string str{ "123456789" };
	std::reverse(str.begin(), str.begin() + 5);
	cout << str << endl;
}

void RotateSample()
{
	std::string str{ "12345" };
	for(auto i = 0; i < str.size(); i++)
	{
		std::string tmp{ str };
		std::rotate(tmp.begin(), tmp.begin() + i, tmp.end());
		cout << tmp << " ";
	}
	cout << endl;
}

void ShuffleSample()
{
	std::vector<int> vec1{ 0,1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec2(vec1);
	std::mt19937 mt;
	std::shuffle(vec1.begin(), vec1.end(), mt);
	//std::random_shuffle(vec1.begin(), vec1.end());
	for (auto v : vec1) cout << v << " ";
	cout << endl;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(vec2.begin(), vec2.end(), std::default_random_engine(seed));
	for (auto v : vec2) cout << v << " ";
	cout << endl;
}

void UniqueSample()
{
	std::vector<int> vec{ 0,0,1,1,2,2,3,4,4,5,3,6,7,8,9,9,2,1 };
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	for (auto v : vec) cout << v << " ";
	cout << endl;

	std::vector<int> vec2{ 1,4,3,3,3,5,9,8,0,2,4,5,7,1,8,8,6,3,2,4 };
	std::vector<int> resVec;
	resVec.reserve((vec2.size()));
	std::unique_copy(vec2.begin(), vec2.end(), std::back_inserter(resVec),
	                 [](int a, int b) {return (a % 2) == (b % 2); });
	for (auto v : vec2) cout << v << " ";
	cout << endl;
	for (auto v : resVec) cout << v << " ";
	cout << endl;
}

void ModifyMain()
{
	CopySample();

	ReplaceMain();

	RemoveSample();

	GenerateSample();

	MoveSample();

	RangeSample();

	TransformSample();

	ReverseSample();
	
	RotateSample();

	ShuffleSample();

	UniqueSample();

	
}

