#include <iostream>
#include <thread>
#include <mutex>

int counter;
const int NCOUNTS = 100;
std::mutex incrementMutex;

void increment()
{
	for(int i=0; i<NCOUNTS; i++)
	{
		std::lock_guard<std::mutex> lock(incrementMutex);
		counter++;
		std::cout << counter << std::endl;
	}
}
void decrement()
{
	for(int i=0; i<NCOUNTS; i++)
	{
		std::lock_guard<std::mutex> lock(incrementMutex);
		counter--;
		std::cout << counter << std::endl;
	}
}

main()
{
	counter = 0;
	// Threads starten
	std::thread a(increment);
	std::thread b(decrement);
	// auf Beendigung warten
	a.join();
	b.join();
}
