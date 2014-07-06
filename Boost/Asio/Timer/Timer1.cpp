#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

void TimerSynchroneous()
{
	cout << "Starting asio timer example 1" << endl;

	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(2));
	t.wait();

	std::cout << "Synchroneous timer expired!\n";
}

