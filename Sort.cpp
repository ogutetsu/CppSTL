#include <iostream>
#include <algorithm>
#include <vector>


using std::cout;
using std::endl;

void SortMain()
{

	std::string str{ "RadJuiKldxmLKHfgeQoIssPldcTidcbFDs" };

	cout << std::is_sorted(str.begin(), str.end()) << endl;


	std::partial_sort(str.begin(), str.begin() + 30, str.end());
	cout << str << endl;

	auto sortUntil = std::is_sorted_until(str.begin(), str.end());
	cout << *sortUntil << endl;

	for (auto charIt = str.begin(); charIt != sortUntil; ++charIt)
		cout << *charIt;
	cout << endl;

	std::vector<int> vec{ 1,0,4,3,5 };
	auto vecIt = vec.begin();
	while(vecIt != vec.end())
	{
		std::nth_element(vec.begin(), vecIt++, vec.end());
		cout << " " << std::distance(vec.begin(), vecIt) << "-th ";
		for (auto v : vec) cout << v;
		cout << "/";
	}
	cout << endl;
	
}

