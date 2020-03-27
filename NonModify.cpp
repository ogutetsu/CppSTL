#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>


using std::cout;
using std::endl;


bool isVowel(char c)
{
	std::string Vowels{ "aeiou" };
	std::set<char> vowels(Vowels.begin(), Vowels.end());
	return (vowels.find(c) != vowels.end());
}


void FindSample()
{
	std::list<char> Char{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	int c[] = { 'A','B','C' };

	cout << "find: " << *find(Char.begin(), Char.end(), 'g') << endl;
	cout << "find_if: " << *find_if(Char.begin(), Char.end(), isVowel) << endl;
	cout << "find_if_not: " << *std::find_if_not(Char.begin(), Char.end(), isVowel) << endl;

	auto it = std::find_first_of(Char.begin(), Char.end(), c, c + 3);
	if (it == Char.end()) cout << "None of A, B or C";
	auto it2 = std::find_first_of(Char.begin(), Char.end(), c, c + 3,
	                              [](char a, char b) { return toupper(a) == toupper(b); });

	if (it2 != Char.end()) cout << *it2 << endl;
	auto it3 = std::adjacent_find(Char.begin(), Char.end());
	if (it3 == Char.end()) cout << "No same adjacent chars." << endl;

	auto it4 = std::adjacent_find(Char.begin(), Char.end(),
	                              [](char a, char b) { return isVowel(a) == isVowel(b); });
	if (it4 != Char.end()) cout << *it4 << endl;
}

void ConditionSample()
{
	auto even = [](int i) {return i % 2; };
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	cout << "any_of: " << std::any_of(vec.begin(), vec.end(), even) << endl;
	cout << "all_of: " << std::all_of(vec.begin(), vec.end(), even) << endl;
	cout << "none_of: " << std::none_of(vec.begin(), vec.end(), even) << endl;
}

void CompareSample()
{
	std::string str1{ "Only For Testing Purpose." };
	std::string str2{ "only for testing purpose." };

	cout << std::equal(str1.begin(), str1.end(), str2.begin()) << endl;
	cout << std::equal(str1.begin(), str1.end(), str2.begin(),
	                   [](char c1, char c2) { return toupper(c1) == toupper(c2);  }) << endl;

	str1 = { "Only for testing Purpose." };
	str2 = { "Only for testing purpose." };
	auto pair = std::mismatch(str1.begin(), str1.end(), str2.begin());
	if(pair.first != str1.end())
	{
		cout << std::distance(str1.begin(), pair.first)
			<< "at (" << *pair.first << "," << *pair.second << ")" << endl;
	}
	auto pair2 = std::mismatch(str1.begin(), str1.end(), str2.begin(),
	                           [](char c1, char c2) {return toupper(c1) == toupper(c2);  });
	if(pair2.first == str1.end())
	{
		cout << "str1 and str2 are equal" << endl;
	}
}

void NonModifyMain()
{
	FindSample();


	ConditionSample();


	CompareSample();

	
}





