//---------------------------------------------------------
/// SMART POINTERS
/// Cadesh
/// 02AGO2018
//---------------------------------------------------------
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//----------------------------------------------------------
class Vehicle
{
	virtual void whoAmI() { cout << "I am Vehicle" << endl; }
	virtual ~Vehicle() = default; // to silence -Wall warnings
};
//----------------------------------------------------------
class Tank : public Vehicle
{
	void whoAmI() override { cout << "I am Tank" << endl; }
	~Tank() {}
};
//----------------------------------------------------------
class Truck : public Vehicle
{
	void whoAmI() override { cout << "I am Truck" << endl; }
	~Truck() {}
};
//----------------------------------------------------------
int main()
{
	std::vector<std::shared_ptr<Vehicle>> vecBase; //vector of base class

	auto tank = std::make_shared<Tank>(); 
	auto truck = std::make_shared<Truck>();

	vecBase.push_back(tank); //insert objects of derived classes on vector
	vecBase.push_back(truck);

	for (auto&& elem : vecBase)
		elem->whoAmI();

	vecBase.resize(0); //clean up
	tank.reset();
	truck.reset();
}
//----------------------------------------------------------