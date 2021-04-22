
#ifndef Employee_hpp
#define Employee_hpp

#include <string>
using namespace std;

class Employee {
	string empID;
	string name;
	string lastName;
	string position;
	string department;

public:

	Employee(); //default constructor, set string variables to ""
	Employee(string id, string n, string l, string pos, string dept); //parametrized constructor

	string getEmpID()const; // return value empID
	string getName()const; // return value name
	string getLastName() const; // return value lastName
	string getPosition()const; // return value position
	string getDepartment()const; // return value department
	void setEmpID(string id); //set empID to id
	void setName(string n); //set name to n
	void setLastName(string l); //set lastName to l
	void setPosition(string pos); //set position to pos
	void setDepartment(string dept); //set department to dept

};

#endif /* Employee_hpp */



