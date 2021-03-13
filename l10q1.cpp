#include<iostream>
using namespace std;

class Vehicle
{
public:
	void display();
};

class Bike : public Vehicle
{
public:
	void display();
};

class Car : public Vehicle
{
public:
	void display();
};

void Vehicle::display() {
	cout << "\n This is a vehicle ";
}
void Car::display() {
	cout << "\n This is a Car ";
}
void Bike::display() {
	cout << "\n This is a Car ";
}

int mian()
{
	Vehicle obj;
	cout << "\n Vehicle ";
	obj.display();

	Car obj1;
	cout << "\n\n Car ";
	obj1.display();

	Bike obj2;
	cout << "\n\n Bike ";
	obj2.display();

	return 0;
}