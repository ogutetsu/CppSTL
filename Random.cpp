#include <iostream>
#include <map>
#include <random>
#include <string>


using std::cout;
using std::endl;

static const int NUM = 100000;

void RandomMain()
{
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> uniformDist(0, 10);
	std::normal_distribution<> normDist(50, 3);

	std::map<int, int> uniformFrequency;
	std::map<int, int> normFrequency;

	for(int i = 0; i <= NUM; i++)
	{
		uniformFrequency[uniformDist(gen)]++;
		normFrequency[normDist(gen)]++;
	}

	for (auto v : uniformFrequency) cout << v.first << ":" << v.second << " ";
	cout << endl;

	for (auto v : normFrequency) cout << v.first << ":" << v.second << " ";
	cout << endl;
	
	
}
