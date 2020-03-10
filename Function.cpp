
#include <iostream>
#include <functional>
#include <map>

using namespace std::placeholders;

using std::cout;
using std::endl;
using std::bind;
using std::function;

using std::make_pair;
using std::map;


double DivFunc(double a, double b) { return a / b; };



void FunctionMain()
{

	auto DivA = bind(DivFunc, _1, _2);
	function< double(double, double) > Div1 = bind(DivFunc, _1, _2);
	function<double(double)> Div2 = bind(DivFunc, 100, _1);

	cout << DivFunc(100, 10) << endl;
	cout << Div1(100, 10) << endl;
	cout << Div2(10) << endl;


	map<const char, std::function<double(double, double)>> table;
	table.insert(make_pair('+', [](double a, double b) { return a + b; }));
	table.insert(make_pair('-', [](double a, double b) { return a - b; }));

	cout << table['+'](3.15, 5.6) << endl;
	cout << table['-'](2.15, 4.6) << endl;
	
	
	
}

