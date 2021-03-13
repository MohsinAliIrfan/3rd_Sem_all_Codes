#include<iostream>
using namespace std;

class Employee
{
	char* firstName;  
	char* lastName;
	const double hourlyRate = 10; 
	double hours, pay;
public:
	// Parameterized Constructor with default arguments
	Employee(char* firstname = nullptr, char* lastname = nullptr, double hours = 0.0)
	{
		setFirstName(firstname);
		setLastName(lastname);
	}
	
	Employee(const Employee& s2)
	{
		this->firstName = deepcopy(s2.firstName);
		this->lastName = deepcopy(s2.lastName);
		this->hours = s2.hours;
		this->pay = s2.pay;
	}

	void CopyName(Employee &s1, char* firstname, char* lastname, double hours)
	{
		s1.firstName = deepcopy(firstname);
		s1.lastName = deepcopy(lastname);
		s1.hours = hours;
	}

	char* deepcopy(char *oldarr)
	{
		int size = strlen(oldarr) + 1;
		char* arr = new char[size];
		strcpy_s(arr, size, oldarr);
		return arr;
	}

	void setFirstName(char* firstname)
	{
		if (firstName != nullptr)
			delete[]firstName;
		
		int size = strlen(firstname) + 1;
		firstName = new char[size];
		strcpy_s(firstName, size, firstname);
	}

	void setLastName(char* lastname)
	{
		if (lastName != nullptr)
			delete[]lastname;

		int size = strlen(lastname) + 1;
		lastName = new char[size];
		strcpy_s(lastName, size, lastname);
	}

	void setHours(double hours)
	{
		if (hours >= 0 && hours <= 23)
			this->hours = hours;
	}

	void printPayroll()
	{
		pay = hourlyRate * hours;
		cout << "\n\n First Name: " << firstName;
		cout << "\n Last Name: " << lastName;
		cout << "\n Hourly Rate: " << hourlyRate;
		cout << "\n Total Hours Worked: " << hours;
		cout << "\n Total Salry: " << pay;
	} 

	~Employee()
	{
		delete[]firstName;
		delete[]lastName;
	}
};


int main()
{
	char* firstName = new char[50];
	char* lastName = new char[50];
    double hourlyRate;
	double hours, pay;
	cout << "\n Enter data for Employee 1";
	cout << "\n Enter first Name: "; cin >> firstName;
	cout << "\n Enter Last Name: "; cin >> lastName;
	cout << "\n Total Hours Worked: "; cin >> hours;

	Employee s1(firstName, lastName, hours);
	s1.setHours(hours);
	s1.printPayroll();
	
	delete[]firstName;
	delete[]lastName;
	firstName = new char[50];
	lastName = new char[50];

	cout << "\n\n Enter data for Employee 2";
	cout << "\n Enter first Name: "; cin >> firstName;
	cout << "\n Enter Last Name: "; cin >> lastName;
	cout << "\n Total Hours Worked: "; cin >> hours;

	Employee s2(firstName, lastName, hours);
	s2.setHours(hours);
	s2.printPayroll();

	Employee s3 = s2;
	cout << "\n\n Data of S3\n";
	s3.printPayroll();

	delete[]firstName;
	delete[]lastName;
	firstName = new char[50];
	lastName = new char[50];

	cout << "\n\n Enter data for Employee 1 to change";
	cout << "\n Enter first Name: "; cin >> firstName;
	cout << "\n Enter Last Name: "; cin >> lastName;
	cout << "\n Total Hours Worked: "; cin >> hours;

	s1.CopyName(s1, firstName, lastName, hours);
	cout << "\n Chnged Data for Employee 1";
	s1.printPayroll();

	delete[]firstName;
	delete[]lastName;

	return 0;
}