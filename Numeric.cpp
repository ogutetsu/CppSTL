#include <array>
#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;

void NumericMain()
{

	std::array<int, 9> ar{ 1,2,3,4,5,6,7,8,9 };
	cout << std::accumulate(ar.begin(), ar.end(), 0) << endl;
	cout << std::accumulate(ar.begin(), ar.end(), 1,
		[](int a, int b) { return a * b; }) << endl;

	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> myVec;
	std::adjacent_difference(vec.begin(), vec.end(),
		std::back_inserter(myVec), [](int a, int b) { return a * b; });
	for (auto v : myVec) cout << v << " ";
	cout << endl;
	cout << std::inner_product(vec.begin(), vec.end(), ar.begin(), 0) << endl;
	
	myVec = {};
	std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
	for (auto v : myVec) cout << v << " ";
	cout << endl;

	myVec.resize(10);
	std::iota(myVec.begin(), myVec.end(), 1000);
	for (auto v : myVec) cout << v << " ";
	cout << endl;


	
}

