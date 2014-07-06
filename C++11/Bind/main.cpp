#include <functional> // std::bind, std::function
#include <memory> // std::shared_ptr<>
#include <iostream>

class bindTest
{
	public:
	int add(int i, int j) { return i+j; }
};

int main(int argc, char **argv)
{
	std::shared_ptr<bindTest> ptr(new bindTest());
	// Erzeugung von Funktionsobjekten
	std::function<int()> f = std::bind(&bindTest::add, ptr, 1, 2);
	// Automatische Typbestimmung
	auto i = f();

	std::cout // Ausgabe "3 / 4 / 5 / 6"
	<< f() << " / "
	<< i+1 << " / "
	<< ptr->add(2, 3) << " / "
	<< std::bind(&bindTest::add, ptr, 3, 3)()
	<< std::endl;
}
