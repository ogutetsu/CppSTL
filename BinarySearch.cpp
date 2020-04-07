#include <iostream>
#include <algorithm>
#include <vector>


using std::cout;
using std::endl;

bool isLessAbs(int a, int b)
{
	return abs(a) < abs(b);
}


void BinarySearchMain()
{
	std::vector<int> vec{-3,1,-3,2,-3,5,-2,7,-7,9,-6,0,1,2,-5,8};

	std::sort(vec.begin(), vec.end(), isLessAbs);
	for (auto v : vec) cout << v << " ";
	cout << endl;

	cout << std::binary_search(vec.begin(), vec.end(), -5, isLessAbs) << endl;
	cout << std::binary_search(vec.begin(), vec.end(), 5, isLessAbs) << endl;

	auto pair = std::equal_range(vec.begin(), vec.end(), 3, isLessAbs);
	cout << std::distance(vec.begin(), pair.first) << endl;
	cout << std::distance(vec.begin(), pair.second)-1 << endl;
	
	for (auto threeIt = pair.first; threeIt != pair.second; ++threeIt)
		cout << *threeIt << " ";
	cout << endl;
	
	
	
}

