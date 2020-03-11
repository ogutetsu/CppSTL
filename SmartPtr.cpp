#include <iostream>
#include <memory>


using std::cout;
using std::endl;


struct SampleInt
{
	SampleInt(int i) : i_(i) {}
	~SampleInt()
	{
		cout << "from " << i_ << endl;
	}
	int i_;
};

struct SampleInt2
{
	int val;
	static int count;

	SampleInt2() : val(count)
	{
		cout << (void*)this << " constructor : " << val << endl;
		count++;
	}
	~SampleInt2()
	{
		cout << (void*)this << " destructor : " << val << endl;
		count--;
	}
};


int SampleInt2::count = 0;


void UniqueSample()
{
	std::unique_ptr<int> uniquePtr1(new int(11));
	//std::unique_ptr<int> uniquePtr2 = uniquePtr1;  Error
	std::unique_ptr<int> uniquePtr3 = std::move(uniquePtr1);


	std::unique_ptr<SampleInt> up1{ new SampleInt(11) };
	cout << up1.get() << endl;
	std::unique_ptr<SampleInt> up2{ std::move(up1) };
	cout << "move : " << up1.get() << endl;
	cout << up2.get() << endl;
	
	up2.reset(new SampleInt(2));
	SampleInt* pInt = up2.release();
	delete pInt;
	
	cout << "release : "<< up2.get() << endl;

	std::unique_ptr<SampleInt> up3{ new SampleInt(100) };
	std::unique_ptr<SampleInt> up4{ new SampleInt(111) };

	cout << "up3 : " << up3.get() << endl;
	cout << "up4 : " << up4.get() << endl;

	std::swap(up3, up4);

	cout << "swap up3 : " << up3.get() << endl;
	cout << "swap up4 : " << up4.get() << endl;


	std::unique_ptr<SampleInt2[]> uniqueArray(new SampleInt2[3]);
}

void SmartPtrMain()
{
	UniqueSample();

}

