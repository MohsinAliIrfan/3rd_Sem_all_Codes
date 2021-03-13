#include<iostream>
#include<string>
using namespace std;

class Employee
{
	const int emp_id = 0;
	char* name;
	int year, salaray;
	char* address;

public:

	Employee()
	{
		salaray = 0;
		year = 0;
	}

	Employee(char* name1, char* add, int empid, int year, int salry) : emp_id(empid)
	{
		this->year = year;
		salaray = salry;
	}

	void setname(char*_name)
	{
		int size = strlen(_name);
			name = new char[size + 1];
			strcpy_s(name, size+1, _name);
	}

	void setadd(char* _add)
	{
		int size = strlen(_add);
			address = new char[size + 1];
		strcpy_s(address, size+1, _add);
	}

	bool setyearr(int year)
	{
		if (year <= 0 || year > 2020)
			return false;
		else
		{
			this->year = year;
			return true;
		}
	}

	bool setsalary(int salry)
	{
		if (year < 0)
			return false;
		else
		{
			this->salaray = salry;
			return true;
		}
	}

	char* getname() const
	{
		int size = strlen(name);
		char* _name = new char[size + 1];
		strcpy_s(_name, size+1, name);
		return _name;
	}

	char* getadd() const
	{
		int size = strlen(address);
		char* add = new char[size + 1];
		strcpy_s(add, size+1, address);
		return add;
	}

	int getyear() const
	{
		return year;		
	}

	int getsalaray() const
	{
		return salaray;
	}

	void display()
	{
		cout << "\n " << name << " has been working since " << year << " years with a salry of " << salaray << " PKR";
		cout << " The Address of " << name << " is " << address;
	}

	void calculation()
	{
		cout << "\n Total years the Employee has been Working is: " << 2020 - year;
	}

	int getemp() const
	{
		return emp_id;
	}

	~Employee()
	{
		delete[]name;
		delete[]address;
	}
};

int main()
{
	char *name1 = new char[50], *add1 = new char[100];
	int year, salry, empid;
	bool check = true;

	cout << " 'Data for Employee 1 '";
	cout << "\n Enter name: "; cin.getline(name1, 50);
	do
	{
		cout << "\n Enter Employee ID: "; cin >> empid;
		if (empid < 0)
			check = false;
		else
			check = true;

	} while (check == false);
	cout << "\n Enter Joining Year: "; cin >> year;
	cout << "\n Enter Salary: "; cin >> salry;
	cout << "\n Enter Address: "; cin.getline(add1, 100); cin.getline(add1, 100); // i dont know the reason but it asks for input whenver i write cin.getline twice

	Employee emp1(name1, add1, empid, salry, year);
		
	check = emp1.setyearr(year);
		while (check == false) 
		{
			cout << "\n Enter Joining Year again: "; cin >> year;
			check = emp1.setyearr(year);
	    }
		check = emp1.setsalary(salry);
		while (check == false)
		{
			cout << "\n Enter Salary again: "; cin >> salry;
			check = emp1.setsalary(salry);
		}
		check = emp1.setyearr(year);

	emp1.setname(name1);
	emp1.setadd(add1);
	name1 = emp1.getname();
	add1 = emp1.getadd();
	year = emp1.getyear();
	salry = emp1.getsalaray();
	empid = emp1.getemp();
	emp1.display();
	emp1.calculation();

	char* name2 = new char[50], * add2 = new char[100];
	int year2, salry2, empid2;
    check = true;

	cout << " \n\n'Data for Employee 2 '";
	cout << "\n Enter name: "; cin.getline(name2, 50);
	do
	{
		cout << "\n Enter Employee ID: "; cin >> empid2;
		if (empid < 0)
			check = false;
		else
			check = true;

	} while (check == false);
	cout << "\n Enter Joining Year: "; cin >> year2;
	cout << "\n Enter Salary: "; cin >> salry2;
	cout << "\n Enter Address: "; cin.getline(add2, 100); cin.getline(add2, 100); // i dont know the reason but it asks for input whenver i write cin.getline twice

	Employee emp2(name2, add2, empid2, salry2, year2);

	check = emp2.setyearr(year2);
	while (check == false)
	{
		cout << "\n Enter Joining Year again: "; cin >> year;
		check = emp2.setyearr(year2);
	}
	check = emp2.setsalary(salry2);
	while (check == false)
	{
		cout << "\n Enter Salary again: "; cin >> salry;
		check = emp2.setsalary(salry2);
	}

	emp2.setname(name2);
	emp2.setadd(add2);
	name2 = emp2.getname();
	add2 = emp2.getadd();
	year2 = emp2.getyear();
	salry2 = emp2.getsalaray();
	empid2 = emp2.getemp();
	emp2.display();
	emp2.calculation();

	delete[]name1;
	delete[]add1;
	delete[]name2;
	delete[]add2;

	cout << endl;
	return 0;
}