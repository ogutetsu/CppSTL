
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

void UtilityMain()
{

	cout << std::min(2000, 2011) << endl;
	cout << std::min({ 1,5,11,200 }) << endl;
	cout << std::min(5, 10, [](int a, int b)
	{
		return std::abs(a) < std::abs(b);
	}) << endl;

	auto pairInt = std::minmax(2000, 2200);
	auto pairSeq = std::minmax({ 10, 5, 200, 220, -1 });
	auto pairAbs = std::minmax({ 10, 5, 200, 220, -20 }, [](int a, int b)
	{
		return std::abs(a) < std::abs(b);
	});

	cout << pairInt.first << " , " << pairInt.second << endl;
	cout << pairSeq.first << " , " << pairSeq.second << endl;
	cout << pairAbs.first << " , " << pairAbs.second << endl;

	
}




