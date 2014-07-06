#include <iostream>

#include "Timer1.h"
#include "Timer2.h"
#include "Timer3.h"

using namespace std;

int main()
{
	cout << "http://www.highscore.de/cpp/boost/asio.html" << endl;

	TimerSynchroneous();
	TimerAsynchroneous();
	BindingArgumentsToAHandler();

	return 0;
}
