
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

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
	vector<int> intVec;
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

void ContainerCompareSample()
{
	vector<int> vec1{ 1,2,3};
	vector<int> vec2{ 1,2,3 };
	cout << "(vec1 == vec2) : " << (vec1 == vec2) << endl;

	vector<int> vec3{ 1,2,4 };
	cout << "(vec1 < vec3) : " << (vec1 < vec3) << endl;
	
	
	map<string, int> map1{ {"abc", 123}, {"def", 345} };
	map<string, int> map2{ {"abc", 123}, {"def", 345} };
	cout << "(map1 == map2) : " << (map1 == map2) << endl;

	unordered_map<string, int> umap1{ {"abc", 123}, {"def", 345} };
	unordered_map<string, int> umap2{ {"Abc", 123}, {"def", 345} };
	cout << "(umap1 == umap2) : " << (umap1 == umap2) << endl;
}

void ContainerMain()
{
	ContainerInitSample();

	ContainerAccessSample();


	ContainerCompareSample();


	
}



