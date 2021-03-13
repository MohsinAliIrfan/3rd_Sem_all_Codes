#include<iostream> 
using namespace std;
class A
{
public:
	A() { cout << "A's constructor called" << endl; }
	void display() { cout << "Display of A"; }
};
class B
{
public:
	B() { cout << "B's constructor called" << endl; }
	void display() { cout << "Display of B"; }
};

class C : public A, public B// Note the order 
{
public:
	C() { cout << "C's constructor called" << endl; }
	//void display() { cout << "Display of C"; }
};
int main()
{
	C c;
	c.A::display();
	c.B::display();
	return 0;
}
//we will have to call the function explicitly bcz display function is in class A and B and both are C parents, so it will be 
// obejct of class c will not understand which funtion to call, so for doing it, wwe have to call both disdplay functions explicitly