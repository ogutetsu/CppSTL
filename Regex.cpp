#include <iostream>
#include <regex>


using std::cout;
using std::endl;

using std::regex_constants::ECMAScript;
using std::regex_constants::icase;


void RegexObjectSample()
{
	std::string question = "C++ or c++, question";
	std::string regExprStr(R"(c\+\+)");

	std::regex rgx(regExprStr);
	std::smatch smatch;

	if(std::regex_search(question, smatch, rgx))
	{
		cout << "case sensitive: " << smatch[0] << endl;
	}

	std::regex rgxIn(regExprStr, ECMAScript | icase);
	if(std::regex_search(question, smatch, rgxIn))
	{
		cout << "case insensitive: " << smatch[0] << endl;
	}
}

void RegexMain()
{
	RegexObjectSample();
}


