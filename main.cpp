///this is the code for part 2///


#include<iostream>
using namespace std;




class Employee {
	
private:
	string name;

public:
	//constructor
	Employee(string nm)
	{
		name = nm;
	}

	//A print method to output class data
	void print()
	{
		cout << "Name : " << name << endl << endl;
	}

	//Virtual functions
	virtual double weeklySalary() = 0;
	virtual int vacations() = 0;
	virtual double insurance() = 0;
};

//A professional employee class that inherits from employee class
class ProfessionalEmployee : public Employee
{
private:
	double monthlySalary;

public:
	//Constructor
	ProfessionalEmployee(string nm, double mSal) : Employee(nm)
	{
		monthlySalary = mSal;
	}

	//overriding the virtual methods of parent class
	double weeklySalary()
	{
		return monthlySalary / 4;
	}

	int vacations()
	{
		return 23;
	}

	double insurance()
	{
		return (2.0 * monthlySalary) / 3.0;
	}
};

//the non-proffesional class, an employee class that is not professional and derives from employee class
class NonProfessionalEmployee : public Employee
{
private:
	double timeWorked,hourlyRate;


public:
	
//Constructor//
	NonProfessionalEmployee(string nm, double wTime, double hRate) : Employee(nm)
	{
		timeWorked = wTime;
		hourlyRate = hRate;
	}

	//the virtual methods of the parent class are overridden
	double weeklySalary()
	{
		return timeWorked * hourlyRate;
	}

	int vacations()
	{
		return 12;
	}

	double insurance()
	{
		return weeklySalary() / 2.0;
	}
};


//========================================//

//Main function
int main()
{
	
  cout << "PROFESSIONAL EMPLOYEE " << endl;
	ProfessionalEmployee obj("Sam", 120000);
	cout << "Weekly Salary: " << obj.weeklySalary() << endl;
	cout << "Insurance: $" << obj.insurance() << endl;
	cout << "Vacations: " << obj.vacations() << endl << endl;

	cout << "NONPROFESSIONAL EMPLOYEE " << endl;
	NonProfessionalEmployee obj1("James", 65, 1500);
	cout << "Weekly Salary: " << obj1.weeklySalary() << endl;
	cout << "Insurance: $" << obj1.insurance() << endl;
	cout << "Vacations: " << obj1.vacations() << endl << endl;
  }



