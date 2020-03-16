#include <iostream>
#include <list>


using std::cout;
using std::endl;

using namespace std;

void ListMain()
{
	list<int> list{ 10,1,3,2,1,4,5,6,1,2,9,7,1,8 };

	list.sort();
	for (auto v : list) cout << v << " ";
	cout << endl;

	list.unique();
	for (auto v : list) cout << v << " ";
	cout << endl;

	
	list.splice(find(list.begin(), list.end(), 11),
		{11, 12, 13, 14, 15});

	for (auto v : list) cout << v << " ";
	cout << endl;

	list.remove_if([](int val)
	{
		return val > 5;
	});
	for (auto v : list) cout << v << " ";
	cout << endl;

	
	
}
