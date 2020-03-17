#include <iostream>
#include <stack>

using std::cout;
using std::endl;


void StackMain()
{
	std::stack<int> intStack;

	cout << "intStack.empty() : " << intStack.empty() << endl;
	cout << "intStack.size() : " << intStack.size() << endl;

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);

	cout << intStack.top() << endl;

	while(!intStack.empty())
	{
		cout << intStack.top() << " ";
		intStack.pop();
	}
	cout << endl;

	cout << "intStack.empty() : " << intStack.empty() << endl;
	cout << "intStack.size() : " << intStack.size() << endl;

	
}
