#include <iostream>
#include <atomic>
#include <functional>
#include <mutex>
#include <thread>
#include <string>
#include <condition_variable>
#include <future>


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


struct Critical
{
	std::mutex mut;
};


struct ConstDouble
{
	constexpr ConstDouble(double v) : val(v) {};
	constexpr double getValue() const { return val; }
	double val;
};


void ShareValueSample()
{

	std::mutex mutexCout;

	std::function<void(std::string)> Worker = [&](std::string name)
	{
		for (int i = 1; i <= 3; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			mutexCout.lock();
			cout << name << ": " << "Work " << i << endl;
			mutexCout.unlock();
		}
	};


	std::thread abc(Worker, "Abc");
	std::thread def(Worker, "  def");
	std::thread hij(Worker, "    hij");
	std::thread klm(Worker, "      klm");

	abc.join();
	def.join();
	hij.join();
	klm.join();


	std::function<void(Critical&, Critical&)> deadLock = [](Critical& a, Critical& b)
	{
		a.mut.lock();
		cout << "first mutex" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		b.mut.lock();
		cout << "second mutex" << endl;
		a.mut.unlock();
		b.mut.unlock();
	};

	//Critical c1;
	//Critical c2;

	//std::thread dt1([&]{ deadLock(c1,c2); });
	//std::thread dt2([&] { deadLock(c1, c2); });




	std::mutex mutexCoutGuard;

	std::function<void(std::string)> WorkerGuard = [&](std::string name)
	{
		for (int i = 1; i <= 3; i++)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			std::lock_guard<std::mutex> lock(mutexCoutGuard);
			cout << name << ": " << "Work " << i << endl;
		}
	};


	std::function<void(Critical&, Critical&)> deadLockResolved = [](Critical& a, Critical& b)
	{
		std::unique_lock<std::mutex> guard1(a.mut, std::defer_lock);
		cout << std::this_thread::get_id() << " : first lock" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::unique_lock<std::mutex> guard2(b.mut, std::defer_lock);
		cout << std::this_thread::get_id() << " : second lock" << endl;
		cout << std::this_thread::get_id() << " : atomic lock" << endl;
		std::lock(guard1, guard2);
	};

	Critical c3;
	Critical c4;

	std::thread dt3([&] { deadLockResolved(c3, c4); });
	std::thread dt4([&] { deadLockResolved(c3, c4); });

	dt3.join();
	dt4.join();


	constexpr ConstDouble db(1.456);
	cout << db.getValue() << endl;



	std::once_flag onceFlag;
	std::function<void(void)> do_once = [&]()
	{
		std::call_once(onceFlag, [] {cout << "Only once." << endl; });
	};

	std::thread o1(do_once);
	std::thread o2(do_once);

	o1.join();
	o2.join();

}


std::mutex mutex_;
std::condition_variable cond;

void ConditionVariableSample()
{

	bool dataReady = false;

	std::function<void(void)> doWork = []()
	{
		cout << "Shared data." << endl;
	};

	std::function<void(void)> waitingForWork = [&]()
	{
		cout << "Worker: Wainting for work." << endl;
		std::unique_lock<std::mutex> ulock(mutex_);
		cond.wait(ulock, [&] {return dataReady; });
		doWork();
		cout << "work done." << endl;
	};

	std::function<void(void)> setDataReady = [&]()
	{
		std::lock_guard<std::mutex> lockguard(mutex_);
		dataReady = true;
		cout << "Sender: Data is ready." << endl;
		cond.notify_one();
	};

	std::thread t1(waitingForWork);
	std::thread t2(setDataReady);

	t1.join();
	t2.join();


}


void TaskSample()
{

	int res;
	std::thread t([&] {res = 2000 + 11; });
	t.join();
	cout << res << endl;

	auto f = std::async([] {return 2000 + 11; });
	cout << f.get() << endl;

	auto begin = std::chrono::system_clock::now();

	auto async1 = std::async(std::launch::deferred, [] {return std::chrono::system_clock::now(); });
	auto async2 = std::async(std::launch::async, [] {return std::chrono::system_clock::now(); });
	std::this_thread::sleep_for(std::chrono::seconds(1));

	auto a1Start = async1.get() - begin;
	auto a2Start = async2.get() - begin;

	auto duration1 = std::chrono::duration<double>(a1Start).count();
	auto duration2 = std::chrono::duration<double>(a2Start).count();

	cout << "defferd: " << duration1 << endl;
	cout << "async: " << duration2 << endl;


	std::function<void(std::promise<int>&&, int, int)> product = [](std::promise<int>&& intPromise, int a, int b)
	{
		intPromise.set_value(a*b);
	};

	int a = 20;
	int b = 10;

	std::promise<int> prodPromise;
	std::future<int> prodResult = prodPromise.get_future();

	std::thread prodThread(product, std::move(prodPromise), a, b);
	prodThread.join();
	cout << "20*10= " << prodResult.get() << endl;


}



void MultithreadMain()
{

	AtomicSample();

	ThreadSample();

	ShareValueSample();

	ConditionVariableSample();

	TaskSample();
	
}
