#include<iostream>
using namespace std;

class Complex
{
	int real, img;
public:

	Complex(int real = 0, int img = 0)
	{
		this->real = real;
		this->img = img;
	}

	void setreal(int real)
	{
		this->real = real;
	}

	void setimg(int img)
	{
		this->img = img;
	}

	int getreal()
	{
		return real;
	}

	int getimg()
	{
		return img;
	}

	Complex(Complex s1, Complex s2)
	{
		real = s1.real + s1.img;
		img = s2.real + s2.img;
	}

	void display()
	{
		cout << "\n Real Part = " << real;
		cout << "\n Imaginary Part = " << img;
		cout << "\n " << real << " + " << img << "i";
	}
};

Complex add(Complex S1, Complex S2)
{
	Complex S3;
	
	int r1 = S1.getreal();
	int i1 = S1.getimg();
	int r2 = S2.getreal();
	int i2 = S2.getimg();

	S3.setreal(r1 + r2);
	S3.setimg(i1 + i2);

	return S3;
}

int main()
{
	int r[2], i[2];
	Complex S1;
	cout << "\n Enter Data for Obejct 1";
	cout << "\n Enter Real Number: "; cin >> r[0];
	cout << "\n Enter Imaginary Number: "; cin >> i[0];
	
	S1.setreal(r[0]);
	S1.setimg(i[0]);
	r[0] = S1.getreal();
	i[0] = S1.getimg();

	Complex S2;
	cout << "\n Enter Data for Obejct 2";
	cout << "\n Enter Real Number: "; cin >> r[1];
	cout << "\n Enter Imaginary Number: "; cin >> i[1];

	S2.setreal(r[1]);
	S2.setimg(i[1]);
	r[1] = S2.getreal();
	i[1] = S2.getimg();

	Complex s3 = add(S1, S2);
	s3.display();

	return 0;
}