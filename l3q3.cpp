#include<iostream>
using namespace std;

class Fun
{
	double* gpa_array;
	int size = 0;
	double cal = 0.0;

public:

	Fun() {
		gpa_array = new double[1];
	}

	void setsize(int size){
		this->size = size;
	}

	void grow(double num)
	{
		// creating a new array of size + 1, where as size indicates the total length of data in the array
		double* new_array = new double[size + 1];
	
		// copying the old data into the new one
			for (int i = 0; i < size; i++)
				new_array[i] = gpa_array[i];

		new_array[size] = num; // storing the latest value enterd by user on the last index of new array
		delete[]gpa_array; // deleting the old araay
		gpa_array = new_array;
	}

	void calculate()
	{
		for (int i = 0; i < size+1; i++)
			cal += gpa_array[i];
	}

	double getcal(){
		return cal;
	}

	~Fun() {
		delete[]gpa_array;
	}
};

void main()
{
	int again = 1;
	int size = 0;
	double gpa = 0.0;
	Fun s1;
	
	while (again == 1)
	{
		cout << "\n Enter Gpa: "; cin >> gpa;
		s1.setsize(size);
		s1.grow(gpa);
		size++;
		
		cout << "\n\n For Entering gpa again press 1: "; cin >> again;
	}
	s1.calculate();
	gpa = s1.getcal();
	cout << "\n\n Your Total is: " << gpa;
}