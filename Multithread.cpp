#include <iostream>
#include <atomic>
#include <functional>
#include <thread>


using std::cout;
using std::endl;


void AtomicSample()
{
	std::atomic_int x, y;
	int r1, r2;

	std::function<void(void)> writeX = [&]()
	{
		x.store(1);
		r1 = y.load();
	};

	std::function<void(void)> writeY = [&]()
	{
		y.store(1);
		r2 = x.load();
	};

	x = 0;
	y = 0;

	std::thread a(writeX);
	std::thread b(writeY);

	a.join();
	b.join();

	cout << r1 << r2 << endl;

}

void MultithreadMain()
{

	AtomicSample();
	
	
}
