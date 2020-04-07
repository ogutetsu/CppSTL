#include <algorithm>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;


void MergeMain()
{
	std::vector<int> vec1{ 1,1,4,3,5,9,6,7,8,2 };
	std::vector<int> vec2{ 1,2,3 };

	std::sort(vec1.begin(), vec1.end());
	std::vector<int> vec(vec1);

	vec1.reserve(vec1.size() + vec2.size());
	vec1.insert(vec1.end(), vec2.begin(), vec2.end());
	cout << "vec1 : ";
	for (auto v : vec1) cout << v << " ";
	cout << endl;

	std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());
	for (auto v : vec1) cout << v << " ";
	cout << endl;
	
	vec2.push_back(10);
	cout << "vec : ";
	for (auto v : vec) cout << v << " ";
	cout << endl;
	cout << "vec2 : ";
	for (auto v : vec2) cout << v << " ";
	cout << endl;

	std::vector<int> res;
	std::set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	cout << "res : ";
	for (auto v : res) cout << v << " ";
	cout << endl;

	res = {};
	std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
		std::back_inserter(res));
	for (auto v : res) cout << v << " ";
	cout << endl;
	
	
	
}

