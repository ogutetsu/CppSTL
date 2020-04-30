#include <iostream>
#include <tuple>
#include <string>

using std::cout;
using std::endl;
using std::tuple;
using std::get;


extern void TieIgnoreSample();

void TupleMain()
{
	tuple<std::string, int, float> tup1("first", 3, 4.5f);
	auto tup2 = std::make_tuple("second", 5, 1.5f);

	cout << get<0>(tup1) << ", " << get<1>(tup1) << ", " << get<2>(tup1) << endl;
	cout << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << endl;

	cout << (tup1 < tup2) << endl;

	get<0>(tup2) = "Second";

	cout << get<0>(tup2) << ", " << get<1>(tup2) << ", " << get<2>(tup2) << endl;


	TieIgnoreSample();
}


void TieIgnoreSample()
{
	int first = 1;
	int second = 2;
	int third = 3;
	int fourth = 4;

	auto tup = std::tie(first, second, third, fourth) = std::make_tuple(11, 12, 13, 14);

	cout << first << ", " << second << ", " << third << ", " << fourth << endl;

	first = 111;
	get<1>(tup) = 222;

	cout << get<0>(tup) << ", " << get<1>(tup) << endl;

	int a, b;
	std::tie(std::ignore, a, std::ignore, b) = tup;
	cout << a << ", " << b << endl;  // 222, 14
	
	
}


