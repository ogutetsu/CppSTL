#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;


bool isOdd(int i) { return (i % 2) == 1; }

void PartitionMain()
{
	std::vector<int> vec{1,4,3,5,6,7,9,5,4,0,1,8,6,4,2,3,3,8,1,4};

	auto parPoint = std::partition(vec.begin(), vec.end(), isOdd);
	for (auto v : vec) cout << v << " ";
	cout << endl;

	for (auto v = vec.begin(); v != parPoint; ++v)
		cout << *v << " ";
	cout << endl;

	for (auto v = parPoint; v != vec.end(); ++v)
		cout << *v << " ";
	cout << endl;
	
}
