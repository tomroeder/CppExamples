#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Asynchroneous timer expired!\n";
}

void TimerAsynchroneous()
{
	cout << "Starting asio timer example 2" << endl;
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(2));
	t.async_wait(&print);

	io.run();
}



