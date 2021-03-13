#include<iostream>
using namespace std;

class Circle
{
	float radius;
	const float Pi = 3.14;
	float area, cir;
public:

	Circle(float radius, float pi): Pi(pi) //this how we change the value of a const type variable
	{
		this->radius = radius;
	}

	void setheight(float radius)
	{
		this->radius = radius;
	}

	void calarea()	
	{
		area = Pi * (radius * radius);
	}

	void calcircum()
	{
		cir = (2 * Pi) * radius;
	}

	float getarea() 
	{
		return area;
	}

	float getcir()
	{
		return cir;
	}
	float getrad()
	{
		return radius;
	}
};

void main()
{
	Circle s1(0.0, 3.14);
	float radius = 0, area, cir;
	cout << "\n Enter Radius: "; cin >> radius;
	
	s1.setheight(radius);
	radius = s1.getrad();
	s1.calarea();
	s1.calcircum();
	area = s1.getarea();
	cir = s1.getcir();

	cout << "\n Area is: " << area;
	cout << "\n Circumference is: " << cir;

}