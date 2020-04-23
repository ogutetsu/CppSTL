#include <functional>
#include <iostream>
#include <regex>
#include <unordered_map>


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

	std::string numberRegEx(R"([-+]?([0-9]*\.[0-9]+|[0-9]+))");
	rgx = std::regex(numberRegEx);
	const char* numChar{ "2020" };

	if(std::regex_match(numChar, rgx))
	{
		cout << numChar << " is a number." << endl;
	}

	const std::string numStr{ "3.14159265359" };
	if(std::regex_match(numStr, rgx))
	{
		cout << numStr << " is a number." << endl;
	}

	const std::vector<char> numVec{ {'-', '2', '.', '7', '1', '8', '2', '8','7', '1', '2', '8'} };
	if(std::regex_match(numVec.begin(), numVec.end(), rgx))
	{
		for (auto v : numVec) { cout << v; };
		cout << " is a number." << endl;
	}
	

	
}

void RegexSearchSample()
{
	std::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");

	std::cmatch cmatch;

	const char* ctime{ "Now it is 23:10." };
	if(std::regex_search(ctime, cmatch, crgx))
	{
		cout << ctime << endl;
		cout << "Time: " << cmatch[0] << endl;
	}

	std::smatch smatch;
	std::string stime{ "Now it is 23:10." };
	if (std::regex_search(stime, smatch, crgx))
	{
		cout << stime << endl;
		cout << "Time: " << smatch[0] << endl;
	}
}

void RegexReplaceSample()
{
	std::string unofficialName{ "The unofficial name of the new C++ standard is C++0x." };

	std::regex rgxCpp{ R"(C\+\+0x)" };
	std::string newCppName{ "C++11" };
	std::string newName{ std::regex_replace(unofficialName, rgxCpp, newCppName) };

	cout << newName << endl;
}

void RegexFormatSample()
{
	const std::string unofficial{ "unofficial, C++0x" };
	const std::string official{ "official, C++11" };

	std::regex regValues{ "(.*),(.*)" };
	std::string standardText{ "The $1 name of the new C++ standard is $2." };
	std::string textNow = std::regex_replace(unofficial, regValues, standardText);
	cout << textNow << endl;

	std::smatch smatch;
	if(std::regex_match(official, smatch, regValues))
	{
		cout << smatch.str() << endl;
		std::string textFuture = smatch.format(standardText);
		cout << textFuture << endl;
	}
}

void RegexIteratorSample()
{
	std::string text{ "That's a (to me) amazingly frequent question. It may be the most f\
requently asked question. Surprisingly, C++11 feels like a new language: The pieces \
just fit together better than they used to and I find a higher-level style of progra\
mming more natural than before and as efficient as ever." };

	std::regex wordReg{ R"(\w+)" };
	std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
	const std::sregex_iterator wordItEnd;
	std::unordered_map<std::string, std::size_t> allWords;
	for(; wordItBegin != wordItEnd; wordItBegin++)
	{
		allWords[wordItBegin->str()]++;
	}
	for(auto v : allWords)
	{
		cout << "(" << v.first << ":" << v.second << ")";
	}
	cout << endl;

	std::string bookText = std::string{ "Pete Becker,The C++ Standard Library Extensions,2006:" } +
		std::string{ "Nicolai Josuttis,The C++ Standard Library,1999" };

	std::regex regBook(R"((\w+)\s(\w+),([\w\s\+]*),(\d{4}))");
	std::sregex_token_iterator bookItBegin(bookText.begin(), bookText.end(), regBook);

	const std::sregex_token_iterator bookItEnd;
	while(bookItBegin != bookItEnd)
	{
		cout << *bookItBegin++ << endl;
	}
	cout << endl;

	std::sregex_token_iterator bookItNameIssueBegin(bookText.begin(), bookText.end(), regBook, { {2,4} });
	const std::sregex_token_iterator bookItNameIssueEnd;

	while(bookItNameIssueBegin != bookItNameIssueEnd)
	{
		cout << *bookItNameIssueBegin++ << ", ";
		cout << *bookItNameIssueBegin++ << endl;
	}
	
	std::regex regBookNeg(":");
	std::sregex_token_iterator bookItNegBegin(bookText.begin(), bookText.end(), regBookNeg, -1);
	
	const std::sregex_token_iterator boolItNegEnd;
	while(bookItNegBegin != boolItNegEnd)
	{
		cout << *bookItNegBegin++ << endl;
	}
}

void RegexMain()
{
	RegexObjectSample();

	RegexMatchSample();


	RegexSearchSample();

	RegexReplaceSample();


	RegexFormatSample();
	
	RegexIteratorSample();

	
	
	
	
	
}


