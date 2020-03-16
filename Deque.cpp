#include <iostream>
#include <deque>


using std::cout;
using std::endl;

using namespace std;


void DequeMain()
{

	deque<int> intDeq;

	intDeq.push_back(5);
	intDeq.emplace_back(1);
	for (auto v : intDeq) cout << v << " ";
	cout << endl;

	deque<int> intDeq2;
	intDeq2.assign({ 1,2,3 });
	for (auto v : intDeq2) cout << v << " ";
	cout << endl;

	
	intDeq2.insert(intDeq2.begin(), 0);
	for (auto v : intDeq2) cout << v << " ";
	cout << endl;

	intDeq2.push_front(-1);
	for (auto v : intDeq2) cout << v << " ";
	cout << endl;
	
	
}

