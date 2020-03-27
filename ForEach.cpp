#include <algorithm>
#include <array>
#include <iostream>
#include <vector>


using std::cout;
using std::endl;



template<typename T>
class Info
{
public:
	

	void operator()(T t)
	{
		num++;
		sum += t;
	}

	int getSum() const { return sum; }
	int getSize() const { return num; }
	double getMean() const
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}
private:
	int num{ 0 };

	T sum{ 0 };
};


void ForEachMain()
{
	std::vector<double> vec{ 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
	auto vecInfo = std::for_each(vec.begin(), vec.end(), Info<double>());

	std::cout << "vecInfo.getSum : " << vecInfo.getSum() << endl;
	std::cout << "vecInfo.getSize : " << vecInfo.getSize() << endl;
	std::cout << "vecInfo.getMean : " << vecInfo.getMean() << endl;

	std::array<int, 100> arr{ 1,2,3,4,5,6,7,8,9,10 };
	auto arrInfo = std::for_each(arr.begin(), arr.end(), Info<int>());

	std::cout << "arrInfo.getSum : " << arrInfo.getSum() << endl;
	std::cout << "arrInfo.getSize : " << arrInfo.getSize() << endl;
	std::cout << "arrInfo.getMean : " << arrInfo.getMean() << endl;

	
}


