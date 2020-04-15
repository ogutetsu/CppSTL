#include <functional>
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

void RegexMatchSample()
{
	std::function<void(const std::string, const std::string)> showCaptureGroups =
		[](const std::string regEx, std::string text)
	{
		std::regex rgx(regEx);
		std::smatch smatch;
		if(std::regex_search(text, smatch, rgx))
		{
			cout << "regEx: " << regEx << " text: " << text << " " << smatch[0] << " " << smatch[1]
				<< " " << smatch[2] << " " << smatch[3] << endl;
		}
		
	};


	showCaptureGroups("abc+", "abccccc");
	showCaptureGroups("(a+)(b+)", "aaabccc");
	showCaptureGroups("((a+)(b+))", "aaabccc");
	showCaptureGroups("(ab)(abc)+", "ababcabc");
	

	std::string privateAddress = "192.168.178.21";
	std::string regEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
	std::regex rgx(regEx);
	std::smatch smatch;

	if(std::regex_match(privateAddress, smatch, rgx))
	{
		for(auto cap : smatch)
		{
			cout << "capture group: " << cap << endl;
			if(cap.matched)
			{
				std::for_each(cap.first, cap.second, [](int v)
				{
					cout << std::hex << v << " ";
				});
				cout << endl;
			}
		}
	}
}

void RegexMain()
{
	RegexObjectSample();

	RegexMatchSample();
	


	
}


