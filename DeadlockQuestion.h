
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <thread>
#include <mutex>
#include <condition_variable>


class CAccount
{
public:
	CAccount() { balance = 100; };
	~CAccount() {};
	void Transfer(CAccount &from, double amount)
	{
		// don't actually take the locks yet
		std::unique_lock<std::mutex> lock_from(from.m, std::defer_lock);
		std::unique_lock<std::mutex> lock_to(this->m, std::defer_lock);
		// lock both unique_locks without deadlock
		std::lock(lock_from, lock_to);
		
		std::chrono::milliseconds timespan(100);
		std::this_thread::sleep_for(timespan);
		from.balance -= amount;
		this->balance += amount;

	}
	double GetBalance() { return balance; };

private:
	std::mutex m;
	double balance;
};

void TransferToChequing(CAccount *chequing, CAccount *savings)
{
	chequing->Transfer(*savings, 10);
}

void TransferToSavings(CAccount *chequing, CAccount *savings)
{
	savings->Transfer(*chequing, 20);
}



