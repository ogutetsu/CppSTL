#include <iostream>
#include <queue>

using std::cout;
using std::endl;



void QueueMain()
{

	std::queue<int> intQueue;

	cout << "intQueue.empty() : " << intQueue.empty() << endl;
	cout << "intQueue.size() : " << intQueue.size() << endl;

	intQueue.push(1);
	intQueue.push(2);
	intQueue.push(3);

	cout << "intQueue.back() : " << intQueue.back() << endl;
	cout << "intQueue.front() : " << intQueue.front() << endl;

	
	while(!intQueue.empty())
	{
		cout << intQueue.back() << " ";
		cout << intQueue.front() << " : ";
		intQueue.pop();
;	}
	cout << endl;

	cout << "intQueue.empty() : " << intQueue.empty() << endl;
	cout << "intQueue.size() : " << intQueue.size() << endl;



	std::priority_queue<int> priQueue;

	cout << "priQueue.empty() : " << priQueue.empty() << endl;
	cout << "priQueue.size() : " << priQueue.size() << endl;

	priQueue.push(3);
	priQueue.push(1);
	priQueue.push(2);

	cout << "priQueue.top() : " << priQueue.top() << endl;

	while(!priQueue.empty())
	{
		cout << priQueue.top() << " ";
		priQueue.pop();
	}
	cout << endl;

}
