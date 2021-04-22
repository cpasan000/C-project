
#include "Employee.h"

Employee::Employee()
{
	empID = "";
	name = "";
	lastName = "";
	position = "";
	department = "";
}

Employee::Employee(string id, string n, string l, string pos, string dept)
{
	empID = id;
	name = n;
	lastName = l;
	position = pos;
	department = dept;
}

string Employee::getEmpID() const
{
	return empID;
}

string Employee::getName() const
{
	return name;
}

string Employee::getLastName() const
{
	return lastName;
}

string Employee::getPosition() const
{
	return position;
}

string Employee::getDepartment() const
{
	return department;
}

void Employee::setEmpID(string id)
{
	empID = id;
}

void Employee::setName(string n)
{
	name = n;
}

void Employee::setLastName(string l)
{
	lastName = l;
}

void Employee::setPosition(string pos)
{
	position = pos;
}

void Employee::setDepartment(string dept)
{
	department = dept;
}

