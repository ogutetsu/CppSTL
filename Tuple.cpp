#include <iostream>
#include <tuple>


using std::cout;
using std::endl;
using std::tuple;
using std::get;

void TupleMain()
{
	tuple<std::string, int, float> tup1("first", 3, 4.5f);
	auto tup2 = std::make_tuple("second", 5, 1.5f);

	cout << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup1) << endl;
	cout << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << endl;

	cout << (tup1 < tup2) << endl;

	get<0>(tup2) = "Second";

	cout << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << endl;


	
}


