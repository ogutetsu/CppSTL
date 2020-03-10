
#include <iostream>
#include <functional>

using namespace std::placeholders;

using std::cout;
using std::endl;
using std::bind;
using std::function;


double DivFunc(double a, double b) { return a / b; };



void FunctionMain()
{

	auto DivA = bind(DivFunc, _1, _2);
	function< double(double, double) > Div1 = bind(DivFunc, _1, _2);
	function<double(double)> Div2 = bind(DivFunc, 100, _1);

	cout << DivFunc(100, 10) << endl;
	cout << Div1(100, 10) << endl;
	cout << Div2(10) << endl;
	
}

