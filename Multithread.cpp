#include <iostream>
#include <atomic>
#include <functional>
#include <thread>
#include <string>


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


class HelloFuncObject
{
public:
	void operator()() const
	{
		cout << "function object" << endl;
	}
};


void ThreadSample()
{

	std::function<void(void)> helloFunc = []()
	{
		cout << "function" << endl;
	};

	std::thread t1(helloFunc);

	HelloFuncObject hello_func_object;
	std::thread t2(hello_func_object);

	std::thread t3([] {cout << "lambda function" << endl;  });


	t1.join();
	t2.join();
	t3.join();


	std::function<void(std::string)> printStringCopy = [](std::string s)
	{
		cout << s << endl;
	};

	std::string s{ "C++" };
	std::thread strCopy(printStringCopy, s);
	std::thread strCopy2([=] {cout << s << endl; });
	strCopy.join();
	strCopy2.join();


	cout << "thread::hardware_concurrency: " << std::thread::hardware_concurrency() << endl;

	std::thread t4([] { cout << "t4 : " << std::this_thread::get_id() << endl; });
	std::thread t5([] { cout << "t5 : " << std::this_thread::get_id() << endl; });
	cout << "t4.get_id : " << t4.get_id() << endl;
	cout << "t5.get_id : " << t5.get_id() << endl;

	t4.swap(t5);
	cout << "  swap  " << endl;
	cout << "t4.get_id : " << t4.get_id() << endl;
	cout << "t5.get_id : " << t5.get_id() << endl;


	cout << "this_thread::get_id : " << std::this_thread::get_id() << endl;


	t4.join();
	t5.join();

}



void MultithreadMain()
{

	AtomicSample();

	ThreadSample();

	
	
}
