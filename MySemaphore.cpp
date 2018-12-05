#include "MySemaphore.h"


MySemaphore::MySemaphore(int count_ = 0):semCount(count_) //initializes as locked by default
{
}

MySemaphore::MySemaphore():semCount(0) //initializes as locked by default
{
}

void MySemaphore::Notify() {
	std::unique_lock<std::mutex> lock(mtx);
	semCount++;
	cv.notify_one();
}

void MySemaphore::Wait() {
	std::unique_lock<std::mutex> lock(mtx);
	while (semCount == 0) {
		//spin locking
		cv.wait(lock);
	}
	semCount--;
}
