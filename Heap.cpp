#include <algorithm>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;

void HeapMain()
{
	std::vector<int> vec{ 4,3,2,1,5,6,7,8,9 };
	std::make_heap(vec.begin(), vec.end());
	for (auto v : vec) cout << v << " ";
	cout << endl;
	cout << std::is_heap(vec.begin(), vec.end()) << endl;

	vec.push_back(100);
	cout << std::is_heap(vec.begin(), vec.end()) << endl;
	cout << *std::is_heap_until(vec.begin(), vec.end()) << endl;
	for (auto v : vec) cout << v << " ";
	cout << endl;

	std::push_heap(vec.begin(), vec.end());
	for (auto v : vec) cout << v << " ";
	cout << endl;

	std::pop_heap(vec.begin(), vec.end());
	for (auto v : vec) cout << v << " ";
	cout << endl;

	cout << vec.front() << endl;
	
	
	
}

