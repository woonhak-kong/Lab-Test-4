// This program demonstrates the use of a structure.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
private:
	int    empNumber;  // Employee number
	string name;       // Employee name
	double hours,      // Hours worked
		payRate;    // Hourly pay rate
public:
	Employee(int empN, string n, double h, double p)
	{
		empNumber = empN;
		name = n;
		hours = h;
		payRate = p;
	}

	Employee()
	{
		empNumber = 0;
		name = "No Name";
		hours = 0;
		payRate = 0;
	}
	void setEmpNumber(int number)
	{
		empNumber = number;
	}

	void setName(string n)
	{
		name = n;
	}

	void setPayRate(double rate)
	{
		payRate = rate;
	}

	void setHours(double h)
	{
		hours = h;
	}

	int getEmpNumber()
	{
		return empNumber;
	}

	string getName()
	{
		return name;
	}

	double getHours()
	{
		return hours;
	}

	double getPayRate()
	{
		return payRate;
	}

	double getWage()
	{
		return payRate * hours;
	}

	string getEmpData()
	{
		string data = "\nEmployee ID Number ===> " + to_string(empNumber);
		data += "\nEmployee Name ========> " + name;
		data += "\nHours Worked =========> " + to_string(hours);
		data += "\nPay Rate =============> " + to_string(payRate);
		data += "\nTotal Wage ===========> " + to_string(getWage());
		data += "\n";

		return data;
	}



};


Employee findHigh(Employee list[], int size);
Employee findLow(Employee list[], int size);
void sortEmployeesAZ(Employee list[], int size);
void sortEmployeesByRate(Employee list[], int size);
double getAverageEarning(Employee list[], int size);
int getNumOfHigherThanAverage(Employee list[], int size);
int findEmloyeeByID(Employee list[], int size, int id);


int main()
{
	const int NUM_EMPLOYEES = 4;

	Employee list[NUM_EMPLOYEES];
	list[0] = Employee(1, "John", 40, 25);
	list[1] = Employee(2, "Mary", 30, 40);
	list[2] = Employee(3, "Grace", 35, 30);
	list[3] = Employee(4, "Mark", 45, 20);

	cout << "======  Sort Employees by rate of pay from high to low =====\n";

	sortEmployeesByRate(list, NUM_EMPLOYEES);

	for (int i = 0; i < NUM_EMPLOYEES; i++)
	{
		cout << list[i].getEmpData();
	}
	cout << "=============================================================\n\n";

	cout << "======  The average earnings of all employees  =====\n";
	cout << "$ " << fixed << setprecision(2) << getAverageEarning(list, NUM_EMPLOYEES) << endl;

	cout << "=============================================================\n\n";

	cout << "======  The number of employees whose earnings are higher then average.   =====\n";
	cout << getNumOfHigherThanAverage(list, NUM_EMPLOYEES) << " people\n";
	cout << "=============================================================\n\n";

	cout << "======  Performs the search for a specific employee and returns the employee ID    =====\n";
	cout << "Find Number 3  --> " << findEmloyeeByID(list, NUM_EMPLOYEES, 3) << endl;

	system("pause");
	return 0;
}

Employee findHigh(Employee list[], int size)
{

	Employee high = list[0];
	for (int i = 0; i < size; i++)
			if (list[i].getWage() > high.getWage())
			{
				high = list[i];
			}
	return high;
}

Employee findLow(Employee list[], int size)
{

	Employee low = list[0];
	for (int i = 0; i < size; i++)
		if (list[i].getWage() < low.getWage())
		{
			low = list[i];
		}
	return low;
}

void sortEmployeesAZ(Employee list[], int size)
{
	Employee emp;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (list[i].getWage() > list[j].getWage())
			{
				emp = list[i];
				list[i] = list[j];
				list[j] = emp;
			}
}

void sortEmployeesByRate(Employee list[], int size)
{
	Employee emp;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (list[i].getPayRate() < list[j].getPayRate())
			{
				emp = list[i];
				list[i] = list[j];
				list[j] = emp;
			}
}

double getAverageEarning(Employee list[], int size)
{
	double averageEarning = 0;
	for (int i = 0; i < size; i++)
	{
		averageEarning += list[i].getWage();
	}
	averageEarning = averageEarning / size;
	return averageEarning;
}

int getNumOfHigherThanAverage(Employee list[], int size)
{
	double average = getAverageEarning(list, size);
	int numOfAverage = 0;

	for (int i = 0; i < size; i++)
	{
		if (list[i].getWage() > average)
		{
			numOfAverage++;
		}
	}
	return numOfAverage;
}

int findEmloyeeByID(Employee list[], int size, int id)
{

	for (int i = 0; i < size; i++)
	{
		if (list[i].getEmpNumber() == id)
		{
			return list[i].getEmpNumber();
		}
	}
	return 0;
}
