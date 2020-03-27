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

void NonModifyMain()
{
	FindSample();


	ConditionSample();


	
}




