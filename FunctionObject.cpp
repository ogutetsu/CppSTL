#include <algorithm>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;



struct Square
{
	void operator()(int& i) { i = i * i; }
};


void FunctionObjectMain()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(vec.begin(), vec.end(), Square());
	for (auto v : vec) cout << v << " ";
	cout << endl;
	
	std::vector<int> vec1{ 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(vec1.begin(), vec1.end(), [](int& i) { i = i * i; });
	
	for (auto v : vec1) cout << v << " ";
	cout << endl;
}

