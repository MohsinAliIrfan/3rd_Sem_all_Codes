#include<iostream>
using namespace std;
const double pie = 3.14;

int getArea(double& a)
{
	double Area;
	Area = 4 * pie * a * a;
	return Area;

}
int getVolume(double& b)
{
	double Volume;
	Volume = 4 / 3 * (pie * b * b * b);
	return Volume;
}
int main() {
	double rad, Area, Volume;
	cout << "enter radius";
	cin >> rad;
	Area= getArea(rad);
	cout << endl << Area;
	Volume = getVolume(rad);
	cout << endl << Volume;
	return 0;

}