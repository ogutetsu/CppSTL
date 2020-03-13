
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>


using std::cout;
using std::endl;

using namespace std;


void ContainerInitSample()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	map<string, int> m = { {"abc", 12345}, {"def", 54321}, {"ghi", 10000}, };
	unordered_map<string, int> um{ m.begin(), m.end() };

	for (auto v : vec) cout << v << " ";
	cout << endl;

	for (auto v : m) cout << v.first << "," << v.second << " ";
	cout << endl;
	for (auto v : um) cout << v.first << "," << v.second << " ";
	cout << endl;
}

void ContainerMain()
{
	ContainerInitSample();
}



