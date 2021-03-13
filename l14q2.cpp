#include<iostream>
using namespace std;

class Person {
	int age;
	char* name = nullptr;
public:
	Person(int age = 0, char* name = nullptr) {
		cout << "\n PERSON:\n ";
		this->age = age;
		this->name = name;
	}

	void setage(int age) 
	{
		if (age <= 0)
			this->age = 1;
		else
			this->age = age;
	}
	void setname(char *Name)
	{
		if (name != nullptr)
			delete[]name;
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
	}

	int getage() { return age; }

	char* getname() 
	{
		char* newarr = new char[strlen(name) + 1];
		strcpy_s(newarr, strlen(name) + 1, name);
		return newarr;
	}
	void display()
	{
		cout << "Name: " << name;
		cout << "\nAge: " << age;
	}
};
class Student :public Person 
{
	char* sec = nullptr;
	char* roll_no = nullptr;
public:
	Student(char *sec = nullptr, char *roll_no = nullptr) 
	{
		this->sec = sec;
		this->roll_no = roll_no;
	}
	void setsec(char *sec)
	{
		if (this->sec != nullptr)
			delete[]this->sec;
		this->sec = new char[strlen(sec) + 1];
		strcpy_s(this->sec, strlen(sec) + 1, sec);
	}
	void setroll(char *roll_no)
	{
		if (this->roll_no != nullptr)
			delete[]this->roll_no;
		
		this->roll_no = new char[strlen(roll_no) + 1];
		strcpy_s(this->roll_no, strlen(roll_no) + 1, roll_no);
	}
	char* getsec() 
	{
		char* newarr = new char[strlen(sec) + 1];
		strcpy_s(newarr, strlen(sec) + 1, sec);
		return newarr;
	}
	char* getroll() 
	{
		char* newarr = new char[strlen(roll_no) + 1];
		strcpy_s(newarr, strlen(sec) + 1,roll_no);
		return newarr;
	}
	void display()
	{
		cout << "\n Roll no. " << roll_no;
		cout << "\n Section: " << sec;
	}
};
class Teacher :public Person
{
	double salaray;
	char* des = nullptr; //deignation
public:
	Teacher(double sal = 0, char* des = nullptr)
	{
		this->salaray = sal;
		this->des = des;
	}
	void setsalaray(int salaray) 
	{
		if (salaray <= 0)
			this->salaray = 1;
		else
			this->salaray = salaray;
	}
	void setdesignation(char* des) 
	{
		if (this->des != nullptr)
			delete[]this->des;
		this->des = new char[strlen(des) + 1];
		strcpy_s(this->des, strlen(des) + 1, des);
	}
	
	double getsalaray() { return salaray; }

	char* getdesignation() 
	{
		char* newarr = new char[strlen(des) + 1];
		strcpy_s(newarr, strlen(des) + 1, des);
		return newarr; 
	}
	void display()
	{
		cout << "\n Designation: " << des;
		cout << " \n Salary: " << salaray;
	}
};
class TA:public Student,public Teacher 
{
	int wlih; //workloadinhours
	char* subject = nullptr;
public:
	TA(int wlih = 0, char*subject = nullptr)
	{
		this->wlih = wlih;
		this->subject = subject;
	}
	void setworkloadinhours(int wlih)
	{
		if (wlih <= 0)
			this->wlih = 1;
		else
			this->wlih = wlih;
	}
	void setsubject(char* sub)
	{
		if (this->subject != nullptr)
			delete[]this->subject;
		this->subject = new char(strlen(sub) + 1);
		strcpy_s(subject, strlen(sub) + 1, sub);
	}
	int getworkloadinhours() { return wlih; }
	char* getsubject()
	{
		char* newarr = new char[strlen(subject) + 1];
		strcpy_s(newarr, strlen(subject) + 1, subject);
		return newarr;
	}
	void display()
	{
		Person::display();
		Student::display();
		Teacher::display();
		cout << "\n Sbject: " << subject;
		cout << "\n Work Load in Hours: " << wlih;
	}
};

int main() 
{
	char arr[20];
	char arr2[20];
	char arr3[20];
	char arr4[20];
	char arr5[20];
	int wlih;
	int num;
	double sal;
	/*cout << "\n Enter Name: "; cin >> arr;
	cout << " \n Enter Age: "; cin >> num;
	cout << "\n Enter Section: "; cin >> arr2;
	cout << "\n Enter Roll Number: "; cin >> arr3;
	Student std;
	std.setname(arr);
	std.setage(num);
	std.setroll(arr3);
	std.setsec(arr2);

	cout << "\n Enter Name: "; cin >> arr;
	cout << " \n Enter Age: "; cin >> num;
	cout << "\n Enter Designation"; cin >> arr2;
	cout << "\n Enter Salary: "; cin >> sal;
	Teacher th;
	th.setname(arr);
	th.setage(num);
	th.setdesignation(arr2);
	th.setsalaray(sal);
	*/
	cout << "\n Enter Name: "; cin >> arr;
	cout << " \n Enter Age: "; cin >> num;
	cout << "\n Enter Section: "; cin >> arr2;
	cout << "\n Enter Roll Number: "; cin >> arr3;
	cout << "\n Enter Designation"; cin >> arr4;
	cout << "\n Enter Salay:"; cin >> sal;
	cout << "\n Enter Work Load in Hour: "; cin >> wlih;
	cout << "\n Enter Subject: "; cin >> arr5;
	TA t;
	t.Student::setname(arr);
	t.Student::setage(num);
	t.setroll(arr3);
	t.setsec(arr2);
	t.setdesignation(arr4);
	t.setsalaray(sal);
	t.setworkloadinhours(wlih);
	t.setsubject(arr5);

	t.display();

	return 0;
}