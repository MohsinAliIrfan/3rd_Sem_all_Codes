#include<iostream>
using namespace std;

class GeomatricShape
{
protected:
	char* stype;
	double area;
public:
	GeomatricShape()
	{
		stype = new char[20];
		stype[0] = 'N';
		stype[1] = 'o';
		stype[2] = 'S';
		stype[3] = 'h';
		stype[4] = 'a';
		stype[5] = 'p';
		stype[6] = 'e';
		stype[7] = '\0';

		area = 0.0;
	}

	double ComputeArea() {
		return area;
	}

	void show() {
		cout << "\n Shape: " << stype;
		cout << "\n Area: " << area;
	}

	~GeomatricShape() {
		if (stype)
			delete[]stype;
	}
};

class Rectangle : public GeomatricShape
{
protected:
	float length, width;
public:
	Rectangle() {
		length = 0;
		width = 0;
	}
	void setshape(char *shape) {
		if (stype)
			delete[]stype;
		stype = new char[strlen(shape) + 1];
		strcpy_s(stype, strlen(shape) + 1, shape);
	}
	void setlength(int length) {
		if (length <= 0)
			length = 1;
		this->length = length;
	}
	void setwidth(int width) {
		if (width <= 0)
			width = 1;
		this->width = width;
	}
	float getlength() {
		return length;
	}
	float getwidth() {
		return width;
	}
	void ComputeArea() {
		area = this->length * this->width;
	}
	void show() 
	{
		cout << "\n SHAPE  = " << stype;
		cout << "\n LENGTH = " << length;
		cout << "\n WIDTH  = " << width;
		cout << "\n AREA   = " << area;
	}
};

class Cuboid : public Rectangle
{
	float length, width, height;
public:
	void setshape(char* shape1) {
		if (stype)
			delete[]stype;
		stype = new char[strlen(shape1) + 1];
		strcpy_s(stype, strlen(shape1) + 1, shape1);
	}
	void setheight(int height) {
		if (height <= 0)
			height = 1;
		this->height = height;
	}
	float getheight() {
		return height;
	}
	void ComputeArea(float length, float width) {
		this->length = length;
		this->width = width;
		area = height * length * width;
	}
	void show()
	{
		cout << "\n SHAPE  = " << stype;
		cout << "\n LENGTH = " << length;
		cout << "\n WIDTH  = " << width;
		cout << "\n HEIGHT = " << height;
		cout << "\n AREA   = " << area;
	}
};


int main()
{
	cout << "\n GEOMATRIC SHAPE CLASS ";
	GeomatricShape obj;
	cout << "\n Area after Calculating " << obj.ComputeArea();
    obj.show();

	cout << "\n\n RECTANGLE CLASS ";
	char shape[] = "Rectangle";
	float length = 0.0, width = 0.0;
	cout << "\n Enter Length: "; cin >> length;
	cout << "\n Enter Width: "; cin >> width;
	Rectangle obj1;
	obj1.setlength(length);
	obj1.setwidth(width);
	obj1.setshape(shape);
	obj1.ComputeArea();
	obj1.show();

	cout << "\n\n CUBOID CLASS ";
	char shape1[] = "Cuboid";
	float height = 0.0;
	cout << "\n Enter Height: "; cin >> height;
	Cuboid obj2;
	obj2.setshape(shape1);
	obj2.setheight(height);
	obj2.ComputeArea(obj1.getlength(), obj1.getwidth());
	obj2.show();

	return 0;
}