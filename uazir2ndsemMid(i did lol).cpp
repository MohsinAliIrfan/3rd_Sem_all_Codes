#include<iostream>
using namespace std;

class P {
public:
	void print() {
		cout << "\n Class A ";
	}
};
class Q:public P{
public:
	void print() {
		cout << "\n Class Q ";
	}
};
class R: public Q {};


int main() {
	R r;
	r.print();
	return 0;
}