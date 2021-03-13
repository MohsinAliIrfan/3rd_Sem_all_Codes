#include<iostream>
using namespace std;

class IntegerList
{
	int* list;
	int count = 0;
public:
	IntegerList(int size = 0)
	{
		if (size == 0)
			list = new int[100];
		else
			list = new int[size];
	}

	IntegerList copy(IntegerList& obj)
	{
		for (int i = 0; i < this->count; i++)
			this->list[i] = obj.list[i];
		return *this;
	}

	IntegerList(IntegerList& obj, int str, int end)
	{
		int a = 0;
		int size = obj.getCount();
		list = new int[size + 1];
		for (int i = str - 1; i < end; i++) {
			list[a++] = obj.list[i];
			count++;
		}
	}

	void insert(int num)
	{
		list[count++] = num;
		//	cout << ""
	}

	int getCount()
	{
		if (count == 0)
			return 0;
		return count;
	}
	void clear()
	{
		for (int i = 0; i < count; i++)
			list[i] = 0;
		count = 0;
	}

	IntegerList& operator+(IntegerList& obj)
	{
		IntegerList temp;
		int ind = 0;
		//	int size = this->count;
		int size1 = this->count + obj.count;

		for (int i = 0; i < this->count; i++)
			temp.list[i] = this->list[i];

		for (int j = this->count; j < size1; j++)
			temp.list[j] = obj.list[ind++];

		temp.count = size1;
		return temp;
	}

	int& operator [](int index)
	{
		if (index >= 0 && index < count)
			return list[index];

		return list[0];
	}

	IntegerList& operator++()
	{
		for (int i = 0; i < this->count; i++)
			++this->list[i];
		return *this;
	}

	IntegerList& operator++(int)
	{
		for (int i = 0; i < this->count; i++)
			this->list[i]++;
		return *this;
	}

	IntegerList& operator--()
	{
		for (int i = 0; i < this->count; i++)
			--this->list[i];
		return *this;
	}

	IntegerList& operator--(int)
	{
		for (int i = 0; i < this->count; i++)
			this->list[i]--;
		return *this;
	}

	bool operator==(const IntegerList& obj)
	{
		bool check = false;
		for (int i = 0; i < this->count; i++) {
			if (this->list[i] == obj.list[i])
				check = true;
		}
		if (check == true)
			return true;
		return false;
	}

	void display() {
			for (int i = 0; i < this->count; i++)
				cout << " " << list[i];
	}

};

void print(IntegerList &obj){
	obj.display();
}


int main()
{
	IntegerList list1;//making empty default IntegerList of 100 size
	int number = 12;
	int i = 1;
	while (i <= number)
	{
		list1.insert(i);//inserting elements into list1 by incrementing its indexes like 0 1, 2, 3, 4 and so on.For eg. 1st time insertion will insert at index 0, then index 1 and so on
			i++;
	}
	cout << "list1\n";
	print(list1);
	cout << "The number of elements in list1 = " << list1.getCount() << endl;
	IntegerList list2(list1, 2, 9);//should copy the elements of list1 from position 2 to 9
	cout << "list2 is a copy of list1 from position 2 to 9\n";
	print(list2);
	cout << "The number of elements in list2 = " << list2.getCount() << endl;
	IntegerList list3;
	cout << "list3 is a constant IntegerList\n";
	cout << "The number of elements in list3 = " << list3.getCount() << endl;
	list1.clear();//should set the values of list1 to zeros and its count to zero
	cout << "After clearing list1\n";
	print(list1);
	IntegerList list4(10);//should make an empty IntegerList of size 10(passed as a parameter)
	cout << "list4 is an empty IntegerList of size 10\n";
	print(list4);
	list4.insert(55);//inserting elements into list4
	list4.insert(56);//inserting elements into list4
	list4.insert(57);//inserting elements into list4
	list4.insert(58);//inserting elements into list4
	cout << "After inserting elements in list4\n";
	print(list4);
	IntegerList list5;
	list5 = list2 + list4; //list5 should have both the elements of list2 and list4
	cout << "\nlist5 contains both the elements of list2 and list4\n";
	print(list5);
	list5[0] = list5[0] + 1;//but it should give compile time error if list5 is constant For eg: const IntegerList list5;
		cout << "After adding 1 to the elmenent at 0 index of list5\n";
	print(list5);
	cout << "\nprint(list5++);\n";
	print(list5++);//post-increment
	cout << "\nprint(++list5)\n";
	print(++list5);//pre-increment
	cout << "\nprint(--list5)\n";
	print(--list5);//pre-decrement

	cout << "\nprint(list5--)\n";
	print(list5--);//post-decrement
	cout << "\nlist6 is a copy of list5\n";
	IntegerList list6 = list5;//list6 is a copy of list5
	print(list6);
	cout << "\nprint(list5++)\n";
	print(list5++);
	cout << "Comparing list5 and list6 are equal or not?\n";
	if (list6 == list5) //comparison of two IntegerLists to compare all the elements of IntegerLists
	{
	cout << "\nAs you can see Both the IntegerLists list5 and list6 are equal\n";
	cout << "list5: ";
	print(list5);
	cout << "list6: ";
	print(list6);
	}
	else
	{
		cout << "\nAs you can see Both the IntegerLists list5 and list6 are not equal\n";
		cout << "list5: ";
		print(list5);
		cout << "\nlist6: ";
		print(list6);
	}
	cout << "\nlist4 after assignment: ";
	(list4 = list5) = list6;
	print(list4);
	return 0;
}