#include <algorithm>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;


void PermutationMain()
{
	std::vector<int> vec{ 1,2,3 };
	do
	{
		for (auto i : vec) cout << i;
		cout << " ";
	} while (std::next_permutation(vec.begin(), vec.end()));
	cout << endl;

	std::reverse(vec.begin(), vec.end());
	do
	{
		for (auto i : vec) cout << i;
		cout << " ";
	} while (std::prev_permutation(vec.begin(), vec.end()));
	cout << endl;
}

