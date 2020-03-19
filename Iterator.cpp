#include <iostream>
#include <vector>
#include <deque>
#include <iterator>


using std::cout;
using std::endl;


void IteratorMain()
{
	std::vector<int> vec{ 1,10,2,3,3,3,5 };
	std::deque<int> deq(vec.capacity());

	std::copy(vec.begin() + 2, vec.end(), deq.begin());

	for (auto v : deq) cout << v << " ";
	cout << endl;

	std::vector<int>::iterator vecIt;
	for (vecIt = vec.begin(); vecIt != vec.end(); vecIt++) cout << *vecIt << " ";
	cout << endl;

	std::vector<int>::const_reverse_iterator revVecItEnd = vec.rend();
	std::vector<int>::reverse_iterator revVecIt;
	for (revVecIt = vec.rbegin(); revVecIt != revVecItEnd; revVecIt++) cout << *revVecIt << " ";
	cout << endl;

		
	
}


