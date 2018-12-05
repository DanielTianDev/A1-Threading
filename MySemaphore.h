#include <atomic>
#include <mutex>
#include <condition_variable>

class MySemaphore
{
public:
	MySemaphore();
	MySemaphore(int);


	void Notify();
	void Wait();

private:
	std::atomic<int> semCount;
	std::mutex mtx;
	std::condition_variable cv;

};

