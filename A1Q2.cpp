#include<iostream>
using namespace std;

class Date
{
	int day = 0, month = 0, year = 0;
public:

	bool setday(int day)
	{
		if (day >= 1 && day <= 31)
		{
			this->day = day;
			return true;
		}
		else
			return false;
	}

	bool setmonth(int month)
	{
		if (month >= 1 && month <= 12)
		{
			this->month = month;
			return true;
		}
		else
			return false;
	}

	bool setyear(int year)
	{
		if (year > 0)
		{
			this->year = year;
			return true;
		}
		else
			return false;
    }

	int getday() const
	{
		return day;
	}

	int getmonth() const
	{
		return month;
	}

	int getyear() const
	{
		return year;
	}

	void display()
	{
		cout << "\n DAY: " << day;
		cout << "\n MONTH: " << month;
		cout << "\n YEAR: " << year;
	}

	void cal(Date &b_date, Date &c_date)
	{
		int _month = 0;
		int _year = c_date.year - b_date.year;
		
		if (c_date.month > b_date.month)
		      _month = c_date.month - b_date.month;
		else
			 _month = b_date.month - c_date.month;
		
		int _day = _month * 30;
		int ans = c_date.day - b_date.month;
		_day -= ans;
		cout << "\n\n Age of User is:\n " << _year << " years  " << _month << " months and  " << _day << " days";
	}
};

int main()
{
	Date b_date, c_date;
	int day = 0, month = 0, year = 0;
	int day1 = 0, month1 = 0, year1 = 0;
	bool check = true;

	cout << "\n Enter Birth Date:\n ";
	do
	{
		cout << "\n Enter Day: "; cin >> day;
		check = b_date.setday(day);

	} while (check == false);
	day = b_date.getday();

	do 
	{
		cout << "\n Enter Month: "; cin >> month;
		check = b_date.setmonth(month);

	} while (check == false);
	month = b_date.getmonth();

	do 
	{
		cout << "\n Enter Year: "; cin >> year;
		check = b_date.setyear(year);

	} while (check == false);
	year = b_date.getyear();

	cout << "\n Enter Current Date:\n ";
	do
	{
		cout << "\n Enter Day: "; cin >> day;
		check = c_date.setday(day);

	} while (check == false);
	day1 = c_date.getday();

	do
	{
		cout << "\n Enter Month: "; cin >> month;
		check = c_date.setmonth(month);

	} while (check == false);
	month1 = c_date.getmonth();

	do
	{
		cout << "\n Enter Year: "; cin >> year;
		check = c_date.setyear(year);

	} while (check == false);
     year = c_date.getyear();


	cout << "\n Birth Date is:";      
	b_date.display();
	cout << "\n\n Current Date is:";    
	c_date.display();

	b_date.cal(b_date, c_date);
	cout << endl;
	return 0;
}