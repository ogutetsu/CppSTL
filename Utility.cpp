
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cout;
using std::endl;


struct ForwardData
{
	ForwardData(int, double, char) {};
};

template<typename T, typename... Args>
T createT(Args&&... args)
{
	return T(std::forward<Args>(args)...);
}


extern void PairSample();


void UtilityMain()
{

	cout << std::min(2000, 2011) << endl;
	cout << std::min({ 1,5,11,200 }) << endl;
	cout << std::min(5, 10, [](int a, int b)
	{
		return std::abs(a) < std::abs(b);
	}) << endl;

	auto pairInt = std::minmax(2000, 2200);
	auto pairSeq = std::minmax({ 10, 5, 200, 220, -1 });
	auto pairAbs = std::minmax({ 10, 5, 200, 220, -20 }, [](int a, int b)
	{
		return std::abs(a) < std::abs(b);
	});

	cout << pairInt.first << " , " << pairInt.second << endl;
	cout << pairSeq.first << " , " << pairSeq.second << endl;
	cout << pairAbs.first << " , " << pairAbs.second << endl;


	std::vector<int> SrcVec(10000, 1000);
	std::vector<int> DstVec;

	/*
	 * コピーよりも移動させる方が安価
	 * 不要なメモリの割り当てと割り当て解除は発生しない
	 */
	DstVec = std::move(SrcVec);


	int at = createT<int>();
	int bt = createT<int>(1);

	std::string s = createT<std::string>("test.");
	ForwardData data = createT<ForwardData>(1, 3.1415, 'a');

	typedef std::vector<int> IntVec;
	IntVec intVec = createT<IntVec>(std::initializer_list<int>{1, 2, 3});
	

	PairSample();
	
}



void PairSample()
{

	std::pair<const char*, double> CharDouble("str", 3.1415);
	std::pair<const char*, double> CharDouble2 = std::make_pair("str", 3.1415);

	auto CharDouble3 = std::make_pair("str", 3.1415);

	cout << CharDouble.first << ", " << CharDouble.second << endl;
	CharDouble.first = "Str";
	std::get<1>(CharDouble) = 5.15;

	cout << CharDouble.first << ", " << CharDouble.second << endl;
	
}




