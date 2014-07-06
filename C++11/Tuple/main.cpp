#include <iostream>
#include <tuple>

using namespace std;

int main(int argc, char **argv)
{
	std::tuple<int, std::string, double, float> t1(4, "Hello world.", 1.234, 5.6789);
	const auto myElement = std::get<1>(t1);
	cout << "Erstes Element = " << myElement << endl;
}
