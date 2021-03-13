#include<iostream>
using namespace std;

class Time
{
	int hours = 0, min = 0, sec = 0;
	char zone;
public:
	Time()
	{
		hours = 0;
		min = 0;
		sec = 0;
	}

	Time(int hours, int min, int sec)
	{
		this->hours = hours;
		this->min = min;
		this->sec = sec;
	}

	Time(const Time &s4) // copy constructor
	{
		hours = s4.hours;
		min = s4.min;
		sec = s4.sec;
	}

	void setzone(char zone)
	{
		this->zone = zone;
	}

	void settime(int hours, int min, int sec)
	{
		if (zone == 'p' && this->hours != 12)
			if (this->hours >= 1 && this->hours <= 11)
				this->hours += 12;

			else if (zone == 'a' && this->hours != 12)
				if (this->hours >= 13 && this->hours <= 23)
					this->hours -= 12;

				else if (this->hours == 12 && zone == 'a')
					this->hours = 0;

				else
					this->hours = 0;

		if (min >= 0 && min <= 60)
			this->min = min;
		else
			this->min = 0;

		if (sec >= 0 && sec <= 6)
			this->sec = sec;
		else
			this->sec = sec;
	}

	void showtime()
	{
		if (zone == 'a')
		{
			if (hours == 12)
				hours = 0;

			if (hours < 10) 
			{
				if (min < 10)
				{
					if (sec < 10) 
					{
						cout << "\n 0" << hours << ": 0" << min << ": 0" << sec << " AM ";
					
					}
					else
						cout << "\n 0" << hours << ": 0" << min << ": " << sec << " AM ";
				}
				else if (sec < 10)
					cout << "\n 0" << hours << ": " << min << ": 0" << sec << " AM ";
				else
					cout << "\n 0" << hours << ": " << min << ": " << sec << " AM ";
			}
			else if (min < 10) 
			{
				if (sec < 10) 
				{
					cout << "\n " << hours << ": 0" << min << ": 0" << sec << " AM ";
				}
				else
					cout << "\n " << hours << ": 0" << min << ": " << sec << " AM ";
			}

			else if(sec<10)
				cout << "\n " << hours << ": " << min << ": 0" << sec << " AM ";
				

		else if(hours >= 10 && min >=10 && sec >=10)
				cout << "\n " << hours << ": " << min << ": " << sec << " AM ";
		}

		if (zone == 'p')
		{
			if (hours == 24)
				hours = 0;

			if (hours < 10) 
			{
				if (min < 10) 
				{
					if (sec < 10)
					{
						cout << "\n 0" << hours << ": 0" << min << ": 0" << sec << " PM ";
					}
					else
						cout << "\n 0" << hours << ": 0" << min << ": " << sec << " PM ";
				}
				else if (sec < 10)
					cout << "\n 0" << hours << ": " << min << ": 0" << sec << " PM ";
				else
					cout << "\n 0" << hours << ": " << min << ": " << sec << " PM ";
			}
			else if (min < 10)
			{
				if (sec < 10) 
				{
					cout << "\n " << hours << ": 0" << min << ": 0" << sec << " PM ";
				}
				else
					cout << "\n " << hours << ": 0" << min << ": " << sec << " PM ";
			}
			else if (sec < 10)
				cout << "\n " << hours << ": " << min << ": 0" << sec << " PM ";

		   else if (hours >= 10 && min >= 10 && sec >= 10)
		    	cout << "\n " << hours << ": " << min << ": " << sec << " PM ";
		}
	}

	void tick()
	{
		if (sec < 60)
			sec += 1;

		if (sec == 60)
		{
			sec = 0;
			min += 1;
		}

		else if (sec > 60)
			sec += 1;

		if (min == 60)
		{
			min = 0;
			hours += 1;
		}
		else if (min > 60)
			min += 1;

		if (hours > 24)
			hours -= hours;

	}

	void check(Time& s1, Time& s2)
	{
		if (s1.hours < s2.hours)
		{
			cout << "\n S1 contains shorter distance: ";
			s1.showtime();
		}
		else if (s1.hours == s2.hours)
		{
			if (s1.min < s2.min)
			{
				cout << "\n S1 contains sshorter distance: ";
				s1.showtime();
			}
			else if (s1.min == s2.min)
			{
				if (s1.sec < s2.sec)
				{
					cout << "\n S1 contains sshorter distance: ";
					s1.showtime();
				}
				else if (s1.sec == s2.sec)
					cout << "\n Both are equal ";
				else
				{
					cout << "\n S2 contains sshorter distance: ";
					s2.showtime();
				}
			}
			else
			{
				cout << "\n S2 contains shorter distance: ";
				s2.showtime();
			}
		}
		else
		{
			cout << "\n S2 contains sshorter distance: ";
			s2.showtime();
		}
	}
};

void main()
{
	int hour = 0, min = 0, sec = 0;
	char zone;
	cout << "\n Enter Hours: "; cin >> hour;
	cout << "\n Enter Minutes: "; cin >> min;
	cout << "\n Enter Seconds: "; cin >> sec;
	cout << "\n Enter Zone(a/p): "; cin >> zone;

	Time s1(hour, min, sec);
	s1.setzone(zone);
	s1.settime(hour, min, sec);
	s1.showtime();

	cout << "\n Enter Hours: "; cin >> hour;
	cout << "\n Enter Minutes: "; cin >> min;
	cout << "\n Enter Seconds: "; cin >> sec;
	cout << "\n Enter Zone(a/p): "; cin >> zone;

	Time s2(hour, min, sec);
	s2.setzone(zone);
	s2.settime(hour, min, sec);
	s2.showtime();

	s1.check(s1, s2);

	for (int i = 0; i < 10; i++)
		s1.tick();
	cout << "\n\n S1 after calling tick 10 times is: ";
	s1.showtime();

	Time s3;
	
	Time s4(10, 56, 5);
	s4.setzone('a');

	Time s5 = s4;

	cout << "\n\n s3: ";
	s3.setzone('a');
	s3.showtime();
	cout << "\n\n s4: ";
	s4.showtime();
	cout << "\n\n s5: ";
	s5.setzone('a');
	s5.showtime();
}