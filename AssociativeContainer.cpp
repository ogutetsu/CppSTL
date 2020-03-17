#include <array>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>


using std::cout;
using std::endl;


void MapSample()
{
	std::map<std::string, int> m{ {"Abcdef", 1999}, {"Ghijk", 2000} };
	m["Efghi"] = 2020;

	for (auto v : m) cout << "{" << v.first << "," << v.second << "},";
	cout << endl;
	
	m.erase("Ghijk");
	for (auto v : m) cout << "{" << v.first << "," << v.second << "},";
	cout << endl;

	m.clear();
	cout << "m.size() : " << m.size() << endl;
	

	// unordered_map

	std::unordered_map<std::string, int> um{ {"Djisdf", 1999}, {"Abcdef", 2000} };
	um["aabc"] = 1934;
	for (auto v : um) cout << "{" << v.first << "," << v.second << "},";
	cout << endl;
}

void SetSample()
{
	std::multiset<int> mset{ 3,1,2,4,5,1,2,6,5,7,3,1,2,4,3,6,9 };
	for (auto v : mset) cout << v << " ";
	cout << endl;

	mset.insert(8);
	for (auto v : mset) cout << v << " ";
	cout << endl;
	std::array<int, 5> arr{ 10,11,12,13,14 };
	mset.insert(arr.begin(), arr.begin() + 3);
	for (auto v : mset) cout << v << " ";
	cout << endl;

	mset.erase(1);
	mset.erase(mset.lower_bound(5), mset.upper_bound(10) );
	for (auto v : mset) cout << v << " ";
	cout << endl;
}

void AssciativeContainerMain()
{
	MapSample();

	SetSample();
	
}

