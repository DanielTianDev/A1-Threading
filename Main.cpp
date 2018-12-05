#include "CMultiThread.h"
#include "DeadlockQuestion.h"

#include <stdlib.h>
#include <stdio.h>

CMultiThread *threadObj;

int main(void) {

	
	threadObj = new CMultiThread;

	if (threadObj == NULL) {
		std::cout << "Could not create thread object!\n";
	}
	else {
		std::cout << "\n\nTwo Thread Test : ";
			threadObj->TwoThreadTest();
			std::cout << "\n\n\nMultipe Thread Test : ";
			threadObj->MultiThreadTest();
			std::cout << "\n\n\nReader - Writer Test : ";
			threadObj->ReaderWriterTest();
	}


	if (threadObj) {
		delete threadObj;
		threadObj = NULL;
	}
	

	
	CAccount chequing, savings;
	std::cout << "Start potential deadlock actions:\n";
	std::thread *thread1 = new std::thread(TransferToChequing, &chequing, &savings);
	std::thread *thread2 = new std::thread(TransferToSavings, &chequing, &savings);
	thread1->join();
	thread2->join();
	std::cout << "\tChq = " << chequing.GetBalance();
	std::cout << "; Sav = " << savings.GetBalance() << std::endl;
	
	
	
	system("pause");
	return 0;
}
