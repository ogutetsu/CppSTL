#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using namespace std;


void VectorMain()
{

	std::vector<int> intVec(5, 200);
	intVec.reserve(10);

	cout << "size : " << intVec.size() << endl;
	cout << "capacity : " << intVec.capacity() << endl;
	
	intVec.shrink_to_fit();
	cout << "capacity : " << intVec.capacity() << endl;

	std::vector<int> intVec2(5);
	cout << "intVec2 size : " << intVec2.size() << endl;
	std::vector<int> intVec3{ 5 };
	cout << "intVec3 size : " << intVec3.size() << endl;


	

	
	
}


