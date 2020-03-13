
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

void ContainerAccessSample()
{
	std::vector<int> intVec;
	intVec.push_back(1);
	intVec.emplace_back(2);

	cout << intVec.size() << endl;

	intVec.assign({ 1,2,3 });
	for (auto v : intVec) cout << v << " ";
	cout << endl;
	
	intVec.insert(intVec.begin(), 0);
	for (auto v : intVec) cout << v << " ";
	cout << endl;

	intVec.insert(intVec.begin()+4, 4);
	for (auto v : intVec) cout << v << " ";
	cout << endl;

	intVec.insert(intVec.end(), {5,6,7,8,9});
	for (auto v : intVec) cout << v << " ";
	cout << endl;

	intVec.pop_back();
	for (auto v : intVec) cout << v << " ";
	cout << endl;
}

void ContainerMain()
{
	ContainerInitSample();

	ContainerAccessSample();

	
}



